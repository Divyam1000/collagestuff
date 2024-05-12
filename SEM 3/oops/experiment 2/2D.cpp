#include<iostream>
#include<string.h>

using namespace std;
class B;
class A{
    int age;
    char name[10];
    public:
    A(){
        cout<<"Enter name: "; cin>>name;
        cout<<"Enter age: "; cin>>age;
    }
    void get_data(){cout<<"Name: "<<name<<endl<<"Age: "<<age<<endl;}
    friend void swap(A& ,A&);
};

void swap(A &a, A &b){
    int age;
    char name[10];
    age = a.age; 
    a.age = b.age; 
    b.age = age; 
    strcpy(name,a.name);
    strcpy(a.name,b.name);
    strcpy(b.name,name);
}

int main(){
    cout<<"Student 1:"<<endl;
    A x;
    cout<<"Student 2:"<<endl;
    A y;
    swap(x,y);
    cout<<"Student 1:"<<endl;
    x.get_data();
    cout<<"Student 2:"<<endl;
    y.get_data();
    return 0;
}