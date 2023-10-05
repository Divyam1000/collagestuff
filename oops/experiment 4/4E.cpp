#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

class Vector{
    int *elements_ptr;
    int len;
    int curent_pos;
public:
    //default constructor
    Vector():len{0},curent_pos{0}{
        elements_ptr =NULL;
    }
    //initialize memory
    Vector(int n):len{n},curent_pos{0}{
        elements_ptr = new int[n];
    }
    //delete the vector
    ~Vector(){
        delete[] elements_ptr;
    }
    //add an element to the vector to at the top position
    void push(int element);
    //pushes the whole array of elements
    void multi_push(int *arr,int n);
    //overloading = operator to copy a object and uses deep copying
    void operator =(Vector vec );
    //multiplies all  the elements of the vector by a constant
    Vector operator *(int constant);
    //adds 2 vectors
    Vector operator +(Vector vec);
    //display function
    string display();
};

void Vector :: push(int element){
    if(len == curent_pos){
        if(len == 0)
            len = 1;
        len*=2;
        int *tmp_ptr = new int[len];
        for(int i = 0; i<curent_pos; i++){
            tmp_ptr[i] = elements_ptr[i];
        }
        delete[] elements_ptr;
        elements_ptr = tmp_ptr;
    }
    elements_ptr[curent_pos] = element;
    curent_pos ++;
}

void Vector :: multi_push(int arr[], int n = 0){
    int i = 0;
    while(i<n){
        this->push(arr[i]);
        i++;
    }
}

void Vector :: operator =(Vector vec){
    delete[] elements_ptr;
    len = vec.len;
    curent_pos = vec.curent_pos;
    elements_ptr = new int[len];
    for(int i = 0; i<curent_pos; i++){
        elements_ptr[i] = vec.elements_ptr[i]; 
    }
}

Vector Vector :: operator *(int constant){
    Vector tmp(len);
    for(int i = 0; i < curent_pos; i++){
        tmp.elements_ptr[i] = elements_ptr[i] * constant;
        tmp.curent_pos ++;
    }
    return tmp;
}

Vector Vector :: operator +(Vector vec){
    int i;
    Vector tmp;

    for (i = 0; i<curent_pos && i<vec.curent_pos; i++){
        int sum = elements_ptr[i] + vec.elements_ptr[i];
        tmp.push(sum);
    }
    while(i <vec.curent_pos){
        tmp.push(vec.elements_ptr[i]);
        i++;
    }
    while(i <curent_pos){
        tmp.push(elements_ptr[i]);
        i++;
    }
    return tmp;
}

string Vector :: display(){         
    string str ="";
    for(int i = 0; i<curent_pos; i++){                        
        str = str + to_string(elements_ptr[i]) + ",";
    }
    str = str + "\0";
    return str;
}

int main()
{
    Vector a(9),b(5),c;
    int arr1[] = {1,2,3,4,5,6,7,8,9};
    int arr2[] = {1,3,5,7,9};
    a.multi_push(arr1,sizeof(arr1)/sizeof(arr1[0]));
    b.multi_push(arr2,sizeof(arr2)/sizeof(arr2[0]));
    cout<<"Vector 1: "<<a.display()<<endl;
    cout<<"Vector 2: "<<b.display()<<endl;

    c = a + b;
    cout<<"Sum of vector a and b: "<<c.display()<<endl;

    c = c * 2;
    cout<<"Multiply vector c by 2: "<<c.display()<<endl;
}
