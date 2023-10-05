#include<iostream>
using namespace std;

int main()
{
	int num, rev=0;
	cout<<"Enter a number: "; cin>>num;
	
	int copy = num;
	while(copy>0)
	{
		rev = rev * 10 + copy % 10;
		copy /= 10;
	}
	if(rev==num) cout<<num<<" is a palindrome"<<endl;
	else cout<<num<<" is not a palindrome"<<endl;
	return 0;
}
