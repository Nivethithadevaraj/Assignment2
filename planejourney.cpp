#include <iostream>
using namespace std;
 
// Function for valid yes/no input
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

void securityScreening() {
    int item = getItemType();
    if (item == 1) {
        cout << "Handsearch required. Return.\n";
    } else if (item == 2) {
        cout << "Give up dangerous goods. Return.\n";
    } else if (item == 3) {
        cout << "Give up articles above permitted limits. Return.\n";
    }
}

bool permitToEnter() {
    char permit = getYesNo("Permit to enter country? (Y/N): ");
    if (permit == 'y' || permit == 'Y') {
        return true;
    } else {
        cout << "Send to originate country. Return.\n";
        return false;
    }
}

int main() {
    while (true) {
        // Security Screening
        securityScreening();
 
        // Journey steps
        cout << "Immigrating...\n";
        cout << "Boarding flight...\n";
        cout << "Flight departs...\n";
        cout << "Flight lands.\n";
 
        // Permit check
        if (!permitToEnter()) {
            break;
        }
 
        // Claim baggage
        cout << "Claim baggage.\n";
 
        // Connection flight check
        char connection = getYesNo("Is there a connection flight? (Y/N): ");
        if (connection == 'n' || connection == 'N') {
            cout << "Journey ends at baggage claim.\n";
            break;
        }
        cout << "Proceeding to next connection flight...\n";
    }
    cout << "Process finished.\n";
    return 0;
}