#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#define BLANK ' '
#define TAB '\t'
#define MAX 50

struct variable{
    long int value;
    char c;
}variables[MAX];

long int stack[MAX];
char infix[MAX];
char prefix[MAX];
int top = -1, v_top =-1;

int is_operator(char symbol){
    if(symbol == '+' || symbol == '-' || symbol == '/' || symbol == '%' || symbol == '*' || symbol == '^')
        return 1;
    else return 0;
}

void push(long int symbol){
    if(top == MAX-1){
        printf("Stack OverFlow\n");
        return;
    }
    stack[++top] = symbol;
}
long int pop(){
    if(top == -1){
        printf("Stack Underflow\n");
        exit(1);
    }
    return(stack[top--]);
}

int instack_priority(char symbol){
    switch (symbol){
        case ')': return 0;
        case '+' :case '-' : return 1;
        case '/' :case '%' :case '*' : return 2;
        case '^' : return 4;
    }
}
int incoming_priority(char symbol){
    switch (symbol){
        case ')': return 0;
        case '+' :case '-' : return 1;
        case '/' :case '%' :case '*' : return 2;
        case '^' : return 3;
    }
}
int whitespace(char symbol){
    if(symbol == BLANK || symbol == TAB || symbol == '\0')
        return 1;
    else return 0;
}

void print_solution(int i, int j){
    printf("%c",infix[i]); printf("\t");
        for(int x=0; x<=top; x++)
            printf("%c",stack[x]);printf("\t");
        for(int x=0; x<j; x++)
            printf("%c",prefix[x]);
        printf("\n");
}

void infix_toprefix(){
    char infix_symbol, stack_symbol;
    int i, j = 0;
    i = strlen(infix);
    infix_symbol = infix[--i];
    while(!whitespace(infix_symbol)){
        switch (infix_symbol){
         case '+':case'-':case'*':case'/':case'%':case'^':
                while(top != -1 && (instack_priority(stack[top]) >= incoming_priority(infix_symbol))){
                    prefix[j++] = pop();
                }
                push(infix_symbol);
                break;
            case ')' : push(infix_symbol); break;

            case '(' :
                while (top != -1 && ((stack_symbol = pop()) != ')'))
                    prefix[j++] = stack_symbol;
                break;
            default :
                if(isalpha(infix_symbol))
                    prefix[j++] = infix_symbol;
                else {printf("Invalid Infix Character Encountered! "); exit(1);}
                break;
        }
        print_solution(i,j);
        infix_symbol = infix[--i];
    }
    while(top != -1)
        prefix[j++] = pop();
    print_solution(i,j);
    prefix[j] = '\0';
}

int search(char c){
    int i=0;
    while(i<=v_top){
        if(c == variables[i].c)
            return i;
        i++;
    }
    return -1;
}

void variable_value(){
    int i=0, pos;
    char ps = prefix[i];
    while(!whitespace(ps)){
        if(isalpha(ps)){
            pos = search(ps);
            if(pos == -1){
                variables[++v_top].c = ps;
                printf("\nEnter value of %c : ",ps);
                scanf("%d",&variables[v_top].value);
            }
        }
        ps = prefix[++i];
    }
}

long int evaluate_prefix(){
    int i = 0, pos;
    top = -1;
    char ps = prefix[i];
    while(!whitespace(ps)){
        if(is_operator(ps)){
            int a, b;
            b = pop();
            a = pop();
            switch (ps){
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
                case '%': push(a % b); break;
                case '^': push(pow(a,b)); break;
            }
        }
        if(isalpha(ps)){
            pos = search(ps);
            stack[++top] = variables[pos].value;
        }
        ps = prefix[++i];
    }
    return pop();
}

int main()
{
    int n;
    char item;

    printf("Enter Infix Expression: "); gets(infix);
    infix_toprefix();

    printf("Prefix Equation: ");
    for(int i = sizeof(prefix); i>=0; i--)
        printf("%c",prefix[i]);

    printf("\n\nEnter values of variables\n");
    variable_value();

    long int result = evaluate_prefix();
    printf("\nElvaluating prefix function...\n");
    printf("Result = %d",result);

return 0;
}
