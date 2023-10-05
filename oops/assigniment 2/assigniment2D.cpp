#include<iostream>
#include<stdlib.h>
#include<string.h>
#include <fstream>
using namespace std;

class book
{
    string title;
    string author;
    float retail_price;
    string publisher;
    int stock;
    void edit_price(float _price){
        retail_price = _price;
    }
public:
    book *next,* prev;
    book()
    {
        cout<<"Enter Title: "; getline(cin, title, '\n');
        cout<<"Enter author: "; getline(cin, author, '\n');
        cout<<"Enter retail price: "; cin>>retail_price; getchar();
        cout<<"Enter publisher: "; getline(cin, publisher, '\n');
        cout<<"Enter book stock: "; cin>>stock; getchar();
        next = prev = NULL;
    }
    string get_author(){
        return author;
    }
    string get_title(){
        return title;
    }
    int find_(string _title, string _author){
        return ((title == _title || author == _author));
    }
    int availablity(){
        return stock;
    }
    int edit_stock(int _stock){
        stock += _stock;
        return stock;
    }
    void display(){
        cout<<"Title: "<<title<<endl;
        cout<<"Author: "<<author<<endl;
        cout<<"Retail price: "<<retail_price<<endl;
        cout<<"Publisher: "<<publisher<<endl;
        cout<<"Stock: "<<stock<<endl;
    }
    void display_for_list(){
        cout<<"\nTitle: "<<title<<endl;
        cout<<"Author: "<<author<<endl;
        cout<<"Retail price: "<<retail_price<<endl;
    }

    // for file loading

    book(string t,string a,float p, string pup, int s){
        title = t;
        author = a;
        retail_price = p;
        publisher = pup;
        stock = s;
        prev = next = NULL;
    }

};


class booklist{
    book *head;
public:
    booklist(){
        head = NULL;
    }
    void load_stock();
    void display_booklist();//
    book *search_book();//
    void buy_book();//
    void new_stock();//
    void delete_book();//
};

void booklist :: new_stock()
{
    book * tmp = new book;
    if(head == NULL){
        head = tmp;
        tmp->prev = tmp->next = NULL;
        return;
    }
    book *p = head, *prev;
    while(p != NULL){
        if(p->find_(tmp->get_title(),tmp->get_author())){
            cout<<"Book already exists!"<<endl;
            return;
        }
        if(p->next == NULL){
            p->next = tmp;
            tmp->prev = p;
            tmp->next = NULL;
            return;
        }
        prev = p;
        p = p->next;
    }
}

book* booklist :: search_book()
{
    string term;
    cout<<"Enter the title or authors name : "<<endl;
    getline(cin, term, '\n');
    book *p = head;
    while(p != NULL){
        if(p->find_(term,term)){
            break;
        }
        p = p->next;
    }
    return p;
}

void booklist :: buy_book()
{
    static int s=0, us=0;
    book* tmp;
    tmp = search_book();
    if(tmp == NULL){
        us ++;
        cout<<"Book not available!"<<endl;
        cout<<us<<" Unsuccsessful transactions!"<<endl;
        return;
    }
    else {
        int q;
        tmp->display();
        cout<<"Enter quantity of books : ";
        cin>>q;
        if(tmp->availablity() >= q){
            s ++;
            tmp->edit_stock(-q);
            cout<<s<<" Successful Transactions!"<<endl;
            cout<<"\nRemaining Stock: "<< tmp->availablity()<<endl;
        }
        else{
            cout<<"Not sufficient stock!\nTry again!"<<endl;
        }
    }
}

void booklist :: delete_book()
{
    book* tmp;
    tmp = search_book();
    if(tmp == NULL){
        cout<<"Book not available!"<<endl;
        return;
    }
    else {
        tmp->display();
        cout<<"\nDeleting Stock...\n"<<endl;
        if(head->next == NULL){
            cout<<"\nBook Store is now Empty"<<endl;
        }else if(tmp == head){
            head = tmp->next;
            tmp->next->prev = NULL;
        }else if(tmp->next == NULL){
            tmp->prev->next = NULL;

        }else{
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
        }
        delete tmp;
    }
}

void booklist :: display_booklist()
{
    book* p;
    if(head == NULL){
        cout<<"\nNo books available!\n"<<endl;
        return;
    }
    p = head;
    while(p != NULL){
        p->display_for_list();
        p = p->next;
    }
}

void booklist :: load_stock()
{
    string title, author,pr, publisher, st;
    int stock;
    float price;
    int count = 0;
    ifstream myfile ("booklist.txt");
    if (myfile.is_open())
    {
        book* p;
        p = NULL;
        while ( getline (myfile,title,'\n') )
        {
            getline (myfile,author,'\n');
            getline (myfile,pr,'\n');
            price = stof(pr);
            getline (myfile,publisher,'\n');
            getline (myfile,st,'\n');
            stock = stof(st);
            book* tmp = new book(title,author,price,publisher,stock);
            count ++;
            if(p == NULL)
                head = tmp;
            else{
                p->next = tmp;
                tmp->prev = p;
            }
            p = tmp;
        }
    }
    else cout << "Unable to open file";
    myfile.close();
}

void MENU_for_operator(booklist & bk_list)
{
    int op;
    book* bk;
    while(true){
    cout<<"\n*****MENU*****\n";
    cout<<"1. Search book \n2. Display booklist\n3. New stock\n4. Delete book\n5. Exit"<<endl;
    cin>>op; getchar();

    switch(op){
    case 1: if((bk = bk_list.search_book()) == NULL){
                cout<<"Book Not Found!"<<endl;
            }else{
                cout<<"\nSearched Book\n"<<endl;
                bk->display();
            }
            break;
    case 2: bk_list.display_booklist(); break;
    case 3: bk_list.new_stock(); break;
    case 4: bk_list.delete_book(); break;
    case 5: return;
    default : cout<<"wrong Option Entered!"<<endl; break;
    }
    }
}


void MENU_for_customr(booklist & bk_list)
{
    int op;
    book* bk;
    while(true){
    cout<<"\n*****MENU*****\n";
    cout<<"1. Search book \n2. Buy Book\n3. Display booklist\n4. Exit"<<endl;
    cin>>op; getchar();
    switch(op){
    case 1: if((bk = bk_list.search_book()) == NULL){
                cout<<"Book Not Found!"<<endl;
            }else{
                cout<<"\nSearched Book\n"<<endl;
                bk->display();
            }
            break;
    case 2: bk_list.buy_book(); break;
    case 3: bk_list.display_booklist();break;
    case 4: return;
    default : cout<<"wrong Option Entered!"<<endl; break;
    }
    }
}

int main()
{
    int op;
    booklist bk_list;
    bk_list.load_stock();
    while(true){
        cout<<"\n1. Customer Menu\n2. Operator Menu\n3. Exit"<<endl;
        cin>>op;
        if(op == 1){
            MENU_for_customr(bk_list);
        }else if(op == 2){
            MENU_for_operator(bk_list);
        }else if(op == 3){return 0;}
        else cout<<"wrong Option Entered"<<endl;
    }
    return 0;
}
