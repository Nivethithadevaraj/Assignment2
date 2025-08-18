#include <iostream>

 
// Function to get valid user input (y/Y/n/N)
char getValidInput(const std::string& prompt) {
    char input;
    while (true) {
        std::cout << prompt;
        std::cin >> input;
 
        if (input == 'y' || input == 'Y' || input == 'n' || input == 'N') {
            return input;
        } else {
            std::cout << "Invalid input! Please enter 'y', 'Y', 'n', or 'N'.\n";
            // Clear input buffer if needed
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
    }
}

int main() {
    std::cout << "===== Plane Boarding System =====\n";
 
    std::cout << "\nPlane has arrived at the gate.\n";
    std::cout << "Priority boarding started.\n";
 
    // PB: Priority Boarding
    char firstClass = getValidInput("Is passenger First Class? (y/n): ");
    
    if (firstClass == 'y' || firstClass == 'Y') {
        std::cout << "First Class passenger boards the plane.\n";
    } else {
        char halfBoarded = getValidInput("Have half of First Class passengers boarded? (y/n): ");
        if (halfBoarded == 'y' || halfBoarded == 'Y') {
            std::cout << "All passengers start boarding the plane.\n";
        } else {
            std::cout << "Waiting for more First Class passengers to board...\n";
        }
    }
 
    // CP: Check Passenger
    std::cout << "\n5 minutes before gate closes.\n";
    char allAboard = getValidInput("Are all passengers aboard? (y/n): ");
 
    if (allAboard == 'y' || allAboard == 'Y') {
        std::cout << "Announcement: All passengers are aboard.\n";
        std::cout << "Waiting 5 minutes...\n";
        std::cout << "Gate closed.\n";
    } else {
        std::cout << "Announcement: Final boarding call for passengers.\n";
        std::cout << "Waiting 5 minutes...\n";
        std::cout << "Gate closed.\n";
    }
 
   
    return 0;
}