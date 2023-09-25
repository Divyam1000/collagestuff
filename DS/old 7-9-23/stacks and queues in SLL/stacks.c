#include<stdio.h>
#include<stdlib.h>

 struct node{
    int info;
    struct node* link;
}*top = NULL;


int isEmpty(){
    return top == NULL;
}

void push(int data){
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    if(tmp == NULL){
        printf("Stack Overflow\n");
        return;
    }
    tmp->info = data;
    tmp->link = top;
    top = tmp;
}

int pop(){
    int item;
    struct node* tmp = top;
    if(isEmpty()){
        printf("Queue Underflow! \n");
        exit(1);
    }
    item = top->info;
    top = top->link;
    free(tmp);
    return item;
}

void display(){
    struct node *p = top;
    if(isEmpty()){
        printf("Stack Underflow!\n");
        return;
    }
    while(p!= NULL){
        printf("%d\n",p->info);
        p = p->link;
    }
}

int main()
{
    int op, tmp;
    while(1){
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
        scanf("%d",&op);
        switch (op){
            case 1: printf("Enter Number: ");
                    scanf("%d",&tmp);
                    push(tmp);
                    break;
            case 2: printf("%d",pop());
                    break;
            case 3: printf("Stack\n");
                    display();
                    break;
            case 4: return 0;
            default : printf("Wrong input!\n");
                    break;
        }
        printf("\n");
    }
}
