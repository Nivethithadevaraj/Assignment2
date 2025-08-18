#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

const string incomeFile = "Income.csv";
const string availableFile = "Available.csv";
const string orderHistoryFile = "OrderHistory.csv";

// Utility functions

void ensureCSVFile(const string& filename, const string& header) {
    if (!fs::exists(filename)) {
        ofstream file(filename);
        file << header << "\n";
    }
}

void appendToCSV(const string& filename, const string& line) {
    ofstream file(filename, ios::app);
    file << line << "\n";
}

char requestOrder() {
    char orderMethod;
    cout << "Customer makes order by (P)hone or (O)nline/software? ";
    cin >> orderMethod;
    return orderMethod;
}

void logIncome(char method) {
    ensureCSVFile(incomeFile, "Method,Status");
    string methodStr = (method == 'P' || method == 'p') ? "Phone" : "Software";
    appendToCSV(incomeFile, methodStr + ",Requested");
    if (methodStr == "Phone") {
        cout << "Call center sends request to server...\n";
    } else {
        cout << "Online/software sends request to server...\n";
    }
}

bool checkAvailabilityAndPickupTime() {
    while (true) {
        cout << "Checking availability (A) and if pickup is within 30 minutes...\n";
        char ans;
        cout << "Is pickup within 30 minutes? (y/n): ";
        cin >> ans;
        if (ans == 'y' || ans == 'Y') {
            return true;
        } else {
            cout << "Not within 30 minutes. Wait 1 minute and check again...\n";
            this_thread::sleep_for(chrono::seconds(1)); // simulate wait
        }
    }
}

void ensureAvailableFile() {
    ensureCSVFile(availableFile, "TaxiID,Pickup,Drop");

    // If file empty except header, add one sample taxi
    ifstream checkFile(availableFile);
    checkFile.seekg(0, ios::end);
    if (checkFile.tellg() < 30) {  // less than header + some data
        ofstream file(availableFile, ios::app);
        file << "TX001,Available,Available\n";
    }
}

bool findTaxi(string& assignedTaxiID) {
    cout << "Finding taxi (FT) within 10 km of pickup location...\n";

    assignedTaxiID = "TX001";  // Hardcoded for simplicity

    ensureAvailableFile();

    while (true) {
        char taxiAns;
        cout << "Taxi found? (y/n): ";
        cin >> taxiAns;
        if (taxiAns == 'y' || taxiAns == 'Y') {
            // Update Available.csv to mark taxi as Picked and Dropped
            {
                ifstream inFile(availableFile);
                ofstream outFile("temp.csv");

                string header, line;
                getline(inFile, header);
                outFile << header << "\n";

                while (getline(inFile, line)) {
                    if (line.find(assignedTaxiID) != string::npos) {
                        outFile << assignedTaxiID << ",Picked,Dropped\n";
                    } else {
                        outFile << line << "\n";
                    }
                }
            }

            this_thread::sleep_for(chrono::milliseconds(100)); // wait for file close

            fs::remove(availableFile);
            fs::rename("temp.csv", availableFile);

            return true;
        } else {
            cout << "No taxi yet. Wait a minute and check again...\n";
            this_thread::sleep_for(chrono::seconds(1)); // simulate wait
        }
    }
}

void driverAssignment(char method, const string& taxiID) {
    cout << "Assigning driver (DA)...\n";
    cout << "Taxi ride started.\nPassenger reached drop point.\n";

    // Update order history CSV
    ensureCSVFile(orderHistoryFile, "Method,TaxiID,Status");

    string methodStr = (method == 'P' || method == 'p') ? "Phone" : "Software";
    appendToCSV(orderHistoryFile, methodStr + "," + taxiID + ",Passenger Dropped");

    cout << "Order history updated.\n";
}

// Main program logic
int main() {
    cout << "=== Ride Assignment Program ===\n";

    char method = requestOrder();
    if (method != 'P' && method != 'p' && method != 'O' && method != 'o') {
        cout << "Invalid option. Exiting...\n";
        return 0;
    }

    logIncome(method);

    if (!checkAvailabilityAndPickupTime()) {
        
        return 0;
    }

    string taxiID;
    if (!findTaxi(taxiID)) {
       
        return 0;
    }

    driverAssignment(method, taxiID);

    
    return 0;
}
