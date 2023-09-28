#include<iostream>
#include<string.h>
using namespace std;

class STRING{
    string string_content;
public:
    STRING():string_content{}{}
    STRING(string str){string_content = str;}

    friend STRING operator +(STRING str_1, STRING str_2){
        STRING return_string;
        return_string.string_content = str_1.string_content + str_2.string_content;
        return return_string;
    }

    friend ostream& operator << (ostream &out, STRING &str){
        out << str.string_content;
        return out;
    }

    bool operator ==(STRING str){
        return string_content == str.string_content;
    }
};

int main()
{
    STRING a ("Hello "), b ("World") ,c;
    cout<<a<<endl;
    cout<<b<<endl;
    c = a + b;
    cout<<c;

}
