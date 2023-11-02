
//oops project
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<iomanip>
using namespace std;

class ticket{
    public:
    string cname;
    int tno;
    string destination;

    ticket(string name,int no,string dest){
        cname=name;
        tno=no;
        destination=dest;
    }

   void putdata(void)
    {
        cout << setw(10) << tno<< setw(10) << cname<< setprecision(2) << setw(10) << destination<< endl;
    }

};


void option1(ticket &tkt){
    ofstream file(to_string(tkt.tno) + ".txt");
    if(file.is_open()){
        file<<"Name : "<<tkt.cname<<endl;
        file<<"Ticket Number : "<<tkt.tno<<endl;
        file<<"Destination : "<<tkt.destination<<endl;
        file.close();
        cout << "Item details saved to file." << endl;
    }
    else{
        cout<<"Culd not create file.\n";
    }
}

void option2(int tno, int tno_new){
        fstream inoutfile; // input/output stream
        inoutfile.seekg(0,ios::beg);
        string file_old = to_string(tno);
        string file_new = to_string(tno_new);
        //strcat(fname,".txt");
        file_old=file_old+".txt";
        file_new=file_new+".txt";
        char oldname[] = "file_old.txt";
        char newname[] = "file_new.txt";
        /*	Deletes the file if exists */
        if (rename(oldname, newname) != 0)
            perror("Error renaming file");
        else
            cout << "File renamed successfully";

        inoutfile.open(file_new.c_str(), ios:: in | ios::out | ios::binary);
        int location = 0;
        if(inoutfile.eof())
            inoutfile.clear();
        inoutfile.seekp(location);
        inoutfile.write((char *) & tno_new, sizeof tno_new) << flush;
        /* >>>>>>>>>>>>> SHOW UPDATED FILE<<<<<<<<<<<<<<< */
        inoutfile.seekg(0); //go to the start
        cout << "CONTENTS OF UPDATED FILE \n";
        while(inoutfile.read((char *) & tkt, sizeof *tkt))
        {
            tkt.putdata();
        }
        inoutfile.close();
}



void option3(int tno,float price){
        ofstream fout;
        ifstream fin;
        string fname = to_string(tno);
        //strcat(fname,".txt");
        fname=fname+".txt";
        fin.open(fname.c_str());
        fout.open(fname.c_str(), ios::app);
        if(fin.is_open()){
            fout<<"price:"<<price;
            cout<<"\n Price has been appended to file"<<endl;
            cout<<"The updated Ticket         details are:\n";
            char r;
            while(!fin.eof())
                {
                    fin>>r;
                    cout<<r;
                }
                fin.close();
                fout.close();
                }
        else {
            cout<<"The ticket you are looking for isn't booked \n";
        }
    }

int main() {
    int choice;
    int tno,tcount,tno_new;
    float price;
    string cn,dest;
    ticket *tkt[100];


    while (1) {
        cout << "Ticket Reservation System" << endl;
        cout << "1. Enter Ticket Details " << endl;
        cout << "2. Edit Ticket Number and Display Updated Content" << endl;
        cout << "3. Append Price to a Ticket File and Display Appended Content" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout<<"Enter customer name : ";
                cin.ignore();
                getline(cin,cn);
                cout<<"Enter Ticket Number :";
                cin>>tno;
                cout<<"Enter Destination : ";
                cin.ignore();
                getline(cin,dest);
                tkt[tno]=new ticket (cn,tno,dest);
                option1(tkt[tno]);
                break;

            case 2:
                cout<<"\nEnter ticket no to be edited: ";
                cin>>tno;
                cout<<"\nEnter the new ticket no :";
                cin>>tno_new;
                option2(tno,tno_new);
                break;
            case 3:
                cout<<"Enter the ticket no:"<<endl;
                cin>>tno;
                cout<<"enter the price: ";
                cin>>price;
                option3(tno,price);
                break;

            case 4:
                exit(1);

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}


