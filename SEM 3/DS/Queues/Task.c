#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

#define MAX 5

enum Status{Idle, Queued, Completed};

typedef struct TASK{
    int taskID;
    char taskTitle[20];
    int delay_t;
    enum Status  status;
} Task;
Task task[10];

typedef struct {
    Task *(task)[5];
    int front;
    int rear;

}Queue;

Queue queue;

int isFull(){
    if((queue.front == 0 && queue.rear == MAX -1) || queue.front == queue.rear + 1 )
        return 1;
    else return 0;
}
int isEmpty(){
    if(queue.rear == -1)
        return 1;
    else
        return 0;
}

void delay(int time){
    long pause;
    clock_t time1,time2;
    pause = time ;
    time2 = time1 = clock();
    while( (time1-time2) < pause ){
        time1 = clock();
    }
}

void init_tasks(){
    strcpy(task[0].taskTitle, "something1");
    task[0].taskID = 1001;
    task[0].delay_t = 5;
    strcpy(task[1].taskTitle,"something2");
    task[1].taskID = 1002;
    task[1].delay_t = 6;
    strcpy(task[2].taskTitle,"something3");
    task[2].taskID = 1003;
    task[2].delay_t = 7;
    strcpy(task[3].taskTitle,"something4");
    task[3].taskID = 1004;
    task[3].delay_t = 8;
    strcpy(task[4].taskTitle,"something5");
    task[4].taskID = 1005;
    task[4].delay_t = 2;
    strcpy(task[5].taskTitle,"something6");
    task[5].taskID = 1006;
    task[5].delay_t = 7;
    strcpy(task[6].taskTitle,"something7");
    task[6].taskID = 1007;
    task[6].delay_t = 10;
    strcpy(task[7].taskTitle,"something8");
    task[7].taskID = 1008;
    task[7].delay_t = 11;
    strcpy(task[8].taskTitle,"something9");
    task[8].taskID = 1009;
    task[8].delay_t = 4;
    strcpy(task[9].taskTitle,"something10");
    task[9].taskID = 1010;
    task[9].delay_t = 9;
    queue.front = -1;
    queue.rear = -1;
}

void Task_Scheduler(){
    int ID;
    printf("Enter Task ID: ");
    scanf("%d",&ID);
    for(int i = 0; i<10; i++){
        if((task+i)->taskID == ID){
            if((task+i)->status == Queued || (task+i)->status == Completed){
                printf("\nTask cannot be scheduled\n");
                return;
            }
            else if(isFull()){
                printf("\nTask scheduler queue is Full\n");
                return;
            }
            else{
                if(queue.front == -1)
                    queue.front = 0;
                queue.rear = (queue.rear + 1) % MAX;
                queue.task[queue.rear] = (task+i);
                queue.task[queue.rear]->status = Queued;
                printf("Task with ID %d is scheduled\n",ID);
                return;
            }
        }
    }
    printf("\nTask with ID %d Not found !\n",ID);
}

void Task_Run(){
    Task *item;
    if(isEmpty()){
        printf("\nTask Scheduler Queue Underflow!\n");
        return ;
    }
    item = queue.task[queue.front];
    if(queue.front == queue.rear){
        queue.front = -1;
        queue.rear = -1;
    }
    queue.front = (queue.front + 1) % MAX ;
    printf("%s is Running...\nTime required : %d\n",item->taskTitle,item->delay_t);
    delay(item->delay_t);
    item->status = Completed;
    printf("Task with ID %d was completed successfully\n",item->taskID);
}

void display(Task *item){
    printf("\nTask Title: %s\n",item->taskTitle);
    printf("Task ID : %d\n",item->taskID);
}

void Display_Queue(){
    int i;
    if(isEmpty()){
        printf("Task Scheduler Queue underflow!\n");
        return;
    }
    i = queue.front;
    if(queue.front <= queue.rear){
        while(i <= queue.rear){
            display(queue.task[i]);
            i++;
        }
    }
    else{
        while(i <= MAX-1){
            display(queue.task[i]);
            i++;
        }
        i = 0;
        while(i <= queue.rear){
            display(queue.task[i]);
            i++;
        }
    }
}

int main()
{
    init_tasks();

    int op;

    while(1)
    {
        printf("\n*****MENU*****\n");
        printf("1. Schedule Task\n2. Run Task\n3. Display Queue\n4.Exit\n");
        scanf("%d",&op);

        switch(op)
        {
        case 1:
            Task_Scheduler();
            break;
        case 2:
            Task_Run();
            break;
        case 3:
            Display_Queue();
            break;
        case 4: return 0;
        }
    }
}
