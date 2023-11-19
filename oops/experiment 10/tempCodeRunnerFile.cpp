#include <iostream>
using namespace std;

void testFunction(int param);

int main() {
    testFunction(1);
    testFunction(0);
    testFunction(-1);
}

void testFunction(int param) {
    try {
        if (param == 1)
            throw param;
        else if (param == 0)
            throw 'c';
        else if (param == -1)
            throw -1.0;
    }

    catch (int m) {
        cout << "int exception" << endl;
    }

    catch (char n) {
        cout << "char exception" << endl;
    }

    catch (double q) {
        cout << "double exception" << endl;
    }
}
