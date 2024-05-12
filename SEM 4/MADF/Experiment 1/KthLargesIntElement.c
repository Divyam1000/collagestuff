#include<stdio.h>
#include<limits.h>

void PrintArray(int *arr, int low, int up, int n, int j)
{
    for(int i = 0; i < n-1; i++){
        if(i == low)
            printf("[%d ",arr[i]);
        else
            printf("%d ",arr[i]);
        if(i == up -2)
            printf("]");
    }
    printf("Piviot : %d -> %d\n",j,arr[j]);

}

int Partition(int *arr, int p, int q)
{
    int v = arr[p];
    int i = p;
    int j = q;

    do
    {
        do
        {
            i++;
        }while (arr[i] <= v);

        do
        {
            j--;
        }while (arr[j] > v);
        
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);

    arr[p] = arr[j];
    arr[j] = v;
    return j;
}

int Select(int *arr, int n, int k)
{
    int j, low, up;
    if(k < n)
    {
        low = 0;
        up = n;
        do
        {
            j = Partition(arr,low,up);
            PrintArray(arr,low,up,n,j);
            if(k == j)
                return arr[k]; 
            else if(k < j)
                up = j;
            else    
                low = j+1;
        }while(1);
    }
    else{
        printf("\nSearch parameter exceeds maximum value\n");
        return -1;
    }
}

int main()
{
    int arr[] = {63, 18, 23, 9, 79, 89, 54, 69, 12, 72, 41, INT_MAX};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int k;
    printf("Given array : ");
    for(int i = 0; i < arr_size -1; i++)
        printf("%d  ",arr[i]);

    printf("\n Enter the k for the kth largest element : ");
    scanf("%d",&k);

    int value = Select(arr,arr_size, arr_size-k-1);
    if(value != -1)
        printf("Element at %d position is : %d\n",k,value);

    return 0;

}