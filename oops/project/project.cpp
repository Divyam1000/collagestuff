#include<iostream>
#include<fstream>
#include<string.h>
#include<stdio.h>
using namespace std;

class ticket
{
public:
    string cname;
    string tno;
    string destination;
    float price;

    ticket():price(0){}
    void display_details();
    //option 1
    static void option1();
    //puts the details from ptr to file
    static void put_details_tofile(ticket *ptr);
    //option 2
    static void option2();
    //edit ticket number (tno)
    static void edit_tno_infile(ticket *old_T, ticket *new_T);
    //option 3
    static void option3();
    //add price to file
    static int add_price_tofile(ticket *ptr);
};

void ticket :: display_details()
{
    string ticketNo = tno + ".txt";
    fstream ticketFile;
    ticketFile.open(ticketNo, ios::in|ios::binary);
    //checks if file exists
    ticketFile.seekg(0);
    if(ticketFile){
        ticketFile.read((char*)this, sizeof(*this));
        ticketFile.close();
    }
    else
    {
        ticketFile.close();
        cout<<"\nFile does not exist !\n";
        return;
    }

    cout<<"\nTicket No. : "<<tno<<endl;
    cout<<"Customer Name : "<<cname<<endl;
    cout<<"Destination : "<<destination<<endl;
    if(price != 0){
        cout<<"Price : "<<price<<endl;
    }
}

void ticket :: option1()
{
    ticket T;
    cout<<"\nEnter details:\n";
    cout<<"Enter customer name : ";
    cin.ignore();
    getline(cin,T.cname);
    cout<<"Enter Ticket Number : ";
    getline(cin,T.tno);
    cout<<"Enter Destination : ";
    getline(cin,T.destination);
    put_details_tofile(&T);
    T.display_details();
}
void ticket :: put_details_tofile(ticket *ptr)
{
    string ticketNo = ptr->tno + ".txt";

    fstream ticketFile;
    ticketFile.open(ticketNo, ios::in);
    //checks if file exists
    if(!ticketFile){
        //creates a new file if does not exist
        ticketFile.close();
        ticketFile.open(ticketNo, ios::out|ios::binary);
        ticketFile.write((char*)ptr,sizeof(*ptr));
    }
    else{
        //gives error if file exists
        cout<<"\nFile already exists!"<<endl;
    }
    ticketFile.close();
}

void ticket :: option2()
{
    ticket old_T, new_T;
    cout<<"\nEnter ticket no to be edited : ";
    cin>>old_T.tno;
    cout<<"\nEnter the new ticket no : ";
    cin>>new_T.tno;

    ticket::edit_tno_infile(&old_T,&new_T);
    new_T.display_details();
}

void ticket :: edit_tno_infile(ticket *old_T, ticket *new_T)
{
    string Ticket_old = old_T->tno + ".txt";
    string Ticket_new = new_T->tno + ".txt";

    //creating updated file
    fstream ticketFile;
    ticketFile.open(Ticket_old,ios::in|ios::binary);
    ticketFile.seekg(0);
    if(!ticketFile){
        cout<<"\nTicket with ticket number "<<old_T->tno<<" does not exist!\n"<<endl;
    }
    else{
        // read data from file in old_T
        ticketFile.read((char*)old_T,sizeof(*old_T));
        old_T->tno = new_T->tno;
        ticketFile.close();
        //deleting old file
        char temp[Ticket_old.length() + 1];
        strcpy(temp, Ticket_old.c_str());
        if(remove(temp) != 0){
            cout<<"/nError in deleting old file !"<<endl;
            return;
        }

        // create new file with new name
        ticketFile.open(Ticket_new, ios::in);
        if(ticketFile){
            cout<<"/nFile already exists !/n";
        }
        else{
            ticketFile.close();
            ticketFile.open(Ticket_new, ios::out|ios::binary);
            ticketFile.seekg(0);
            ticketFile.write((char*)old_T, sizeof(*old_T));
        }
    }
    ticketFile.close();
}

void ticket :: option3()
{
    ticket T;
    cout<<"\nEnter Ticket number : ";
    cin>>T.tno;
    cin.ignore();
    cout<<"\nEnter ticket price: ";
    cin>>T.price;
    if(ticket :: add_price_tofile(&T) == 0)
        T.display_details();
}

int ticket :: add_price_tofile(ticket *ptr)
{
    string ticketNo = ptr->tno + ".txt";
    fstream ticketFile;
    ticket temp;

    ticketFile.open(ticketNo, ios::in|ios::binary);
    //checks if file exists
    if(ticketFile){
        //copys contents from file to temp
        ticketFile.seekg(0);
        ticketFile.read((char*)&temp, sizeof(temp));
        ticketFile.close();
        //update price in temp
        temp.price = ptr->price;
        //update contents of file
        ticketFile.open(ticketNo, ios::out|ios::binary);
        ticketFile.seekg(0);
        ticketFile.write((char*)&temp,sizeof(temp));
    }
    else{
        //gives error if file does not exists
        cout<<"\nFile does not exists!"<<endl;
        return 1;
    }
    ticketFile.close();
    return 0;
}

int main()
{
    int choice;

    while (1)
    {
        cout << "\nTicket Reservation System" << endl;
        cout << "1. Enter Ticket Details " << endl;
        cout << "2. Edit Ticket Number and Display Updated Content" << endl;
        cout << "3. Append Price to a Ticket File and Display Appended Content" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            ticket::option1();
            break;

        case 2:
            ticket::option2();
            break;

        case 3:
            ticket::option3();
            break;

        case 4:
            return 0;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }
    return 0;
}
