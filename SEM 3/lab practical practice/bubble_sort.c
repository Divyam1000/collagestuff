#include<stdio.h>
#include<stdlib.h>
int main()
{
    int arrSize;
    printf("Enter size of array  : ");
    scanf("%d",&arrSize);
    int* arr = (int*)malloc(sizeof(int) * arrSize);
    printf("Enter Elements of array \n");
    for(int i = 0; i < arrSize; i++)
    	scanf("%d",&arr[i]);
    
    for(int i = arrSize; i > 0; i--)
    {
     	for(int j = 0; j < i-1; j++)
	{
	    if(arr[j] < arr[j+1])
	    {
	    	int temp = arr[j];
		arr[j] = arr[j+1];
		arr[j+1] = temp;
     	    }
	}
    }
    
    printf("Sorted array : ");
    for(int t = 0; t < arrSize; t++)
    	printf("%d  ",arr[t]);
}