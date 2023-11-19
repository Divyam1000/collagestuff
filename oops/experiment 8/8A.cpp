#include <iostream>

using namespace std;

template <typename T>
void swapElements(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int num1 = 5, num2 = 10;
    double double1 = 3.14, double2 = 6.28;
    char char1 = 'A', char2 = 'B';

    cout << "Before swapping:" << endl;
    cout << "num1: " << num1 << ", num2: " << num2 << endl;
    cout << "double1: " << double1 << ", double2: " << double2 << endl;
    cout << "char1: " << char1 << ", char2: " << char2 << endl;

    swapElements(num1, num2);
    swapElements(double1, double2);
    swapElements(char1, char2);

    cout << "\nAfter swapping:" << endl;
    cout << "num1: " << num1 << ", num2: " << num2 << endl;
    cout << "double1: " << double1 << ", double2: " << double2 << endl;
    cout << "char1: " << char1 << ", char2: " << char2 << endl;

    return 0;
}
