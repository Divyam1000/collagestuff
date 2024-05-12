#include <iostream>
#include <string>
#include <vector>

using namespace std;

class person {
    string name;
    string address;
    unsigned int phNo;

public:
    person() : name(""), address(""), phNo(0000000000) {}
    person(const string& n, const string& addr, unsigned int phone)
        : name(n), address(addr), phNo(phone) {}
    virtual void getDetails() const {
        cout << "Name: " << name << "\nAddress: " << address << "\nPhone Number: " << phNo << endl;
    }
};

class employee : public person {
    unsigned int eno;
    string eName;

public:
    employee() : person(), eno(0), eName("") {}
    employee(const string& n, const string& addr, unsigned int phone, unsigned int empNo)
        : person(n, addr, phone), eName(n), eno(empNo) {}
    virtual void getDetails() const {
        cout << "Employee Name: " << eName << "\nEmployee Number: " << eno << endl;
    }
};

class manager : public employee {
    string designation;
    string departmentName;
    int basicSalary;

public:
    manager() : employee(), designation(""), departmentName(""), basicSalary(0) {}
    manager(const string& n, const string& addr, unsigned int phone, unsigned int empNo,
            const string& desig, const string& dept, int salary)
        : employee(n, addr, phone, empNo), designation(desig), departmentName(dept), basicSalary(salary) {}
    virtual void getDetails() const {
        cout << "Designation: " << designation << "\nDepartment: " << departmentName << "\nBasic Salary: " << basicSalary << endl;
    }
    int getSalary() const { return basicSalary; }
};

int main() {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    vector<manager> managers;

    string name, address, designation, departmentName;
    int basicSalary;
    unsigned int eno, phNo;


    for (int i = 0; i < n; i++) {
        cout << "Enter manager details:" << endl;
        cin.ignore();  // Ignore the newline character left in the buffer
        cout << "Manager name: ";
        getline(cin, name);

        cout << "Phone Number: ";
        cin >> phNo;
        cin.ignore();  // Ignore the newline character left in the buffer

        cout << "Address: ";
        getline(cin, address);

        cout << "Employee number: ";
        cin >> eno;

        cin.ignore();  // Ignore the newline character left in the buffer

        cout << "Designation: ";
        getline(cin, designation);

        cout << "Department name: ";
        getline(cin, departmentName);

        cout << "Basic salary: ";
        cin >> basicSalary;

        managers.push_back(manager(name, address, phNo, eno, designation, departmentName, basicSalary));
    }

    manager highestSalaryManager;

    for (const manager& m : managers) {
        if (m.getSalary() > highestSalaryManager.getSalary()) {
            highestSalaryManager = m;
        }
    }

    cout << "\nManager with the highest salary:\n";
    highestSalaryManager.getDetails();

    return 0;
}
