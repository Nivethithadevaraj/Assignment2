#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Predefined credentials for admin
const string adminUsername = "admin";
const string adminPassword = "admin123";
const string correctNewPassword = "newpass456";

vector<pair<string, string>> users; // Stores username and password pairs

bool userIdentification() {
    char input;
    cout << "User Identification (U)? (Y/N): ";
    cin >> input;
    return (input == 'Y' || input == 'y');
}

bool isAdmin() {
    char input;
    cout << "If Admin? (Y/N): ";
    cin >> input;
    return (input == 'Y' || input == 'y');
}

bool login(string &username) {
    string password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // Admin check
    if (username == adminUsername && password == adminPassword) {
        cout << "Login successful.\n";
        return true;
    }

    // User check
    for (auto &user : users) {
        if (user.first == username && user.second == password) {
            cout << "Login successful.\n";
            return true;
        }
    }

    cout << "Invalid credentials.\n";
    return false;
}

bool requestNewPassword(string username) {
    char input;
    cout << "Forgot password? Request new password (NP)? (Y/N): ";
    cin >> input;
    if (input == 'Y' || input == 'y') {
        string newPassword;
        cout << "Enter new password: ";
        cin >> newPassword;
        if (newPassword == correctNewPassword) {
            // Update password for that user
            for (auto &user : users) {
                if (user.first == username) {
                    user.second = newPassword;
                    cout << "New password accepted.\n";
                    return true;
                }
            }
            cout << "Username not found.\n";
            return false;
        } else {
            cout << "New password invalid.\n";
            return false;
        }
    }
    return false;
}

void adminDashboard() {
    cout << "Admin Dashboard (AD)...\n";
    char choice;
    do {
        cout << "Choose Action - Update (U), Answer Queries (Q), Logout (L): ";
        cin >> choice;
        choice = toupper(choice);

        switch (choice) {
            case 'U':
                cout << "Update the car library.\n";
                break;
            case 'Q':
                cout << "Answer queries.\n";
                break;
            case 'L':
                cout << "Logout.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 'L');
}

bool isRegisteredUser() {
    char input;
    cout << "Are you a registered user? (Y/N): ";
    cin >> input;
    return (input == 'Y' || input == 'y');
}

bool registerUser() {
    string username, password;
    cout << "Sign Up - Enter new username: ";
    cin >> username;

    // Check if username already exists
    for (auto &user : users) {
        if (user.first == username) {
            cout << "Username already exists. Please login instead.\n";
            return false;
        }
    }

    cout << "Enter new password: ";
    cin >> password;

    users.push_back({username, password});
    cout << "User registered successfully.\n";
    return true;
}

void rentVehicle() {
    char input;
    cout << "Search for the vehicle? (Y/N): ";
    cin >> input;
    if (input == 'Y' || input == 'y') {
        cout << "Vehicle found.\n";
        cout << "Proceeding to payment...\n";
        cout << "Payment successful! Vehicle rented.\n";
    } else {
        cout << "Return (No vehicle selected)\n";
    }
}

void makePayments() {
    cout << "Make payments.\n";
}

int main() {
    cout << "Start\n";

    if (!userIdentification()) {
        cout << "End\n";
        return 0;
    }

    if (isAdmin()) {
        string dummy;
        if (!login(dummy)) {
            cout << "Admin login failed.\nEnd\n";
            return 0;
        }
        adminDashboard();
        cout << "End\n";
        return 0;
    }

    if (!isRegisteredUser()) {
        if (!registerUser()) {
            cout << "Sign up failed.\nEnd\n";
            return 0;
        }
        cout << "Please log in with your new credentials.\n";
    }

    string username;
    if (!login(username)) {
        if (!requestNewPassword(username)) {
            cout << "Return (Login Failed)\n";
            cout << "End\n";
            return 0;
        }
    }

    cout << "Dashboard displayed.\n";
    rentVehicle();
    makePayments();

    cout << "End\n";
    return 0;
}
