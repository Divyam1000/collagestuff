#include<iostream>
using namespace std;

class base{
public:
    void display(){
        cout<<"Display Base"<<endl;
    }
    virtual void show(){
        cout<<"Show Base"<<endl;
    }
};

class derived: public base{
public:
    void display(){
        cout<<"Display Derived"<<endl;
    }
    void show(){
        cout<<"Show Derived"<<endl;
    }
};

int main(){
    base B;
    derived D;
    base *ptr = &B;
    ptr->display();
    ptr->show();
    ptr = &D;
    ptr->display();
    ptr->show();
    return 0;
}
