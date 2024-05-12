#include<iostream>
using namespace std;

template <typename T>
T LargestElement(T a, T b, T c)
{
    return a >= b ? a : b >= c ? b : c;
}

int main()
{
    cout<<"Largest int element : "<<LargestElement(34,1,3)<<endl;
    cout<<"Largest double element :"<<LargestElement(2.32,123.31,43.123)<<endl;
    return 0;
}