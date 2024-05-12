#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

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

int FindMinEdge(int **C, int n, int j, int *cost)
{
    int k = 0;
    int optimalcost = INT_MAX;
    for(int i=0; i<n; i++)
    {
        if((C[j][i] != INT_MAX && j != i))
        {
            if(C[j][i] + cost[i] < optimalcost)
            {
                k = i;
                optimalcost= C[j][i] + cost[i];
            }
        }
            
    }
    return k;
}

void PrintPath(int *path, int k)
{
    printf("\nShortest Path :\n");
    for(int i=0; i<k; i++)
    {
        if(i==k-1)
            printf(" %d ",path[i]+1);
        else    
            printf(" %d ->",path[i]+1);
    }
}

void PrintTable(int**C, int*cost, int*path, int *stages, int *d, int n, int k)
{   
    int l = k-2;
    printf("\nVertex\t\t\tCost\t\t\tMinimum Values Considered\n");
    for (int i = n - 2; i >= 0; i--)
    {
        if (path[l] == i){
            printf("|d[%d,%d]|=|%d|\t\tcost[%d,%d]=%d\t\t\tmin(", stages[i], i + 1, d[i] + 1, stages[i], i + 1, cost[i]);
        }
        else
            printf("d[%d,%d]=%d\t\tcost[%d,%d]=%d\t\t\tmin(", stages[i], i + 1, d[i] + 1, stages[i], i + 1, cost[i]);
        int first = 1; // Flag to handle printing comma
        for (int j = i + 1; j < n; j++)
        {
            if (C[i][j] != INT_MAX)
            {
                if (!first)
                {
                    printf(", ");
                }
                printf("%d", cost[j]+C[i][j]);
                first = 0;
            }
        }
        printf(")"); 
        if (path[l] == i)
        {                      
            printf(" [Path]"); 
            l--;
        }
        printf("\n");
    }
}

void CalculateSortestPath(int**C, int*cost, int*path, int n, int k)
{
    int D[100] = {INT_MAX};
    int stages[100] = {-1};
    cost[n-1] = 0; 
    D[n-1] = n-1;
    stages[n-1] = k;
    for(int j=n-2; j>=0; j--)
    {
        int r = FindMinEdge(C,n,j,cost);
        cost[j] = C[j][r] + cost[r];
        D[j] = r;
        stages[j] = stages[D[j]]-1;
    }
    path[0]=0;
    path[k-1]=n-1;
    
    for(int j = 1; j<=k-1; j++)
    {
        path[j] = D[path[j-1]];
    }
    PrintTable(C,cost,path,stages,D,n,k);

    printf("\nMinimum Cost: %d\n",cost[0]);
}

int main()
{

    int **C;
    int *cost;
    int *path;
    int n, k;
    printf("Enter the number of vertices : ");
    scanf("%d",&n);
    printf("Enter number of stages : ");
    scanf("%d",&k);

    C = malloc(sizeof(*C)*n);
    cost = malloc(sizeof(*cost)*n);
    path = malloc(sizeof(*path)*k);

    for(int i=0; i<n; i++)
    {
        C[i] = malloc(sizeof(*C[i])*n);
    }

    CreateWeightedGraph(C,n);
    CalculateSortestPath(C,cost,path,n,k);
    PrintPath(path,k);
    
}

// 1 2 13 1 3 12 1 4 18 1 5 17 2 6 16 2 8 15 3 7 11 3 9 12 4 6 11 4 8 13 5 7 11 5 9 12 6 10 14 6 11 15 6 12 11 7 10 10 7 11 5 7 12 12 8 11 11 8 12 10 9 11 8 9 12 10 10 13 9 11 13 8 12 13 5

/*
1 2 13
1 3 12
1 4 18
1 5 17
2 6 16
2 8 15
3 7 11
3 9 12
4 6 11
4 8 13
5 7 11
5 9 12
6 10 14
6 11 15
6 12 11
7 10 10
7 11 8
7 12 12
8 11 11
8 12 10
9 11 8
9 12 10
10 13 9
11 13 8
12 13 7
-1-1

*/