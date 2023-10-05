#include <iostream>

using namespace std;

class vector{
    float *ptr;
    int size;
public:
    vector(){
        ptr = NULL;
    }
    vector(int n){
        ptr = new float [n];
        size = n;
    }
    ~vector(){
        delete(ptr) ;
        }
    void create_vector(){
        for(int i = 0; i<size; i++){
            cout<<"\nEnter Element "<<i+1<<" : "; cin>>ptr[i];
        }
    }
    bool modify(int pos, float num){
        if(pos > size){
            return false;
        }
        ptr[pos-1] = num;
        return true;
    }
    friend vector multipy_byconst(vector &vec, float c);
    friend vector add_vectors(vector a, vector b);
    void display();
};

vector multipy_byconst(vector &vec, float c){
    if(vec.ptr != NULL)
        for(int i=0; i<vec.size; i++){
            vec.ptr[i] = vec.ptr[i] * c; cout<<vec.ptr[i];
        }
    else
        cout<<"\nEmpty vector"<<endl;
    return vec;
}
vector add_vectors(vector a, vector b){
    int size = a.size>b.size ? a.size:b.size;
    vector c(size);
    for(int i=0; i<size; i++){
            c.ptr[i] = a.ptr[i] + b.ptr[i];
    }
    return c;
}
void vector :: display(){
    if(ptr != NULL)
        for(int i=0; i<size; i++){
            cout<<ptr[i];
            if(i != size-1)
                cout<<" ,";
    }
    else
        cout<<"\nEmpty vector"<<endl;
}

int main()
{
    int size,op, pos;
    cout<<"Enter size of vector A : "; cin>>size;
    vector A(size);
    cout<<"vector A : " ; A.create_vector();
    cout<<"Enter size of vector B : "; cin>>size;
    vector B(size);
    cout<<"vector B : "; B.create_vector();

    cout<<"Vecotr A : "; A.display(); cout<<endl;
    cout<<"Vector B : "; B.display(); cout<<endl;

    cout<<"Vector to modify\n1.Vector A\n2.Vector B"<<endl;
    cin>>op;
    cout<<"Enter position: "; cin>>pos;
    int element;
        cout<<"Enter element to modify: ";cin>>element;
    if(op==1){
        if(A.modify(pos, element))
            cout<<"Element added sucessfully !"<<endl;
        else cout<<"Position not found !"<<endl;
    }
    else if(op == 2){
        if(B.modify(pos, element))
            cout<<"Element added sucessfully !"<<endl;
        else cout<<"Position not found !"<<endl;
    }
    else cout<<"Error! vector not found"<<endl;

    cout<<"Vecotr A : "; A.display(); cout<<endl;
    cout<<"Vector B : "; B.display(); cout<<endl;

    float tmp;
    cout<<"Multiply by constant\n1. Vector A\n2.Vector B"<<endl;cin>>op;
    cout<<"Enter constant to multiply: "; cin>>tmp;
    if(op == 1){
        A = multipy_byconst(A,tmp);
    }
    else if(op == 2){
        B = multipy_byconst(B,tmp);
    }
    else cout<<"Error! vector not found"<<endl;

    cout<<"Vecotr A : "; A.display(); cout<<endl;
    cout<<"Vector B : "; B.display(); cout<<endl;

    cout<<"Add two vectors to\n1. Vector A\n2.Vector B"<<endl;cin>>op;
    if(op == 1){
        A = add_vectors(A,B);
    }
    else if(op == 2){
        B = add_vectors(B,A);
    }
    else cout<<"Error! vector not found"<<endl;

    cout<<"Vecotr A : "; A.display(); cout<<endl;
    cout<<"Vector B : "; B.display(); cout<<endl;

    return 0;
}
