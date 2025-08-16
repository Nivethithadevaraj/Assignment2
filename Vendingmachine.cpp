#include <iostream>
using namespace std;

bool On=true;
int main(){
     cout<< "Vending machine\n";
     cout<< "Powering on...\n";
     while (On){
        Selectprocess();
     }
     return 0;
}

void Selectprocess(){
    int choice;
    cout<<"Enter your selection";
    cin>> choice;

    switch (choice)
    {
    case 1:
        cout<< "Preparing Mocha\n";
        cout<< "Adding chocolate powder\n";
    case 2:
        cout<< "preparing latte\n";
        cout<<"dding frothed milk\n";
    case 3:
        cout<<"preparing espresso\n";
        cout<<" adding hot coffee\n";
    }
}