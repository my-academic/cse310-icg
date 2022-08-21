#include <bits/stdc++.h>

using namespace std;

// to use in stack array index
//  enum nonterminals{start, program, unit, func_declaration, func_definition, parameter_list, compound_statement, var_declaration, type_specifier,declaration_list,
//  statements, statement, expression_statement, variable, expression, logic_expression, rel_expression, simple_expression, term, unary_expression, factor, argument_list,
//  arguments};

// int yyparse(void);
// int yylex(void);
// extern FILE *yyin;
// //line and error count
// extern int line_count;
// extern int error_count;
// int syntcx_error, err_line;

// extern char* yytext;

// bool hasReturnStatement = false;

// //log and error file
// ofstream logfile, errorfile;
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


// asm code for println function
//  ifstream ifs("printlnASM.txt");
//  string println_code( (std::istreambuf_iterator<char>(ifs) ),(std::istreambuf_iterator<char>()    ) );

// storing variable data type
//  string datatype;
//  string tempVar;
//  bool tempSet=false;

// for function parameters
//  vector<symbol_info*> parameters;
//  vector<string> paramTypeList;
//  symbol_info *current_function=NULL;

// //symbol table declaration
// int total_buckets=31;
// SymbolTable *symboltable = new SymbolTable(total_buckets);

// //asm code file
// ofstream codefile;
// ofstream optimizedCode;

// //asm code stack
// stack<string> asmCodeStack[arguments+1];

// string data_asmcode,code_asmcode;
// string func_asmcode="";
// string asm_newline="\n;printing new line\nmov ah,2\nmov dl,10\nint 21h\nmov dl,13\nint 21h\n\n";

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
        fprintf(asmCodeOut, "main proc\npush bp\nmov bp, sp\nmov cx, @data\nmov ds,cx\n\n");
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

// void addCodeForConst(string var_name, string value)
// {
//     fprintf(asmCodeOut, "mov %s, %s\n\n", var_name.c_str(), value.c_str());
// }

void addArrayIndexInAsm()
{
    fprintf(asmCodeOut, "pop bx\nshl bx, 1\npush bx\n\n");
}

// void addCodeForArrayAssignment(string lhs, string idx, string rhs)
// {
//     // fprintf()
//     fprintf(asmCodeOut, "pop cx\npop bx\nmov %s[bx], cx\n\n", lhs.c_str());
//     pushToStackTemp("cx");
// }

// void addCodeForVariableAssignment(string lhs, string rhs)
// {
//     fprintf(asmCodeOut, "pop cx\nmov %s, cx\n\n", lhs.c_str());
//     pushToStackTemp("cx");
// }

// void addCodeForInDeOP(string op, string temp, string variable, string idx = "")
// {
//     // if (idx != "")
//     //     fprintf(asmCodeOut, "mov cx, %s\nmov %s, cx\nmov bx, %s\n%s %s[bx]\n\n", variable.c_str(), temp.c_str(), idx.c_str(), op.c_str(), variable.c_str());
//     // else
//     //     fprintf(asmCodeOut, "mov cx, %s\nmov %s, cx\n%s %s\n\n", variable.c_str(), temp.c_str(), op.c_str(), variable.c_str());
//     if (idx != "")
//         fprintf(asmCodeOut, "pop bx\npush %s[bx]\n%s %s[bx]\n\n",  idx.c_str(),  variable.c_str(), op.c_str(), variable.c_str());
//     else
//         fprintf(asmCodeOut, "push %s\n%s %s\n\n", variable.c_str(), op.c_str(), variable.c_str());
// }

// void bufferingVariable(string temp_var_name, string var_name, string idx = "")
// {
//     if (idx == "")
//         fprintf(asmCodeOut, "mov cx, %s\nmov %s, cx\n\n", var_name.c_str(), temp_var_name.c_str());
//     else
//         fprintf(asmCodeOut, "mov bx, %s\nmov cx, %s[bx]\nmov %s, cx\n\n", idx.c_str(), var_name.c_str(), temp_var_name.c_str());
// }

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
    // if (optr == "+")
    //     fprintf(asmCodeOut, "mov cx, %s\nadd %s, cx\n", rt.c_str(), lt.c_str());
    // else if (optr == "-")
    //     fprintf(asmCodeOut, "mov cx, %s\nsub %s, cx\n", rt.c_str(), lt.c_str());
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
        string s(line);
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
            if(intermediate[intermediate.length()-1]==','){
                intermediate.replace(intermediate.length()-1,1,"");
            }
            if(intermediate == " " || intermediate == "") {

            }
            else 
                token.push_back(intermediate);
            // cout << intermediate << endl;
        }

        current_line = token;

        if(i == 0 || token.size() == 0 || token[0][0] == ';') {
            // prev_line = token;
            if(i == 0) {
                prev_line = token;
            }
            token.clear();
            continue;
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
                // will do optimize
                prev_line.clear();
                current_line.clear();
            }
        }

        // extra
        // push
        else if(current_line[0] == "pop" && prev_line[0] == "push"){
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

        // adding zero
        else if((current_line[0] == "add" || current_line[0] == "sub") && (current_line[2] == "0")) {
            current_line.clear();
        }

        

        // print prev_line
        if(prev_line.size() >= 3) {
            prev_line[prev_line.size() - 2] += ", ";
        }

        cout << " prev line " << prev_line.size() << endl; 

        for (size_t i = 0; i < prev_line.size(); i++)
        {
            output += prev_line[i] + " ";
            // cout << prev_line[i] <<  " ";
        }

        cout << endl;

        for (int i = 0; i < current_line.size(); i++) {
            // cout << current_line[i] << " ";
        }
        
        cout << endl;
        output += "\n";
        // cout << output << endl;
        // prev_line.push_back(output);

        optimized_lines.push_back(output);
        

        

        token.clear();

        


        prev_line = current_line;
        cout << i <<  " " << lines.size() << " " << output.size() << endl;
        output = "";
    }

    for (size_t i = 0; i < prev_line.size(); i++)
    {
        output += prev_line[i] + " ";
    }

    output += "\n";

    cout << output.size() << "  " << optimized_lines.size() << endl;

    for(int i = 0; i < optimized_lines.size(); i ++) {
        for(int j = 0; j < optimized_lines[i].size(); j++) 
            fprintf(optimizeCode, "%c", optimized_lines[i][j]);
    }

    // do {
    //     ch = fgetc(asmCodeOut);

	// 	if(ch == EOF) break;
    //     fprintf(wholeasm, "%c", ch);
 
    //     // Checking if character is not EOF.
    //     // If it is EOF stop eading.
    // } while (ch != EOF);
    


        // mov optimization
        // else if(current_line[0] == "mov" && prev_line[0] == "mov") {
        //     if(current_line[1] == prev_line[1] && current_line[2] == prev_line[2]) {
        //         // will do optimize
        //         current_line.clear();
        //     }
        //     else if(current_line[1] == prev_line[2] && current_line[2] == prev_line[1]) {
        //         // will do optimize
        //         current_line.clear();
        //     }
        // }
        // // push optimization
        // else if(current_line[0] == "push" && prev_line[0] == "pop") {
        //     if(current_line[1] == prev_line[1]) {
        //         // will do optimize
        //         current_line.clear();
        //     }
        // }

    //     // extra
    //     // push
    //     else if(current_line[0] == "push" && prev_line == "pop"){
    //         if(current_line[1] != prev_line[1]) {
    //             // prev
    //         }
    //     }

        // if(token1.size()==0){
        // token1 = token;
        // token.clear();
        // }
        // else if(token2.size()==0){
        // token2 = token;
        // token.clear();
        // }
        // else{
        // token1.clear();
        // token1 = token2;
        // token2.clear();
        // token2 = token;
        // token.clear();
        // }


        // for(int i = 0; i < token1.size(); i++){
        //     cout << token1[i] << " ";
        // }

        // cout << endl;

        // for(int i = 0; i < token2.size(); i++){
        //     cout << token2[i] << " ";
        // }

        // cout << endl;

        //optimization for mov
        // if(token1.size()==token2.size() && token1.size()==3){
        //cout<<token1.size()<<endl;
        // for(int j=0;j<token2.size();j++){
        //   cout<<"first : "<<token1[j]<<" \tsecond line : "<<token2[j]<<"\n";
        // }
        // if(token1[0]=="mov" && token2[0]=="mov"){
        //     if(token1[2]==token2[1] && token1[1] == token2[2]){
        //     cout<<lines[i]<<" is redundant.\n";
        //     lines[i]=";"+lines[i]+"    is removed for optimization";
        //     }
        // }
        // }

        // finalOutput += lines[i]+"\n";
    // }

    // string finalOutput="";
    // vector<string> lines;
    // vector <string> token1, token2, token;
    

    // // stringstream class check1
    // stringstream check1(inputCode);

    // string intermediate;

    // // Tokenizing w.r.t. space '\n'
    // while(getline(check1, intermediate, '\n')) {lines.push_back(intermediate);}

    // for(int i = 0; i < lines.size(); i++){
    //     //cout << lines[i] << '\n';
    //     stringstream check2(lines[i]);
    //     while(getline(check2, intermediate, ' ')) {
    //     if(intermediate[intermediate.length()-1]==','){
    //         intermediate.replace(intermediate.length()-1,1,"");
    //     }
    //     token.push_back(intermediate);
    //     }

    //     if(token1.size()==0){
    //     token1 = token;
    //     token.clear();
    //     }
    //     else if(token2.size()==0){
    //     token2 = token;
    //     token.clear();
    //     }
    //     else{
    //     token1.clear();
    //     token1 = token2;
    //     token2.clear();
    //     token2 = token;
    //     token.clear();
    //     }

    //     //optimization for mov
    //     if(token1.size()==token2.size() && token1.size()==3){
    //     //cout<<token1.size()<<endl;
    //     // for(int j=0;j<token2.size();j++){
    //     //   cout<<"first : "<<token1[j]<<" \tsecond line : "<<token2[j]<<"\n";
    //     // }
    //     if(token1[0]=="mov" && token2[0]=="mov"){
    //         if(token1[2]==token2[1] && token1[1] == token2[2]){
    //         cout<<lines[i]<<" is redundant.\n";
    //         lines[i]=";"+lines[i]+"    is removed for optimization";
    //         }
    //     }
    //     }

    //     finalOutput += lines[i]+"\n";
    // }
    // return finalOutput;
}

// void printInAsm(string str){
//     fprintf(asmCodeOut, "mov cx, %s\ncall print_number\n", str.c_str());
// }


// void saveASMinStack(nonterminals nt, string str){
//   //cout<<nt<<": saving \n
// "<<str<<endl;
    //   asmCodeStack[nt].push(str);
    // }

    // string getASMfromStack(nonterminals nt){
    //   if(!asmCodeStack[nt].empty()){
    //     string str =  asmCodeStack[nt].top();
    //     asmCodeStack[nt].pop();
    //     //cout<<nt<<": getting \n"<<str<<endl;
    //     return str;
    //   }
    //   return "";
    // }

    // void handle_data(string temp, bool vartype=true,string type="VARIABLE", string arrSize=""){
    //   string t;
    //   if(type=="VARIABLE"){
    //     temp = !vartype ? temp : temp+to_string(symboltable->countTables);
    //     t= temp + " DW  0\n\t\t";
    //   }
    //   else if(type=="ARRAY"){
    //     temp = !vartype ? temp : temp+to_string(symboltable->countTables);
    //     t = temp + " DW "+arrSize+" DUP(0)\n\t\t";
    //   }
    //   else{
    //     cout<<"handle_data function: check here\n";
    //   }
    //   tempVar=temp;
    //   tempSet=true;
    //   data_asmcode+=t;
    // }

    

    // void WriteOptimized_code(){
    //   string model= ".model small\n";
    //   string stack = "\n.stack 100h\n";
    //   string datapart = "\n.data \n\n\t\t"+data_asmcode+"\n";
    //   string codepart = "\n.code\n\nmain proc \nmov cx,@data\nmov ds,cx\n\n"+codeOptimization(code_asmcode)+"\n";
    //   optimizedCode<<model+stack+datapart+codepart+"\n\nMOV AH, 4CH\nINT 21H\nmain ENDP\n\n";
    //   optimizedCode<<codeOptimization(func_asmcode);
    //   optimizedCode<<println_code;
    //   optimizedCode<<"\n\nEND MAIN\n";
    // }

    // void initialASMcode(){
    //   string model= ".model small\n";
    //   string stack = "\n.stack 100h\n";
    //   string datapart = "\n.data \n\n\t\t"+data_asmcode+"\n";
    //   string codepart = "\n.code\n\nmain proc \nmov cx,@data\nmov ds,cx\n\n"+code_asmcode+"\n";
    //   codefile<<model+stack+datapart+codepart+"\n\nMOV AH, 4CH\nINT 21H\nmain ENDP\n\n";
    //   codefile<<func_asmcode;
    //   codefile<<println_code;
    //   codefile<<"\n\nEND MAIN\n";

    //   WriteOptimized_code();
    // }

    string
    newLabel()
{
    string lb = "L";
    lb += to_string(labelCount);
    labelCount++;
    // cout<<line_count<<" label : "<<lb<<endl;
    return lb;
}

string newTemp()
{
    string t = "t";
    t += to_string(tempCount);
    tempCount++;
    addDataInAssembly(t, "");

    return t;
}

// void printDetails_func(symbol_info *func1) {
//   if(func1!=NULL){
//     cout<<"size : "<<func1->ids.size()<<endl;
//     for(int i=func1->ids.size()-1;i>=0;i--){
//       cout<<"name : "<<func1->ids[i]<<"  temp : "<<func1->tempids[i]<<endl;
//     }
//   }
// }

// string handle_asm_function_code(string code, symbol_info* func){
//   //printDetails_func(func);
//   string temp;
//   temp = "\n\n"+func->getName()+"_procedure PROC\n\n";

//   temp += "PUSH BP\nMOV BP, SP\n";

//   // for(int i=0;i<func->tempids.size();i++){
//   //   //cout<<"name : "<<func->ids[i]<<"  temp : "<<func->tempids[i]<<endl;
//   //   temp += "PUSH "+ func->tempids[i]+"\n";
//   // }

//   for(int i=func->tempids.size()-1, j=0;i>=0;i--,j++){
//     //cout<<"name : "<<func->ids[i]<<"  temp : "<<func->tempids[i]<<endl;
//     temp += "mov cx, [BP+"+to_string(j*2+4)+"]\n";
//     temp += "mov "+func->tempids[i]+", cx\n";
//   }
//   temp += code;
//   if(!hasReturnStatement){
//     temp += "\nPOP BP\n";
//     temp += "RET\n";
//   }
//   temp += "\n"+func->getName()+"_procedure ENDP\n\n";
//   func_asmcode += temp;
//   return "";
// }

// string handle_logicop_code(symbol_info *exp1, symbol_info *op, symbol_info *exp2){
//   string codeTemp="";
//   string temp = newTemp();
//   string label1 =newLabel();
//   string label2 = newLabel();

//   //cout<<line_count<<" logicop : "<<exp1->getTempSymbol()<<"  "<<exp2->getTempSymbol()<<endl;
//   if(op->getName()=="&&"){
//     codeTemp += "mov cx, "+ exp1->getTempSymbol() +"\n";
//     codeTemp +="cmp   cx, 1\n";
//     codeTemp += "jnge  "+label1+"\n";
//     codeTemp += "mov cx, "+ exp2->getTempSymbol() +"\n";
//     codeTemp += "cmp  cx, 1\n";
//     codeTemp += "jnge  "+label1+"\n";
//     codeTemp += "mov  "+temp+", 1\n";
//     codeTemp += "jmp  "+label2+"\n";
//     codeTemp += label1+":\n"+"\tmov  "+temp+", 0\n";
//     codeTemp += label2+":\n";
//   }

//   else if(op->getName()=="||"){
//     codeTemp += "mov cx, "+ exp1->getTempSymbol() +"\n";
//     codeTemp += "cmp  cx, 1\n";
//     codeTemp += "jge  " + label2 + "\n";
//     codeTemp += "mov cx, "+ exp2->getTempSymbol() +"\n";
//     codeTemp += "cmp  cx, 1\n";
//     codeTemp += "jge  " + label2 + "\n";
//     codeTemp += "mov  "+temp+", 0\n";
//     codeTemp += "jmp  " + label1+"\n";
//     codeTemp += label2+":\n\t"+"mov  "+temp+", 1\n";
//     codeTemp += label1 +":\n\t";
//   }

//   tempVar = temp;
//   tempSet = true;

//   //cout<<codeTemp;
//   return codeTemp;
// }

// string handle_relop_code(symbol_info *exp1, symbol_info *op, symbol_info *exp2){
//   string codeTemp;
//   //cout<<line_count<<" relop :"<<exp1->getTempSymbol()<<"  "<<exp2->getTempSymbol()<<endl;
//   codeTemp += "mov cx, " + exp1->getTempSymbol()+"\n";
//   codeTemp += "cmp cx, " + exp2->getTempSymbol()+"\n";

//   string temp=newTemp();
//   string label1=newLabel();
//   string label2=newLabel();

//   if(op->getName()=="<"){
//     codeTemp += "jl  " + label1+"\n";
//   }
//   else if(op->getName()=="<="){
//     codeTemp += "jle  " + label1+"\n";
//   }
//   else if(op->getName()==">"){
//     codeTemp += "jg  " + label1+"\n";
//   }
//   else if(op->getName()==">="){
//     codeTemp += "jge  " + label1+"\n";
//   }
//   else if(op->getName()=="=="){
//     codeTemp += "je " + label1+"\n";
//   }
//   else{ // !=
//     codeTemp += "jne " + label1+"\n";
//   }

//   codeTemp+="mov  "+temp +", 0\n";
//   codeTemp+="jmp  "+ label2 +"\n";
//   codeTemp+= label1 +":\nmov "+ temp+", 1\n";
//   codeTemp+= label2+":\n";

//   tempVar = temp;
//   tempSet = true;

//   return codeTemp;
// }

// string handle_addop_code(symbol_info *exp1, symbol_info *op, symbol_info *exp2){
//   string codeTemp;
//   string temp = newTemp();
//   //cout<<line_count<<" addop : "<<exp1->getTempSymbol()<<"  "<<exp2->getTempSymbol()<<endl;
//   codeTemp = "mov cx, "+exp1->getTempSymbol()+"\n";
//   if(op->getName()=="+"){
//     codeTemp += "add cx, "+exp2->getTempSymbol()+"\n";
//   }
//   else if(op->getName()=="-"){
//     codeTemp += "sub cx, "+exp2->getTempSymbol()+"\n";
//   }
//   codeTemp += "mov "+temp+", cx\n";

//   tempVar = temp;
//   tempSet = true;

//   return codeTemp;
// }

// string handle_mulop_code(symbol_info *exp1, symbol_info *op, symbol_info *exp2){
//   string codeTemp;

//   //cout<<line_count<<" mulop: "<<exp1->getTempSymbol()<<"  "<<exp2->getTempSymbol()<<endl;
//   codeTemp += "mov cx, "+ exp1->getTempSymbol()+"\n";
//   codeTemp += "mov bx, "+ exp2->getTempSymbol() +"\n";

//   string temp=newTemp();

//   if(op->getName()=="*"){
//     codeTemp += "mul bx\n";
//     codeTemp += "mov "+ temp + ", cx\n";
//   }
//   else if(op->getName()=="/"){
//     // clear dx, perform 'div bx' and mov cx to temp
//     codeTemp += "xor dx, dx\n";
//     codeTemp += "div bx\n";
//     codeTemp += "mov "+ temp + ", cx\n";
//   }
//   else{
//     // clear dx, perform 'div bx' and mov dx to temp
//     codeTemp += "xor dx, dx\n";
//     codeTemp += "div bx\n";
//     codeTemp += "mov "+ temp + ", dx\n";
//   }

//   tempVar = temp;
//   tempSet = true;

//   return codeTemp;
// }

// string handle_minus_exp_code(symbol_info *exp){
//   string codeTemp;
//   string temp = newTemp();

//   codeTemp += "mov cx, "+exp->getTempSymbol()+"\n";
//   codeTemp += "neg cx\n";
//   codeTemp += "mov "+temp + ", cx\n";

//   tempVar = temp;
//   tempSet = true;

//   return codeTemp;
// }
