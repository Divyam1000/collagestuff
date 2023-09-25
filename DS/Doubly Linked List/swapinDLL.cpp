
struct node* swap(struct node *start){
    if(start == NULL){
        printf("Empty list\n");
        return start;
    }
    struct node *p = start;
    while(p->next != NULL && p != NULL){
        p = p->next;
        p->prev->next = p->next;
        p->next = p->prev;
    }
}
