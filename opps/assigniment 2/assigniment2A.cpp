#include<iostream>

using namespace std;
class DB;
class DM{
    int meter;
    float centimeter;
public:
    DM(){           //metric units
        meter = 0;
        centimeter = 0;
    }
    DM(float d){
        meter = d;
        centimeter = 0;
        centimeter =(d - meter) * 100;
    }
    friend DM sum(DM&, DB&);
    friend DB sum(DB&, DM&);
    void display(){
        cout<<meter<<" m "<<centimeter<<" cm"<<endl;
    }
};

class DB{           //imperial units
    int feet;
    float inches;
public:
    DB(){
        feet = 0;
        inches = 0;
    }
    DB(float d){
        feet = d;
        inches = 0;
        inches = (d - feet) * 12;
    }
    friend DM sum(DM&, DB&);
    friend DB sum(DB&, DM&);
    void display(){
        cout<<feet<<" \' "<<inches<<" \""<<endl;
    }
};

DB sum(DB &b, DM &a){
    float distance = b.feet + b.inches * 0.0833 + (a.meter + (a.centimeter)/100)* 3.28084;
    DB c(distance);
    return c;
}
DM sum(DM &a, DB &b){
    float distance = a.meter + (a.centimeter / 100) + ((b.feet + (b.inches * 0.0833)) * 0.3048);
    DM c(distance);
    return c;
}

int main()
{
    float distance;

    cout<<"Enter distance in metrics format: ";cin>>distance;
    DM m_dist(distance);
    cout<<"Enter distance in Imperial format: ";cin>>distance;
    DB i_dist = DB(distance);

    cout<<"For sum of the two distances: "<<endl;
    int op;
    cout<<"Choose measurment Unit!"<<endl;
    cout<<"1.Matric"<<endl<<"2.Imperial"<<endl;
    cin>>op;

    if(op == 1){
        cout<<"\nSum of both lengths and converted in metric"<<endl;
        m_dist = sum(m_dist, i_dist);
        m_dist.display();
    }
    else if(op == 2){
        cout<<"\nSum of both lengths and converted in imperial"<<endl;
        i_dist = sum(i_dist, m_dist);
        i_dist.display();
    }

    return 0;
}
