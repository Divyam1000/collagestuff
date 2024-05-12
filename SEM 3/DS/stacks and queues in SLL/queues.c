#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node* link;
}node;

struct node * front = NULL;
struct node * rear = NULL;

int isEmpty(){
    return front == NULL;
}

void insert(int data){
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    if(tmp == NULL){
        printf("Queue Overflow\n");
        return;
    }
    tmp->info = data;
    tmp->link = NULL;
    if(front == NULL)
        front = tmp;
    else
        rear->link = tmp;
    rear = tmp;
}

int delete(){
    int item;
    struct node* tmp = front;
    if(isEmpty()){
        printf("Queue Underflow! \n");
        exit(1);
    }
    item = front->info;
    front = front->link;
    free(tmp);
    return item;
}

void display(){
    struct node* p = front;
    if(isEmpty()){
        printf("Queue Underflow!\n");
        return;
    }
    while(p != NULL){
        printf("%d\n",p->info);
        p = p->link;
    }
}

int main()
{
    int op, tmp;
    while(1){
        printf("1.insert\n2.delete\n3.Display\n4.Exit\n");
        scanf("%d",&op);
        switch (op){
            case 1: printf("Enter Number: ");
                    scanf("%d",&tmp);
                    insert(tmp);
                    break;
            case 2: printf("%d",delete());
                    break;
            case 3: printf("Queue\n");
                    display();
                    break;
            case 4: return 0;
            default : printf("Wrong input!\n");
                    break;
        }
        printf("\n");
    }
}
