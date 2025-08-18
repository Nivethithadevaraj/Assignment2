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
int main() {
    cout << "Banking Process Start\n";
    cout << "Initialization process:\n";
    initializationProcess();
    cout << "Review process:\n";
    reviewProcess();
    cout << "End of Banking Transaction.\n";
    return 0;
}
 