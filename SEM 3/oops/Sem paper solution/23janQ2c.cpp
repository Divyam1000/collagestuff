#include<iostream>
using namespace std;

int main()
{
    float floatNum = 23.75;
    int integerNum = 10;

    integerNum += (int) floatNum;

    cout<<"integerNum = "<<integerNum<<endl;

    floatNum -= (float) integerNum;

    cout<<"floatNum = "<<floatNum<<endl;
    return 0;
}