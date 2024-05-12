#include<stdio.h>
#include<stdlib.h>

#define MAX 100
#define initial 1
#define waiting 2
#define visited 3

int adj[MAX][MAX];
int n;
int state[MAX];

int queue[MAX], front = -1, rear = -1;

int stack[MAX], top = -1;


void create_graph()
{
    int max_edges, i, origin, destin;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    max_edges = n*(n-1);
    for(i = 1; i<=max_edges; i++){
        printf("Enter edge %d(-1 -1 to quit): ",i);
        scanf("%d %d",&origin,&destin);
        if(origin == -1 && destin == -1)
            break;
        if(origin >= n || destin >= n || origin < 0 || destin < 0){
            printf("invalid vertex!\n");
            i--;
        }
        else
            adj[origin][destin] = 1;
    }
}

void insert_edge(int origin, int destin)
{
    if(origin <0 || origin>=n){
        printf("origin vertex does not exist!\n");
        return;
    }
    if(destin<0 || destin>=n){
        printf("destination vertex does not exist!\n");
        return;
    }
    adj[origin][destin] = 1;
}

void display()
{
    int i,j;
    for(i = 0; i<n; i++){
        for(j = 0; j<n; j++)
            printf("%4d",adj[i][j]);
        printf("\n");
    }
}

//Breadth First Search

void insert_queue(int vertex)
{
    if(rear == MAX -1)
        printf("Queue Overflow!\n");
    else{
        if(front == -1)
            front = 0;
        rear = rear + 1;
        queue[rear] = vertex;
    }
}

int delete_queue()
{
    int del_item;
    if(front == -1 || front >rear){
        printf("Queue Underflow!\n");
        exit(1);
    }
    del_item = queue[front];
    front = front + 1;
    return del_item;
}

int isEmpty_queue()
{
    if(front == -1 || front > rear){
        return 1;
    }
    else{
        return 0;
    }
}

void BFS(int v)
{
    int i;
    insert_queue(v);
    state[v] = waiting;
    while(!isEmpty_queue()){
        v = delete_queue();
        printf("%d\t",v);
        state[v] = visited;
        for(i = 0; i<n; i++){
            if(adj[v][i] == 1 && state[i] == initial){
                insert_queue(i);
                state[i] = waiting;
            }
        }
    }
    printf("\n");
}

void BF_traversal(){
    int v;
    for(v = 0; v<n; v++)
        state[v] = initial;
    printf("Enter starting vertex for breadth first traversal: ");
    scanf("%d",&v);
    BFS(v);
    for(v =0; v<n; v++)
        if(state[v] == initial)
            BFS(v);
}

int isEmpty_stack()
{
    if(top == -1)
        return 1;
    else return 0;
}

int pop()
{
    int v;
    if(top == -1){
        printf("Stack Underflow\n");
        exit(1);
    }
    v = stack[top];
    top = top-1;
    return v;
}
void push(int v)
{
    if(top == MAX-1){
        printf("Stack Overflow! \n");
    }
    else{
        top = top +1;
        stack[top] = v;
    }
}

void DFS(int v)
{
    int i;
    push(v);
    while(!isEmpty_stack()){
        v = pop();
        if(state[v] == initial){
            printf("%d\t",v);
            state[v] = visited;
        }
        for(i = n; i >= 0; i--){
            if(adj[v][i] == 1 && state[i] == initial)
                push(i);
        }
    }
    printf("\n");
}

void DF_traversal()
{
    int v;
    for(v = 0; v < n; v++)
        state[v] = initial;
    printf("Enter the starting vertex: ");
    scanf("%d",&v);
    DFS(v);
    for(v = 0; v < n; v++)
        if(state[v] == initial)
            DFS(v);
}

int main()
{
    int ch, origin, destin;
    create_graph();

    while(1){
        printf("\n*************");
        printf("\n1.Insert an edge\n2.Delete an edge\n3.Display\n4.Breadth First Traversal\n5.Depth First Traversal \n6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
        case 1:
            printf("Enter the edge to be inserted: \n");
            scanf("%d %d",&origin,&destin);
            insert_edge(origin,destin);
            break;
        case 2:
            break;
        case 3:
            display();
            break;
        case 4:
            BF_traversal();
            break;
        case 5:
            DF_traversal();
            break;
        case 6:
            return 0;
        default:
            printf("Invalid input!\n");
        }
    }

}

// 0 1 0 3 0 4 1 2 1 4 3 6 3 4 4 5 4 7 2 5 6 7 6 4 7 8 7 5 -1 -1
// 0 1 0 4 0 3 1 2 1 4 2 5 3 4 3 6 4 5 4 2 4 7 6 7 -1 -1
