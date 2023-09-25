#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int info;
    struct node* link;

};

void display(struct node* start);
struct node* addatbeg(struct node* start, int data);
struct node* deletenode(struct node* start, int data);

struct node* UNION(struct node* startA, struct node* startB);
struct node* INTERSECTION(struct node* startA, struct node* startB);
struct node* DIFFERENCE(struct node* start1, struct node* start2);


int main()
{
	struct node* startA = NULL , * startB = NULL, *startC = NULL;
	int n1, n2;
    int data;
	bool loop=true;
	int option;

	printf("Enter size of set A: "); scanf("%d",&n1);
	printf("Enter the elements of set A: \n");
	for(int i=0 ; i<n1; i++){
		printf("Enter element: "); scanf("%d",&data);
 		startA = addatbeg(startA,data);
	}
	printf("Enter size of set B: "); scanf("%d",&n2);
	printf("Enter the elements of set B: \n");
	for(int i=0 ; i<n2; i++){
		printf("Enter element: "); scanf("%d",&data);
		startB = addatbeg(startB,data);
	}

	while(loop){
		printf("*****MENU*****\n1.Union\n2.Intersection\n3.Difference\n4.Exit\n");
		printf("Enter option: "); scanf("%d",&option);

		switch(option)
		{
			case 1: startC = UNION(startA, startB);
                    display(startC);
                    break;
			case 2: startC = INTERSECTION(startA, startB);
                    display(startC);
                    break;
			case 3: {
                    printf("1. A - B\n2. B - A\nEnter option: ");
                    scanf("%d",&option);
                    switch(option){
                    case 1: startC = DIFFERENCE(startA,startB);
                            display(startC);
                            break;
                    case 2: startC = DIFFERENCE(startB, startA);
                            display(startC);
                            break;
                    default: printf("\nInput error!\n"); break;
                    }
                }
                break;

			case 4: loop = false; break;

			default : printf("\nEnter correct option!\n"); continue;
		}
	}
	return 0;
}

//linked list functions
struct node* addatbeg(struct node* start, int data)
{
	struct node* tmp = (struct node*)malloc(sizeof(struct node));
	if(tmp == NULL) return start;
	tmp->info = data;
	tmp->link = start;
	start = tmp;
	return start;
}

void display(struct node* start)
{
    struct node* p;
    if(start == NULL){
        printf("\nEmpty list!\n");
        return;
    }
    p = start;
    while(p!=NULL){
        printf("%d\t",p->info);
        p = p->link;
    }
    printf("\n");
}

struct node* deletenode(struct node* start, int data)
{
    struct node* p, *tmp;
    if(start == NULL){
        printf("\nEmpty list!\n");
        return start;
    }
    if(start->info == data){
        tmp = start;
        start = start->link;
        free(tmp);
        return start;
    }
    p = start;
    while(p->link != NULL){
        if(p->info == data){
            tmp = p->link;
            p->link = tmp->link;
            free(tmp);
            return start;
        }
        p = p->link;
    }
    printf("\nData not found!\n");
    return start;
}

//Custom funtions
struct node* UNION(struct node* startA, struct node* startB)
{

	struct node *p1, *p2, *p3, *startC = NULL;
	bool flag;
	p1 = startA;
	p2 = startB;
    while(p1 != NULL){
		startC = addatbeg(startC, p1->info);
		p1 = p1->link;
	}

	while(p2 != NULL){
        p3 = startC;
        flag = false;
		while(p3 != NULL){
			if(p2->info == p3->info){
				flag = true;
				break;
			}
			p3 = p3->link;
		}
		if(!flag){
			startC = addatbeg(startC, p2->info);
		}
		p2 = p2->link;
	}
    return startC;
}


struct node* INTERSECTION(struct node* startA, struct node* startB)
{
    struct node *p1, *p2, *startC = NULL;
	p1 = startA;
	p2 = startB;

	while(p1 != NULL){
        p2 = startB;
		while(p2 != NULL){
			if(p1->info == p2->info){
				startC = addatbeg(startC, p2->info);
				break;
			}
			p2 = p2->link;
		}
		p1 = p1->link;
	}
    return startC;
}


struct node* DIFFERENCE(struct node* start1, struct node* start2)
{
    struct node* p1, *p2, *start3 = NULL;
    p1 = start1;
    p2 = start2;
    while(p1 != NULL){
        p2 = start2;
        while(p2 != NULL){
            if(p1->info == p2->info){
                break;
            }
            p2 = p2->link;
        }

        if(p2 == NULL){
            start3 = addatbeg(start3,p1->info);
        }
        p1 = p1->link;
    }
    return start3;
}
