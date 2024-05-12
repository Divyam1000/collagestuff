#include<stdio.h>
#include<stdlib.h>

int arrSize;

typedef struct Array
{
    int **arr;
    int row;
    int col;
} array;

void InitArray(array * arr, int n, int r, int c)
{
    arr->arr = malloc(n*sizeof(int*));
    for(int i=0; i<n; i++){
        arr->arr[i] = malloc(n*sizeof(int));
    }
    arr->row = r;
    arr->col = c;
}

void Add(array A, array B, array C, int Dimension)
{
    for(int i = 0; i< Dimension; i++ )
    {
        for(int j = 0; j < Dimension; j++)
        {
            C.arr[C.row + i][C.col + j] = A.arr[A.row + i][A.col + j] + B.arr[B.row + i][B.col + j];
        }
    }
}


void Multiply(array A, array B, array C, int Dimension)
{
    int mid = Dimension/2;
    if(Dimension < 2 && Dimension == 1)
    {
        C.arr[C.row][C.col] = A.arr[A.row][A.col] * B.arr[B.row][B.col]; 
    }
    
// intialising temprory variables

    array temp1, temp2;
    InitArray(&temp1,mid,0,0);
    InitArray(&temp2,mid,0,0);







    for(int i=0; i<mid; i++)
    {
        free(temp1.arr[i]);
        free(temp2.arr[i]);
    }
    free(temp1.arr);
    free(temp2.arr);

}


int main()
{
    int n;

    printf("Enter size of square matrix : ");
    scanf("%d",&n);
    arrSize = n;

    array A, B, C;
    
    InitArray(&A,n,0,0);
    InitArray(&B,n,0,0);
    InitArray(&C,n,0,0);



    printf("Enter array elements of array A : \n");
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &A.arr[i][j]);

    printf("Enter array elements of array B : \n");
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &B.arr[i][j]);



}
