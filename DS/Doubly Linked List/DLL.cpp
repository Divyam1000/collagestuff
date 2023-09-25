#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node* prev;
    int info;
    struct node* next;
};

void display(struct node* start){
    if(start == NULL){
        printf("List is empty is empty!\n");
        return;
    }
    struct node* p = start;
    while(p!=NULL){
        printf("\n%d",p->info);
        p = p->next;
    }
}


struct node* add_toempty(struct node *start, int data){
    struct node* tmp;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->prev = NULL;
    tmp->next = NULL;
    start = tmp;
    return start;
}

struct node* add_atend(struct node* start, int data){
    struct node *tmp, *p;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->next = NULL;
    p = start;
    while(p->next != NULL){
         p = p->next;
        tmp->prev = p;
    }
    p->next = tmp;
    return start;
}

struct node* createlist(struct node* start){
    int i, n, data;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    start = NULL;
    if(n == 0)
        return start;
    printf("Enter the data : ");
    scanf("%d",&data);
    start = add_toempty(start,data);
    for(i = 2; i<=n ;i++){
        printf("\nEnter the data : ");
        scanf("%d",&data);
        start = add_atend(start,data);
    }
    return start;
}

struct node* add_atbeg(struct node*start , int data){
    struct node *tmp, *p;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->prev = NULL;
    tmp->next = start;
    start->prev = tmp;
    start = tmp;
    return start;
}

struct node* addafter(struct node*start , int data, int item){
    struct node *tmp, *p;
    p = start;
    while(p != NULL){
        if(p->info == item){
            tmp = (struct node*)malloc(sizeof(struct node));
            tmp->info = data;
            tmp->next = p->next;
            tmp->prev = p;
            if(p->next != NULL)
                p->next->prev = tmp;
            p->next = tmp;
            return start;
        }
        p = p->next;
    }
    printf("Item not found!");
    return start;
}

struct node* addbefore(struct node* start, int data, int item){
    struct node *tmp, *p;
    if(start->info == item){
        return add_atbeg(start, data);
    }
    p = start;
    while(p != NULL){
        if(p->info == data){
            tmp = (struct node*)malloc(sizeof(struct node));
            tmp->info = data;
            tmp->prev = p->prev;
            tmp->next = p;
            p->prev->next = tmp;
            p->prev = tmp;
            return start;
        }
    }
    printf("Element not found!\n");
    return start;
}





int main(){
    struct node* start;
    int op;
    int data, item;

    while(1){
        printf("\n*****MENU*****");
        printf("\n1. creatlist\n2. display\n3. add after node ");
        printf("\n4. add before node\n5. add at end\n6. add at beginning");
        printf("\n7. delete\n8. reverse\n9. exit");
        scanf("%d",&op);
        switch(op){
            case 1: start = createlist(start); break;
            case 2: display(start);
            case 3: printf("Enter data : "); scanf("%d",&data);
                    printf("Enter item : "); scanf("%d",&item);
                    addafter(start, item, data)
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9: return 0;
        }
    }
}
