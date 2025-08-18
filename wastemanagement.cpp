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

int main() {
    cout << "Waste Management System:\n";
    cout << "Get waste...\n";
    cout << "Separating waste...\n";
    separateWaste();
    return 0;
}