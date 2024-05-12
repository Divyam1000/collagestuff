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
 
void copy(int *arr, int *temp, int low, int up)
{
    for(int i = low; i <= up; i++)
	arr[i] = temp[i];
}

void merge_sort(int*arr, int low, int up )
{
    int temp[MAX];
    int mid ;
    if(low < up)
    {
	mid = ( low + up ) / 2;
	merge_sort(arr,low,mid);
	merge_sort(arr,mid+1,up);
	merge(arr,temp,low,mid,mid+1,up);
	copy(arr,temp,low,up);
    }
} 


int main()
{
    int arr[10], arrSize = 10, incr;
    printf("Enter 10 numbers ");
    
    for(int i = 0; i < arrSize; i++)
    	scanf("%d",&arr[i]);
    
    merge_sort(arr, 0, arrSize-1);

    printf("sorted array :  ");
    for(int t = 0; t<arrSize; t++)
	printf("%d   ",arr[t]);
}