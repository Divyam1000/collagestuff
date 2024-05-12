#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
    string name;
    string rollNo;
    string address;
    string branch;
};

void addStudent() {
    ofstream outFile;
    Student newStudent;

    cout << "Enter student name: ";
    cin >> newStudent.name;

    cout << "Enter student roll number: ";
    cin >> newStudent.rollNo;
    cin.ignore();
    cout << "Enter student address: ";
    getline(cin, newStudent.address);

    cout << "Enter student branch: ";
    cin >> newStudent.branch;

    outFile.open(newStudent.rollNo + ".txt");

    outFile << "Name: " << newStudent.name << endl;
    outFile << "Roll Number: " << newStudent.rollNo << endl;
    outFile << "Address: " << newStudent.address << endl;
    outFile << "Branch: " << newStudent.branch << endl;

    outFile.close();

    cout << "Student added successfully." << endl;
}

void searchStudent() {
    int rollNo;
    cout << "Enter the roll number to search: ";
    cin >> rollNo;

    ifstream inFile;
    string fileName = to_string(rollNo) + ".txt";

    inFile.open(fileName);

    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line) ) {
            cout << line << endl;
        }
        inFile.close();
    } else {
        cout << "Student with roll number " << rollNo << " not found." << endl;
    }
}

void updateStudent() {
    int rollNo;
    cout << "Enter the roll number to update: ";
    cin >> rollNo;

    fstream file;
    string fileName = to_string(rollNo) + ".txt";

    file.open(fileName, ios::in | ios::out);

    if (file.is_open()) {
        Student updatedStudent;

        cout << "Enter updated student name: ";
        cin >> updatedStudent.name;

        cout << "Enter updated student address: ";
        cin.ignore();
        getline(cin, updatedStudent.address);

        cout << "Enter updated student branch: ";
        cin >> updatedStudent.branch;

        file << "Name: " << updatedStudent.name << endl;
        file << "Roll Number: " << rollNo << endl;
        file << "Address: " << updatedStudent.address << endl;
        file << "Branch: " << updatedStudent.branch << endl;

        file.close();

        cout << "Student details updated successfully." << endl;
    } else {
        cout << "Student with roll number " << rollNo << " not found." << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "\nStudent Database Application\n";
        cout << "1. Add Student\n";
        cout << "2. Search Student\n";
        cout << "3. Update Student\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                searchStudent();
                break;
            case 3:
                updateStudent();
                break;
            case 4:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
