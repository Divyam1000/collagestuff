#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 1000

struct node {
struct node *lchild;
int info;
struct node *rchild;
};

struct node *queue[MAX];
int front = - 1, rear = - 1;

struct node *search(struct node *ptr,int skey) {
    if(ptr==NULL) {
        printf("Key not found/n");
        return NULL;
    }
    else if(skey<ptr->info)
        return search(ptr->lchild,skey);
    else if(skey>ptr->info)
        return search(ptr->rchild,skey);
    else
        return ptr;
}

struct node *insert(struct node *ptr,int ikey) {
    if(ptr == NULL) {
        ptr = (struct node *)malloc(sizeof(struct node));
        ptr->info = ikey;
        ptr->lchild = NULL;
        ptr->rchild = NULL;
    }
    else if(ikey < ptr->info)
        ptr->lchild = insert(ptr->lchild,ikey);
    else if(ikey > ptr->info)
        ptr->rchild = insert(ptr->rchild,ikey);
    else
        printf("Duplicate key\n");
    return ptr;
}

struct node *del(struct node *ptr, int dkey) {
    struct node *tmp,*succ,*parsucc;
    if(ptr== NULL) {
        printf("%d not present in the tree",dkey);
        return ptr;
    }
    if(dkey < ptr->info)
        ptr->lchild = del(ptr->lchild,dkey);
    else if(dkey > ptr->info)
        ptr->rchild = del(ptr->rchild,dkey);
    else {
        if(ptr->lchild != NULL && ptr->rchild != NULL) {
            parsucc = ptr;
            succ = ptr->rchild;
            while(succ->lchild != NULL){
                parsucc = succ;
                succ = succ->lchild;
            }
            ptr->info = succ->info;
            ptr->rchild = del(ptr->rchild,succ->info);
        }
        else {
            tmp = ptr;
            if(ptr->lchild != NULL)
                ptr = ptr->lchild;
            else if(ptr->rchild != NULL)
                ptr = ptr->rchild;
            else ptr = NULL;
            free(tmp);
        }
    }
    return ptr;
}


void preorder(struct node *p) {
    if(p==NULL)
        return;
    printf("%d ",p->info);
    preorder(p->lchild);
    preorder(p->rchild);
}

void postorder(struct node *p) {
    if(p==NULL)
        return;
    postorder(p->lchild);
    postorder(p->rchild);
    printf("%d ",p->info);
}


void inorder(struct node *p) {
    if(p==NULL)
        return;
    inorder(p->lchild);
    printf("%d " ,p->info);
    inorder(p->rchild);
}

int max_item(struct node* p)
{
    while(p != NULL && p->rchild != NULL)
        p = p->rchild;
    return p->info;
}

int min_item(struct node *p)
{
    while(p != NULL && p->lchild != NULL)
        p = p->lchild;
    return p->info;
}

//printing tree

void insert_queue(struct node *item)
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
    struct node *item;
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

int height(struct node* p){
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

void give_space(int space, struct node *ptr, int mode){
    if(mode == 1)
    {
        if(ptr->lchild == NULL)
        {
            for(int i = 0; i < space-1; i++)
                printf("  ");
        }
        else
        {
            space /= 2;
            for(int i = 0; i < space-1; i++)
                printf("  ");
            for(int i = 0; i < space; i++)
                printf("--");
        }
    }
    if(mode == 2)
    {
        if(ptr->rchild == NULL)
        {
            for(int i = 0; i < space; i++)
                printf("  ");
        }
        else
        {
            space /= 2;
            for(int i = 0; i < space; i++)
                printf("--");
            for(int i = 0; i < space; i++)
                printf("  ");
        }
    }
}

void print_tree(struct node* root){
    int h = height(root);
    int space = pow(2,h);
    int level = 0;
    int lnc =0;

    struct node *ptr = root, filler;
    filler.info = -1;
    filler.lchild = NULL;
    filler.rchild = NULL;

    if(root == NULL)
        return;

    insert_queue(ptr);

    while(level <= h)
    {
        if(lnc == 0){
            printf("\n");
            lnc = pow(2,level);
            level ++;
            space /= 2;
        }
        ptr = del_queue ();
        lnc--;
//printing node and arms
        give_space(space, ptr, 1);
        if(ptr->info == -1)
            printf("  ");
        else
            printf ("%2d",ptr->info);
        give_space(space,ptr, 2);
// queueing
        if (ptr->lchild != NULL)
            insert_queue(ptr->lchild );
        else
            insert_queue(&filler);
        if (ptr->rchild != NULL)
            insert_queue(ptr->rchild );
        else
            insert_queue(&filler);

    }
    front = -1;
    rear = -1;
}

int main()
{
    struct node* root = NULL;
    int n, key, op;
    printf("Create Binary Search Tree : ");
    printf("\nEnter no. of elements : ");
    scanf("%d",&n);
    for(int i = 0; i <n; i++){
        printf("Enter item to insert : ");
        scanf("%d",&key);
        root = insert(root,key);
    }
    print_tree(root);
    while(1){
        printf("\n1. Insert item\n2. Delete item\n3. Search item\n4. Inorder , Preorder, Postorder traversal and display tree\n5. Max and Min of BST\n6. exit\n");
        printf("Enter Option : "); scanf("%d",&op);
        switch(op){
            case 1:
                printf("\nEnter item : "); scanf("%d",&key);
                root = insert(root,key);
                break;
            case 2:
                printf("\nEnter item : "); scanf("%d",&key);
                root = del(root, key);
                break;
            case 3:
                printf("\nEnter item : "); scanf("%d",&key);
                root = search(root,key);
                break;
            case 4:
                printf("\nIn order : "); inorder(root); printf("\n");
                printf("pre order : "); preorder(root); printf("\n");
                printf("post order : "); postorder(root); printf("\n");
                print_tree(root);
                break;
            case 5:
                printf("\nLargest item in the BST : %d\n",max_item(root));
                printf("Smallest item in the BST : %d\n",min_item(root));
                break;
            case 6:
                return 0;
            default: printf("\nInvalid input !\n");
        }
    }
}
// 41 70 58 49 25 12 44 20 68 91 57 42 37 28 27
