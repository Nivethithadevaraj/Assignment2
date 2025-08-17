#include <iostream>
using namespace std;

// helper to get only y/n
char getYesNo(string msg) {
    char ch;
    cout << msg;
    cin >> ch;
    while (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N') {
        cout << "Invalid input! Please enter y or n: ";
        cin >> ch;
    }
    return ch;
}
// Step 1: Registration
void Registration() {
    char reg = getYesNo("Is patient already registered? (y/n): ");
    if (reg == 'n' || reg == 'N')
        cout << "Registering new patient...\n";
    else
        cout << "Patient already registered.\n";
}

int main() {
   
    cout << "Patient arrives at hospital.\n";
 
    Registration();
    // NurseAvailability();
    // DoctorAvailability();
 
    cout << "Patient leaves hospital.\n";
    
    return 0;
}