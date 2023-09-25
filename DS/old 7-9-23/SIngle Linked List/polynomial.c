#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define NEWLINE printf("\n")
struct poly
{
    int coeff;
    int power;
    struct poly* link;
};

//linked list functions
void display(struct poly* start);
struct poly* addatbeg(struct poly* start, int power, int coeff);
struct poly* addatend(struct poly* start, int power, int coeff);
struct poly* insert(struct poly* start, int coeff, int power);
struct poly* delete(struct poly* start, int power);

//impliment functions
int menu();
struct poly* accept(struct poly* start);
struct poly* addpoly(struct poly* start1, struct poly* data);
struct poly* multiplypoly(struct poly* start1, struct poly* start2);
struct poly* insert_term(struct poly* start);
struct poly* delete_list(struct poly* start);
struct poly* poly_from_file();

int main()
{
    struct poly *start1 =NULL, *start2 = NULL, *start3 = NULL;
    struct poly* add = NULL, *multiply = NULL;
    _Bool loop = trunc;
    int op;

    while(loop)
    {
        op=menu();
        switch (op)
        {

            case 1: start1 = accept(start1);
                    start2 = accept(start2);
                    printf("\nPolynomial 1: "); display(start1); NEWLINE;
                    printf("\nPolynomial 2: "); display(start2); NEWLINE;
                    NEWLINE;
                    break;
            case 2:
                    add = addpoly(start1,start2);
                    printf("\nAddition of Polynomial 1 and 2: ");display(add);NEWLINE;
                    break;
            case 3:
                    multiply = multiplypoly(start1, start2);
                    printf("\nMultiplication of Polynomial 1 and 2: ");display(multiply);NEWLINE;
                    break;
            case 4: printf("\nSelect polynomial");
                    printf("\n1. Polynomial 1 : "); display(start1);
                    printf("\n2. Polynomial 2 : "); display(start2); NEWLINE;
                    scanf("%d",&op);
                    if(op == 1){
                        start1 = insert_term(start1);
                        printf("\nPolynomial after insertion : "); display(start1); NEWLINE;
                        break;
                    }
                    if(op == 2){
                        start2 = insert_term(start2);
                        printf("\nPolynomial after insertion : "); display(start2); NEWLINE;
                        break;
                    }
                    else printf("\nINPUT ERROR!\n");
                    break;
            case 5: printf("\nSelect polynomial");
                    printf("\n1. Polynomial 1 : "); display(start1);
                    printf("\n2. Polynomial 2 : "); display(start2); NEWLINE;
                    scanf("%d",&op);
                    if(op == 1){
                        printf("Enter power of term to delete : "); scanf("%d",&op);
                        start1 = delete(start1, op);
                        printf("\nPolynomial after deletion : "); display(start1); NEWLINE;
                        break;
                    }
                    if(op == 2){
                        printf("Enter power of term to delete : "); scanf("%d",&op);
                        start2 = delete(start2, op);
                        printf("\nPolynomial after deletion : "); display(start2); NEWLINE;
                        break;
                    }
                    else printf("\nINPUT ERROR!\n");
                    break;
            case 6: start3 = poly_from_file();
                    printf("\nPolynomial from FILE : ");
                    display(start3);NEWLINE;
                    break;
            case 7: loop = 0;
                    break;
            default:
                    break;
        }
    }
}

// displays ooptions and returns the selected one
int menu(){
    int op;
    printf("*****MENU*****\n1.Accept two polynomial\n2.Add two polynomial\n");
    printf("3.Multiply two polynomials\n4.Insert a term in Polynomial\n");
    printf("5.Delete a term in Polynomial\n6.Accept polynomial from files\n7. Exit\n");
    printf("Enter your choice: "); scanf("%d",&op);
    return op;
}

/* LinkedList Functions */

// Takes in a pointer and displays the polymial
void display(struct poly* start)
{
        struct poly* p;
        if(start == NULL){printf("Empty list"); return;}
        p=start;
        while(p!=NULL){
            if(p != start) if(p->coeff > 0) printf("+");
            if(p->power == 0) 
                printf("%d",p->coeff);
            else if(p->coeff == 1)
                printf("x^%d",p->power);
            else
            printf("%dx^%d",p->coeff,p->power);
            p=p->link;
        }
}

// Takes in a pointer and two other argumments coeff and power 
// Adds a node to the list and returns it address
struct poly* addatbeg(struct poly* start, int coeff, int power)
{
    struct poly* tmp;
    tmp = (struct poly*)malloc(sizeof(struct poly));
    tmp->coeff = coeff;
    tmp->power = power;
    tmp->link = start;
    start = tmp;
    return start;
}

// Adds a node to the end of the list by treversing it and return its address
struct poly* addatend(struct poly* start, int coeff, int power)
{
    struct poly* p, * tmp;
    p=start;
    tmp = (struct poly*)malloc(sizeof(struct poly));
    tmp->coeff = coeff;
    tmp->power = power;
    while(p->link != NULL){
        p = p->link;
    }
    tmp->link = p->link;
    p->link = tmp;
    return start;
}

// combination of addatbeg and addatend
struct poly* insert(struct poly* start, int coeff, int power)
{
    if(!start){
        return addatbeg(start,coeff,power);
    }
    else{
        return addatend(start, coeff, power);
    }
}

struct poly* delete(struct poly* start, int power)
{
    struct poly* p = start, *tmp;
    if(start == NULL){
        printf("\nEmpty list\n");
        return start;
    }
    if(power == start->power){
        tmp = start;
        start = start->link;
        free(tmp);
        return start;
    }
    while(p->link != NULL){
        if(p->link->power == power){
            tmp = p->link;
            p->link = tmp->link;
            free(tmp);
            return start;
        }
        p = p->link;
    }
    printf("\nTerm was not found!\n");
}

/* Implementation Functions */

// Function to take in a Polynomial
struct poly* accept(struct poly* start)
{
    int n;
    int coeff, power;
    printf("Enter number of terms: "); scanf("%d",&n);
    if(n==0) return start;
    for(int i=1; i<=n; i++)
    {
        printf("Enter coeff of %d term: ",i+1); scanf("%d",&coeff);
        printf("Enter power of %d term: ",i+1); scanf("%d",&power);
        start = insert(start, coeff, power);
    }
    return start;
}

// Function to add two polynomial
struct poly* addpoly(struct poly* start1, struct poly* start2)
{
    struct poly *p1 = start1, *p2= start2, *start3 = NULL;
    int coeff, power;

    while(p1 && p2){
        if(p1->power == p2->power){
            coeff = p1->coeff + p2->coeff;
            start3 = insert(start3, coeff, p1->power);
            p1 = p1->link; p2 = p2->link;
        }else if(p1->power > p2->power){
            start3 = insert(start3,p1->coeff, p1->power);
            p1 = p1->link;
        }else{
            start3 = insert(start3,p2->coeff, p2->power);
            p2 = p2->link;
        }
    }
    while(p1){
            start3 = insert(start3,p1->coeff,p1->power);
            p1 = p1->link;
        }
    while(p2){
            start3 = insert(start3, p2->coeff, p2->power);
            p2 = p2->link;
    }
    return start3;
}

// Function to multiply two polynomial
struct poly* multiplypoly(struct poly* start1, struct poly* start2)
{
    struct poly* p1 =start1, *p2 = start1, *start3 = NULL, *tmp = NULL;
    int coeff, power;

    while(p1 != NULL){
        p2 = start2;
        tmp = NULL;
        while(p2 != NULL){
            coeff = p1->coeff * p2->coeff;
            power = p1->power + p2->power;
            tmp = insert(tmp, coeff, power);
            p2 = p2->link;
        }
        start3 = addpoly(start3, tmp);
        p1 = p1->link;
    }
    return start3;
}

// Inserts a term in a polynomial
struct poly* insert_term(struct poly* start)
{
    int coeff, power;
    struct poly* p = start, *tmp = NULL, *prev = NULL;
    tmp = (struct poly*)malloc(sizeof(struct poly));

    printf("Enter coeff of term: ");
    scanf("%d",&tmp->coeff);
    printf("Enter power of term: ");
    scanf("%d",&tmp->power);

    prev = p;
    while((p != NULL) && (p->power > tmp->power)){ //loop to make pointer stop at position of insertion
        prev = p;                            
        p = p->link;
    }
    if(p == start){
        tmp->link = p;
        start = tmp;
    }else if(p->power == tmp->power){
        p->coeff += tmp->coeff;
    }else{
        tmp->link = p;
        prev->link = tmp;
    }
    return start;
}

// Deletes the whole list
struct poly* delete_list(struct poly* start)
{
    while(start){
        start = delete(start, start->power);
    }
    return start;
}

struct poly* poly_from_file()
{
    #define M_COEFF  1
    #define M_POWER  2
    #define M_NCOEFF 13
    #define M_NPOWER 23
    struct poly* start = NULL;
    int coeff = 1, power = 1, tmp = 0, mode = 0;
    FILE *fp;
    fp = fopen("poly.txt","r");
    char c;
    
    while((c = fgetc(fp)) != '\n' && c != EOF){
        switch(c)
        {
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '0':
                tmp = (tmp * 10) + (c - '0') ;
                break;
            case '+':
                mode = M_COEFF;
                break;
            case '-':
                if(mode == M_POWER) mode = M_NPOWER;
                else mode = M_NCOEFF;
                break;
            case '^':
                mode = M_POWER;
                break;
            default : break;
        }
        
        if(mode == M_COEFF || mode == M_NCOEFF ){
            power *= tmp; 
            if(coeff != 0){
                start = insert(start, coeff, power);
            }
            if(mode == M_NCOEFF)
                coeff = -1;
            else
                coeff = 1;
            tmp = 0;
            mode = 0;
        }
        
        if(mode == M_POWER || mode == M_NPOWER){
            coeff *= tmp;
            if(mode == M_NPOWER)
                power = -1;
            else
                power = 1;
            tmp = 0;
            mode = 0;
        }
    }
    return start;
}

//3 4 3 5 2 -3 0 4 2 5 6 4 1 2 1 0
//1 3 4 3 5 2 -3 0 4 2 5 6 4 1 2 1 0
