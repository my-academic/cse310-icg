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
// int syntax_error, err_line;

// extern char* yytext;

// bool hasReturnStatement = false;

// //log and error file
// ofstream logfile, errorfile;
FILE *asmDataOut, *asmCodeOut;

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
    fprintf(asmCodeOut, "\n;%s\n", str.c_str());
}

void initiateAssembly()
{

    //   string model= ".model small\n";
    //   string stack = "\n.stack 100h\n";
    fprintf(asmDataOut, ".model small\n.stack 100h\n.data\n");
    fprintf(asmCodeOut, "\n.code\n\n");
}

void addDataInAssembly(string name, string scope_id, bool is_array = false, int size_of_array = 0)
{
    if (!is_array)
        fprintf(asmDataOut, "%s%s DW 0\n", name.c_str(), scope_id.c_str());
    else
        fprintf(asmDataOut, "%s%s DW %d DUP(0)\n", name.c_str(), scope_id.c_str(), size_of_array);
}

void addFuncDefinitionInAsm(string name, int param_count)
{

    if (name == "main")
        fprintf(asmCodeOut, "main proc\nmov ax, @data\nmov ds,ax\n\n");
    else
        fprintf(asmCodeOut, "%s_procedure proc\npush bp\nmov bp, sp\n\n", name.c_str());
}

void addFunctionEndStatementInAsm(string name, int param_count)
{
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
}

void addCodeForConst(string var_name, string value)
{
    fprintf(asmCodeOut, "mov ax, %s\nmov %s, ax\n\n", value.c_str(), var_name.c_str());
}

void addArrayIndexInAsm(string var_name, string temp_idx)
{
    fprintf(asmCodeOut, "mov bx, %s\nshl bx, 1\nmov %s, bx\n\n", var_name.c_str(), temp_idx.c_str());
}

void addCodeForArrayAssignment(string lhs, string idx, string rhs)
{
    fprintf(asmCodeOut, "mov ax, %s \nmov bx, %s\nmov %s[bx], ax\n\n", rhs.c_str(), idx.c_str(), lhs.c_str());
}

void addCodeForVariableAssignment(string lhs, string rhs)
{
    fprintf(asmCodeOut, "mov ax, %s \nmov %s, ax\n\n", rhs.c_str(), lhs.c_str());
}

void addCodeForInDeOP(string op, string variable, string idx = "")
{
    if (idx != "")
        fprintf(asmCodeOut, "mov bx, %s\n%s %s[bx]\n\n", idx.c_str(), op.c_str(), variable.c_str());
    else
        fprintf(asmCodeOut, "%s %s\n\n", op.c_str(), variable.c_str());
}

void bufferingVariable(string temp_var_name, string var_name, string idx = "")
{
    if (idx == "")
        fprintf(asmCodeOut, "mov ax, %s\nmov %s, ax\n\n", var_name.c_str(), temp_var_name.c_str());
    else 
        fprintf(asmCodeOut, "mov bx, %s\nmov ax, %s[bx]\nmov %s, ax\n\n", idx.c_str(), var_name.c_str(), temp_var_name.c_str());
}

void pushToStack(string str){
    fprintf(asmCodeOut, "push %s\n", str.c_str());
}

void callFunction(string str) {
    fprintf(asmCodeOut, "call %s_procedure\n", str.c_str());
}

void setReturnValueInAsm(string str) {
    fprintf(asmCodeOut, "mov ax, %s\n\n", str.c_str());
}
// void saveASMinStack(nonterminals nt, string str){
//   //cout<<nt<<": saving \n"<<str<<endl;
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

// string codeOptimization(string inputCode){
//   string finalOutput="";
//   vector<string> lines;
//   vector <string> token1, token2, token;

//   // stringstream class check1
//   stringstream check1(inputCode);

//   string intermediate;

//   // Tokenizing w.r.t. space '\n'
//   while(getline(check1, intermediate, '\n')) {lines.push_back(intermediate);}

//   for(int i = 0; i < lines.size(); i++){
//       //cout << lines[i] << '\n';
//       stringstream check2(lines[i]);
//       while(getline(check2, intermediate, ' ')) {
//         if(intermediate[intermediate.length()-1]==','){
//           intermediate.replace(intermediate.length()-1,1,"");
//         }
//         token.push_back(intermediate);
//       }

//       if(token1.size()==0){
//         token1 = token;
//         token.clear();
//       }
//       else if(token2.size()==0){
//         token2 = token;
//         token.clear();
//       }
//       else{
//         token1.clear();
//         token1 = token2;
//         token2.clear();
//         token2 = token;
//         token.clear();
//       }

//       //optimization for mov
//       if(token1.size()==token2.size() && token1.size()==3){
//         //cout<<token1.size()<<endl;
//         // for(int j=0;j<token2.size();j++){
//         //   cout<<"first : "<<token1[j]<<" \tsecond line : "<<token2[j]<<"\n";
//         // }
//         if(token1[0]=="mov" && token2[0]=="mov"){
//           if(token1[2]==token2[1] && token1[1] == token2[2]){
//             cout<<lines[i]<<" is redundant.\n";
//             lines[i]=";"+lines[i]+"    is removed for optimization";
//           }
//         }
//       }

//       finalOutput += lines[i]+"\n";
//   }
//   return finalOutput;
// }

// void WriteOptimized_code(){
//   string model= ".model small\n";
//   string stack = "\n.stack 100h\n";
//   string datapart = "\n.data \n\n\t\t"+data_asmcode+"\n";
//   string codepart = "\n.code\n\nmain proc \nmov ax,@data\nmov ds,ax\n\n"+codeOptimization(code_asmcode)+"\n";
//   optimizedCode<<model+stack+datapart+codepart+"\n\nMOV AH, 4CH\nINT 21H\nmain ENDP\n\n";
//   optimizedCode<<codeOptimization(func_asmcode);
//   optimizedCode<<println_code;
//   optimizedCode<<"\n\nEND MAIN\n";
// }

// void initialASMcode(){
//   string model= ".model small\n";
//   string stack = "\n.stack 100h\n";
//   string datapart = "\n.data \n\n\t\t"+data_asmcode+"\n";
//   string codepart = "\n.code\n\nmain proc \nmov ax,@data\nmov ds,ax\n\n"+code_asmcode+"\n";
//   codefile<<model+stack+datapart+codepart+"\n\nMOV AH, 4CH\nINT 21H\nmain ENDP\n\n";
//   codefile<<func_asmcode;
//   codefile<<println_code;
//   codefile<<"\n\nEND MAIN\n";

//   WriteOptimized_code();
// }

string newLabel()
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
//     temp += "mov ax, [BP+"+to_string(j*2+4)+"]\n";
//     temp += "mov "+func->tempids[i]+", ax\n";
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
//     codeTemp += "mov ax, "+ exp1->getTempSymbol() +"\n";
//     codeTemp +="cmp   ax, 1\n";
//     codeTemp += "jnge  "+label1+"\n";
//     codeTemp += "mov ax, "+ exp2->getTempSymbol() +"\n";
//     codeTemp += "cmp  ax, 1\n";
//     codeTemp += "jnge  "+label1+"\n";
//     codeTemp += "mov  "+temp+", 1\n";
//     codeTemp += "jmp  "+label2+"\n";
//     codeTemp += label1+":\n"+"\tmov  "+temp+", 0\n";
//     codeTemp += label2+":\n";
//   }

//   else if(op->getName()=="||"){
//     codeTemp += "mov ax, "+ exp1->getTempSymbol() +"\n";
//     codeTemp += "cmp  ax, 1\n";
//     codeTemp += "jge  " + label2 + "\n";
//     codeTemp += "mov ax, "+ exp2->getTempSymbol() +"\n";
//     codeTemp += "cmp  ax, 1\n";
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
//   codeTemp += "mov ax, " + exp1->getTempSymbol()+"\n";
//   codeTemp += "cmp ax, " + exp2->getTempSymbol()+"\n";

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
//   codeTemp = "mov ax, "+exp1->getTempSymbol()+"\n";
//   if(op->getName()=="+"){
//     codeTemp += "add ax, "+exp2->getTempSymbol()+"\n";
//   }
//   else if(op->getName()=="-"){
//     codeTemp += "sub ax, "+exp2->getTempSymbol()+"\n";
//   }
//   codeTemp += "mov "+temp+", ax\n";

//   tempVar = temp;
//   tempSet = true;

//   return codeTemp;
// }

// string handle_mulop_code(symbol_info *exp1, symbol_info *op, symbol_info *exp2){
//   string codeTemp;

//   //cout<<line_count<<" mulop: "<<exp1->getTempSymbol()<<"  "<<exp2->getTempSymbol()<<endl;
//   codeTemp += "mov ax, "+ exp1->getTempSymbol()+"\n";
//   codeTemp += "mov bx, "+ exp2->getTempSymbol() +"\n";

//   string temp=newTemp();

//   if(op->getName()=="*"){
//     codeTemp += "mul bx\n";
//     codeTemp += "mov "+ temp + ", ax\n";
//   }
//   else if(op->getName()=="/"){
//     // clear dx, perform 'div bx' and mov ax to temp
//     codeTemp += "xor dx, dx\n";
//     codeTemp += "div bx\n";
//     codeTemp += "mov "+ temp + ", ax\n";
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

//   codeTemp += "mov ax, "+exp->getTempSymbol()+"\n";
//   codeTemp += "neg ax\n";
//   codeTemp += "mov "+temp + ", ax\n";

//   tempVar = temp;
//   tempSet = true;

//   return codeTemp;
// }
