
#include<stdio.h>
#include<limits.h>

void PrintArray(char *arr, int low, int up, int n, int j)
{
    for(int i = 0; i < n-1; i++){
        if(i == low)
            printf("[%c ",arr[i]);
        else
            printf("%c ",arr[i]);
        if(i == up -2)
            printf("]");
    }
    printf("Piviot : %d -> %c\n",j,arr[j]);

}

int Partition(char *arr, int p, int q)
{
    char v = arr[p];
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
            char temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);

    arr[p] = arr[j];
    arr[j] = v;
    return j;
}

char Select(char *arr, int n, int k)
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
        return '0';
    }
}

int main()
{
    char arr[] = { 'T', 'J', 'F', 'R', 'I', 'V','L', 'N', 'Z', 'B', 'U', CHAR_MAX};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int k;
    printf("Given array : ");
    for(int i = 0; i < arr_size -1; i++)
        printf("%c  ",arr[i]);

    printf("\n Enter the k for the kth smallest element : ");
    scanf("%d",&k);

    char value = Select(arr,arr_size, k-1);
    if(value != '0')
        printf("Element at %d position is : %c\n",k,value);

    return 0;

}