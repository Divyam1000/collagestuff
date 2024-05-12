#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* prev;
    int info;
    struct node* next;
};

struct node* add_toempty(struct node* start, int data) {
    struct node* tmp;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->prev = NULL;
    tmp->next = NULL;
    start = tmp;
    return start;
}

struct node* add_atend(struct node* start, int data) {
    struct node* tmp, * p;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->next = NULL;
    if (start == NULL) {
        tmp->prev = NULL;
        start = tmp;
        return start;
    }
    p = start;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = tmp;
    tmp->prev = p;
    return start;
}

struct node* createlist(struct node* start) {
    int i, n, tmp, info;
    printf("Enter the number : ");
    scanf("%d", &n);
    start = NULL;
    tmp = n;
    info = tmp % 10;
    tmp /= 10;
    start = add_toempty(start, info);
    while(tmp > 0){
        info = tmp % 10;
        tmp /= 10;
        start = add_atend(start, info);
    }
    return start;
}

int info(struct node *p){
    if(p == NULL)
        return 0;
    else
        return p->info;
}

struct node* add_lists(struct node* start1, struct node* start2){
    struct node* start3;

    if(start1 == NULL && start2 == NULL){
        printf("First add some elements to both lists !\n");
        return NULL;
    }
    start3 = add_toempty(start3, info(start1) + info(start2));
    while(start1 != NULL || start2 != NULL){
        start3 = add_atend(start3, info(start1) + info(start2));
        start1 = start1->next;
        start2 = start2->next;
    }
    printf("Adding sucessful !\n");
    return start3;
}

void display(struct node*p){
    if(p->next != NULL)
        display(p->next);
    printf("%d",p->info);
}

int main(){
    int op;
    struct node *start1,*start2, *start3;
    int data;

    while(1){
        printf("\n*****MENU*****\n");
        printf("1. create list from numbers\n2. add the numbers\n3. display\n4. Exit\n");
        scanf("%d",&op);
        switch(op){
            case 1:
                printf("First Number :\n");
                start1 = createlist(start1);
                printf("Second Number :\n");
                start2 = createlist(start2);
                 break;
            case 2:
                start3 = add_lists(start1, start2);
                break;
            case 3:
                printf("1. List 1\n2. List 2\n3. List 3\n");
                scanf("%d",&op);
                switch (op){
                    case 1:
                        if(start1 == NULL)
                            printf("Empty list !\n");
                        else
                            display(start1);
                            break;
                    case 2:
                        if(start2 == NULL)
                            printf("Empty list !\n");
                        else
                            display(start2);
                            break;
                    case 3:
                        if(start3 == NULL)
                            printf("Empty list !\n");
                        else
                            display(start3);
                            break;
                    default: printf("Invalid input !\n");
                }
                break;
            case 4: return 0;
            default: printf("Invalid input !\n");

        }
    }
}

