#include <iostream>
using namespace std;
 
// Helper for Y/y/N/n validation
char getYesNo(const string& prompt) {
    char answer;
    while (true) {
        cout << prompt;
        cin >> answer;
        if (answer == 'y' || answer == 'Y' || answer == 'n' || answer == 'N')
            return answer;
        cout << "Invalid input. Please enter Y/y or N/n only.\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}
// Diagnose function
void diagnose() {
    char errorMsg = getYesNo("Is there an error message? (Y/N): ");
    if (errorMsg == 'y' || errorMsg == 'Y') {
        cout << "Perform Diagnosis.\nGo to Power Check.\n";
    } else {
        cout << "Computer is in good condition. Return.\n";
    }
}

// Power supply check function
void powerSupplyCheck() {
    char powerLight = getYesNo("Is power light ON? (Y/N): ");
    if (powerLight == 'y' || powerLight == 'Y') {
        cout << "Find specialist. Return.\n";
        return;
    }
    char pluggedIn = getYesNo("Is power plugged into wall? (Y/N): ");
    if (pluggedIn == 'y' || pluggedIn == 'Y') {
        cout << "Find specialist. Return.\n";
    } else {
        cout << "Plug power into the wall. Return.\n";
    }
}
// Power check function
void powerCheck() {
    char computerOn = getYesNo("Is computer ON? (Y/N): ");
    if (computerOn == 'y' || computerOn == 'Y') {
        cout << "Error handling starts.\n";
    } else {
        cout << "Checking power supply...\n";
        powerSupplyCheck();
    }
}
int main() {
    cout << "Computer Diagnosis System:\n";
    cout << "Start with Power Check...\n";
    powerCheck();
    cout << "Error/Diagnosis check...\n";
    diagnose();
    cout << "Process ended.\n";
    return 0;
}