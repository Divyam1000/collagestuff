#include<stdio.h>
#include<stdlib.h>

struct Edge;
struct Vertex{
    int info;
    struct Vertex* nextVertex;
    struct Edge *firstedge;
}*start = NULL;

struct Edge{
    struct Vertex *destVertex;
    struct Edge *nextEdge;
};

void insertVertex(int u)
{
    struct Vertex *tmp, *ptr;
    tmp = malloc(sizeof(struct Vertex));
    tmp->info = u;
    tmp->nextVertex = NULL;
    tmp->firstEdge = NULL;
    if(start == NULL){
        start = tmp;
        return;
    }
    ptr = start;
    while(ptr->nextVertex != NULL)
        ptr = ptr->nextVertex;
    ptr->nextVertex = tmp;
}

struct Vertex *findVertex(int u)
{
    struct Vertex *ptr, *loc;
    ptr = start;
    while(ptr != NULL){
        if(ptr->info == u){
            loc = ptr;
            return loc;
        }
        else ptr = ptr->nextVertex;
    }
    loc = NULL;
    return loc;
}

void insertEdge(int u, int v)
{
    struct Vertex *locu, *locv;
    struct Edge *ptr, *tmp;
    locu = findVertex(u);
    locv = findVertex(v);
    if(locu == NULL){
        printf("Start vertex not present, first insert vertex %d\n",u);
        return;
    }
    if(locv == NULL){
        printf("End vertex not present, first insert vertex %d\n",u);
        return;
    }
    tmp = malloc(sizeof(struct Edge));
    tmp->destVertex = locv;
    tmp->nextEdge = NULL;
    if(locu->firstedge == NULL){
        locu->firstedge = tmp;
        return;
    }
    ptr = locu->firstedge;
    while(ptr->nextEdge ! = NULL)
        ptr = ptr->nextEdge;
        ptr->nextEdge = tmp;
}

void deleteVertex(int u)
{
    struct Vertex *tmp, *q;
    struct Edge *p, *temp;
    if(start == NULL){
        printf("No vertices to be deleted\n");
        return;
    }
    if(start->info == u){
        tmp = start;
        start = start->nextVertex;
    }

}

void deleteEdge(int u, int v)
{


}

void display()
{

}


int main()
{
    int choice,u,origin,destin;
    while(1){
        printf("1. Insert a vertex\n2. Insert an Edge\n3. Delete an Vertex\n4. Delete an Edge\n5. Display\n6. Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
    case 1:

        break;
    case 2:

        break;
    case 3:

        break;
    case 4:

        break;
    case 5:
        break;
    case 6:
        return 0;
    default:
        printf("Invlaid input!\n");
        }
    }
}
