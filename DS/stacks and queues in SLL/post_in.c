#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 50

char postfix[MAX];
char infix[MAX];

struct node{
    char *ch;
    struct node *link;
} *top = NULL;

int is_op(int *c){
    if(c == '+' || c == '-'|| c == '/'|| c == '*' || c == '%')
        return 1;
    else return 0;
}

int isEmpty(){
    return top == NULL;
}

void push(char *ch){
    struct node * tmp = (struct node*)malloc(sizeof(struct node));
    tmp->ch = ch;
    tmp->link = top;
    top = tmp;
}
void push_node(struct node* p){
    top = p;
}

struct node* pop(){
    if(isEmpty()){
        printf("Stack underflow! \n");
    }
    struct node *tmp = top;
    char* ch;
    ch = top->ch;
    top = top->link;
    return tmp;
}

int length(struct node *p){
    int len = 1;
    while (p != NULL){
        len++;
        p = p->link;
    }
    return len;
}

void display(struct node* p){
    if(isEmpty()){
        printf("Stack Underflow!\n");
        return;
    }
    if(p->link != NULL)
        display(p->link);
    if(p->ch == "(" || p->ch == ")")
        printf("%s",p->ch);
    else
        printf("%c",p->ch);
}

void push_all(struct node* op1, struct node* op2, char *op){
    struct node* tmp = op1;
    while(!isEmpty()){
        tmp = pop();
    }
    push("(");
    tmp->link = top;
    push_node(op1);
    push(")");
    push(op);
    push(op2->ch);
}

void postfix_to_infix(){
    char *item;
    for(int i = 0; i <= strlen(postfix); i++){
        item = postfix[i];

        if(is_op(item)){
            struct node *op2 = pop();
            struct node *op1 = pop();
            push_all(op1, op2,item);

        }
        else{
            push(item);
        }
    }
}

int main(){

    printf("Enter a Postfix Expression: ");
    gets(postfix);
    printf("Converting....\n");
    postfix_to_infix();

    printf("Infix: ");
    display(top);
}
