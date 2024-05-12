#include<stdio.h>
#include<stdlib.h>

#define INT_MAX 99999


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

void RPrint(int *pred, int source, int j)
{
    if(j == source)
        printf("%d",source+1);
    else{
        RPrint(pred,source,pred[j]);
        printf("->%d",j+1);
    }   
}

void Print(int *dist, int n, int v, int *pred)
{
    printf("sr dist lenght path");
        for(int j=0; j<n; j++)
        {
            if(v!=j)
            {
                printf("\n%d  %d    %2d     ",v+1,j+1,dist[j]);
                RPrint(pred,v,j);
            }
        }
}

void BellmenFord(int **cost, int n, int* dist, int v)
{
    int oldDist[n], pred[n];
    for(int i=0; i<n; i++)
    {
        dist[i] = cost[v][i];
        oldDist[i] = dist[i];
        pred[i] = v;
    }
    printf("Vertex     ");
    for(int i=0; i<n; i++)
    {
        printf(" [%d] ",i+1);
    }
    printf("\nDistance   ");
    for(int i=0; i<n; i++)
    {
        if(dist[i] == INT_MAX)
                printf(" inf ");
            else
                printf(" %3d ",dist[i]);
    }printf("\nPredcessor ");
    for(int i=0; i<n; i++)
    {
        printf("  %d  ", pred[i]+1);
    }printf("\n");

    for(int k=0; k<n-2; k++){
        for(int i=0; i<n; i++)
        {
            for(int u=0; u<n; u++)
            {
                if(u!=v)
                {   
                    if(dist[u] > (oldDist[i] + cost[i][u]))
                    {
                        if(oldDist[i] == INT_MAX && cost[i][u] == INT_MAX)
                            dist[u] = INT_MAX;
                        else{
                            dist[u]=(oldDist[i] + cost[i][u]);
                            pred[u] = i;
                        }
                    }
                }
            }
        }
        //output section
        printf("\nDistance   ");
        for(int j=0; j<n; j++)
        {
            if(dist[j] < oldDist[j])
            {
                printf(" \033[4m%3d\033[24m ",dist[j]);
            }
            else if(dist[j] == INT_MAX)
                printf(" inf ");
            else
                printf(" %3d ",dist[j]);
        }
        printf("\nPredcessor ");
        for(int j=0; j<n; j++)
        {
            if(dist[j] < oldDist[j])
            {
                printf(" \033[4m[%d]\033[24m ",pred[j]+1);
                oldDist[j] = dist[j];
            }
            else
                printf("  %d  ",pred[j]+1);        
        }
        printf("\n");
    }printf("\n");
    Print(dist,n,v,pred);
}


int main()
{
    int n, v;
    int** cost, *dist;
    
    printf("Enter the number of vertices in the graph : ");
    scanf("%d",&n);
    
    cost = malloc(sizeof(*cost)*n);
    dist = malloc(sizeof(dist)*n);
    for(int i=0; i<n; i++)
    {
        cost[i]=malloc(sizeof(*cost[i])*n);
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &v);

    CreateWeightedGraph(cost,n);

    BellmenFord(cost,n,dist,v-1);

    printf("\n");
    return 0;
}

// 1 2 4 1 4 5 1 6 2 2 3 2 2 4 -6 3 5 -4 3 7 -4 4 3 3 4 5 -1 4 6 -3 5 4 5 5 6 -2 5 7 1 6 7 3 7 1 3 7 5 -1 7 6 -2