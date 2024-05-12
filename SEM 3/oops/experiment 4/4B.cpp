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
    temp operator *(temp y){
        temp cpy;
        cpy.num = num * y.num;
        return cpy;
    }
    friend temp operator +(int a, temp b){
        temp cpy;
        cpy.num = a + b.num;
        return cpy;
    }
    temp operator +(int a){
        temp cpy;
        cpy.num = num + a;
        return cpy;
    }
    void display(){
        cout<<num<<endl;
    }
};

int main()
{
    temp x(20), y(10);
    x = 5 + y;
    x.display();
    x = x * y;
    x.display();
    x = y + 5;
    x.display();

}
