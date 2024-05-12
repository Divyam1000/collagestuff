#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


void MinCostEdge(int **cost, int n, int *x, int *y)
{
    int smallest = cost[0][0];
    *x = *y = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n ;j++)
        {
            if(cost[i][j] < smallest)
            {
                smallest = cost[i][j];
                *x = i; *y = j;
            }
        }
    }
}

int NearestEdge(int *near,int **cost, int n)
{
    int nearest = -1,minCost = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        if(cost[i][near[i]] < minCost && near[i] != -1)
        {
            nearest = i;
            minCost = cost[i][near[i]];
        }
    }
    return nearest;
}
void PrintMCSTree(int **MCSTree,int**cost,int n)
{
    printf("\n    src   dest   cost\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d]  ",i+1);
        printf("%d     ",MCSTree[i][0]+1);
        printf("%d     ",MCSTree[i][1]+1);
        printf("%d\n",cost[MCSTree[i][0]][MCSTree[i][1]]);
    }
}
void PrintNearCost(int *near, int **cost, int n)
{
    printf("\nnear  ");
    for(int i= 0; i<n; i++)
    {
        if(near[i] == -1)
            printf("  0  ");
        else
            printf("  %d  ",near[i]+1);
    }
    printf("\ncost  ");
    for(int i= 0; i<n; i++)
    {
        if(cost[i][near[i]] == INT_MAX)
            printf(" INF ");
        else if(near[i] == -1)
            printf(" --- ");
        else
            printf("  %d  ",cost[i][near[i]]);
    }printf("\n");

}

int Prims(int **edge, int **cost, int **MCSTree, int n)
{
    int minCost = 0;
    int x,y;
    int *near;
    near = malloc(n*sizeof(int));

    MinCostEdge(cost,n,&x,&y);
    minCost = cost[x][y];

    MCSTree[0][0] = x;
    MCSTree[0][1] = y;

    for(int i = 0; i < n; i++)
    {
        if(cost[i][x] < cost[i][y])
            near[i] = x;
        else
            near[i] = y;
    }
    near[x] = near[y] = -1;
    printf("\nindex ");
    for(int i = 0; i <n; i++)
    {
        printf(" [%d] ",i+1);
    }printf("\n");
    PrintNearCost(near,cost,n);
    PrintMCSTree(MCSTree,cost,1);

    for(int i = 1; i < n-1; i++)
    {
        int minEdge = NearestEdge(near,cost,n);
        MCSTree[i][0] = minEdge;
        MCSTree[i][1] = near[minEdge];
        minCost = (minCost + cost[minEdge][near[minEdge]]);
        near[minEdge] = -1;

        for(int j = 0; j < n; j ++)
        {
            if(near[j] != -1 && (cost[j][near[j]] > cost[j][minEdge]))
                near[j] = minEdge;
        }
        PrintNearCost(near,cost,n);
        PrintMCSTree(MCSTree,cost,i+1);
    }

    return minCost;
}

void CreateWeightedGraph(int **edge, int **cost, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            edge[i][j] = 0;
            cost[i][j] = INT_MAX;
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
            if(edge[x][y] == 1)
            {
                printf("An edge already exists at (%d , %d)",x,y);
                continue;
            }
            printf("Enter Weight(cost) of edge : ");
            scanf("%d",&weight);

            edge[x][y] = 1;
            edge[y][x] = 1;
            cost[x][y] = weight;
            cost[y][x] = weight;
        }
    }

}

int main()
{
    int n;
    printf("Enter number of nodes : ");
    scanf("%d",&n);
    int **edge, **cost, **MCSTree;

    edge = malloc(n*sizeof(*edge));
    cost = malloc(n * sizeof(*cost));
    MCSTree = malloc(n * sizeof(*MCSTree));

    for(int i =0; i < n; i++)
    {
        edge[i] = malloc(n* sizeof(*edge[i]));
        cost[i] = malloc(n* sizeof(*cost[i]));
        MCSTree[i] = malloc(2* sizeof(*edge[i]));
    }

    CreateWeightedGraph(edge,cost,n);

    int minCost = Prims(edge,cost,MCSTree,n);

    printf("\nThe minimum cost is : %d\n",minCost);

}

// 1 2 2 1 4 2 1 5 3 2 3 4 2 4 1 2 5 2 3 5 3 3 6 1 4 5 1 4 7 2 5 6 3 5 7 1 5 8 2 7 8 1 8 6 1