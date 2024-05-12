#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct treenode{
    struct treenode * lchild;
    int info;
    struct treenode * rchild;
};

struct listnode{
    struct listnode* next;
    int info;
};



struct treenode *queue[MAX];
int front = - 1, rear = - 1;

struct listnode* creatlist(int num){
    if(num == 0)
        return NULL;
    struct listnode* tmp = (struct listnode*)malloc(sizeof(struct listnode));
    int info;
    printf("Enter element: ");
    scanf("%d",&info);
    tmp->info = info;
    tmp->next = creatlist(--num);
    return tmp;
}

void display_list(struct listnode* p){
    if(p == NULL)
        return;
    printf("%d\n",p->info);
    display_list(p->next);
}

struct treenode* construct_in_post(struct listnode* inptr, struct listnode* postptr, int num) {
    struct treenode* temp;
    struct listnode* q, * ptr;
    int i,j;
    if (num <= 0)
        return NULL;
    ptr = postptr;
    for (i = 1; i < num; i++)
        ptr = ptr->next;
    temp = (struct treenode*)malloc(sizeof(struct treenode));
    temp->info = ptr->info;
    temp->lchild = NULL;
    temp->rchild = NULL;
    if (num == 1)
        return temp;
    q = inptr;
    for (i = 0; q->info != ptr->info; i++)
        q = q->next;
    temp->lchild = construct_in_post(inptr, postptr, i);
    for(j=1; j<=i;j++)
        postptr=postptr->next;
    temp->rchild = construct_in_post(q->next, postptr, num - i - 1);

    return temp;
}

void post_traversal(struct treenode *p){
    if(p == NULL)
        return;
    post_traversal(p->lchild);
    post_traversal(p->rchild);
    printf("%d ",p->info);
}

int height(struct treenode* p){
    int lh, rh;
    if(p == NULL)
        return 0;
    lh = 1 + height(p->lchild);
    rh = 1 + height(p->rchild);
    if(lh > rh)
        return lh;
    else
        return rh;
}

int depth(struct treenode *p, int key){
    static int dpt = -1;
    static int found = 0;
    if(p == NULL)
        return dpt;
    dpt ++;
    if(p->info == key){
        found = 1;
        return dpt;
    }
    depth(p->lchild,key);
    if(found)
        return dpt;
    depth(p->rchild,key);
    if(found)
        return dpt;
    else
        dpt --;
    return dpt;
}

void insert_queue(struct treenode *item)
{
    if (rear == MAX - 1)
    {
        printf ("Queue Overflow.......\n");
        return;
    }
    if (front == - 1)
        front = 0;
    rear = rear + 1;
    queue[rear] = item;
}
struct node * del_queue()
{
    struct treenode *item;
    if (front == - 1|| front == rear + 1)
    {
        printf ("Queue underflow.......\n");
        exit(1);
    }
    item = queue[front];
    front = front + 1;
    return item;
}

int queue_empty ()
{
    if (front == - 1|| front == rear + 1)
        return 1;
    else
        return 0;
}
void level_trav(struct node *root)
{
    struct treenode *ptr = root ;
    if (ptr == NULL)
    {
        printf ("Tree is empty\n");
        return;
    }
    insert_queue(ptr);
    while(! queue_empty())
    {
        ptr = del_queue ();
        printf ("%d ",ptr->info);
        if (ptr->lchild != NULL)
            insert_queue(ptr->lchild );
        if (ptr->rchild != NULL)
            insert_queue(ptr->rchild );
    }
    printf ("\n");
}

int main(){
    int p,i;
    struct listnode * inorder, *postorder;
    struct treenode *binary_tree;

    printf("Enter number of elements in inorder list: ");
    scanf("%d",&i);
    inorder = creatlist(i);
    printf("list created sucessfuly !\n");

    printf("Enter number of elements in postorder list: ");
    scanf("%d",&p);
    postorder = creatlist(p);
    printf("list created sucessfuly !\n");

    binary_tree = construct_in_post(inorder, postorder, p);
    printf("Postorder traversal: ");
    post_traversal(binary_tree);

    int op, key,d;
    while(1){
        printf("\n1. Tree Height\n2. Depth of given node\n3. Level order traversal\n4. Exit\n");
        printf("Enter : ");scanf("%d",&op);
        switch(op){
        case 1:
            printf("Height of tree is : %d\n",height(binary_tree));
            break;
        case 2:
            printf("Enter Node of which depth is to found out : ");
            scanf("%d",&key);
            d = depth(binary_tree, key);
            if(d == -1)
                printf("Node with key %d not found !\n",key);
            else
                printf("Depth of node %d = %d",key,d);
            break;
        case 3:
            level_trav(binary_tree);
            break;
        case 4: return 0;
        default : printf("Invalid input !\n");
        }

    }
}
/*8
19
25
65
85
11
44
33
29
8
65
25
11
85
19
33
29
44*/
