#include <iostream>
#include <string>
using namespace std;
 
bool On = true;
void showOptions() {
    cout << "\nAvailable Options:\n";
    cout << "1. Espresso\n";
    cout << "2. Latte\n";
    cout << "3. Mocha\n";
}
 
void selectProcess() {
    string input;
 
    while (true) {
        cout << "Enter your selection: ";
        cin >> input;
 
        if (input.length() != 1 || (input[0] < '1' || input[0] > '3')) {
            cout << "Invalid selection! Choose 1, 2, or 3.\n";
            showOptions();
            continue;
        }
 
        char choice = input[0];
        switch(choice) {
            case '3': cout << "Preparing Mocha...\nAdding chocolate powder\n";
            case '2': cout << "Adding frothed milk\n";
            case '1': cout << "Hot coffee\n"; return;
        }
    }
}
 
void terminationProcess() {
    string input;
    cout << "\nPress 'P' to power off or any other key to continue: ";
    cin >> input;
    if(!input.empty() && (input[0]=='P'||input[0]=='p')) On = false;
}
 
int main() {
    cout << "Vending Machine Simulation Started\nPowering On...\n";
 
    while (On) {
        showOptions();
        selectProcess();
        terminationProcess();
    }
 
    cout << "Vending Machine Powered Off.\n";
    return 0;
}