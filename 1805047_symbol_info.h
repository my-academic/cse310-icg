#include <bits/stdc++.h>
using namespace std;
enum symbol_id_type
{
    VARIABLE,
    ARRAY,
    FUNCTION
};

class symbol_info
{
private:
    string name;
    string type;
    symbol_info *next;

    bool khali;
    symbol_info *prev;

public:
    string temp_id;
    string temp_index;

    symbol_id_type id_type;
    // function
    bool is_defined = false;
    vector<symbol_info *> sequence_of_parameters;
    bool is_parameters_inserted = false;
    string return_type;

    // array
    string array_type;

    // variable
    string variable_type;

    bool isFunction()
    {
        return id_type == FUNCTION;
    }
    bool isArray()
    {
        return id_type == ARRAY;
    }
    bool isVariable()
    {
        return id_type == VARIABLE;
    }

    symbol_info(string n, string t) : name(n), type(t)
    {
        next = nullptr;
    }

    symbol_info()
    {
        next = nullptr;
    }

    // symbol_info operator=(const symbol_info &symbolInfo)
    // {
    //     this->name = symbolInfo.name;
    //     this->type = symbolInfo.type;
    //     this->id_type = symbolInfo.id_type;

    //     this->is_defined = symbolInfo.is_defined;
    //     this->return_type = symbolInfo.return_type;
    //     for (int i = 0; symbolInfo.sequence_of_parameters.size(); i++)
    //     {
    //         this->sequence_of_parameters.push_back(symbolInfo.sequence_of_parameters[i]);
    //     }

    //     this->size_of_array = symbolInfo.size_of_array;

    //     this->variable_type = symbolInfo.variable_type;
    //     this->int_value = symbolInfo.int_value;
    //     this->float_value = symbolInfo.float_value;

    //     return *this;
    // }

    ~symbol_info()
    {
        // cout << "calling destructor of symbol info" << endl;
        next = nullptr;
        // free(next);
        // delete next;
    }

    string getName() const { return name; }
    void setName(const string &name_) { name = name_; }

    string getType() const { return type; }
    void setType(const string &type_) { type = type_; }

    symbol_info *getNext() const { return next; }
    void setNext(symbol_info *next_) { next = next_; }

    symbol_info *getPrev() const { return prev; }
    void setPrev(symbol_info *prev_) { prev = prev_; }

    bool getKhali() const { return khali; }
    void setKhali(bool khali_) { khali = khali_; }

    void print(FILE *logout)
    {
        fprintf(logout, " < %s : %s> ", name.c_str(), type.c_str());
        // cout << "< " << name << " : " << type << "> ";
    }
    void print()
    {
        // fprintf(logout, " < %s : %s> ", name.c_str(), type.c_str());
        cout << "< " << name << " : " << type << "> ";
    }
};