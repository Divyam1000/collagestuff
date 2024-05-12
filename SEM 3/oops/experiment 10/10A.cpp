#include <iostream>
using namespace std;

void divide(float x, float y) {
    try {
        if (y != 0) {
            cout << "Division = " << x / y;
        } else {
            throw y;
        }
    } catch (int q) {
        cout << "Exception caught in divide Function y = " << q << endl;
        throw;
    }
}

int main() {
    float num1, num2;
    cout << "\nEnter num1 and num2: ";
    cin >> num1 >> num2;

    try {
        divide(num1, num2);
    } catch (int p) {
        cout << "Divide by zero exception caught in main, " << "num2 = " << p << endl;
    }

    return 0;
}


