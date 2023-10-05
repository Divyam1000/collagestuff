#include<iostream>

using namespace std;

int isprime(int n)
{
     for(int i=2; i<n/2; i++){
        if(n%i==0){
            return 0;
        }
    }
}

int main()
{
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    if(isprime(n)==0)
        cout<<n<<" is not a prime Number"<<endl;
    else
        cout<<n<<" is a prime Number"<<endl;


}

