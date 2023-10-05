
#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node* prev;
    int info;
    struct node* next;
};

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

struct node* del_node(struct node* start, int item){
    struct node* p, *tmp;
    if(start == NULL){
        printf("Empty list\n");
        return start;
    }
    if(start->info == item){
        tmp = start;
        if(start->next == NULL)
            start = NULL;
        else{
            start = start->next;
            start->prev = NULL;
        }
        printf("\n%d\n",tmp->info);
        free(tmp);
        return start;
    }
    p = start->next;
    while(p->next != NULL){
        if(p->info == item){
            tmp = p;
            p->prev->next = p->next;
            p->next->prev = p->next;
            printf("\n%d\n",p->info);
            free(tmp);
            return start;
        }
        p = p->next;
    }
    if(p->info == item){
        p->prev->next = NULL;
        printf("\n%d\n",p->info);
        free(p);
    }
}

struct node* reverse_list(struct node* start){
    if(start == NULL){
        printf("List is empty!\n");
        return start;
    }
    struct node* p = start;
    struct node* tmp = NULL;

    while(p != NULL){
        tmp = p->prev;  printf("%d",p->prev);
        p->prev = p->next;
        p->next = tmp;
        if(p->prev == NULL){
            start = p;
        }
        p = p->prev;
    }
    return start;
}


struct node* swap_adjacent(struct node* start){
    if(start == NULL){
        printf("List is empty!\n");
        return start;
    }
    if(start->next == NULL){
        printf("cannot reverse, only one element!\n");
        return start;
    }
    start = start->next;
    struct node* p = start,*q = start->next;
    while(p->next != NULL){printf("HERE1\n");
        p->next = q->next;
        q->next = p;
        q->prev = p->prev;
        p->prev = q;
        p = p->next;
        q = p->next;printf("HERE2\n");
    }
    return start;
}

void display(struct node* start){
    if(start == NULL){
        printf("Empty list!\n");
        return;
    }
    struct node* p = start;
    while(p != NULL){
        printf("%d\n",p->info);
        p = p->next;
    }
}

int main(){
    int op;
    struct node *start;
    int data;

    while(1){
        printf("\n*****MENU*****\n");
        printf("1.creat list\n2.add node\n3. delete node\n4. reverse list\n5. swap\n6. display\n");
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
            case 4: start = reverse_list(start);    break;
            case 5: start = swap_adjacent(start);   break;
            case 6: display(start); break;

        }
    }
}
