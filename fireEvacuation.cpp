#include <iostream>
#include <cctype>
 

 
int main() {
    int trigger;
    std::cout << "Enter 123 if there is a trigger (see or detect fire): ";
    std::cin >> trigger;
 
    if (trigger == 123) {
        char inBuilding;
        std::cout << "Are you in the building? (y/n): ";
        std::cin >> inBuilding;
        inBuilding = std::tolower(inBuilding);
        if (inBuilding == 'n') {
            std::cout << "Contact fire department.\n";
        } else {
            char smokeDetector;
            std::cout << "Did the smoke detector detect smoke? (y/n): ";
            std::cin >> smokeDetector;
            smokeDetector = std::tolower(smokeDetector);
 
            if (smokeDetector == 'y') {
                contactFireDepartment();
                evacuation();
            } else {
                char seeFire;
                std::cout << "Do you see fire or strong smoke? (y/n): ";
                std::cin >> seeFire;
                seeFire = std::tolower(seeFire);
 
                if (seeFire == 'y') {
                    evacuation();
                } else {
                    std::cout << "Stay alert. Follow further safety instructions if the situation changes.\n";
                }
            }
        }
    } else {
        std::cout << "No triggers detected. No evacuation needed.\n";
    }
 
    return 0;
}
 