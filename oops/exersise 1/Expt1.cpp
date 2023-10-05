#include<iostream>

using namespace std;

int main()
{
    int x, n, sol=1;
    cout<<"Enter x and n: "<<endl;
    cin>>x>>n;

    for(int i=0; i<n; i++){
        sol *= x;
    }

    cout<<x<<"^"<<n<<"="<<sol<<endl;

    return 0;
}
