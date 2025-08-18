#include <iostream>
#include <string>
using namespace std;
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