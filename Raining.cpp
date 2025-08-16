#include <iostream>
using namespace std;
 
// Function to get only y/n input
char getYesNo(string message) {
    char input;
    while (true) {
        cout << message;
        cin >> input;
        if (input == 'y' || input == 'Y' || input == 'n' || input == 'N') {
            return input;
        } else {
            cout << "Invalid input! Please enter y/n only.\n";
        }
    }
} 
 
int main() {
    while (true) {
        // (w) Check weather
        char raining = getYesNo("Is it raining? (y/n): ");
        if (raining == 'n' || raining == 'N') {
            cout << "Don't bring umbrella.\n";
            break; // exit loop
        }
  // (f) Raining → try to find umbrella
        char found = getYesNo("Did you find the umbrella? (y/n): ");
        if (found == 'y' || found == 'Y') {
            cout << "Bring umbrella.\n";
            break; 
        } else {
            cout << "Umbrella not found, re-checking weather...\n";
        }
     
    }
      
    cout << "Stop.\n";
    return 0;
}