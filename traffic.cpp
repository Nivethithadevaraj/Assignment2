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
 
bool trafficLight() {
    char available;
    cout << "Is traffic light available? (y/n): ";
    cin >> available;
    if (available == 'y' || available == 'Y') {
        string color;
        cout << "What is the light color? (red/green): ";
        cin >> color;
        if (color == "green" || color == "Green") {
            cout << "You may cross.\n";
            return true;
        } else {
            cout << "Light is red, check traffic crossing.\n";
            return false;
        }
    }
    return false;
}
// Function for Traffic Crossing process
bool trafficCrossing() {
    char car_left, car_right;
    cout << "Look left. Is a car approaching? (y/n): ";
    cin >> car_left;
    if (car_left == 'y' || car_left == 'Y') {
        cout << "Wait, car approaching from left.\n";
        return false;
    }
    cout << "Look right. Is a car approaching? (y/n): ";
    cin >> car_right;
    if (car_right == 'y' || car_right == 'Y') {
        cout << "Wait, car approaching from right.\n";
        return false;
    }
    cout << "Safe to cross.\n";
    return true;
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