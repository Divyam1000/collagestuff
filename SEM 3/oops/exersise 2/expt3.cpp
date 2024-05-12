#include<iostream>
using namespace std;

void fib(int n)
{
	int a=0,b=1,temp;
	cout<<a<<" ";
	for(int i=1; i<n; i++){
		cout<<b<<" ";
		temp = b;
		b += a;
		a = temp;
	}
}

int main()
{
	int n,a=0,b=1;
	cout<<"Enter the number of terms for fibonaci series: "; cin>>n;
	for(int i=1; i<=n; i++){
		fib(i);
		cout<<endl;
	}
}
