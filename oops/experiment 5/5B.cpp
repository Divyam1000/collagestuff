#include <iostream>
using namespace std;

class Person {
public:
    string name;
    void setName(const string &n) {
        name = n;
    }
};

class Address : virtual public Person {
public:
    string address;
    void setAddress(const string &addr) {
        address = addr;
    }
};

class Contact : virtual public Person {
public:
    string phoneNumber;
    void setPhoneNumber(const string &phone) {
        phoneNumber = phone;
    }
};

class ContactInfo : public Address, public Contact {
public:
    void display() {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Phone Number: " << phoneNumber << endl;
    }
};

int main() {
    ContactInfo contactInfo;
    contactInfo.setName("Divyam Redkar");
    contactInfo.setAddress("GrandPulwaddo Benaulim Goa");
    contactInfo.setPhoneNumber("1234567890");

    contactInfo.display();

    return 0;
}
