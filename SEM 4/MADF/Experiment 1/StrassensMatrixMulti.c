#include<stdio.h>
#include<stdlib.h>

int arrSize;

typedef struct Matrix
{
    int **arr;
} matrix;

void InitMatrix(matrix * arr, int n)
{
    arr->arr = malloc(n*sizeof(*arr->arr));
    for(int i=0; i<n; i++){
        arr->arr[i] = malloc(n*sizeof(*arr->arr[i]));
    }
}

void PrintMatrix(matrix arr, int row, int col, int Dimension)
{
    for(int i=0; i<Dimension; i++){
        for(int j=0; j<Dimension; j++)
            printf("%d  ",arr.arr[i+row][j+col]);
        printf("\n");
    }
}

void Add(matrix A, int row1, int col1, matrix B, int row2, int col2, matrix C, int row3, int col3, int Dimension)
{
    for(int i = 0; i< Dimension; i++ )
    {
        for(int j = 0; j < Dimension; j++)
        {
            C.arr[row3 + i][col3 + j] = A.arr[row1 + i][col1 + j] + B.arr[row2 + i][col2 + j];
        }
    }
}

void Subtract(matrix A,int row1, int col1, matrix B, int row2, int col2, matrix C, int Dimension)
{
    for(int i = 0; i< Dimension; i++ )
    {
        for(int j = 0; j < Dimension; j++)
        {
            C.arr[i][j] = A.arr[row1 + i][col1 + j] - B.arr[row2 + i][col2 + j];
        }
    }
}

void Copy(matrix A ,int row, int col, matrix B, int Dimension)
{
    for(int i = 0; i< Dimension; i++ )
    {
        for(int j = 0; j < Dimension; j++)
        {
            B.arr[i][j] = A.arr[row + i][col + j];
        }
    }
}

void Multiply(matrix A, matrix B, matrix C, int Dimension)
{
    int mid = Dimension/2;
    if(Dimension < 2 && Dimension == 1)
    {
        C.arr[0][0] = A.arr[0][0] * B.arr[0][0]; 
        return;
    }
    
// intialising temprory variables

    matrix temp1, temp2, P, Q, R, S, T, U, V;
    InitMatrix(&temp1,mid);
    InitMatrix(&temp2,mid);
    InitMatrix(&P,mid);
    InitMatrix(&Q,mid);
    InitMatrix(&R,mid);
    InitMatrix(&S,mid);
    InitMatrix(&T,mid);
    InitMatrix(&U,mid);
    InitMatrix(&V,mid);

// finding values of equation by reccuresion

    // P = (A11 + A22)(B11 + B22)

        Add(A,0,0,A,mid,mid,temp1,0,0,mid);
        Add(B,0,0,B,mid,mid,temp2,0,0,mid);
    Multiply(temp1,temp2,P,mid);

    //Q = (A21 + A22)B11
        Add(A,mid,0,A,mid,mid,temp1,0,0,mid);
        Copy(B,0,0,temp2,mid);
    Multiply(temp1,temp2,Q,mid);
    
    //R = A11(B12 - B22)
        Copy(A,0,0,temp1,mid);
        Subtract(B,0,mid,B,mid,mid,temp2,mid);
    Multiply(temp1,temp2,R,mid);

    //S = A22(B21 - B11)
        Copy(A,mid,mid,temp1,mid);
        Subtract(B,mid,0,B,0,0,temp2,mid);
    Multiply(temp1,temp2,S,mid);

    //T = (A11 + A12)B22
        Add(A,0,0,A,0,mid,temp1,0,0,mid);
        Copy(B,mid,mid,temp2,mid);
    Multiply(temp1,temp2,T,mid);

    //U = (A21 - A11)(B11 + B12)
        Subtract(A,mid,0,A,0,0,temp1,mid);
        Add(B,0,0,B,0,mid,temp2,0,0,mid);
    Multiply(temp1,temp2,U,mid);

    //V = (A12 - A22)(B21 + B22)
        Subtract(A,0,mid,A,mid,mid,temp1,mid);
        Add(B,mid,0,B,mid,mid,temp2,0,0,mid);
    Multiply(temp1,temp2,V,mid);

// adding to final result

    //C11 = P + S - T + V
        Add(P,0,0,V,0,0,temp1,0,0,mid);
        Subtract(S,0,0,T,0,0,temp2,mid);
    Add(temp1,0,0,temp2,0,0,C,0,0,mid);

    //C12 = R + T
    Add(R,0,0,T,0,0,C,0,mid,mid);

    //C21 = Q + S
    Add(Q,0,0,S,0,0,C,mid,0,mid);

    //C22 = P + R - Q + U
        Add(P,0,0,U,0,0,temp1,0,0,mid);
        Subtract(R,0,0,Q,0,0,temp2,mid);
    Add(temp1,0,0,temp2,0,0,C,mid,mid,mid);


//Printing the output of Intermediate metrices

    printf("Intermediate Matrices of %d*%d matrix\n",Dimension,Dimension);

    printf("P: \n");
    PrintMatrix(P,0,0,mid);

    printf("Q: \n");
    PrintMatrix(Q,0,0,mid);

    printf("R: \n");
    PrintMatrix(R,0,0,mid);

    printf("S: \n");
    PrintMatrix(S,0,0,mid);

    printf("T: \n");
    PrintMatrix(T,0,0,mid);

    printf("U: \n");
    PrintMatrix(U,0,0,mid);

    printf("V: \n");
    PrintMatrix(V,0,0,mid);

    printf("C11: \n");
    PrintMatrix(C,0,0,mid);

    printf("C12: \n");
    PrintMatrix(C,0,mid,mid);

    printf("C21: \n");
    PrintMatrix(C,mid,0,mid);

    printf("C22: \n");
    PrintMatrix(C,mid,mid,mid);


    for(int i=0; i<mid; i++)
    {
        free(temp1.arr[i]);
        free(temp2.arr[i]);
        free(P.arr[i]);
        free(Q.arr[i]);
        free(R.arr[i]);
        free(S.arr[i]);
        free(T.arr[i]);
        free(U.arr[i]);
        free(V.arr[i]);
    }
    free(temp1.arr);
    free(temp2.arr);
    free(P.arr);
    free(Q.arr);
    free(R.arr);
    free(S.arr);
    free(T.arr);
    free(U.arr);
    free(V.arr);
}

int main()
{
    int n;

    printf("Enter size of square matrix : ");
    scanf("%d",&n);
    arrSize = n;

    matrix A, B, C;
    
    InitMatrix(&A,n);
    InitMatrix(&B,n);
    InitMatrix(&C,n);

    printf("Enter matrix elements of matrix A : \n");
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &A.arr[i][j]);

    printf("Enter matrix elements of matrix B : \n");
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &B.arr[i][j]);

    Multiply(A,B,C,n);

    printf("Matrix Multiplication of A * B\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            printf("%d  ",C.arr[i][j]);
        printf("\n");
    }

    return 0;
}
