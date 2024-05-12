#include<stdio.h>

int main()
{
    int arr[10], arrSize = 10, incr;
    printf("Enter 10 numbers ");
    
    for(int i = 0; i < arrSize; i++)
    	scanf("%d",&arr[i]);
    
    printf("Enter the starting increment : ");
    scanf("%d",&incr);
    
    while(incr >= 1){
    for(int i = incr; i < arrSize; i++)
    {
	int k = arr[i],j;
    	for(j = i-incr; j >= 0 && k < arr[j]; j-=incr)
	    arr[j+incr] = arr[j];
 	arr[j+incr] = k;

    }
	incr -= 2;
    }

    printf("sorted array :  ");
    for(int t = 0; t<arrSize; t++)
	printf("%d   ",arr[t]);
}