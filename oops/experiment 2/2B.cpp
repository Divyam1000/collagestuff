#include <iostream>
using namespace std;

inline float addition(float a, float b){return a + b;}
inline float subtraction(float a, float b){return a - b;}
inline float division(float a, float b){return a / b;}
inline float multiplication(float a, float b){return a * b;}

int main()
{
    float num1, num2;
    int op;
    while (true)
    {
        cout << "Enter operations" << endl;
        cout << "1.Addition\n2.Subtraction\n3.Division\n4.Multiplication\n5.exit" << endl;
        cin >> op;
        if(op == 5) exit(1);
        cout << "Enter first number : ";
        cin >> num1;
        cout << "Enter second number : ";
        cin >> num2;

        switch (op)
        {
        case 1:
            cout << "Sum: "<<addition(num1, num2)<<endl; break;
        case 2:
            cout<<"Sub: "<<subtraction(num1, num2)<<endl; break;
        case 3:
            cout<<"Div: "<<division(num1, num2)<<endl; break;
        case 4: 
            cout<<"Multi: "<<multiplication(num1, num2)<<endl; break;
        case 5: exit(1);
        default : cout<<"wrong input!"<<endl; break;
        }
    }
}