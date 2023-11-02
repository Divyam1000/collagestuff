
//oopsproject
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

    ticket(){}

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


void option2(int tno, int tno_new) {
    fstream inoutfile;
    string file_old = to_string(tno) + ".txt";
    string file_new = to_string(tno_new) + ".txt";

    if (rename(file_old.c_str(), file_new.c_str()) == 0) {
        cout << "File renamed successfully" << endl;
    } else {
        perror("Error renaming file");
        cout << "File rename failed" << endl;
        return;
    }

    inoutfile.open(file_new.c_str(), ios::in | ios::out | ios::binary);
    if (inoutfile.is_open()) {
        int location = 0;
        if (inoutfile.eof())
            inoutfile.clear();
        inoutfile.seekp(location, ios::beg);
        inoutfile.write((char *) &tno_new, sizeof tno_new) << flush;

        inoutfile.seekg(0);
        cout << "CONTENTS OF UPDATED FILE \n";
        ticket tkt;
        while (inoutfile.read((char *)&tkt, sizeof tkt)) {
            tkt.putdata();
}
        inoutfile.close();
    } else {
        cout << "Could not open the file for editing.\n";
    }
}

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

void option2(int tno, int tno_new) {
    fstream inoutfile;

    // Generate the filenames for the old and new files
    string file_old = to_string(tno) + ".txt";
    string file_new = to_string(tno_new) + ".txt";

    // Open the old file for reading
    inoutfile.open(file_old.c_str(), ios::in | ios::binary);

    if (inoutfile.is_open()) {
        // Open the new file for writing
        ofstream newFile(file_new.c_str(), ios::out | ios::binary);

        if (newFile.is_open()) {
            // Update the ticket number and write to the new file
            ticket tkt;
            while (inoutfile.read((char *)&tkt, sizeof tkt)) {
                tkt.tno = tno_new;
                newFile.write((char *)&tkt, sizeof tkt);
            }
            newFile.close();
            inoutfile.close();

            // Display the updated contents
            cout << "File renamed successfully\n";
            cout << "CONTENTS OF UPDATED FILE \n";
            ifstream updatedFile(file_new.c_str(), ios::in | ios::binary);
            while (updatedFile.read((char *)&tkt, sizeof tkt)) {
                tkt.putdata();
            }
            updatedFile.close();
        } else {
            cout << "Could not open the new file for writing.\n";
        }
    } else {
        cout << "Could not open the old file for reading.\n";
    }
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
    ticket tkt[100];


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
                if(tno>=0 && tno<100)
                {
                    tkt[tno]=ticket (cn,tno,dest);
                    option1(tkt[tno]);
                }
                else
                {
                    cout<<"Invalid Ticket Number\n";
                }
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




