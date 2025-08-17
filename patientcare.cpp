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

// Step 4: Assign Doctor
void AssignDoctor() {
    cout << "Doctor assigned to patient.\n";
    //FollowUp();
}
 
// Step 3: Doctor Availability
void DoctorAvailability() {
    char doc = getYesNo("Is doctor available? (y/n): ");
    if (doc == 'y' || doc == 'Y')
        AssignDoctor();
    else {
        cout << "Waiting for doctor...\n";
        cout << "Now doctor is available.\n";
        AssignDoctor();
    }
}
// Step 2: Nurse Availability
void NurseAvailability() {
    char nurse = getYesNo("Is nurse available? (y/n): ");
    if (nurse == 'y' || nurse == 'Y')
        cout << "Nurse records patient condition.\n";
    else {
        cout << "Waiting for nurse...\n";
        cout << "Now nurse is available. Recording condition.\n";
    }
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
    NurseAvailability();
    DoctorAvailability();
 
    cout << "Patient leaves hospital.\n";
    
    return 0;
}