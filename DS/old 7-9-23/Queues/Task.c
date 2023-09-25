#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

#define MAX 5

typedef struct{
    int taskID;
    char taskTitle[20];
    int delay_t;
} Task;

typedef struct{
    Task task;
}Queue;

Task *init_tasks(){
    static Task task[10];
    //task[0].taskTitle = "something1";
    strcpy(task[0].taskTitle, "something1");
    task[0].taskID = 1001;
    task[0].delay_t = 5;
    //task[1].taskTitle = "something2";
    strcpy(task[1].taskTitle,"something2");
    task[1].taskID = 1002;
    task[1].delay_t = 5;
    //task[2].taskTitle = "something3";
    strcpy(task[2].taskTitle,"something3");
    task[2].taskID = 1003;
    task[2].delay_t = 5;
    //task[3].taskTitle = "something4";
    strcpy(task[3].taskTitle,"something4");
    task[3].taskID = 1004;
    task[3].delay_t = 5;
    //task[4].taskTitle = "something5";
    strcpy(task[4].taskTitle,"something5");
    task[4].taskID = 1005;
    task[4].delay_t = 5;
    //task[5].taskTitle = "something6";
    strcpy(task[5].taskTitle,"something6");
    task[5].taskID = 1006;
    task[5].delay_t = 5;
   // task[6].taskTitle = "something7";
    strcpy(task[6].taskTitle,"something7");
    task[6].taskID = 1007;
    task[6].delay_t = 5;
    //task[7].taskTitle = "something8";
    strcpy(task[7].taskTitle,"something8");
    task[7].taskID = 1008;
    task[7].delay_t = 5;
    //task[8].taskTitle = "something9";
    strcpy(task[8].taskTitle,"something9");
    task[8].taskID = 1009;
    task[8].delay_t = 5;
    //task[9].taskTitle = "something10";
    strcpy(task[9].taskTitle,"something10");
    task[9].taskID = 1010;
    task[9].delay_t = 5;

}


int main()
{
    Task *task[10];


}
