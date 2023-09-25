#include<iostream>

using namespace std;

int fac(int num){
    int result = 1;
    while(num){
        result *= num--;
    }
    return result;
}

int KMN(int &num){
    int tmp = num, result = 0;
    while(tmp){
        result += fac(tmp % 10);
        tmp /= 10;
    }
    return result;
}

int main()
{
    int num;
    cout<<"Enter a Number: "; cin>>num;
    if(num == KMN(num))
        cout<<"Entered Number is a Krishnamuthy Number"<<endl;
    else
        cout<<"Entered Number is not a Krishnamuthy Number"<<endl;
    return 0;
}
