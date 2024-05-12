#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct _Path
{
    int* list; 
    int n;
}path;

void CreateWeightedGraph(int **cost, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i != j)
                cost[i][j] = INT_MAX;
            else
                cost[i][j] = 0;
        }
    }

    int x,y,weight;
    while(1)
    {
        printf("Enter edge (x, y) Enter (-1 -1) to exit: \n");
        scanf("%d%d",&x,&y);
        if(--x >= n || --y >= n)
        {
            printf("Node exceeds size limit\nEnter again\n");

        }
        else if(x < 0 && y < 0 )
        {
            break;
        }
        else{
            if(cost[x][y] != INT_MAX)
            {
                printf("An edge already exists at (%d , %d)",x,y);
                continue;
            }
            printf("Enter Weight(cost) of edge : ");
            scanf("%d",&weight);
            cost[x][y] = weight;
        }
    }

}

int min(int a, int b)
{   
    return (a < b ? a : b);
}   

void Print(int **A, int n, path **P)
{
    printf("sr dist lenght path\n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i!=j)
            {
                printf("%d  %d    %2d     ",i+1,j+1,A[i][j]);
                for(int k=0; k<P[i][j].n; k++)
                {
                    if(k != P[i][j].n-1)
                        printf("%d->",P[i][j].list[k]);
                    else
                        printf("%d\n",P[i][j].list[k]);
                }
            }
        }
        printf("------------------------\n");
    }
}

void EditPath(int i, int j, int k, path **P)
{
    int l=0, m=1;
    P[i][j].n = P[i][k].n + P[k][j].n - 1;
    free(P[i][j].list);
    P[i][j].list = malloc(sizeof(int)*P[i][j].n);
    while( l<P[i][k].n)
        P[i][j].list[l] = P[i][k].list[l++];
    while( m<P[k][j].n)
        P[i][j].list[l++] = P[k][j].list[m++];
}

void PrintMatrix(int**A, int n, int count)
{   
    printf("A%d:\n",count);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(A[i][j] == INT_MAX)
                printf(" IN");
            else
                printf(" %2d",A[i][j]);
        }
        printf("\n");
    }   
    printf("\n");
}

void AllSourceShortestPath(int **cost, int n, int **A, path **pathMatrix)
{
    int minimun;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            A[i][j] = cost[i][j];
            if(A[i][j] != INT_MAX)
            {
                if(A[i][j] == 0){
                    pathMatrix[i][j].list = malloc(sizeof(int)*1);
                    pathMatrix[i][j].n = 1;
                    pathMatrix[i][j].list[0] = i+1;
                }
                else{
                    pathMatrix[i][j].list = malloc(sizeof(int)*2);
                    pathMatrix[i][j].n = 2;
                    pathMatrix[i][j].list[0] = i+1;
                    pathMatrix[i][j].list[1] = j+1;
                }
            }
        }
    PrintMatrix(A,n,0);
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                minimun = min(A[i][j], A[i][k] + A[k][j]);
                if(minimun < A[i][j])
                {
                    EditPath(i,j,k,pathMatrix);
                    A[i][j] = minimun;
                }
            }
        PrintMatrix(A,n,k+1);
    }
}

int main()
{
    int n;
    int** cost, **A;
    path **pathMatrix;

    
    printf("Enter the number of vertices in the graph : ");
    scanf("%d",&n);
    
    cost = malloc(sizeof(*cost)*n);
    A = malloc(sizeof(*A)*n);
    pathMatrix = malloc(sizeof(*pathMatrix)*n);
    for(int i=0; i<n; i++)
    {
        cost[i]=malloc(sizeof(*cost[i])*n);
        A[i]=malloc(sizeof(*A[i])*n);
        pathMatrix[i]=malloc(sizeof(*pathMatrix[i])*n);
    }
    CreateWeightedGraph(cost,n);

    AllSourceShortestPath(cost,n,A,pathMatrix);
    Print(A,n, pathMatrix);

    printf("\n");
    return 0;
}

/*
1 2 -2 1 3 -4 1 4 3 1 5 -1 2 1 3 2 3 2 2 4 2 2 5 4 3 1 6 3 2 2 3 4 2 3 5 4 4 1 3 4 2 2 4 3 2 4 5 3 5 1 5 5 3 -3 5 4 3 5 2 4
*/