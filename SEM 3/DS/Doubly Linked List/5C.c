#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void deleteAlt(struct node* last) {
    if (last == NULL)
        return;
    struct node* prev = last;
    struct node* node = last->next;
    while (prev != NULL && node != NULL) {
        prev->next = node->next;
        free(node);
        prev = prev->next;
        if (prev != NULL)
            node = prev->next;
    }
}

void push(struct node* last, int new_data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    if(last == NULL){
        new_node->next = new_node;
        last = new_node;
        return last;
    }
    new_node->next = last->next;
    last->next = new_node;
    last = new_node;
    return last;
}

void printList(struct node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct node* last = NULL;
    last = push(last, 5);
    last = push(last, 4);
    last = push(last, 3);
    last = push(last, 2);
    last = push(last, 1);
    printf("List before calling deleteAlt(): ");
    printList(last);
    deleteAlt(last);
    printf("\nList after calling deleteAlt(): ");
    printList(last);
    return 0;
}
