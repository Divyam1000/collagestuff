#include<iostream>
#include<string.h>
using namespace std;

class temp{
    char* word;
    int len;
public:
    temp(){
        word = NULL;
        len = 0;
    }
    temp(char* w){
        len = strlen(w);
        word = new char[len+1];
        strcpy(word,w);
    }
    void join(temp p, temp q){
        len = p.len + q.len;
        word = new char[len + 1];
        strcpy(word, p.word);
        strcat(word, q.word);
    }
    void display(){
        cout<<word<<endl;
    }
};
int main()
{
    char* f1 = "Goa ";
    temp name1(f1),
    name2("College "), name3("Engineering "), s1, s2;
    s1.join(name1,name2);
    s2.join(s1,name3);
    s2.display();

    return 0;
}
