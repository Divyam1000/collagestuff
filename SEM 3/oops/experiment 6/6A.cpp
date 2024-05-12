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
    virtual void fun(){};
};

class derived: public base{
public:
     void display(){
        cout<<"Display Derived"<<endl;
    }
    void show(){
        cout<<"Show Derived"<<endl;
    }
    void fun() {cout<<"derived"<<endl;};
};
class abs
{
    public:
        virtual void desc() = 0{ cout<<"HELLO"<<endl;}
};
class a : public derived
{
    //int x;
    public:
     void fun(){cout<<"a"<<endl;};
};
int main(){
    base B;
    derived D;
    base *ptr = &B;
    //derived *ptr1= &D;
    ptr->display();
    ptr->show();
    ptr = &D;
    ptr->display();
    ptr->show();

    ptr->base::display();

    //ptr1->display();
    //ptr1->show();

    //D.fun();
    //D.fun(1.2);
    //ptr->fun();
    //ptr->fun(1.2);
    //ptr = new a;
    //ptr->fun();

    return 0;
}
