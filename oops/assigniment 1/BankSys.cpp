#include <iostream>
#include<string.h>
#include<time.h>
#include<stdlib.h>
using namespace std;

#define CLEAR_SCREEN (cout<<"\033[2J"<<"\033[H")
#define MENU (cout<<"******** MENU ********\n 1. Deposit\n 2. Withdraw\n 3. Check Balance \n 4. Exit\n")

int base = rand()*100;

struct account
{
    int acc_no;
    char name[20];
    float balance;
    int trans;
};

void create_account(struct account *p,int i);
void deposit(struct account *p);
bool withdraw(struct account *p);
void check_balance(struct account *p);
bool close();
struct account* search(struct account *p, int acc_no, int n);

int main()
{
    int n;
    bool loop=true;
    int choice;
    cout<<"Enter the number of Customers: "; 
    cin>>n;
    if(n==0) exit(0);
    struct account *p = (struct account*)malloc(n*sizeof(struct account));
    for(int i=0; i<n; i++)
    {
        create_account(&p[i],i);
    }
    while(loop){
        int acc_no;
        struct account *pass;
        char c;
        cout<<"\nEnter Account Number: "; cin>>acc_no;
        pass = search(p,acc_no,n);
        if(pass == NULL){
            CLEAR_SCREEN;
            cout<<"\nAccount not found!"<<endl; loop = close();
        }
        else{
            MENU;
            cin>>choice;
            switch(choice)
            {
                case 1 : deposit(pass); 
                         CLEAR_SCREEN; loop = close(); break;
                case 2 : if(withdraw(pass)){ CLEAR_SCREEN; cout<<"\nTransaction Sucessful!\n";
                         loop = close(); break; }
                         else  {cout<<"\nExceded withdraw trials!\nRe-enter credentials or ";
                         loop = close() ;break;}
                case 3 : check_balance(pass); loop = close(); break;
                case 4 : loop = false; break;
                default : CLEAR_SCREEN; cout<<"\nInvalid input!\n"; loop = close(); break;
            }
        }
    } 
    CLEAR_SCREEN;
    return 0;
}

void create_account(struct account *p,int i)
{
    cout<<"\nEnter Name: ";
    cin>>p->name;
    p->acc_no = base+i;
    cout<<"\nYour Account number is : "<<p->acc_no<<endl;
    p->trans = 0;
    p->balance = 0;
}
void deposit(struct account *p)
{
    CLEAR_SCREEN;
    float temp;
    cout<<"\nEnter deposit ammout : "; cin>>temp;
    p->balance+=temp;
    p->trans++;
    CLEAR_SCREEN;
}
bool withdraw(struct account *p)
{
    CLEAR_SCREEN;
    float temp; int loop=3;
    while(loop>0){
    cout<<"\nEnter withdraw amount: "; cin>>temp;
    if(temp<500){
        CLEAR_SCREEN;
        cout<<"\nEnter Greater ammount!"<<endl;
        loop--;
    }
    else if(temp>p->balance){
        CLEAR_SCREEN;
        cout<<"\nExceding account balance!"<<endl;
        loop--;
    }
    else{
        p->balance -= temp;
        p->trans++;
        return true;
    }
    }
    return false;
}
void check_balance(struct account *p)
{
    cout<<"Account Holder: "<<p->name<<endl;
    cout<<"Account Number: "<<p->acc_no<<endl;
    cout<<"Balance Number: "<<p->balance<<endl;
}
bool close()
{
    char c;
    cout<<"\nDO you want to continue (y/n): "; cin>>c;
    if(c=='y'||c=='Y') {  CLEAR_SCREEN; return true;}
    else {CLEAR_SCREEN; return false;}
}
struct account* search(struct account *p, int acc_no, int n)
{
    for(int i=0; i<n; i++){
        if(p[i].acc_no == acc_no)
            return &p[i];
    }
    return NULL;
}
