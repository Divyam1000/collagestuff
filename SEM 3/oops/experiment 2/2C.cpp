#include<iostream>
using namespace std;

double area(double r){
    return (3.14 * r * r);
}
double area(double a, double b){
    return (a * b);
}
double area(double b, double h, int t){
    return (0.5 * b * h);
}

int main()
{
    int op;
    while(true)
    {
        cout<<"\n1.Area of circle\n2.Area of rectangle\n3.Area of triangle\n4.exit"<<endl;
        cin>>op;
        
        switch(op)
        {
            case 1:
                double r;
                cout<<"Enter radius of circle: "; cin>>r;
                cout<<"Area: "<<area(r);
                break;
            case 2:
                double x, y;
                cout<<"Enter Both sides of rectangle: "; cin>>x>>y;
                cout<<"Area: "<<area(x,y);
                break;
            case 3:
                double b, h;
                cout<<"Enter Base and Height of triangle: "; cin>>b>>h;
                cout<<"Area: "<<area(b,h,1);
                break;
            case 4: exit(1);
            default : cout<<"Wrong Input! Enter again! "<<endl; break;
        }
    }
}