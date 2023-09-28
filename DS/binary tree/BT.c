#include<stdio.h>
#include<stdlib.h>

struct treenode{
    struct treenode * lchild;
    int info;
    struct treenode * rchild;
};

struct listnode{
    struct listnode* next;
    int info;
};

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

struct treenode* construct_in_pre(struct listnode* preptr, struct listnode* inptr, int num)
{
    int i,j;
    struct treenode* tmp;
    struct listnode* p;
    if(num == 0)
        return NULL;
    tmp = (struct treenode*)malloc(sizeof(struct treenode));
    tmp -> lchild = NULL;
    tmp -> rchild = NULL;
    tmp->info = preptr->info;
    if(num == 1)
        return tmp;
    p = inptr;
    for(i = 0; p->info != preptr->info; i++)
        p = p->next;
    tmp->lchild = construct_in_pre(preptr->next,inptr,num);
    for(j = 0; j <= i+1; j++)
        preptr = preptr->next;
    tmp->rchild = construct_in_pre(preptr, p->next, num-i);
    return tmp;

}

void disp_pre(struct treenode* ptr){
    if(ptr == NULL)
        return;
    printf("%d",ptr->info);
    disp_pre(ptr->lchild);
    disp_pre(ptr->rchild);
}

int main(){
    int p,i;
    struct listnode* preorder,* inorder;
    struct treenode* binary_tree;
    printf("Enter number of elements in preoder list: ");
    scanf("%d",&p);
    preorder = creatlist(p);
    printf("Enter number of elements in inorder list: ");
    scanf("%d",&i);
    inorder = creatlist(i);

    binary_tree = construct_in_pre(preorder, inorder,p);

    disp_pre(binary_tree);


}

