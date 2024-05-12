#include<stdio.h>
#define MAX 10


void merge(int *arr,int *temp, int low1, int up1, int low2, int up2)
{
    int i = low1;
    int j = low2;
    int k = low1;
    while(i <= up1 && j <= up2)
    {	
	if(arr[i] < arr[j])
	    temp[k++] = arr[i++];
	else
  	    temp[k++] = arr[j++];
    }

    while(i <= up1)
	temp[k++] = arr[i++];
    while(j <= up2)
	temp[k++] = arr[j++];
} 
 
void copy(int *arr, int *temp, int n)
{
    for(int i = 0; i <= n; i++)
	arr[i] = temp[i];
}

void merge_pass(int *arr, int *temp, int n, int size)
{
    int low1, low2, up1, up2;
    low1 = 0;
    while(low1+size < n)
    {
	up1 = low1 + size - 1;
	low2 = low1 + size;
	up2 = low2 + size -1;
	if(up2 >=n)
	    up2-=1;
	merge(arr, temp, low1, up1, low2, up2);
    }
    for(int i = low1; i < n; i++)	
	temp[i] = arr[i];
    copy(arr, temp, n);
}

void merge_sort(int*arr, int n )
{
    int temp[MAX];
    int size = 1 ;
    while(size < n)
    {
	merge_pass(arr,temp,n, size);
	size *= 2;
    }
} 


int main()
{
    int arr[MAX], arrSize = 10;
    printf("Enter 10 numbers ");
    
    for(int i = 0; i < arrSize; i++)
    	scanf("%d",&arr[i]);
    
    merge_sort(arr, arrSize);

    printf("sorted array :  ");
    for(int t = 0; t<arrSize; t++)
	printf("%d   ",arr[t]);
}