#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to ask a yes/no question and return true/false
bool askQuestion(const string& question) {
    char input;
    while (true) {
        cout << question << " (Y/N)? ";
        cin >> input;
        input = tolower(input);
        if (input == 'y') return true;
        if (input == 'n') return false;
        cout << "Invalid input, please enter Y or N.\n";
    }
}

// Function to update "Customer Database" CSV file
void updateCustomerDatabase(const string& status) {
    ofstream dbFile("customer_database.csv", ios::app);
    if (!dbFile) {
        cout << "Error opening customer_database.csv for writing.\n";
        return;
    }
    dbFile << "Transaction," << status << "\n";
    dbFile.close();
    cout << "Customer database updated.\n";
}

// Function to verify the transaction
bool verification() {
    cout << "Payment verified by card network.\n";

    if (!askQuestion("Card valid")) {
        cout << "Return: Card not valid.\n";
        return false;
    }

    if (!askQuestion("Funds available")) {
        cout << "Return: Insufficient funds.\n";
        return false;
    }

    cout << "Payment verified by the bank.\n";

    if (!askQuestion("Account valid")) {
        cout << "Return: Account not valid.\n";
        return false;
    }

    return true;
}

// Function to complete the transaction
void completion() {
    cout << "Transaction complete.\n";
    updateCustomerDatabase("Success");
    cout << "Card holder receives statement at the end of the cycle.\n";
    cout << "Return.\n";
}

// Main function
int main() {
    cout << "Start.\n";
    cout << "Order placed by the client.\n";

    // Loop until verification passes
    bool verified = false;
    while (!verified) {
        verified = verification();
        if (!verified) {
            cout << "Verification failed. Please try again.\n";
        }
    }

    completion();
    return 0;
}
