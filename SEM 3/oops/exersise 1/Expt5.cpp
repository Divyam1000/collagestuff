#include<iostream>

using namespace std;

int main()
{
    int num,rev=0;
    cout << "Enter a 4 digit number: ";
    cin>>num;
    int temp = num;
    while(temp>0)
    {
        rev = rev*10 + temp%10;
        temp/=10;
    }
    cout<<"The reversed number is:"<<rev<<endl;
}
