#include<stdio.h>
#include<stdlib.h>

struct block
{
    int low, high, min, max,space;
};
struct block *stack = NULL;
int stackTop = -1;
int space  = -1;



void PrintSearchTree()
{
    for(int i = stackTop; i >= 0; i-- )
    {
        for(int j = 1; j <= stack[i].space; j++){
                printf("     ");
        }
        printf("low : %d, high : %d, min : %d, max : %d\n",stack[i].low,stack[i].high,stack[i].min,stack[i].max);

    }
}

void MinMax(int *arr, int i, int j, int *min, int *max)
{
    int min1, min2, max1, max2, mid;
    space++;
    if(i == j -1)
    {
        if(arr[i] < arr[j])
        {
            *min = arr[i];
            *max = arr[j];
        }
        else{
            *min = arr[j];
            *max = arr[i];
        }
    }

    else if(i == j)
    {
        *max = *min = arr[i];
    }

    else{
        mid = (i+j)/2 ;
        MinMax(arr, i, mid, &min1, &max1);
        MinMax(arr, mid+1, j, &min2, &max2);
        if( max1 < max2)
            *max = max2;
        else
            *max = max1;
        if(min1 > min2)
            *min = min2;
        else
            *min = min1;
    }

    stack[++stackTop].low = i;
    stack[stackTop].high = j;
    stack[stackTop].min = *min;
    stack[stackTop].max = *max;
    stack[stackTop].space = space;
    space--;
}


int main()
{
    int arr[] = {83,10,77,43,95,-5,12,81,39};
    int min, max;
    int n = sizeof(arr) / sizeof(arr[0]);
    stack = (struct block*)malloc(sizeof(struct block)*n);
    MinMax(arr,0,n-1,&min,&max);
    PrintSearchTree();
    printf("Min : %d\nMax : %d",min,max);

}
