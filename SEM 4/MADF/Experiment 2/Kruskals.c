#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>

typedef struct node
{
    int x, y, cost;
} unit;

void PrintHeap(unit *heap, int n)
{
    for(int i =0; i<n; i++)
    {
        printf("\nx : %d  y : %d  cost : %d",heap[i].x,heap[i].y,heap[i].cost);
    }
}

void PrintParent(int* parent, int n, unit min, int x)
{
    printf("\nstep%d (%d,%d) ",x,min.x,min.y);
    for(int i = 0; i<n; i++)
    {
        if(parent[i] < 0)
        printf("%d   ",parent[i]);
        else
        printf(" %d   ",parent[i]);
    }
}

void PrintMCSTree(unit *MCSTree, int n)
{
    printf("\n\nsrc dest  cost\n");
    for(int i =0; i<n; i++)
    {
        printf("%d   %d  :  %d\n",MCSTree[i].x,MCSTree[i].y,MCSTree[i].cost);
    }
}

int InsertinHeap(unit *heap, int n)
{
    int i = n;
    unit item = heap[n];
    while((i > 0) && (heap[i/2].cost > item.cost))
    {
        heap[i] = heap[i/2];
        i = i/2;
    }
    heap[i] = item;
    return 1;
}

void CreateHeap(unit *heap, int n, int n1)
{
    int x, y, cost, pos = 0;
    while(pos < n)
    {
        printf("\nEnter an Edge (x y) and its cost, (-1 -1 to exit) : \n");
        scanf("%d%d%d",&x,&y,&cost);

        if(x < 0 && y < 0)
            break;
        else if(x < 0 || y < 0 || x >n1 || y>n1)
        {
            printf("\nEnter a valid edge");
        }
        else{
            heap[pos].x = x;
            heap[pos].y = y;
            heap[pos].cost = cost;
            InsertinHeap(heap, pos); 
            pos++;
            //PrintHeap(heap,pos);
        }
    }
}

void Adjust(unit *heap, int i, int n)
{
    int j = (2 * i) + 1;
    unit item = heap[i];
    while(j < n)
    {
        if(j+1 < n && heap[j].cost > heap[j+1].cost)
            j++;
        if(item.cost <= heap[j].cost)
            break;
        heap[(int)ceil(((float)j)/2)-1] = heap[j];
        j = (j*2)+1;
    }
    heap[(int)ceil((float)j/2)-1] = item;
}

void Heapify(unit *heap, int n)
{   
    for(int i =(n/2)-1; i > 0; i--)
    {
        Adjust(heap,i,n);
    }
}

void DelMin(unit *heap, int n, unit * item)
{
        if(n < 0)
        {
            printf("\nThe Heap is Empty !");
            return;
        }
    *item = heap[0];
    heap[0] = heap[n-1];
    Adjust(heap,0,n-1);
}

int Find(int i, int* parent)
{
    while(parent[i] >= 0)
        i = parent[i];
    return i;
}

void Union(int i, int j, int *parent)
{
    parent[i] = j;
}

int Kruskals(unit *heap, int nVer,int nEdges, unit *MCSTree)
{
    int *parent = malloc(sizeof(int) * nVer);
    for(int i = 0; i<nVer; i++)
    {
        parent[i] = -1; 
    }
    int i = 0, j, k, nEdgeCount = nEdges;
    int minCost = 0;
    unit min;
    
    printf("\n\n\t   ");
    for(int c = 0; c<nVer; c++)
        printf(" [%d] ",c);
    printf("\nparent\t   ");
    for(int c = 0; c<nVer; c++)
        printf(" %d  ",parent[c]);
    
    while(i < nVer - 1 && i < nEdges)
    {
        DelMin(heap,nEdgeCount--,&min);
        Heapify(heap,nEdgeCount);
        j = Find(min.x-1, parent);
        k = Find(min.y-1,parent);
        if(j != k)
        {
            MCSTree[i] = min;
            i++;
            minCost += min.cost;
            Union(j,k,parent);
            PrintParent(parent,nVer,min, i);
        }
    }
    PrintMCSTree(MCSTree,nVer-1);
    if(i != nVer-1)
        printf("\nNo Spanning Tree");
    else return minCost;
    return -1;
}

int main()
{
    int nEdges, nVert;

    printf("Enter number of edges : ");
    scanf("%d",&nEdges);
    printf("Enter number of vertices : ");
    scanf("%d",&nVert);

    unit *heap = malloc(sizeof(unit)*nEdges);
    unit *MCSTree = malloc(sizeof(unit)*(nVert-1));
    CreateHeap(heap,nEdges,nVert);

    int minCost = Kruskals(heap,nVert,nEdges,MCSTree);
    printf("\nThe minimum cost is : %d\n",minCost);

}
// 15 8
// 1 2 2 1 4 2 1 5 3 2 3 4 2 4 1 2 5 2 3 5 3 3 6 1 4 5 1 4 7 2 5 6 3 5 7 1 5 8 2 7 8 1 8 6 1