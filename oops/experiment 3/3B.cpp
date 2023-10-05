#include<iostream>
#include<string.h>
using namespace std;

class copier{
    int roll;
    string name;
public:
    copier(copier& p){
        roll = p.roll;
        name = p.name;
    }
    copier(int r, string n){
        roll = r;
        name = n;
    }
    void display(){
        cout<<"Name "<<name<<endl;
        cout<<"Roll No. "<<roll<<endl;
    }
};

int main()
{
    string name;
    int roll;
    cout<<"Name: "; getline(cin, name, '\n');
    cout<<"Roll No. ";cin>>roll;
    copier a(roll,name);
    copier b(a);
    cout<<"sucessfully copied"<<endl;
    b.display();
    return 0;
}
