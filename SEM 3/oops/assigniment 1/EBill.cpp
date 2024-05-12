#include <iostream>
#include <string>
#include<iomanip>
using namespace std;

#define CLEAR_SCREEN (cout<<"\033[2J"<<"\033[H")


int main()
{
    string consumerName;
    int unitsConsumed;
    double totalAmount = 0.0;
    bool loop =  true;
    char c;

    while (loop)
    {

        cout << "Enter the name of the consumer: ";
        getline(cin, consumerName);
        cout << "Enter the number of units consumed: ";
        cin >> unitsConsumed;
        CLEAR_SCREEN;
        // Calculate charges based on the given rates
        cout<<"**********ELECTRICITY BILL**********"<<endl;
        cout<<"Consumer name: "<<consumerName<<endl;
        if (unitsConsumed > 100)
        {
            totalAmount = 100 * 0.60;
            cout<<setw(30)<<left<<"First 100 units: Rs. "<<totalAmount<<endl;
        }
        if (unitsConsumed <= 100)
        {
            totalAmount = unitsConsumed * 0.60;
            if (totalAmount<50){cout<<setw(30)<<left<<"First 100 units: Rs. 50"<<endl;}
            else{cout<<setw(30)<<left<<"First 100 units: Rs. "<<totalAmount<<endl;}
        }
        if(unitsConsumed <= 300)
        {
            totalAmount += (unitsConsumed - 100) * 0.80;
            cout<<setw(30)<<left<<"101 - 300 units: Rs. "<<( unitsConsumed - 100) * 0.80 <<endl;
        }
        
        if(unitsConsumed > 300)
        {
            totalAmount += 300 * 0.80;
            cout<<setw(30)<<left<<"For 101 - 300 units: Rs. "<<300 * 0.80<<endl;
            totalAmount += (unitsConsumed-300) * 90;
            cout<<setw(30)<<left<<"For >300 units: Rs. "<<(unitsConsumed-300) * 90<<endl;
        }

        cout<<setw(30)<<"Total : Rs. "<<totalAmount<<endl;
        // Check if additional surcharge is required
        if (totalAmount > 300.0)
        {
            cout<<"Additional surcharge of 15% for total amount going beyond Rs. 300"<<endl;
            totalAmount += totalAmount * 0.15;
        }

        cout <<setw(30)<<left<<"Total Charges: Rs. " << totalAmount << endl;

        cout<<"Do you want to exit ? (y/n) : ";
        cin>>c;
        if(c=='y'||c=='Y') {  CLEAR_SCREEN; loop = false;}
        else {CLEAR_SCREEN;}
        getchar();
    }
    return 0;
}
