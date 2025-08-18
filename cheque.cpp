#include <iostream>
#include <string>
using namespace std;

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
void receiverDetails() {
    string receiverAccount;
    cout << "Enter receiver bank account: ";
    cin >> receiverAccount;
    cout << "Insert cheque...\n";
    string value;
    cout << "Enter cheque value: ";
    cin >> value;
    string senderAccount;
    cout << "Enter sender account: ";
    cin >> senderAccount;
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
        cout << "Invalid transaction. Return.\n";
    }
}

int main() {
    cout << "Banking Process Start\n";
    cout << "Initialization process:\n";
    initializationProcess();
    cout << "Review process:\n";
    reviewProcess();
    cout << "End of Banking Transaction.\n";
    return 0;
}
 