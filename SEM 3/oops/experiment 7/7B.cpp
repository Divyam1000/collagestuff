#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int main()
{
    cout<<"Enter some text: (use ctr + z to end input)"<<endl;
    string text;
    int no_lines = 0, no_words = 0, no_char = 0, char_ctr = 0;
    while(getline(cin,text)){
        for(char ch : text){
            if(isspace(ch) && char_ctr != 0){
                no_char += char_ctr;
                no_words ++;
                char_ctr = 0;
            }
            else
                char_ctr ++;
        }
        if(char_ctr !=0 ){
            no_char += char_ctr;
            no_words ++;
            char_ctr = 0;
        }
        no_lines ++;
    }
    cout<<setiosflags(ios::left)<<setw(15)<<"Number of lines"<<setiosflags(ios::right)<<setw(10)<<no_lines<<endl;
    cout<<resetiosflags(ios::adjustfield)<<setiosflags(ios::left)<<setw(15)<<"Number of words"<<setiosflags(ios::right)<<setw(10)<<no_words<<endl;
    cout<<resetiosflags(ios::adjustfield)<<setiosflags(ios::left)<<setw(15)<<"Number of char"<<setiosflags(ios::right)<<setw(10)<<no_char<<endl;

    return 0;
}
/*
Hello World!
How are you?
FINE! Thats great!
*/
