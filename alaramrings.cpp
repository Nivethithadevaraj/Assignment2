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
// Step 4: Leave Bed
void LeaveBed() {
    cout << "You left the bed.\n";
    cout << "Turning off the alarm...\n";
    cout << " Alarm process complete.\n\n";
}
 
// Step 5: Snooze (only once)
void Snooze() {
    cout << "Snoozing alarm for 5 minutes...\n";
    this_thread::sleep_for(chrono::seconds(2));
    cout << "\n(5 minutes later...)\n";
    cout << "Alarm rings again!\n";
    LeaveBed();  
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