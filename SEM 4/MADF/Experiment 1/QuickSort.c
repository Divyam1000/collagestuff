#include <stdio.h>
#include <limits.h>

void PrintArray(int *arr, int n, int piviot)
{
    for(int i = 0; i < n-1 ; i++){
        if(i == piviot)
            printf("\033[4m\033[1m%d\033[0m  ",arr[i]);
        else
            printf("%d  ",arr[i]);

    }
    printf("\n");
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

void QuickSort(int *arr, int p, int q, int n)
{
    if (p < q)
    {
        int j = Partition(arr, p, q );
        PrintArray(arr,n,j);
        QuickSort(arr, p, j, n);
        QuickSort(arr, j + 1, q, n);
    }
}

int main()
{
    int arr[] = {55, 11, 33, 23, -17, 89, -11, 72, 43, INT_MAX};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array before sorting :");
    for (int i = 0; i < n-1; i++)
        printf("%d  ", arr[i]);
    printf("\n");
    QuickSort(arr, 0, n - 1, n);

    printf("\nArray after sorting : ");
    for (int i = 0; i < n-1; i++)
        printf("%d  ", arr[i]);
    printf("\n");
    return 0;
}