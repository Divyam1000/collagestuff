#include<iostream>

using namespace std;

int fact(int n)
{
    if(n==0){
        return 1;
    }
    else{
        n *= fact(n-1);
        return n;
    }
}

int main()
{
    int n;
    cout<<"Enter number to find factorial: ";
    cin>>n;

    cout<<"Factorial of "<<n<<" = "<<fact(n)<<endl;

    return 0;
}
