#include <iostream>
using namespace std;
 
// Helper for yes/no input, only accepts Y/y/N/n
char getYesNo(const string& prompt) {
    char answer;
    while (true) {
        cout << prompt;
        cin >> answer;
        if (answer == 'y' || answer == 'Y' || answer == 'n' || answer == 'N')
            return answer;
        cout << "Invalid input. Enter Y/y or N/n only.\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}
void separateWaste() {
    char isOrganic = getYesNo("Is the waste organic? (Y/N): ");
    if (isOrganic == 'y' || isOrganic == 'Y') {
        cout << "Proceeding to energy check...\n";
        energyCheck();
        return;
    }
    char isReusable = getYesNo("Is the waste reusable? (Y/N): ");
    if (isReusable == 'y' || isReusable == 'Y') {
        cout << "Reuse for other applications. Return.\n";
        return;
    }
    char isRecyclable = getYesNo("Is the waste recyclable? (Y/N): ");
    if (isRecyclable == 'y' || isRecyclable == 'Y') {
        cout << "Recycle for other applications. Return.\n";
        return;
    }
    cout << "Send waste to landfill. Return.\n";
}
int main() {
    cout << "Waste Management System:\n";
    cout << "Get waste...\n";
    cout << "Separating waste...\n";
    separateWaste();
    return 0;
}