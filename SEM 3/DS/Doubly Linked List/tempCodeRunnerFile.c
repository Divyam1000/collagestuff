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
    int i, n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    start = NULL;
    if (n == 0)
        return start;
    printf("Enter the data : ");
    scanf("%d", &data);
    start = add_toempty(start, data);
    for (i = 2; i <= n; i++) {
        printf("\nEnter the data : ");
        scanf("%d", &data);
        start = add_atend(start, data);
    }
    return start;
}

struct node* del_node(struct node* start, int item) {
    struct node* p, * tmp;
    if (start == NULL) {
        printf("Empty list\n");
        return start;
    }
    if (start->info == item) {
        tmp = start;
        if (start->next == NULL)
            start = NULL;
        else {
            start = start->next;
            start->prev = NULL;
        }
        printf("\n%d\n", tmp->info);
        free(tmp);
        return start;
    }
    p = start->next;
    while (p != NULL) {
        if (p->info == item) {
            tmp = p;
            p->prev->next = p->next;
            if (p->next != NULL)
                p->next->prev = p->prev;
            printf("\n%d\n", p->info);
            free(tmp);
            return start;
        }
        p = p->next;
    }
    printf("\n%d not found in the list\n", item);
    return start;
}

struct node* reverse(struct node* start) {
    struct node* p1, * p2;
    p1 = start;
    p2 = p1->next;
    p1->next = NULL;
    p1->prev = p2;
    while (p2 != NULL) {
        p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev;
    }
    start = p1;
    printf("\nList reversed\n");
    return start;
}

struct node* swap(struct node* start) {
    struct node* p1, * p2;
    if(start == NULL){
        printf("Empty list !\n");
        return start;
    }
    if(start->next == NULL){
        printf("Only one element in list! Add more elements to swap !\n");
        return start;
    }
    p1 = start;
    start = p1->next;
    while(p1 != NULL && p1->next != NULL){
        p2 = p1->next;
        p1->next = p2->next;
        p2->prev = p1->prev;
        p2->next = p1;
        p1->prev = p2;
        if (p1->next != NULL)
            p1->next->prev = p1;
        if(p2->prev != NULL)
            p2->prev->next = p2;
        p1 = p1->next;
    }
    printf("\nNodes swapped\n");
    return start;
}

void display(struct node* start) {
    struct node* p;
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    p = start;
    printf("List is :\n");
    while (p != NULL) {
        printf("%d ", p->info);
        p = p->next;
    }
    printf("\n");
}

int main(){
    int op;
    struct node *start;
    int data;

    while(1){
        printf("\n*****MENU*****\n");
        printf("1. create list\n2. add node\n3. delete node\n4. reverse list\n5. swap\n6. display\n7. Exit\n");
        scanf("%d",&op);
        switch(op){
            case 1: start = createlist(start);  break;
            case 2: printf("Enter data: "); scanf("%d",&data);
                    if(start == NULL){
                        start = add_toempty(start, data);
                    }else{
                        start = add_atend(start, data);
                    }   break;
            case 3: printf("Enter item to delete: "); scanf("%d",&data);
                    start = del_node(start , data); break;
            case 4: start = reverse(start);    break;
            case 5: start = swap(start);   break;
            case 6: display(start); break;
            case 7: return 0;
            default: printf("Invalid input !\n");

        }
    }
}
