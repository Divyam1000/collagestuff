#include<iostream>
using namespace std;

int main()
{
	int n, tmp;
    cout<<"Enter size of rows of a squre matrix: "; cin>>n;
    int **array = new int* [n];
    for(int i = 0; i < n; i++)
        array[i] = new int [n];
    
    cout<<"Enter Elements of array"<<endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>array[i][j]; 
        }
    }
    cout<<"Mtrix:"<<endl;
     for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i = 0, j = n-1 ; i < n && j >= 0; i++, j--){
            tmp = array[i][i];
            array[i][i] = array[i][j];
            array[i][j] = tmp;
    }
    cout<<"After Interchanging of diagonals "<<endl;
     for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
