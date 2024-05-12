#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    struct node* left;
    bool lthread;
    int info;
    bool rthread;
    struct node* right;
};

struct node *in_succ (struct node *ptr)
{
    if (ptr->rthread == true)
        return ptr->right ;
    else
    {
        ptr=ptr->right;
        while(ptr->lthread==false)
            ptr=ptr->left;
        return ptr;
    }
}

struct node *in_pred (struct node *ptr)
{
    if (ptr->lthread == true)
        return ptr->left;
    else
    {
        ptr=ptr->left;
        while(ptr->rthread==false)
            ptr=ptr->right;
        return ptr;
    }
}

struct node* insert(struct node* root, int ikey){
    struct node *tmp, *par, *ptr;
    int found = 0;
    ptr = root;
    par = NULL;
    while(ptr != NULL){
        if(ikey == ptr->info){
            found = 1;
            break;
        }
        par = ptr;
        if(ikey < ptr->info){
            if(ptr->lthread == false)
                ptr = ptr->left;
            else
                break;
        }
        else {
            if(ptr->rthread == false){
                ptr = ptr->right;
            }
            else
                break;
        }
    }
    if(found)
        printf("Duplicate key\n");
    else{
        tmp = (struct node*)malloc(sizeof(struct node));
        tmp->info = ikey;
        tmp->lthread = true;
        tmp->rthread = true;
        if(par == NULL){
            root = tmp;
            tmp->left = NULL;
            tmp->right = NULL;
        }
        else if(ikey < par->info){
            tmp->left = par->left;
            tmp->right = par;
            par->lthread = false;
            par->left = tmp;
        }
        else{
            tmp->right = par->right;
            tmp->left = par;
            par->rthread = false;
            par->right = tmp;
        }
    }
    return root;
}

void search(struct node* root, int ikey){
    struct node *par, *ptr;
    int found = 0;
    ptr = root;
    par = NULL;
    while(ptr != NULL){
        if(ikey == ptr->info){
            found = 1;
            break;
        }
        par = ptr;
        if(ikey < ptr->info){
            if(ptr->lthread == false)
                ptr = ptr->left;
            else
                break;
        }
        else {
            if(ptr->rthread == false){
                ptr = ptr->right;
            }
            else
                break;
        }
    }
    if(found)
        printf("\n Found! \n");
    else
        printf("\nNot Found! \n");
}

struct node * case_a(struct node *root, struct node *par, struct node *ptr)
{
    if (ptr == NULL)
        root = NULL;
    else if (par->left == ptr)
    {
        par->lthread = true;
        par->left = ptr->left ;
    }
    else
    {
        par->rthread = true;
        par->right = ptr->right ;
    }
    free(ptr);
    return root;

}

struct node * case_b(struct node *root, struct node *par, struct node *ptr)
{
    struct node *child, *p, *s ;
    if (ptr->lthread == false)
        child = ptr->left ;
    else
        child = ptr->right ;
    if (par == NULL)
        root = child;
    else if (par->left == ptr)
        par->left = child;
    else
        par->right = child;
    s=in_succ(ptr);
    p=in_pred(ptr);
    if( ptr->lthread==false)
        p->right=s;
    else if( ptr->rthread==false)
        s->left=p;
    free(ptr);
    return root;
}

struct node * case_c(struct node *root, struct node *par, struct node *ptr)
{
    struct node *succ, *parsucc;
    parsucc = ptr;
    succ = ptr->right ;
    while (succ->left != NULL )
    {
        parsucc = succ;
        succ = succ->left ;
    }
    ptr->info = succ->info ;
    if (succ->lthread == true && succ->rthread == true )
        root = case_a (root,parsucc,succ);
    else
        root = case_b (root,parsucc,succ);
    return root;
}

struct node * del (struct node *root, int dkey)
{
    struct node * par, *ptr;
    int found=0;
    ptr = root;
    par = NULL;
    while (ptr != NULL)
    {
        if (dkey == ptr->info)
        {
            found=1;
            break;
        }
        par = ptr;
        if (dkey < ptr->info)
        {
            if (ptr->lthread==false)
                ptr = ptr->left;
            else
                break;
        }
        else
        {
            if (ptr->rthread==false)
                ptr = ptr->right;
            else
                break;
        }
    }
    if (found == 0 )
        printf("%d not present in the tree",dkey);
    else if (ptr->lthread == false && ptr->rthread == false )
        root = case_c(root, par,ptr);
    else if (ptr->lthread == false )
        root = case_b(root, par,ptr);
    else if (ptr->rthread == false)
        root = case_b(root, par,ptr);
    else
        root = case_a(root, par,ptr);
    return root;
}

void inorder(struct node *root)
{
    struct node *ptr;
    if (root== NULL)
    {
        printf("Tree is empty");
        return;
    }
    ptr=root;
    while(ptr->lthread==false)
        ptr=ptr->left;
    while(ptr!= NULL)
    {
        printf("%d ", ptr->info);
        ptr=in_succ(ptr);
    }
}

void perorder(struct node *root)
{
    struct node *ptr;
    if (root== NULL)
    {
        printf("Tree is empty");
        return;
    }
    ptr=root;
    while(ptr!= NULL)
    {
        printf("%d ", ptr->info);
        if(ptr->lthread==false)
            ptr=ptr->left;
        else if (ptr->rthread==false)
            ptr=ptr->right;
        else
        {
            while(ptr!= NULL && ptr->rthread==true)
                ptr=ptr->right;
            if (ptr!= NULL)
                ptr=ptr->right;
        }
    }
}

int main(){
    int op, n, key;
    struct node *root = NULL;

    printf("create list : \n");
    printf("Enter number of elements : ");
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        printf("Enter item : ");
        scanf("%d",&key);
        root = insert(root, key);
    }

    while(true){
        printf("\n\n***Menu***");
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Inorder an Perorder traversal\n5. Exit\n");
        printf("Enter option : ");
        scanf("%d",&op);
        switch(op){
        case 1: printf("Enter key: ");scanf("%d",&key);
                root = insert(root,key);
                break;
        case 2: printf("Enter key: ");scanf("%d",&key);
                root = del(root,key);
                break;
        case 3: printf("Enter key: ");scanf("%d",&key);
                search(root,key);
                break;
        case 4:
                printf("Inorder : "); inorder(root);
                printf("\nPerorder : "); perorder(root);
                break;
        case 5: return 0;
        default:
            printf("Input Error! \n");
        }
    }
    return 0;
}
// 30 79 35 73 24 58 57 99 26 72 22
