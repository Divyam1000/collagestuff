#include<iostream>
#include<math.h>
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
    	float n, x, cnt=1, sign=1, f_sol;
    cout<<"Enter inputs for sin series"<<endl;
    cout<<"x: "; cin>>x;
    cout<<"n: "; cin>>n;

    for(int i=0; i<n; i++)
    {
	cout<<pow(x,cnt)/fact(cnt)<<endl;
    	f_sol += sign*(pow(x,cnt)/fact(cnt));
	sign*=-1;
	cnt+=2;
    }
    cout<< "solution of sin series of "<<x<<" upto "<<n<<" terms is : "<<f_sol<<endl;
}
