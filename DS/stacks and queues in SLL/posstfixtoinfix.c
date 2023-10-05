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

int is_op(int c){
    if(c == '+' || c == '-'|| c == '/'|| c == '*' || c == '%')
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
    char ch = "\0";
    //struct node* tmp = top;
    if(isEmpty()){
        printf("Queue Underflow! \n");
        return ch;
    }
    ch = top->ch;
    top = top->link;
    return ch;
}

void display(){
    struct node *p = top;
    if(isEmpty()){
        printf("Stack Underflow!\n");
        return;
    }
    while(p!= NULL){
        printf("%c\n",p->ch);
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
    int size = sizeof(exp1);
    push("(");
    for(int i = size - 1; i>=0 ; i--){
        push(exp1[i]);
    }
    push(op);
    push(exp2);
    push(")");
}

char all_pop(){
    char *exp = NULL;
    int index = 0;
    char ch;
    while(!isEmpty()){
        ch = pop();
        exp = (char*)realloc(exp,sizeof(char)*(index+1));
        exp[index] = ch;
        index ++;
    }
    return exp;
}

void postfix_to_infix(){
    int i = 0;
    while(i<=strlen(postfix)){
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
    display();
    i =length()-1;
    while(i>=0){
        infix[i] = pop();
        i--;
    }
}


int main(){

    printf("Enter a Postfix Expression: ");
    gets(postfix); printf("%s",postfix);
    printf("Converting....\n");
    postfix_to_infix();

    printf("Infix: ");
    puts(infix);
}
