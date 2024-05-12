#include<iostream>

using namespace std;

class B;
class A
{
    int num;
public:
    A (int a) : num(a){}
    friend void swap(A& Aobj, B& Bobj);
    void GetValue(){
        cout<<"Class A : "<<num<<endl;
    }
};
class B
{
    int num;
public:
    B (int b) : num(b){}
    friend void swap(A& Aobj, B& Bobj);   
    void GetValue(){
        cout<<"Class B : "<<num<<endl;
    }
};

void swap(A& Aobj, B& Bobj)
{
    auto temp = Aobj.num;
    Aobj.num = Bobj.num;
    Bobj.num = temp;
}

int main()
{
    A a(12);
    B b(23);
    cout<<"Before swap"<<endl;
    a.GetValue();
    b.GetValue();
    swap(a,b);
    cout<<"After swap"<<endl;
    a.GetValue();
    b.GetValue();
    return 0;
}