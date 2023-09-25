#include<iostream>
using namespace std;

int main()
{
	int num, first, last, temp;
	cout<<"Enter a number: "; cin>>num;
	temp = num;	
	last = num % 10;
	while(temp>0){
		first = temp % 10;
		temp /= 10;
	}
	cout<<"\nNumber: "<<num<<"\nFirst digit : "<<first<<"\nlast digit : "<<last<<endl;
}
