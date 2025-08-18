#include <iostream>
#include <string>
using namespace std;

bool checkAttempts(int attempts) {
    if (attempts >= 5) {
        cout << "Account locked due to 5 unsuccessful attempts.\n";
        cout << "Alert: Please contact support.\n";
        return true;
    }
    return false;
}

int main() {
    int attempts = 0;
    bool accessGranted = false;
 
    while (!accessGranted) {
        if(checkAttempts(attempts)) {
            break;
        }
 
        accessGranted = authorize();
 
        if (!accessGranted) {
            attempts++;
        }
    }
 
    return 0;
}