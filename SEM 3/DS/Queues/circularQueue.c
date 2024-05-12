#include<stdio.h>
#include<stdlib.h>

#define MAX 5
long int CQ_arr[MAX];
int front = -1, rear = -1;

int isFull(){
    if((front == 0 && rear == MAX -1) || front == rear + 1 )
        return 1;
    else return 0;
}
int isEmpty(){
    if(rear == -1)
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
    rear = (rear + 1) % MAX;
    CQ_arr[rear] = item;
}

long int delete(){
    int item;
    if(isEmpty()){
        printf("Circular Queue Underflow!\n");
        return NULL;
    }
    item = CQ_arr[front];
    if(front == rear){
        front = -1;
        rear = -1;
    }
    front = (front + 1) % MAX ;
    return item;
}

void display(){
    int i;
    if(isEmpty()){
        printf("Queue underflow!\n");
        return;
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

int peek(){
    if(isEmpty()){
        printf("stack underflow!\n");
        exit(1);
    }
    return CQ_arr[front];
}

int main()
{
    long int item;
    int op;
    while(1){
        printf("MENU\n1.Insert\n2.Delete\n3.Display\n4.Peek\n5.Exit\n");
        scanf("%d",&op);
        switch(op){
            case 1: printf("Enter item : "); scanf("%d",&item);
                    insert(item);
                    break;
            case 2: if(!isEmpty())
                        printf("Item = %d\n",delete());
                    else printf("Stack Undewrflow\n");
                    break;
            case 3: if(!isEmpty()){
                        printf("The Elements of Queue are: \n");
                        display();
                    }
                    else printf("Stack Undewrflow\n");
                    break;
            case 4: printf("Top Element: %d\n",peek()); break;
            case 5: exit(1); break;
        }
    }
    return 0;
}
