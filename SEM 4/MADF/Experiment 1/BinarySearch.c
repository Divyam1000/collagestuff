#include<stdio.h>
#include<stdlib.h>

int sizeOfArr;

void PrintArray(char *arr, int i, int j)
{   
    for(int k =0; k < sizeOfArr; k++)
    {
        if(k == i)
            printf("[%c ",arr[k]);
        else if(k == j)
            printf("%c] ",arr[k]);
        else
            printf(" %c ",arr[k]);
    }
    printf("\n");
}
 
int BinarySerach(char skey, char *arr, int i, int j)
{
    int mid = (i + j) / 2;
    PrintArray(arr,i,j);
    if(arr[mid] == skey)
    {
        return mid;
    }
    else if(i == j)
    {
        return -1;
    }
    else if(skey < arr[mid])
    {
        j = mid;
        return BinarySerach(skey,arr,i,j);
    }
    else if(skey >  arr[mid])
    {
        i = mid + 1;
        return BinarySerach(skey,arr,i,j);
    }
}

int main()
{
    char *arr;
    char skey;

    printf("Enter size of array : ");
    scanf("%d",&sizeOfArr);

    arr = (char*)malloc(sizeOfArr * sizeof(char) );
    printf("Enter the elements of the array:\n");
    getchar();
    for(int i = 0; i < sizeOfArr; i++)
    {
        scanf("%c",&arr[i]);getchar();
    }
    printf("Enter element to search : ");
    scanf("%c",&skey);

    int pos = BinarySerach(skey,arr, 0, sizeOfArr-1);
    if(pos != -1)
        printf("%c found at pos %d\n", skey, pos+1);
    else
        printf("%c not found in array ", skey);

    return 0;
}


// B E J K N O P R S V W