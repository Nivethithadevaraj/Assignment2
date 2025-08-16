#include <iostream>
using namespace std;

bool On=true;

void showOptions() {
    cout << "\nAvailable Options:\n";
    cout << "1. Espresso\n";
    cout << "2. Latte\n";
    cout << "3. Mocha\n";
}
void selectProcess() {
    int choice;
 
    while (true) {
        cout << "Enter your selection: ";
        cin >> choice;
 
        switch(choice) {
            case 1: // Espresso
                cout << "Preparing Hot coffee...\n";
                cout << "Hot coffee\n";
            case 2: // Latte
                if(choice >= 2) {
                cout << "Preparing Latte...\n";
                cout << "Adding frothed milk\n";
                }
            case 3: // Mocha
                if(choice == 3)
                cout << "Preparing Mocha...\n"; 
                cout << "Adding chocolate powder\n";
                return; 
            default:
                if(choice < 1 || choice > 3) {
                    cout << "Invalid selection!\n";
                    showOptions();
                }
                break;
        }
    }
}
int main(){
     cout<< "Vending machine\n";
     cout<< "Powering on...\n";
     while (On){
        selectProcess();
     }
     return 0;
}

