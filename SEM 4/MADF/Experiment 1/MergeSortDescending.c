#include<stdio.h>

void PrintArray(int *arr, int low, int up,int n)
{
    for(int i = 0; i < n; i++)
    {
        if(i >= low && i <= up)
            printf("\033[1m\033[4m%d \033[0m",arr[i]);
        else
            printf("%d ",arr[i]);
        if(i == (low+up)/2)
            printf("|");
    }
    printf("\n");
}

void Merge(int *arr, int low, int up, int mid)
{
    int n1, n2, i, j, k;
    n1 = mid - low + 1;
    n2 = up - mid ;
    int arr1[n1], arr2[n2];

    for(i = 0; i< n1; i++)
        arr1[i] = arr[low+i]; 
    for(i = 0; i< n2; i++)
        arr2[i] = arr[mid+1+i];

    i = low; 
    j = k = 0;
    while(j < n1 && k < n2 && i < up)
    {
        if(arr1[j] >= arr2[k])
            arr[i] = arr1[j++];
        else
            arr[i] = arr2[k++];
        i++;
    }
    while(j < n1 )
        arr[i++] = arr1[j++];

    while(k < n2 )
        arr[i++] = arr2[k++];
    
}

void MergeSort(int *arr, int low, int up,int n)
{
    int mid = (low + up)/ 2;
    if(low >= up)
        return;
    MergeSort(arr,low,mid,n);        
    MergeSort(arr, mid+1, up,n);
    Merge(arr, low, up, mid);
    PrintArray(arr,low,up,n);

}

int main()
{
    int arr[] = { 65, 18, 40, 52, 81, 93, 111, 23, 28, 25, 21 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given Array : ");
    for(int i = 0; i < arr_size; i++)
        printf("%d ",arr[i]);
    printf("\n");

    MergeSort(arr,0,arr_size-1,arr_size);

    printf("After sorting : ");
    for(int i = 0; i < arr_size; i++)
        printf("%d ",arr[i]);
    printf("\n");

    return 0;
}