#include<stdio.h>

int main()
{
    int arr[10], arrSize = 10;
    printf("Enter 10 numbers ");
    
    for(int i = 0; i < arrSize; i++)
    	scanf("%d",&arr[i]);
    
    int smallest, pos;
    for(int i = 0; i <= arrSize; i++)
    {
	smallest = arr[i];
	pos = i;
	for(int j = i+1; j < arrSize; j++)
	{
     	    if( arr[j] < smallest)
	    {
	    	smallest = arr[j];
		pos = j;
	    }
	}
	arr[pos] = arr[i];
	arr[i] = smallest;
    }

    for(int t = 0; t < arrSize; t++)
	printf("%d  ",arr[t]);
}