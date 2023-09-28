#include<iostream>

using namespace std;

class Vector{
    int *elements_ptr;
    int len;
public:
    Vector():len(0){
        elements_ptr =NULL;
    }
    Vector(int n):len(n){
        elements_ptr = new int[n];
    }
    ~Vector(){
        delete[] elements_ptr;
    }
    void push(int element){
        elements_ptr[len] = element;
        len = len+1;
    }
    multi_push(int *arr);
    Vector operator *(int constant);
    Vector operator +(int vec);

};

Vector Vector :: operator *(int constant){
    Vector tmp(len);
    for(int i = 0; i < len; i++){
        tmp.elements_ptr[i] *= constant;
    }
    return tmp;
}

Vector Vector :: operator +(int vec){

}

int main()
{


}
