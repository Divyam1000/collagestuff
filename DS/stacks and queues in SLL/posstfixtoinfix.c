#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 50

char postfix[MAX];
char infix[MAX];

struct node{
    char ch;
    struct node *link;
} *top = NULL;

int is_op(char c){
    if(strcmp(c,"+")||strcmp(c,"-")||strcmp(c,"/")||strcmp(c,"*")||strcmp(c,"%"))
        return 1;
    else return 0;
}

int isEmpty(){
    return top == NULL;
}

void push(char data){
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    if(tmp == NULL){
        printf("Stack Overflow\n");
        return;
    }
    tmp->ch = data;
    tmp->link = top;
    top = tmp;
}

char pop(){
    char ch;
    struct node* tmp = top;
    if(isEmpty()){
        printf("Queue Underflow! \n");
        return "\0";
    }
    ch = top->ch;
    top = top->link;
    free(tmp);
    return ch;
}

void display(){
    struct node *p = top;
    if(isEmpty()){
        printf("Stack Underflow!\n");
        return;
    }
    while(p!= NULL){
        printf("%d\n",p->ch);
        p = p->link;
    }
}

int length(){
    struct node * link = top;
    int len = 0;
    while (link != NULL){
        len++;
        link = link->link;
    }
    return len;
}

void all_push(char *exp1, char exp2, char op){
    push("(");
    for(int i = strlen(exp1); i>=0 ; i--)
        push(exp1[i]);
    push(op);
    push(exp2);
    push(")");
}

char *all_pop(){
    char *exp = (char*)malloc(sizeof(char)*length());
    int index = 0;
    while(top != NULL){
        exp[index] = pop();
        index++;
    }
    return exp;
}

void postfix_to_infix(){
    int i = 0;
    while(i<sizeof(postfix)){

        char item = postfix[i];

        if(is_op(item)){
            char operand2 = pop();
            char *operand1 = all_pop();
            all_push(operand1,operand2,item);
        }

        else{
            push(item);
        }
        i++;
    }
    for(;i>=0;i--){
        infix[i] = pop();
    }
}


int main(){

    printf("Enter a Postfix Expression: ");
    gets(postfix);

    postfix_to_infix();

    printf("InfixL: ");
    puts(infix);
}
