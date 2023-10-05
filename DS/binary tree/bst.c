#include<stdio.h>
#include<stdlib.h>

struct node {
struct node *lchild;
int info;
struct node *rchild;
};

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
    else if(ikey < ptr->info)
        ptr->rchild = insert(ptr->rchild,ikey);
    else
        printf("Duplicate key/n");
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
    printf("%d",p->info);
    preorder(p->lchild);
    preorder(p->rchild);
}

void postorder(struct node *p) {
    if(p==NULL)
        return;
    postorder(p->lchild);
    postorder(p->rchild);
    printf("%d",p->info);
}


void inorder(struct node *p) {
        if(p==NULL)
        return;
    inorder(p->lchild);
    printf("%d",p->info);
    inorder(p->rchild);
}

int main() {

}
