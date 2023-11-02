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


int main(){
    int op, n;
    struct node *root = NULL;
    while(true){
        printf("***Menu***");
        printf("\n1. Insert\n2. Delete\n3. Search\n4. exit\n");
        scanf("%d",&op);
        switch(op){
        case 1: printf("Enter key: ");scanf("%d",&n);
                root = insert(root,n);
                break;
        case 2: printf("Enter key: ");scanf("%d",&n);
                break;
        case 3: printf("Enter key: ");scanf("%d",&n);
                search(root,n);
                break;
        case 4: return 0;
        default:
            printf("\nInput Error! \n");
        }
    }
    return 0;
}
