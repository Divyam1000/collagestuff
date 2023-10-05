#include<iostream>

using namespace std;

class temp{
    int num;
public:
    temp(){
        num = 0;
    }
    temp(int _num){
        num = _num;
    }
    temp operator ++(){
        ++ num;
        temp cpy(num);
        return cpy;
    }
    temp operator --(){
        -- num;
        temp cpy(num);
        return cpy;
    }
    temp operator ++(int){
        num ++;
        temp cpy(num);
        return cpy;
    }
    temp operator --(int){
        num --;
        temp cpy(num);
        return cpy;
    }

    void display(){
        cout<<num<<endl;
    }
};

int main(){
    temp a(23),b;

    ++a;
    a.display();
    a++;
    a.display();
    --a;
    a.display();
    a--;
    a.display();

    b = a++;
    b.display();
}
