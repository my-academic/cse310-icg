#include <bits/stdc++.h>
using namespace std;

// line and error count
extern int line_count;
extern int lexical_error_count;
int syntax_error_count = 0;

extern char *yytext;

// log and error file
FILE *logout, *errorout;
string integer = "int";
string fraction = "float";
string _void = "void";
string intermediate = "intermediate";

// storing variable data type
vector<symbol_info *> variables;

// for function parameters
string return_type;
vector<symbol_info *> parameters;
int count_of_parameters_without_name = 0;
bool isFunctionStarted = true;
vector<symbol_info *> args;

symbol_info *current_function = nullptr;

// vector<string> paramTypeList;
// symbol_info *current_function=NULL;

int bucket_size = 31;
symbol_table *symbolTable = new symbol_table(bucket_size);

// string keywordArray[] = {"IF", "ELSE", "FOR", "WHILE", "INT", "FLOAT", "VOID", "RETURN", "PRINTLN"};
// set<string> keywords(keywordArray, keywordArray + 9);

enum non_terminals
{
  start,
  program,
  unit,
  func_declaration,
  func_definition,
  parameter_list,
  compound_statement,
  var_declaration,
  type_specifier,
  declaration_list,
  statements,
  statement,
  expression_statement,
  variable,
  expression,
  logic_expression,
  rel_expression,
  simple_expression,
  term,
  unary_expression,
  factor,
  argument_list,
  arguments
};

vector<stack<string>> non_terminals_stack(50);

bool isArray(symbol_info *lhs)
{
  return lhs->getName().find('[') != std::string::npos;
}

void printCompatibilityRelatedThings(symbol_info *s)
{
  if (s == nullptr)
    return;
  cout << s->getName() << ", id_type: " << s->id_type << ", variable_type: " << s->variable_type << ", array_type: " << s->array_type << ", return_type: " << s->return_type << endl
       << endl;
  ;
}

void setCompatibleRelatedThings(symbol_info *s1, symbol_info *s2)
{
  s1->id_type = s2->id_type;
  s1->variable_type = s2->variable_type;
  s1->array_type = s2->array_type;
}

bool checkCompatibility(symbol_info *s1, symbol_info *s2)
{
  return s1->variable_type == s2->variable_type;
}

void yyerror(char *s)
{
  return;
}

void printLog(string str1, string str2, string str3)
{
  // printf("Line %d: %s : %s\n%s\n", line_count, str1.c_str(), str2.c_str(), str3.c_str());
  fprintf(logout, "Line %d: %s : %s\n\n%s\n\n", line_count, str1.c_str(), str2.c_str(), str3.c_str());
}

void printError(string str1)
{
  // printf("Error at line %d: %s\n", line_count, str1.c_str());
  fprintf(errorout, "Error at line %d: %s\n\n", line_count, str1.c_str());
  fprintf(logout, "Error at line %d: %s\n\n", line_count, str1.c_str());
  syntax_error_count++;
}

void stackPush(non_terminals nt, string str)
{
  non_terminals_stack[nt].push(str);
}

bool checkNull(symbol_info *s1, symbol_info *s2)
{
  return s1 == nullptr || s2 == nullptr;
}

bool checkArray(symbol_info *s1, symbol_info *s2, string str)
{
  if (s1->id_type == ARRAY || s2->id_type == ARRAY)
  {
    printError("type ARRAY can not be an operand of " + str);
    return true;
  }
  return false;
}

bool checkVoid(symbol_info *s1, symbol_info *s2, string str)
{
  if (s1->variable_type == _void || s2->variable_type == _void)
  {
    printError("Void used in expression");
    return true;
  }
  return false;
}

bool checkFunction(symbol_info *s1, symbol_info *s2, string str)
{
  if (s1->id_type == FUNCTION || s2->id_type == FUNCTION)
  {
    printError("type FUNCTION can not be an operand of " + str);
    return true;
  }
  return false;
}

bool checkNull(symbol_info *s1)
{
  return s1 == nullptr;
}

bool checkArray(symbol_info *s1, string str)
{
  if (s1->id_type == ARRAY)
  {
    printError("type ARRAY can not be an operand of " + str);
    return true;
  }
  return false;
}

bool checkVoid(symbol_info *s1, string str)
{
  if (s1->variable_type == _void)
  {
    printError("Void used in expression");
    return true;
  }
  return false;
}

bool checkFunction(symbol_info *s1, string str)
{
  if (s1->id_type == FUNCTION)
  {
    printError("type FUNCTION can not be an operand of " + str);
    return true;
  }
  return false;
}

bool checkNullFunctionArrayVoid(symbol_info *symbolInfo, string optr)
{
  return checkNull(symbolInfo) || checkFunction(symbolInfo, optr) || checkArray(symbolInfo, optr) || checkVoid(symbolInfo, optr);
}

bool checkNullFunctionArrayVoid(symbol_info *s1, symbol_info *s2, string optr)
{
  return checkNull(s1, s2) || checkFunction(s1, s2, optr) || checkArray(s1, s2, optr) || checkVoid(s1, s2, optr);
}

pair<symbol_info *, string> findSymbol(symbol_info *symbolInfo)
{
  return symbolTable->lookup(symbolInfo->getName());
}

symbol_info *findVariable(symbol_info *symbolInfo)
{
  pair<symbol_info *, string> p1 = findSymbol(symbolInfo);
  symbol_info *s = p1.first;
  if (s == nullptr)
  {
    printError("Undeclared variable " + symbolInfo->getName());
    return s;
  }
  int i, size = current_function->sequence_of_parameters.size();
  for (i = 0; i < size; i++)
  {
    symbol_info *si = current_function->sequence_of_parameters[i];
    if (si->getName() == s->getName())
    {
      s = si;
      break;
    }
  }
  if (i < size)
  {
    s->temp_id = "[bp+" + to_string((size - 1 - i) * 2 + 4) + "]";
  }
  else
    s->temp_id = s->getName() + p1.second;
  return s;
}

string stackPop(non_terminals nt)
{
  string str = non_terminals_stack[nt].top();
  non_terminals_stack[nt].pop();
  return str;
}

void setVariableAndArrayRelatedValues(symbol_info *symbolInfo, string type, symbol_info *s)
{
  symbolInfo->id_type = s->id_type;
  symbolInfo->variable_type = type;
  symbolInfo->array_type = type;
}

void insertDeclarationListRecord(symbol_info *symbolInfo, bool is_array = false, int size_of_array = 0)
{
  if (is_array)
  {
    if (size_of_array <= 0)
      printError("array size can not be less than 1");
    symbolInfo->id_type = ARRAY;
  }
  else
  {
    symbolInfo->id_type = VARIABLE;
  }
  variables.push_back(symbolInfo);
  addDataInAssembly(symbolInfo->getName(), symbolTable->getCurrentScopeId(), is_array, size_of_array);
}

void setVariableAndArrayValues(string type)
{
  if (type == _void)
  {
    printError("Variable type cannot be void");
  }
  for (int i = 0; i < variables.size(); i++)
  {
    symbol_info *s = symbolTable->lookupCurrentScope(variables[i]->getName());
    if (s == nullptr)
    {
      symbolTable->insert(variables[i]->getName(), variables[i]->getType());
      s = symbolTable->lookup(variables[i]->getName()).first;
      setVariableAndArrayRelatedValues(s, type, variables[i]);
    }
    else
    {
      printError("Multiple declaration of " + s->getName());
    }
  }

  variables.clear();
}

void insertIntoParameters(symbol_info *symbolInfo, string type)
{
  symbolInfo->id_type = VARIABLE;
  symbolInfo->variable_type = type;
  symbolInfo->array_type = type;
  parameters.push_back(symbolInfo);
}

void setFunctionParameters()
{
  if (current_function == nullptr)
    return;
  for (int i = 0; !current_function->is_parameters_inserted && i < parameters.size(); i++)
  {
    current_function->sequence_of_parameters.push_back(parameters[i]);
  }
  current_function->is_parameters_inserted = true;
  for (int i = 0; i < parameters.size(); i++)
  {
    current_function->sequence_of_parameters[i]->setName(parameters[i]->getName());
  }
}

void checkFunctionParameters(string return_type, symbol_info *symbolInfo, bool is_defined)
{
  symbol_info *s = symbolTable->lookup(symbolInfo->getName()).first;
  set<string> params;
  for (int i = 0; i < parameters.size(); i++)
  {
    if (params.count(parameters[i]->getName()))
      printError("Multiple declaration of " + parameters[i]->getName() + " in parameter");
    params.insert(parameters[i]->getName());
  }

  s->id_type = FUNCTION;
  s->return_type = return_type;
  s->is_defined = is_defined;
  current_function = s;
}

void setAndClearFunctionThings()
{
  setFunctionParameters();
  parameters.clear();
  current_function = nullptr;
}

void checkParametersCompatibilityWithDeclaration(symbol_info *symbolInfo)
{
  if (parameters.size() != symbolInfo->sequence_of_parameters.size())
    printError("Total number of arguments mismatch with declaration in function " + symbolInfo->getName());
  for (int i = 0; i < parameters.size(); i++)
  {
    if (parameters[i]->variable_type != symbolInfo->sequence_of_parameters[i]->variable_type)
      printError("Type mismatch with declaration in function " + symbolInfo->getName());
  }
}

void setFunctionValues(string return_type, symbol_info *symbolInfo, bool is_defined)
{
  symbol_info *s = symbolTable->lookup(symbolInfo->getName()).first;
  if (s == nullptr)
  {
    symbolTable->insert(symbolInfo->getName(), symbolInfo->getType());
    checkFunctionParameters(return_type, symbolInfo, is_defined);
  }
  else if (s->id_type != FUNCTION)
  {
    printError("Multiple declaration of " + s->getName());
  }
  else if (!s->is_defined && is_defined)
  {
    if (s->return_type != return_type)
      printError("Return type mismatch with function declaration in function " + s->getName());
    checkParametersCompatibilityWithDeclaration(s);
    checkFunctionParameters(return_type, symbolInfo, is_defined);
  }
  else
  {
    // error
    // check first in online compiler about multiple declaration
    // check screenshot
    if (s->is_defined)
    {
      printError("Multiple definition of " + s->getName());
    }
  }
  isFunctionStarted = true;
  printCurrentStatement(return_type + " " + symbolInfo->getName() + " function");
  addFuncDefinitionInAsm(symbolInfo->getName(), parameters.size());
}

symbol_info *checkArrayIndex(string var_name, symbol_info *idx)
{
  if (idx->variable_type == fraction)
  {
    printError("Expression inside third brackets not an integer");
    return nullptr;
  }
  else
  {
    pair<symbol_info *, string> p = symbolTable->lookup(var_name);
    symbol_info *s = p.first;
    if (s == nullptr)
      printError("Undeclared array " + var_name);
    else if (s->id_type != ARRAY)
      printError(var_name + " is not an array");
    else
    {
      symbol_info *t = new symbol_info(var_name + "[" + idx->getName() + "]", intermediate);
      t->id_type = VARIABLE;
      t->variable_type = s->array_type;
      t->temp_id = var_name + p.second;
      t->temp_index = newTemp();
      printCurrentStatement(t->getName());
      addArrayIndexInAsm(idx->temp_id, t->temp_index);
      return t;
    }
  }
  return nullptr;
}

symbol_info *checkAssignCompatibility(symbol_info *lhs, symbol_info *rhs)
{
  if (lhs == nullptr || rhs == nullptr)
  {
    return nullptr;
  }

  else if (lhs->id_type == ARRAY || rhs->id_type == ARRAY)
  {
    printError("Type Mismatch, " + (lhs->id_type == ARRAY ? lhs->getName() : rhs->getName()) + " is an array");
    return nullptr;
  }
  else if (lhs->id_type == FUNCTION || rhs->id_type == FUNCTION)
  {
    printError("Type Mismatch, " + (lhs->id_type == FUNCTION ? lhs->getName() : rhs->getName()) + " is a function");
    return nullptr;
  }
  else if (lhs->variable_type == _void || rhs->variable_type == _void)
  {
    printError("Void used in expression");
    return nullptr;
  }
  else if (lhs->variable_type == integer && rhs->variable_type == fraction)
  {
    printError("Type mismatch");
    return nullptr;
  }
  symbol_info *s = new symbol_info(lhs->getName() + " = " + rhs->getName(), "intermediate");

  if (isArray(lhs))
  {
    printCurrentStatement(s->getName());
    addCodeForArrayAssignment(lhs->temp_id, lhs->temp_index, rhs->temp_id);
  }
  else
  {
    printCurrentStatement(s->getName());
    addCodeForVariableAssignment(lhs->temp_id, rhs->temp_id);
  }
  s->id_type = VARIABLE;
  s->variable_type = lhs->variable_type;
  return s;
}

symbol_info *setIntermediateValues(string symbol_type, string variable_type, float float_value = 0)
{
  string name = to_string(float_value);
  name.erase(name.find_last_not_of('0') + 1, string::npos);
  if (variable_type == integer)
  {
    name = to_string(int(float_value));
  }
  symbol_info *target = new symbol_info(name, symbol_type);
  target->id_type = VARIABLE;
  target->variable_type = variable_type;
  target->temp_id = newTemp();
  printCurrentStatement(target->getName());
  addCodeForConst(target->temp_id, name);
  return target;
}

symbol_info *checkAndDoMulopThings(symbol_info *left, string optr, symbol_info *right)
{
  if (checkNullFunctionArrayVoid(left, right, optr))
    return nullptr;

  if (optr == "%")
  {
    if (right->variable_type == fraction || left->variable_type == fraction)
    {
      printError("Non-Integer operand on modulus operator");
      return nullptr;
    }
    if (right->getName() == "0")
    {
      printError("Modulus by Zero");
      return nullptr;
    }
  }
  if (optr == "/" && right->getName() == "0" && right->getName() == "0.")
  {
    printError("Division by Zero");
    return nullptr;
  }

  symbol_info *s = new symbol_info(left->getName() + optr + right->getName(), "intermediate");
  printCurrentStatement(s->getName());
  mulopInAsm(left->temp_id, right->temp_id, left->temp_id, optr);
  s->id_type = VARIABLE;
  s->temp_id = left->temp_id;
  s->variable_type = left->variable_type == fraction || right->variable_type == fraction ? fraction : integer;
  return s;
}

symbol_info *checkAdditionCompatibility(symbol_info *left, string optr, symbol_info *right)
{
  if (checkNullFunctionArrayVoid(left, right, optr))
    return nullptr;

  symbol_info *s = new symbol_info(left->getName() + optr + right->getName(), "intermediate");
  printCurrentStatement(s->getName());
  addopInAsm(left->temp_id, right->temp_id, optr);
  s->temp_id = left->temp_id;
  s->id_type = VARIABLE;
  s->variable_type = left->variable_type == fraction || right->variable_type == fraction ? fraction : integer;
  return s;
}

symbol_info *checkRELOPCompetibility(symbol_info *left, string optr, symbol_info *right)
{
  if (checkNullFunctionArrayVoid(left, right, optr))
    return nullptr;

  symbol_info *s = new symbol_info(left->getName() + optr + right->getName(), "intermediate");
  printCurrentStatement(s->getName());
  relopInAsm(left->temp_id, right->temp_id, optr, newLabel(), newLabel());
  s->temp_id = left->temp_id;
  s->id_type = VARIABLE;
  s->variable_type = integer;
  return s;
}

symbol_info *checkLogicCompetibility(symbol_info *left, string optr, symbol_info *right)
{
  if (checkNullFunctionArrayVoid(left, right, optr))
    return nullptr;

  symbol_info *s = new symbol_info(left->getName() + optr + right->getName(), intermediate);
  printCurrentStatement(s->getName());
  logicopInAsm(left->temp_id, right->temp_id, optr, newLabel(), newLabel());
  s->temp_id = left->temp_id;
  s->id_type = VARIABLE;
  s->variable_type = integer;
  return s;
}

symbol_info *checkFunctionArguments(symbol_info *si)
{
  pair<symbol_info *, string> p1 = findSymbol(si);
  symbol_info *symbolInfo = p1.first;
  if (symbolInfo == nullptr)
  {
    printError("Undeclared function " + si->getName());
    args.clear();
    return nullptr;
  }
  if (symbolInfo->id_type != FUNCTION)
  {
    printError("is not function");
    args.clear();
    return nullptr;
  }
  if (args.size() != symbolInfo->sequence_of_parameters.size())
  {
    printError("Total number of arguments mismatch in function " + symbolInfo->getName());
    args.clear();
    return nullptr;
  }
  string argus = symbolInfo->getName() + "(";
  for (int i = 0; i < args.size(); i++)
  {
    if (args[i]->id_type == ARRAY)
    {
      printError("Type mismatch, " + args[i]->getName() + " is an array");
      args.clear();
      return nullptr;
    }
    else if (args[i]->id_type == FUNCTION)
    {
      printError("Type mismatch, " + args[i]->getName() + " is a function");
      args.clear();
      return nullptr;
    }

    if (args[i]->variable_type != symbolInfo->sequence_of_parameters[i]->variable_type)
    {
      printError(to_string(i + 1) + "th argument mismatch in function " + symbolInfo->getName());
      args.clear();
      return nullptr;
    }
    argus += args[i]->getName() + (i == args.size() - 1 ? "" : ",");
  }
  argus += ")";
  symbol_info *s = new symbol_info(argus, intermediate);
  s->id_type = VARIABLE;
  s->variable_type = symbolInfo->return_type;
  args.clear();
  printCurrentStatement(argus);
  callFunction(si->getName());
  return s;
}

void checkFuncReturnCompatibility(symbol_info *symbolInfo)
{
  if (current_function != nullptr && symbolInfo->variable_type != current_function->return_type)
  {
    printError("return type does not match");
  }
  printCurrentStatement("return " + symbolInfo->getName());
  setReturnValueInAsm(symbolInfo->temp_id);
}

symbol_info *checkINDECopCompatibility(symbol_info *symbolInfo, string optr)
{
  if (checkNullFunctionArrayVoid(symbolInfo, optr))
    return nullptr;

  symbol_info *s = new symbol_info(symbolInfo->getName() + optr, intermediate);
  s->id_type = VARIABLE;
  s->variable_type = symbolInfo->variable_type;
  if (isArray(symbolInfo))
  {
    printCurrentStatement(s->getName());
    addCodeForInDeOP(optr == "++" ? "inc" : "dec", symbolInfo->temp_id, symbolInfo->temp_index);
  }
  else
  {
    printCurrentStatement(s->getName());
    addCodeForInDeOP(optr == "++" ? "inc" : "dec", symbolInfo->temp_id);
  }
  return s;
}

symbol_info *checkINCOPCompatibility(symbol_info *symbolInfo)
{
  return checkINDECopCompatibility(symbolInfo, "++");
}

symbol_info *checkDECOPCompatibility(symbol_info *symbolInfo)
{
  return checkINDECopCompatibility(symbolInfo, "--");
}

symbol_info *checkUnaryADDOPThings(string optr, symbol_info *symbolInfo)
{
  if (checkNullFunctionArrayVoid(symbolInfo, optr))
    return nullptr;

  symbol_info *s = new symbol_info(optr + symbolInfo->getName(), intermediate);
  s->id_type = VARIABLE;
  s->variable_type = symbolInfo->variable_type;
  printCurrentStatement(s->getName());
  s->temp_id = symbolInfo->temp_id;
  if(optr == "-"){
    string temp = newTemp();
    negateInAssembly(symbolInfo->temp_id, temp);
    s->temp_id = temp;
  }
  return s;
}

symbol_info *checkNotCompatibility(symbol_info *symbolInfo)
{
  if (checkNullFunctionArrayVoid(symbolInfo, "!"))
    return nullptr;

  symbol_info *s = new symbol_info("!" + symbolInfo->getName(), intermediate);
  s->id_type = VARIABLE;
  s->variable_type = integer;
  s->temp_id = symbolInfo->temp_id;
  string l1 = newLabel();
  string l2 = newLabel();
  printCurrentStatement(s->getName());
  notOperationOfCinAssembly(s->temp_id, l1, l2);
  return s;
}

symbol_info *checkLPAREN_Expression_RPAREN(symbol_info *symbolInfo)
{
  if (checkNullFunctionArrayVoid(symbolInfo, "()"))
    return nullptr;

  symbol_info *s = new symbol_info("(" + symbolInfo->getName() + ")", intermediate);
  s->temp_id = symbolInfo->temp_id;
  s->temp_index = symbolInfo->temp_index;
  s->id_type = VARIABLE;
  s->variable_type = symbolInfo->variable_type;
  return s;
}

void printLineAndErrors()
{
  symbolTable->printAllScopeTable(logout);
  fprintf(logout, "\nTotal lines: %d\nTotal errors: %d\n\n", line_count, syntax_error_count + lexical_error_count);
}

void enterNewScope()
{
  symbolTable->enterScope();
  for (size_t i = 0; isFunctionStarted && i < parameters.size(); i++)
  {

    symbolTable->insert(parameters[i]->getName(), parameters[i]->getType());
    symbol_info *s = symbolTable->lookup(parameters[i]->getName()).first;
    setCompatibleRelatedThings(s, parameters[i]);
  }

  setFunctionParameters();

  parameters.clear();
  isFunctionStarted = false;
}

void printTable()
{
  symbolTable->printAllScopeTable(logout);
}

void exitScope()
{
  // cout << line_count << endl;
  symbolTable->exitScope();
}
