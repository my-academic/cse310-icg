#include <bits/stdc++.h>

using namespace std;

FILE *asmDataOut, *asmCodeOut;
string else_if_label = "";
extern int line_count;
class var_info {
public: 
    string name;
    int size;

    var_info(string n, int s): name(n), size(s) {}
};

vector<vector<var_info>> variables_stack; // stack for variables
int bp_current_position = -1;

bool has_main_function = false;

void pushToStackTemp(string str) {
    fprintf(asmCodeOut, "push %s\n", str.c_str());
}

int labelCount = 0;
int tempCount = 0;


void printCurrentStatement(string str)
{
    fprintf(asmCodeOut, "\n;line %d: %s\n", line_count, str.c_str());
}

void initiateAssembly()
{

    //   string model= ".model small\n";
    //   string stack = "\n.stack 100h\n";
    fprintf(asmDataOut, ".model small\n.stack 100h\n.data\nMINUS DB ?\nNUMBER_STRING DB \'00000$\'\n");
    fprintf(asmCodeOut, "\n.code\n\n");
}

void addDataInAssembly(string name, string scope_id, bool is_array = false, int size_of_array = 0)
{
    if (!is_array)
        fprintf(asmDataOut, "%s DW 0\n", name.c_str());
    else
        fprintf(asmDataOut, "%s DW %d DUP(0)\n", name.c_str(), size_of_array);
}

void addFuncDefinitionInAsm(string name, int param_count)
{
    has_main_function |= (name == "main");
    if (name == "main")
        fprintf(asmCodeOut, "main proc\npush bp\nmov bp, sp\nmov cx, @data\nmov ds, cx\n\n");
    else
        fprintf(asmCodeOut, "%s_procedure proc\npush bp\nmov bp, sp\n\n", name.c_str());
}

void addFunctionEndStatementInAsm(string name, int param_count, vector<string> return_label, int offset)
{
    for (size_t i = 0; i < return_label.size(); i++)
    {
        fprintf(asmCodeOut, "%s: \n", return_label[i].c_str());
    }

    fprintf(asmCodeOut, "add sp, %d\n", offset);

    
    if (name == "main")
    {
        fprintf(asmCodeOut, "\nmov ah, 4ch\nint 21h\n");
        fprintf(asmCodeOut, "%s endp\n\n", name.c_str());
    }
    else
    {
        fprintf(asmCodeOut, "\npop bp\nret %d\n", param_count * 2);
        fprintf(asmCodeOut, "%s_procedure endp\n\n", name.c_str());
    }
    bp_current_position --;
}

void addArrayIndexInAsm()
{
    fprintf(asmCodeOut, "pop bx\nshl bx, 1\npush bx\n\n");
}

void pushToStack(string str)
{
    fprintf(asmCodeOut, "push %s\n", str.c_str());
}

void callFunction(string str)
{
    // fprintf(asmCodeOut, "call %s_procedure\nmov %s, cx\n", str.c_str(), temp.c_str());
    fprintf(asmCodeOut, "call %s_procedure\n", str.c_str());
    pushToStackTemp("cx");
}

void setReturnValueInAsm(string return_label)
{
    fprintf(asmCodeOut, "pop cx\njmp %s\n", return_label.c_str());
}

void negateInAssembly()
{
    fprintf(asmCodeOut, "pop cx\nneg cx\n");
    pushToStackTemp("cx");
}

void notOperationOfCinAssembly(string l1, string l2)
{
    fprintf(asmCodeOut, "pop cx\ncmp cx, 0\nje %s\nmov cx, 0\njmp %s\n%s:\nmov cx, 1\n%s:\n", l1.c_str(), l2.c_str(), l1.c_str(), l2.c_str());
    pushToStackTemp("cx");
}

void mulopInAsm(string optr)
{
    if (optr == "*")
        fprintf(asmCodeOut, 
        "\
        pop ax\n\
        pop bx\n\
        mul bx\n");
    else
        fprintf(asmCodeOut,
        "\
        pop bx\n\
        pop ax\n\
        xor dx, dx\n\
        div bx\n");
    pushToStackTemp(optr == "%" ? "dx" : "ax");
}

void addopInAsm(string optr)
{
    string cmd = optr == "-" ? "sub" : "add";
    fprintf(asmCodeOut, "pop bx\npop cx\n%s cx, bx\n", cmd.c_str());
    pushToStackTemp("cx");
}

void relopInAsm(string optr, string l1, string l2)
{
    string branching = optr == "<=" ? "jle" : optr == ">=" ? "jge"
                                          : optr == ">"    ? "jg"
                                          : optr == "<"    ? "jl"
                                          : optr == "=="   ? "je"
                                          : optr == "!="   ? "jne"
                                                           : "";
    fprintf(asmCodeOut, 
        "\
        pop cx\n\
        pop bx\n\
        cmp bx, cx\n\
        %s %s\n\
        push 0\n\
        jmp %s\n\
        %s:\n\
        push 1\n\
        %s:\n",
        branching.c_str(), l1.c_str(),
        l2.c_str(),
        l1.c_str(),
        l2.c_str());
}

void logicopInAsm(string optr, string l1, string l2)
{
    string branching = optr == "&&" ? "je" : optr == "||" ? "jne" :"";
    fprintf(asmCodeOut, 
        "\
        pop bx\n\
        pop cx\n\
        cmp cx, 0\n\
        %s %s\n\
        cmp bx, 0\n\
        %s %s\n\
        push %d\n\
        jmp %s\n\
        %s:\n\
        push %d\n\
        %s:\n",
        branching.c_str(), l1.c_str(),
        branching.c_str(), l1.c_str(),
        optr == "&&",
        l2.c_str(),
        l1.c_str(),
        optr == "||",
        l2.c_str());
}

char *trimString(char *str)
{
    char *end;

    while(isspace((unsigned char)*str)) str++;

    if(*str == 0)
        return str;

    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;

    end[1] = '\0';

    return str;
}

void runOptimization(FILE* code, FILE* optimizeCode){

     char * line = NULL;
    size_t len = 0;
    ssize_t read;
    vector<string> lines, token, token1, token2;
    string intermediate;

    // fp = fopen("/etc/motd", "r");
    if (code == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, code)) != -1) {
        // printf("Retrieved line of length %zu:\n", read);
        // printf("%s\n", line);
        string s(trimString(line));
        lines.push_back(line);
        // cout << line << endl;
    }

    vector<string> prev_line, current_line;
    string output = "";
    vector<string> optimized_lines;

    for(int i = 0; i < lines.size(); i++) {
        //cout << lines[i] << '\n';
        stringstream check2(lines[i]);
        while(getline(check2, intermediate, ' ')) {
            if(intermediate[intermediate.length()-1]==',' ){
                intermediate.replace(intermediate.length()-1,1,"");
            }
            if(intermediate == " " || intermediate == "") continue;
            string s(trimString((char* )intermediate.c_str()));
            intermediate = s;
            token.push_back(intermediate);
            // cout << intermediate << endl;
        }

        current_line = token;

        // cout << "token " << token.size()  << " ";
        // for (size_t i = 0; i < token.size(); i++)
        // {
        //     cout << token[i].size() <<  " " << token[i] << " ";
        // }
        // cout << endl;
        

        if(i == 0 || token.size() <= 1 || token[0][0] == ';') {
            // prev_line = token;
            if(i == 0) {
                prev_line = token;
            }
            if(token[0][0] == ';') {
                optimized_lines.push_back( "\n" + lines[i] + "\n");
            }
            if(!(token[0][token[0].size() - 1] == ':'))  {

            token.clear();
            continue;
            }
        }


        // mov optimization
        else if(current_line[0] == "mov" && prev_line[0] == "mov") {
            if(current_line[1] == prev_line[1] && current_line[2] == prev_line[2]) {
                // will do optimize
                current_line.clear();
            }
            else if(current_line[1] == prev_line[2] && current_line[2] == prev_line[1]) {
                // will do optimize
                current_line.clear();
            }
        }
        // push pop optimization
        else if(current_line[0] == "pop" && prev_line[0] == "push") {

            
            
            if(current_line[1] == prev_line[1]) {
                // cout << "here" << endl;
                // will do optimize
                prev_line.clear();
                current_line.clear();
            }
            else  {
                if(
                    current_line[1] != prev_line[1] 
                    && 
                    (
                    current_line[1] == "ax" ||
                    current_line[1] == "bx" ||
                    current_line[1] == "cx" ||
                    current_line[1] == "dx" ||
                    prev_line[1] == "ax" ||
                    prev_line[1] == "bx" ||
                    prev_line[1] == "cx" ||
                    prev_line[1] == "dx"
                    )) {
                    // extra
                    // push ax -- pop a <=> mov a, ax
                    string rhs = prev_line[1];
                    string lhs = current_line[1];
                    prev_line.clear();
                    current_line.clear();
                    prev_line.push_back("mov");
                    prev_line.push_back(lhs);
                    prev_line.push_back(rhs);
                }
            }
        }

        // extra

        // adding zero
        else if((current_line[0] == "add" || current_line[0] == "sub") && (current_line[2] == "0")) {
            current_line.clear();
        }

        // adding one
        else if((current_line[0] == "add" || current_line[0] == "sub") && (current_line[2] == "1")) {
            string optr = current_line[0] == "add" ? "inc" : "dec";
            string operand = current_line[1];
            current_line.clear();

            current_line.push_back(optr);
            current_line.push_back(operand);
        }

        // if(current_line.size() == 0) {
        //     continue;
        // }

            // cout << "------------------" << endl;
            // for (size_t i = 0; i < prev_line.size(); i++)
            // {
            //     cout << prev_line[i] <<  " " ;
            // }
            // cout << endl;
            // for (size_t i = 0; i < current_line.size(); i++)
            // {
            //     cout << current_line[i] <<  " " ;
            // }
            // cout << endl << "------------------" << endl;
        



        

        // print prev_line
        if(prev_line.size() >= 3) {
            prev_line[prev_line.size() - 2] += ", ";
        }

        // cout << " prev line " << prev_line.size() << endl; 

        for (size_t i = 0; i < prev_line.size(); i++)
        {
            output += prev_line[i] + " ";
            // cout << prev_line[i] <<  " ";
        }

        // cout << endl;

        for (int i = 0; i < current_line.size(); i++) {
            // cout << current_line[i] << " ";
        }
        
        // cout << endl;
        // output += "\n";
        // cout << output << endl;
        // prev_line.push_back(output);

        optimized_lines.push_back(output);
        

        token.clear();

        prev_line = current_line;
        output = "";
    }


    for (size_t i = 0; i < prev_line.size(); i++)
    {
        output += prev_line[i] + " ";
    }


    // output += "\n";

    // cout << output.size() << "  " << optimized_lines.size() << endl;

    optimized_lines.push_back(output);

    for(int i = 0; i < optimized_lines.size(); i ++) {
        for(int j = 0; j < optimized_lines[i].size(); j++) 
            fprintf(optimizeCode, "%c", optimized_lines[i][j]);
        fprintf(optimizeCode, "\n");
    }

    
}

string newLabel()
{
    string lb = "L";
    lb += to_string(labelCount);
    labelCount++;
    // cout<<line_count<<" label : "<<lb<<endl;
    return lb;
}
