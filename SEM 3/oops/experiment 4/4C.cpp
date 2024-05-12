#include<iostream>
using namespace std;

class temp{
    int num;
public:
    temp():num {0}{}
    temp(int n):num {n}{}
    friend istream& operator >> (istream &in, temp &n){
        in >> n.num;
        return in;
    }
    friend ostream& operator << (ostream &out, temp &n){
        out << n.num;
        return out;
    }
};

int main()
{
    temp a,b = 10;
    cout<<"Enter a number : ";
    cin>>a;
    cout<<"a= "<<a<<endl;
    cout<<"b= "<<b<<endl;

    return 0;
}
