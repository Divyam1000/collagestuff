#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int emp_no = 10;

struct employee{
    int ID;
    char name[30];
};

void setEmployee(struct employee * ptr){
    ptr[1].ID = 101;
    strcpy(ptr[1].name , "james");
    ptr[2].ID = 102;
    strcpy(ptr[2].name, "mark");
    ptr[3].ID = 103;
    strcpy(ptr[3].name , "ryan");
    ptr[4].ID = 104;
    strcpy(ptr[4].name , "coddy");
    ptr[5].ID = 105;
    strcpy(ptr[5].name , "drake");
    ptr[6].ID = 106;
    strcpy(ptr[6].name , "john");
    ptr[7].ID = 107;
    strcpy(ptr[7].name , "jamal");
    ptr[8].ID = 108;
    strcpy(ptr[8].name , "abdul");
    ptr[9].ID = 109;
    strcpy(ptr[9].name , "ramesh");
    ptr[10].ID = 110;
    strcpy(ptr[10].name , "suresh");
}

int linearSearch(int id, struct employee *ptr){
    int i = 0;
    while(i<emp_no && id!=ptr[i].ID)
        i++;
    if(i<emp_no)
        return i;
    else return -1;
}

int binarySearchNonRec(int id, struct employee *ptr){
    int low = 0, up = emp_no, mid;
    while(low <= up){
        mid = (low = up)/2;
        if(id > ptr[mid].ID)
            low = mid + 1;
        else if(id > ptr[mid].ID)
            up = mid - 1;
        else return mid;
    }
    return -1;
}

int binarySearchRec(int id, struct employee *ptr, int low, int  up){
    int mid;
    if(low > up)
        return -1;
    mid = (low + up)/2;
    if(id > ptr[mid].ID)
        binarySearchRec(id, ptr, mid+1, up);
    else if(id < ptr[mid].ID)
        binarySearchRec(id, ptr, low, mid-1);
    else
        return mid;
}

int getID(){
    int id;
    printf("Enter ID to search Employee : "); scanf("%d",&id);
    return id;
}

void printDetails(int index, struct employee *ptr){
    if(index == -1){
        printf("Employee not found !\n");
        return;
    }
    else{
        printf("Employee Details: \n");
        printf("Employee ID : %d\n",ptr[index].ID);
        printf("Employee Name : %s\n",ptr[index].name);
    }
}

int main()
{
    struct employee* emp = ( struct employee*)malloc(sizeof(struct employee) * emp_no);
    setEmployee(emp);
    int ch, index;
    while(1){
        printf("\n*****MENU*****\n");
        printf("1.Linear search\n2.Binary search Recursive\n3.Binary search Non Recursive\n4.Hashing\n5.Exit\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
        case 1:
            printDetails(linearSearch(getID(),emp),emp);
            break;
        case 2:
            printDetails(binarySearchRec(getID(),emp,0, emp_no-1),emp);
            break;
        case 3:
            printDetails(binarySearchNonRec(getID(),emp),emp);
            break;
        case 4:
            //printDetails(hashing(getID(),emp),emp);
            break;
        case 5:
            return 0;
        default: printf("Incorrect Input!\n");
        }
    }
}

