#include<iostream>
#include<string.h>
using namespace std;

#define SPACE (cout<<endl<<endl)

struct marks {
    double maths;
    double ld;
    double co;
    double ds;
    double oops;
    double percentage;
};

class student
{
    string name;
    int rollno;
    string branch;
    struct marks m;
public: 
    void EnterDetails(int base);
    bool DisplayDetails(int roll);
    bool DisplayPer(int roll);
};

int main()
{
    bool loop = true;
    int op=0;
    int base=2200;
    int roll;
    bool flag;

    while(loop){
        cout<<"*****MENU*****"<<endl;
        cout<<"1.Enter 3 student detail\n2.Diplay Stuent details\n3.Display Percentage\n4.Exit"<<endl;
        cin>>op;
        switch(op)
        {
            case 1:
                static student s[3];
                    for(int i=0; i<3; i++){
                        base++;
                        s[i].EnterDetails(base);
                    } 
                break;
            case 2:
                cout<<"Enter Roll No.: "; cin>>roll;
                for(int i=0; i<3; i++){
                    if(s[i].DisplayDetails(roll)==true){
                        flag = true;
                        break;
                    }
                }
                if(flag!=true) cout<<"Roll No. not found"<<endl;
                flag = true;
                break;
            case 3:
                cout<<"Enter Roll No.: "; cin>>roll;
                for(int i=0; i<3; i++){
                    if(s[i].DisplayPer(roll)==true){
                        flag = true;
                        break;
                    }
                }
                if(flag!=true) cout<<"Roll No. not found"<<endl;
                flag = true;
                break;
            case 4: loop = false; break;

            default : cout<<"ERROR! Wrong input!"<<endl;
        }
    }
}

void student :: EnterDetails(int base)
{
    cout<<"Enter Student name: ";cin>>name;
    cout<<"Enter Branch: "; cin>>branch;
    cout<<"Enter markss of maths, LD, CO, DS, OOPS: ";
    cin>>m.maths>>m.ld>>m.co>>m.ds>>m.oops;
    rollno = base;
    cout<<"Roll No. : "<<rollno<<endl;
    DisplayDetails(rollno);
    SPACE;
}
bool student :: DisplayDetails(int roll)
{
    if(roll != rollno) return false;
    cout<<"Student name: "<<name<<endl; cout<<"Branch: "<<branch<<endl;
    cout<<"Maths : "<<m.maths<<endl; cout<<"LD : "<<m.ld<<endl;
    cout<<"CO : "<<m.co<<endl; cout<<"DS : "<<m.ds<<endl; cout<<"OOPS : "<<m.oops<<endl;
    return true;
    SPACE;
}
bool student :: DisplayPer(int roll)
{
    if(roll != rollno) return false;
    m.percentage = (m.maths + m.ld + m.co + m.ds + m.oops)/5;
    cout<<"Percentage : "<<m.percentage<<endl;
    return true;
    SPACE;
}