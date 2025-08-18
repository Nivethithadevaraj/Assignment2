#include <iostream>
#include <string>
#include <set>
using namespace std;
 
// Predefined valid accounts
const set<string> validAccounts = {
    "12345678", "87654321", "11223344"
};
 
// Helper for robust Y/y/N/n input
char getYesNo(const string& prompt) {
    char answer;
    while (true) {
        cout << prompt;
        cin >> answer;
        if (answer == 'y' || answer == 'Y' || answer == 'n' || answer == 'N')
            return answer;
        cout << "Invalid input. Please enter Y/y or N/n only.\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}
 
// Receiver details (RD)
void receiverDetails() {
    string receiverAccount;
    // Verify receiver account input
    while (true) {
        cout << "Enter receiver bank account: ";
        cin >> receiverAccount;
        if (validAccounts.count(receiverAccount)) {
            break;
        } else {
            cout << "Invalid receiver account. Please try again.\n";
        }
    }
 
    cout << "Insert cheque...\n";
    string value;
    cout << "Enter cheque value: ";
    cin >> value;
 
    string senderAccount;
    // Verify sender account input
    while (true) {
        cout << "Enter sender account: ";
        cin >> senderAccount;
        if (validAccounts.count(senderAccount)) {
            break;
        } else {
            cout << "Invalid sender account. Please try again.\n";
        }
    }
 
    cout << "Receiver details recorded. Return.\n";
}
 
// Review process (RP)
void reviewProcess() {
    char sevenDays = getYesNo("Has it been 7 days since process started? (Y/N): ");
    if (sevenDays == 'y' || sevenDays == 'Y') {
        cout << "Money transferred to the reviewer. Return.\n";
        return;
    }
    char senderReview = getYesNo("Does the sender want to review? (Y/N): ");
    if (senderReview == 'n' || senderReview == 'N') {
        cout << "Invalid transaction. Return.\n";
        return;
    }
    char senderAuthorize = getYesNo("Does the sender authorize transaction? (Y/N): ");
    if (senderAuthorize == 'y' || senderAuthorize == 'Y') {
        cout << "Money transferred to the reviewer. Return.\n";
    } else {
        cout << "Invalid transaction.\n";
    }
}
 
// Initialization process (IP)
void initializationProcess() {
    cout << "Insert bank card...\n";
    string accountNumber;
    // Verify entered account number against predefined list
    while (true) {
        cout << "Enter bank account number: ";
        cin >> accountNumber;
        if (validAccounts.count(accountNumber)) {
            break;
        } else {
            cout << "Invalid account number. Please try again.\n";
        }
    }
    receiverDetails();
}
 
int main() {
    cout << "Banking Process Start\n";
    cout << "Initialization process:\n";
    initializationProcess();
    cout << "Review process:\n";
    reviewProcess();
    
    return 0;
}
 