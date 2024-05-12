#include<iostream>
#include<string>

using namespace std;

class employee
{
    string firstName;
    string lastName;
    int salary;
public:
    employee() : firstName(""), lastName(""), salary(0) {}
    employee(string fname, string lname, int sal) : firstName(fname), lastName(lname), salary(sal){}

    string get_firstName(){return firstName;}
    string get_lastName(){return lastName;}
    int get_salary(){return salary;}
    void set_firstNaem(string fname){firstName = fname;}
    void set_lastName(string lname){lastName = lname;}
    void set_salary(int sal){salary = sal;}

    void YearlySalalry()
    {
        int totalSalary = salary * 12;
        cout<<"Yearly salary of "<<firstName<<" "<<lastName<<" : "<<totalSalary<<endl;
    }
};

int main()
{
    employee emp1("Divyam","Redkar",80000);
    employee emp2;
    emp2.set_firstNaem("Alex");
    emp2.set_lastName("West");
    emp2.set_salary(50000);
    
    cout<<emp2.get_firstName()<<" "<<emp2.get_lastName()<<endl;
    cout<<"Salary : "<<emp2.get_salary()<<endl;

    emp1.YearlySalalry();
    emp2.YearlySalalry();
    return 0;
}