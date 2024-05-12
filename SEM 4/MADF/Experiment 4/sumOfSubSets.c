#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include<limits.h>

// Some data types and idk macro?
typedef enum boolean {true = 1, false = 0}bool;
#define non_leaf_node 0
#define leaf_node 1
#define soloution_node 2
typedef struct Node
{
    int level, nodeNo;
    int s,k,r;
    int* set;
    bool type;
} node;
// Some global variables
int n, m, solCount = 0, nodeCount = 0;
int x[100], w[100], temp_w[100];
node *stack[100]; int stackTop=0;

// creatas the nodes to be put on the stack representing the tree
node* createNode(int s, int k, int r, int *_x, int _level, int _nodeNo, int type)
{
    node *_node = malloc((int)1*sizeof(node));
    _node->s = s;
    _node->k = k;
    _node->r = r;
    _node->level = _level;
    _node->nodeNo = _nodeNo;
    _node->type = type;
    _node->set = malloc(n*sizeof(int));
    for(int i=0; i<n; i++)
    {
        _node->set[i] = 0;
    }
    for(int i=0; i<=k; i++)
    {
        _node->set[i] = _x[i];
    }
    return _node;
}

void reverseInputaArray()
{
    for(int i=0 ; i<n; i++)
    {
        temp_w[i] = w[i];
    }
    for(int i=0, j=n-1; i<n; i++, j--)
    {
        w[i] = temp_w[j];
    }
}

void randomizeInputArray()
{
    for (int i = 0; i < n - 1; i++) {
        int j = i + rand() / (RAND_MAX / (n - i) + 1);
        int temp = w[j];
        w[j] = w[i];
        w[i] = temp;
    }
}

void clearStack()
{
    for(int i=0; i<100; i++)
    {
        free(stack[i]);
    }
    stackTop=0;
}

// its just push
void pushOnStack(node *_node)
{
    stack[stackTop++] = _node;
}

// drawing tree
void printTree()
{
    int _stackTop = stackTop-1;
    while(_stackTop != 0)
    {
        for(int i=0; i< stack[_stackTop]->level; i++)
        {
            printf("    ");   
        }
        
        printf("Node %d ( %d %d %d ) ",stack[_stackTop]->nodeNo,stack[_stackTop]->s,stack[_stackTop]->k+2,stack[_stackTop]->r);
        if(stack[_stackTop]->type == leaf_node)
        {
            printf("x[");
            for(int j=0; j<n; j++)
            {   
                if(j!=n-1)
                    printf("%d,",stack[_stackTop]->set[j]);
                else   
                    printf("%d",stack[_stackTop]->set[j]);
            }
            printf("]");
        }
        else if(stack[_stackTop]->type == soloution_node)
        {
            printf("x[");
            for(int j=0; j<n; j++)
            {   
                if(j!=n-1)
                    printf("%d,",stack[_stackTop]->set[j]);
                else   
                    printf("%d",stack[_stackTop]->set[j]);
            }
            printf("] w:[");
            for(int j=0; j<n; j++)
            {   
                if(stack[_stackTop]->set[j]){
                    if(j!=n-1)
                        printf("%d,",j+1);
                    else   
                        printf("%d",j+1);
                }
            }
            printf("] Solution %d",++solCount);
        }
        _stackTop--;
        printf("\n");
    }
}

// weird algorithm
void sumOfSub(int s, int k, int r) {
    x[k] = 1;
    int level = k+1;
    int nodeNo = nodeCount++;
    // Checks if this is the solution 
    if (s + w[k] == m) 
    {
        nodeNo++,nodeCount++;
        pushOnStack(createNode(s+w[k],k,r-w[k],x,level,nodeNo,soloution_node));
        nodeNo--;
    }
    // possible solution still ahead
    else if (s + w[k] + w[k+1] <= m)  
    {
        // goes to left child means there is a possible soloution with this combination of x
        sumOfSub(s + w[k], k + 1, r - w[k]);
    }
   
    pushOnStack(createNode(s,k-1,r,x,level-1,nodeNo,non_leaf_node));

    // checks if there is a possible solution without this combination of x
    if ((s + r - w[k] >= m) && (s + w[k+1] <= m))   
    {
        x[k] = 0;
        // goes to next possible combination of x without the current node
        sumOfSub(s, k+1, r - w[k]);         
    }
}

int main() {
    int sum=0;
    printf("Enter the number of elements in set : ");
    scanf("%d",&n);

    printf("Enter the weights of the elements of the set : ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&w[i]);
        sum += w[i];
    }

    printf("Enter the desired sum : ");
    scanf("%d",&m);

    for (int i = 0; i < n; i++) {
        x[i] = 0;
    }
    w[n]=INT_MAX;

    printf("\nSubsets using asscending input : CASE 1\n\n\n");
    pushOnStack(createNode(0,0,sum,x,0,++nodeCount,non_leaf_node));    
    sumOfSub(0,0,sum); 
    printTree();

    printf("\n\n\nSubsets using descending input : CASE 2\n\n\n");
    reverseInputaArray();
    solCount=0;
    nodeCount=0;
    clearStack();
    pushOnStack(createNode(0,0,sum,x,0,++nodeCount,non_leaf_node));    
    sumOfSub(0,0,sum); 
    printTree();

    printf("\n\n\nSubsets using jumbled input : CASE 3\n\n\n");
    srand(time(NULL));
    randomizeInputArray();
    printf("Randomized array\n");
    for(int i=0; i<n; i++)
    {
        if(i ==n-1)
        printf("%d",w[i]);
        else
        printf("%d,",w[i]);
    }
    printf("\n");
    solCount=0;
    nodeCount=0;
    clearStack();
    pushOnStack(createNode(0,0,sum,x,0,++nodeCount,non_leaf_node));    
    sumOfSub(0,0,sum); 
    printTree();

    
    return 0;
}

// 7 1 2 4 9 19 24 29 29
