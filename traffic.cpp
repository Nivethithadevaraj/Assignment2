#include <iostream>
#include <string>
using namespace std;
 
// Function for Footbridge process
bool footbridge() {
    char available;
    cout << "Is footbridge available? (y/n): ";
    cin >> available;
    if (available == 'y' || available == 'Y') {
        cout << "Use the footbridge.\n";
        return true;
    }
    return false;
}
int main() {
    cout << "Pedestrian Crossing Decision Simulation\n";
 
    while (true) {   // keep looping until a way is found
        if (footbridge()) break;
        if (tunnel()) break;
        if (!crossing()) continue; // crossing unavailable, restart loop
        if (trafficLight()) break;
        if (trafficCrossing()) break;
    }
 
    cout << "Decision process ended.\n";
    return 0;
}