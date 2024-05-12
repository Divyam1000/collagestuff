#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include<stdlib.h>
#include<stdio.h>
#include<cstdlib>

using namespace std;

class TP_directory{
public:
    string name;
    string number;

    static void enterDetails();
    static int searchDetails();
    static void editDetails(int);

};

class IO{
public:
    static void serializeDetails(TP_directory *ptr, fstream &file);
    static void deserializeDetails(TP_directory *ptr, fstream &file);
};

void IO :: serializeDetails(TP_directory *ptr,fstream &file){
    file << ptr->name.size();
    file << ',';
    file << ptr->name.c_str();
    file << ',';
    file << ptr->number.size();
    file << ',';
    file << ptr->number.c_str();
    file << '\n';
}

void IO :: deserializeDetails(TP_directory *ptr,fstream &file){
    char dlem;
    int len;
    file >> len;
    file >> dlem;
    if (file && len) {
        vector<char> tmp(len);
        file.read(tmp.data() , len);
        ptr->name.assign(tmp.data(), len);
    }
    file >> dlem;
    file >> len;
    file >> dlem;
    if (file && len) {
        vector<char> tmp(len);
        file.read(tmp.data() , len);
        ptr->number.assign(tmp.data(), len);
    }
    //file >> dlem;
}

void TP_directory :: enterDetails(){
    int n;
    TP_directory ent;
    fstream file;
    file.open("TelePhoneBook.txt",ios::in );
    if(!file){
        file.close();
        file.open("TelePhoneBook.txt",ios::out );
    }
    else{
        file.close();
        file.open("TelePhoneBook.txt",ios::app );
    }
    file.seekp(0,ios::end);
    cout<<"\nEnter Number of Entries : ";
    cin >> n;
    while(n--){
        cin.ignore();
        cout<<"\nEnter name : ";
        getline(cin,ent.name);
        cout<<"Enter phone number : ";
        getline(cin,ent.number);
        IO::serializeDetails(&ent,file);
    }
    cout<<"Inout task complete !"<<endl;
}

int TP_directory ::searchDetails(){
    string name;
    int pos = 0, len;
    cout<<"\nEnter the name to be searched : ";
    cin.ignore();
    getline(cin, name);

    TP_directory src;
    fstream file;
    file.open("TelePhoneBook.txt",ios::in );
    if(!file){
        cout<<"\nNo Data is available ! "<<endl;
    }
    file.seekg(0,ios::end);
    len = file.tellg();
    file.seekg(0,ios::beg);

    while(len-=pos){
        pos = file.tellg();
        IO ::deserializeDetails(&src, file);
        if(src.name == name){
            cout<<"\nSearch Successful ! "<<endl;
            cout<<"Name : "<<src.name<<endl;
            cout<<"Phone Number : "<<src.number<<endl;
            break;
        }
    }
    if(src.name != name){
        cout<<"\nSearch unsuccessful"<<endl;
    }
    file.close();
    return pos;
}

void TP_directory :: editDetails(int edit_pos){
    if(edit_pos < 0){
        return;
    }
    fstream filein,fileout;
    int len, pos = 0;
    TP_directory cp;
    filein.open("TelePhoneBook.txt", ios::in);
    fileout.open("updating.txt", ios::out);
    if(!filein || !fileout){cout<<"Error opening file ! "<<endl;}
    else{
        filein.seekg(0,ios::end);
        len = filein.tellg();
        filein.seekg(0,ios::beg);
        while(!filein.eof()){
            pos = filein.tellg();
            IO ::deserializeDetails(&cp,filein);
            if(filein.fail()) break;
            if(pos == edit_pos){
                cout<<"\nEnter new phone number : ";
                //cin.ignore();
                getline(cin,cp.number);
            }
            IO ::serializeDetails(&cp,fileout);
        }
        filein.close();
        fileout.close();
        char a[] = "TelePhoneBook.txt";
        if(remove(a) != 0)
            cout<<"\nError Deleting old file ! "<<endl;
        if(rename("updating.txt","TelePhoneBook.txt") != 0)
            cout<<"\nError renaming file !"<<endl;
        cout<<"\nUpdate successful ! "<<endl;
    }
}

int main()
{
    int choice;

    while(1){
        cout<<"\n------Telephone directory------\n"<<endl;
        cout<<"1. Enter new entry"<<endl;
        cout<<"2. Search and change number"<<endl;
        cout<<"3. search"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"ENTER YOUR CHOICE : ";
        cin >> choice;
        switch(choice){
        case 1:
            TP_directory::enterDetails();
            break;
        case 2:
            TP_directory ::editDetails(TP_directory::searchDetails());
            break;
        case 3:
            TP_directory::searchDetails();
            break;
        case 4: return 0;
        default: cout<<"wrong input!"<<endl;
        }
    }
}
