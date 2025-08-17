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