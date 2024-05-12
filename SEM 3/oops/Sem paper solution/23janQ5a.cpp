#include<iostream>
using namespace std;

double performArithmetic(double num1, double num2, char op) {
    switch(op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if(num2 == 0)
                throw(num2);
            else
                return num1 / num2;
        default: 
            throw(invalid_argument("Invalid operator!"));
    }
    return 0;
}

int main() {
    double num1, num2, result;
    char op;

    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    cout << "Enter operation to perform on the numbers: ";
    cin >> op;

    try {
        result = performArithmetic(num1, num2, op);
        cout << "Result: " << result << endl;
    } catch (double divisor) {
        cout << "\nDivide by zero exception caught. The divisor is: " << divisor << endl;
    }
    catch(invalid_argument &e){
        cout<<"Error: "<<e.what()<<endl;
    }

    return 0;
}
