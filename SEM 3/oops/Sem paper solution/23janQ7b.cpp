#include<iostream>
#include<string>
using namespace std;

struct Marks
{
    float sub1, sub2, sub3;
};

class student
{
    Marks marks;
    string name;
    int rollno;
public:
    student() : marks ({0,0,0}) , name(""), rollno(0) {}
    student(string name, int rollno, Marks marks) : name(name), rollno(rollno), marks(marks) {} 
    float getAverageMarks(){return (marks.sub1 + marks.sub2, marks.sub3)/3;}
};

void averageOfStudentMarks(student s1, student s2)
{
    float average = (s1.getAverageMarks() + s2.getAverageMarks()) / 2;
    cout<<"The average marks of the two student is "<<average<<endl;
}

int main()
{
    student stud1("Ryan", 1, Marks({76,89,100}));
    student stud2("Rocky", 2, Marks({67,87,90}));

    averageOfStudentMarks(stud1,stud2);

    return 0;
}