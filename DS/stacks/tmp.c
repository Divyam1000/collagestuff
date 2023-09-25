#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#define BLANK ' '
#define TAB '\t'
#define MAX 50

// structure top store value of variables of postfix equation
struct variable{
    float value;
    char c;
}variables[MAX];

float stack[MAX];
char infix[MAX];
char postfix[MAX];
int top = -1, v_top =-1;

int is_operator(char symbol){
    if(symbol == '+' || symbol == '-' || symbol == '/' || symbol == '%' || symbol == '*' || symbol == '^')
        return 1;
    else return 0;
}

void push(float symbol){
    if(top == MAX-1){
        printf("Stack OverFlow\n");
        return;
    }
    stack[++top] = symbol;
}
float pop(){
    if(top == -1){
        printf("Stack Underflow\n");
        exit(1);
    }
    return(stack[top--]);
}

int instack_priority(char symbol){
    switch (symbol){
        case '(': return 0;
        case '+' :case '-' : return 1;
        case '/' :case '%' :case '*' : return 2;
        case '^' : return 3;
        default : printf("Invalid operator");
    }
}
int incoming_priority(char symbol){
    switch (symbol){
        case '(': return 0;
        case '+' :case '-' : return 1;
        case '/' :case '%' :case '*' : return 2;
        case '^' : return 4;
        default : printf("Invalid operator");
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
            printf("%c",postfix[x]); 
        printf("\n");
}

void infix_topostfix()
{ 
    char infix_symbol, stack_symbol, temp[MAX];
    int i = 0, j = 0;
    infix_symbol = infix[i];
    while(!whitespace(infix_symbol))
    {  
        switch (infix_symbol){
            case '+':case'-':case'*':case'/':case'%':case'^':
                while(top != -1 && (instack_priority(stack[top]) >= incoming_priority(infix_symbol))){
                    postfix[j++] = pop();
                }
                push(infix_symbol);
                break;
            case '(' : push(infix_symbol); break;
            
            case ')' : 
                while (top != -1 && ((stack_symbol = pop()) != '('))
                    postfix[j++] = stack_symbol;
                break;
            default :
                if(isalpha(infix_symbol))
                    postfix[j++] = infix_symbol;
                else {printf("Invalid Infix Character Encountered! "); exit(1);}
                break;
        }
        print_solution(i,j);
        infix_symbol = infix[++i];
    }
    while(top != -1)
        postfix[j++] = pop();
    print_solution(i,j);
    postfix[j] = '\0';
}
// serches the struct variables array to find if the passed character (which denotes to variable) is present 
// and return its position in the array 
int search(char c){
    int i=0;
    while(i<=v_top){
        if(c == variables[i].c)
            return i;
        i++;
    }
    return -1;
}
// Scans all possible characters or variables in the postfix and passes as them to struct variables[]
// data member char c, this is basically the identefier of the variable 
// it then takes in the value for the variable and stores in struct variables[]
void variable_value() {
    int i = 0, pos;
    char ps = postfix[i];
    while (!whitespace(ps)) {
        if (isalpha(ps)) {
            pos = search(ps);
            if (pos == -1) {
                variables[++v_top].c = ps;
                printf("\nEnter value of %c : ", ps);
                scanf("%f", &variables[v_top].value); // Use %f for float input
            }
        }
        ps = postfix[++i];
    }
}

long float evaluate_potfix() { // Change the return type to float
    int i = 0, pos;
    top = -1;
    char ps = postfix[i];
    while (!whitespace(ps)) {
        if (is_operator(ps)) {
            float a, b; // Change from int to float
            b = pop();
            a = pop();
            switch (ps) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
                case '%': push(fmod(a, b)); break; // Use fmod for floating-point modulus
                case '^': push(pow(a, b)); break;
            }
        }
        if (isalpha(ps)) {
            pos = search(ps);
            stack[++top] = variables[pos].value;
        }
        ps = postfix[++i];
    }
    return pop();
}

int main()
{
    int n;
    char item;
    
    printf("Enter Infix Expression: "); gets(infix);
    infix_topostfix();

    printf("\nEnter values of variables\n");
    variable_value();

    long int result = evaluate_potfix();
    printf("\nElvaluating postfix function...\n");
    printf("Result = %f",result);

return 0;
}