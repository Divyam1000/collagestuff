#include<iostream>
using namespace std;

class complex{
    float a, b;

public:
    complex(){
        a = 0;
        b = 0;
    }
    complex(float x, float y){
        a = x;
        b = y;
    }
    void display(){
        if(b>=0)
        cout<<a<<"+"<<b<<"i"<<endl;
        else cout<<a<<b<<"i"<<endl;    
    }
    friend complex sum(complex &A, complex &B){
        float a = A.a + B.a;
        float b = A.b + B.b;
        complex C(a,b);
        return C;
    }
};

int main()
{
    complex A(1.1 , 1.2);
    complex B = complex(1.3, 1.4);
    complex C;
    C = sum(A, B);
    C.display();
    return 0;
}