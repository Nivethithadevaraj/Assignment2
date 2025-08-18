#include <iostream>
using namespace std;
 
// Helper function for robust Y/y/N/n input
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
    cout << "Order placed.\n";
 
    char moreItems;
    do {
        cout << "\nProcessing an item...\n";
        char inWarehouse = getYesNo("Is the item in the warehouse? (Y/N): ");
 
        if (inWarehouse == 'y' || inWarehouse == 'Y') {
            cout << "Pack with other orders in the warehouse.\n";
        } else {
            cout << "Contact seller.\n";
            cout << "Seller sends goods to customer.\n";
        }
 
        moreItems = getYesNo("Do you want to process another item? (Y/N): ");
    } while (moreItems == 'y' || moreItems == 'Y');
    return 0;
}