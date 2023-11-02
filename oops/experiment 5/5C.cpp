#include<iostream>
#include<string>

using namespace std;

class base
{
    int num;
public:
    base(int n){
        num = n;
        cout<<"base initialized"<<endl;
    }
    void show_num(){
        cout<<"num : "<<num<<endl;
    }

};

class derived: public base
{
    string name;
public:
    derived(string _name, int n):base(n){
        name = _name;
        cout<<"derived initialized"<<endl;
    }
    void show_name(){
        cout<<"name : "<<name<<endl;
    }
};

int main()
{
    derived A("Divyam", 58);
    A.show_name();
    A.show_num();
}
