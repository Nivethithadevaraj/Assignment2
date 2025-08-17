#include <iostream>
#include <thread>
#include <chrono>
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
 // Step 3: Check Time
void CheckTime() {
    char late = getYesNo("Will you be late if you sleep more? (y/n): ");
    if (late == 'y' || late == 'Y')
        LeaveBed();
    else
        Snooze();
}
 
// Step 2: Ready to Wake Up
void ReadyToWakeUp() {
    char choice = getYesNo("Are you ready to wake up? (y/n): ");
    if (choice == 'y' || choice == 'Y')
        LeaveBed();
    else
        CheckTime();
}
// Step 1: Alarm Rings
void Alarm() {
    cout << "Alarm rings!\n";
    ReadyToWakeUp();
}
 
// Main
int main() {
    
    Alarm();
    return 0;
}