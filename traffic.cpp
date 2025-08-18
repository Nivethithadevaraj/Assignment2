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

// Function for Tunnel process
bool tunnel() {
    char available;
    cout << "Is tunnel available? (y/n): ";
    cin >> available;
    if (available == 'y' || available == 'Y') {
        cout << "Use the tunnel.\n";
        return true;
    }
    return false;
}
 
// Function for Crossing process
bool crossing() {
    char available;
    cout << "Is crossing available? (y/n): ";
    cin >> available;
    if (available == 'y' || available == 'Y') {
        return true;
    } else {
        cout << "Walk away.\n";
        return false;
    }
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