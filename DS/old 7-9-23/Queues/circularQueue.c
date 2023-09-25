#include<stdio.h>
#include<stdlib.h>

#define MAX 5
long int CQ_arr[MAX];
int front = -1, rear = -1;

int isFull(){
    if(front == (rear + 1) % MAX)
        return 1;
    else return 0;
}
int isEmpty(){
    if(rear == (rear +1) % MAX || rear == front)
        return 1;
    else
        return 0;
}

void insert(int item){
    if(isFull()){
        printf("Circular list full!\n");
        return;
    }
    if(front == -1)
        front = 0;
    if(rear == MAX -1)
        rear = 0;
    else
        rear = rear + 1;
    CQ_arr[rear] = item;
}

long int delete(){
    int item;
    if(isEmpty()){
        printf("Circular Queue Underflow!\n");
        exit(1);
    }
    item = CQ_arr[front];
    if(front == rear){
        front = -1;
        rear = -1;
    }
    if(front == MAX -1)
        front = 0;
    else front = front + 1;

    return item;
}

void display(){
    int i;
    if(isEmpty()){
        printf("Queue underflow!\n");
        exit(1);
    }
    i = front;
    if(front <= rear){
        while(i <= rear){
            printf("%d\n",CQ_arr[i]);
            i++;
        }
    }
    else{
        while(i <= MAX-1){
            printf("%d\n",CQ_arr[i]);
            i++;
        }
        i = 0;
        while(i <= rear){
            printf("%d\n",CQ_arr[i]);
            i++;
        }
    }
}

int main()
{
    long int item;
    int op;
    while(1){
        printf("MENU\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d",&op);
        switch(op){
            case 1: printf("Enter item : "); scanf("%d",&item);
                    insert(item);
                    break;
            case 2: printf("Item = %d\n",delete());
                    break;
            case 3: printf("The Elements of Queue are: \n");
                    display();
                    break;
            case 4: exit(1); break;
        }
    }
    return 0;
}
