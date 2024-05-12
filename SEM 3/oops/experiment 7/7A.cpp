#include<iostream>
#include<iomanip>
using namespace std;


int main()
{
    cout.setf(ios::showpoint);
    int n = 1;
    float term, sum = 0;
    cout<<setw(5)<<setiosflags(ios::left)<<"n"<<setw(20)<<"Inverse_of_n"<<setw(20)<<"Sum_of_terms"<<endl;
    for(n = 1; n<=10; n++){
        term = 1.0/n;
        sum = sum + term;
        cout.setf(ios::left,ios::adjustfield);
        cout.width(5);
        cout<<n;
        cout.precision(4);
        cout.setf(ios::scientific,ios::floatfield);
        cout.setf(ios::left,ios::adjustfield);
        cout.width(20);
        cout<<term;
        cout.unsetf(ios::floatfield);
        cout.setf(ios::right,ios::adjustfield);
        cout.width(8);
        cout<<sum<<endl;
    }
    return 0;
}
