#include <iostream>
#include <string>

int main() {
    using namespace std;

    string str1 = "Hello, ";
    string str2 = "World!";
    string result;

    result = str1 + str2;
    cout << "Concatenated String: " << result << endl;

    if (str1 == str2) {
        cout << "Strings are equal." << endl;
    } else {
        cout << "Strings are not equal." << endl;
    }

    string mainString = "This is a sample string";
    string substring = "sample";
    char searchChar = 'a';

    size_t found = mainString.find(substring);
    if (found != string::npos) {
        cout << "Substring found at position: " << found << endl;
    } else {
        cout << "Substring not found." << endl;
    }

    found = mainString.find(searchChar);
    if (found != string::npos) {
        cout << "Character found at position: " << found << endl;
    } else {
        cout << "Character not found." << endl;
    }

    string temp = str1;
    str1 = str2;
    str2 = temp;

    cout << "After swapping:" << endl;
    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;

    return 0;
}
