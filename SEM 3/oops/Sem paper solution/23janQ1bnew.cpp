#include<iostream>
#include<string>
#include<vector>
#include<stdexcept> // Include <stdexcept> for out_of_range
using namespace std;

class Student {
    string name;
    int rollno;

public:
    Student() : name(""), rollno(0) {}
    Student(string name, int rollno) : name(name), rollno(rollno) {}
    void display() {
        cout << "Name: " << name << "\nRoll No.: " << rollno << endl;
    }
};

class StudentList {
    vector<Student> students;

public:
    void addStudent(const string name, const int rollno) {
        students.push_back(Student(name, rollno));
    }

    Student operator[](int index) {
        if (index >= students.size()) {
            throw out_of_range("Accessing data out of bounds");
        } else {
            return students[index];
        }
    }

    int size() const {
        return students.size();
    }
};

int main() {
    StudentList studentList;
    studentList.addStudent("John", 10);
    studentList.addStudent("Nick", 12);
    studentList.addStudent("Mike", 14);

   
    for (int i = 0; i < studentList.size()+1; i++) {
        try{
            studentList[i].display();
        }
        catch (const out_of_range &e) {
        cerr << "Error: " << e.what() << endl;
    }
    }

    return 0;
}
