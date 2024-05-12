#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct person
{
    string name;
    long long int phoneNo;
};


int main()
{
    fstream contactsFile("a.txt",ios::app);
    person A({"Alex",6789239433})
    ,B({"Brian", 8923984294});

    contactsFile <<"Name : "<< A.name.c_str()<<"\nPhone Number : "<<A.phoneNo<<"\n";
    contactsFile <<"Name : "<< B.name.c_str()<<"\nPhone Number : "<<B.phoneNo<<"\n";
    
    contactsFile.close();
}