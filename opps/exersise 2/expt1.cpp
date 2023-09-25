#include<iostream>
using namespace std;

int main()
{
	int arr[5];
	cout<<"Enter elements in array: "<<endl;
	for(int i=0; i<5; i++){
		cin>>arr[i];
	}
	int max= arr[0],pos=0;
	for(int i=1; i<5; i++){
		if(arr[i]>max){
			max=arr[i];
			pos=i;
		}
	}
	cout<<"Maximum number in the array is: "<<max<<" at position "<<pos+1<<endl;

}
