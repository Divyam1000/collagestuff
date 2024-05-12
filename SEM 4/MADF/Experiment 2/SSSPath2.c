#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

#define false 0
#define true 1

int iter = 0;

void CreateWeightedGraph(int **cost, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
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

void Print(int *dist, int *S, int n, int u)
{
    if(iter == 0)
    {
        printf("\nIteration   Vertex                Distance");
        printf("\n            Selected   ");
        for(int i=1; i<=n; i++)
            printf("[%d]  ",i);
        printf("\nInitial         --     ");
        for(int i=0; i<n; i++){
            if(dist[i] == INT_MAX)
                printf("INF  ");
            else
                printf("%3d  ",dist[i]);
        }
    }
    else
    {
        printf("\n%7d      \t %d   ",iter,u+1);
        for(int i=0; i<n; i++){
            if(dist[i] == INT_MAX)
                printf("  INF");
            else
                printf("%5d",dist[i]);
        }
        printf("  S : {");
        for(int j=0; j<n; j++)
            if(S[j] == true)
                printf("%d,",j+1);
        printf("}");
    }
}


int NearestVertex(int *S, int *dist,int n)
{
    int shortestDistance = INT_MAX;
    int shortest = -1;
    for(int i = 0; i<n; i++)
    {
        if(S[i] == true)
            continue;
        else{
            if(dist[i] < shortestDistance)
            {
                shortestDistance = dist[i];
                shortest = i;
            }
        }
    }
    return shortest;
}

void PrintPath(int *pred, int j)
{
    if(j == 0)
        printf("1");
    else
    {
        PrintPath(pred,pred[j]);
        printf("->%d",j+1);
    }
}

void PrintPaths(int*dist, int*pred, int n)
{
    printf("src  dest  path\n");
    for(int i=0; i<n; i++)
    {
        printf(" 1    %d    ",i+1);
        PrintPath(pred,i);
        printf(" = %d\n",dist[i]);
    }
}

void SingleSourceShortestPath(int **cost, int n, int* dist, int source,int *pred)
{
    int *S = malloc(sizeof(int)*n);
    int shortest;
    for(int i=0; i<n; i++)
    {
        S[i] = false; 
        dist[i] = cost[source][i];
    }
    S[source] = true;
    dist[source] = 0;
    pred[0] = 0;
    Print(dist,S,n,0);

    for(int i = 1; i<n-1; i++)
    {
        shortest = NearestVertex(S,dist,n);
        S[shortest] = true;
        
        for(int j=0; j<n; j++)
        {
            if(cost[shortest][j] != INT_MAX && S[j] == false)
            {
                if (dist[j] > dist[shortest] + cost[shortest][j])
                {
                    dist[j] = dist[shortest] + cost[shortest][j];
                    pred[j] = shortest;
                }
            }
        }
        iter++;
        Print(dist,S,n,shortest);
    }printf("\n");
    PrintPaths(dist,pred,n);
}

int main()
{
    int n;
    int** cost, *dist, *pred;
    
    printf("Enter the number of vertices in the graph : ");
    scanf("%d",&n);
    
    cost = malloc(sizeof(*cost)*n);
    dist = malloc(sizeof(int)*n);
    pred = malloc(sizeof(*pred)*n);
    for(int i=0; i<n; i++)
        cost[i]=malloc(sizeof(*cost[i])*n);
    
    CreateWeightedGraph(cost,n);
    for (int i = 1; i <= n; i++)
        pred[i] = 0;
    SingleSourceShortestPath(cost,n,dist,0,pred);
    printf("\n");
    
    return 0;
}

// 1 2 40 1 3 20 1 4 10 1 5 50 1 7 60 2 5 5 2 3 1 3 5 2 3 6 10 3 7 2 4 3 5 4 7 5 5 6 3 5 8 5 6 8 5 6 7 3 7 8 3 8 2 2 8 4 5 8 3 1 -1 -1