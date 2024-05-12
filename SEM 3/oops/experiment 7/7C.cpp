#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

ostream &value(ostream &output)
    {
        output.setf(ios::right,ios::adjustfield);
        output.setf(ios::internal,ios::adjustfield);
        output.width(5);
        return output;
    }

    ostream &multiofvalue(ostream &output){
        output.unsetf(ios::adjustfield);
        output.precision(4);
        output.setf(ios::right,ios::adjustfield);
        output.setf(ios::showpoint);
        output.width(23);
        return output;
    }

int main()
{

    cout<<"VALUE"<<setfill('*')<<setiosflags(ios::right)<<setw(23)<<"MULTI OF VALUE"<<endl;
    for(int i = 1; i <= 4; i++){
        cout.fill('.');
        cout.setf(ios::showpos);
        cout<<value<<i;
        cout<<multiofvalue<<i*2.0<<endl;
    }

}
