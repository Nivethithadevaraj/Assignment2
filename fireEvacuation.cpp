#include <iostream>
#include <cctype>
 
void contactFireDepartment() {
    std::cout << "Contact fire department immediately.\n";
}
 
void precautionSteps() {
    std::cout << "Do not open the door.\n";
    std::cout << "Seal all cracks with wet towels.\n";
    std::cout << "Contact fire department and wave at the windows.\n";
    std::cout << "Wait for the rescue.\n";
}
 
void evacuation() {
    std::cout << "Bring keys, wallet, phone, wet towels.\n";
    char doorHotSmoke;
    std::cout << "Is the door hot or is there smoke? (y/n): ";
    std::cin >> doorHotSmoke;
    doorHotSmoke = std::tolower(doorHotSmoke);
 
    if (doorHotSmoke == 'y') {
        precautionSteps();
        return;
    }
 
    std::cout << "Leave the building. Go downstairs until you exit.\n";
    char escaped;
    std::cout << "Did you escape the building? (y/n): ";
    std::cin >> escaped;
    escaped = std::tolower(escaped);
 
    if (escaped == 'y') {
        std::cout << "You are safe.\n";
    } else {
        char reachedBalcony;
        std::cout << "Did you reach the balcony? (y/n): ";
        std::cin >> reachedBalcony;
        reachedBalcony = std::tolower(reachedBalcony);
 
        if (reachedBalcony == 'y') {
            std::cout << "Wait for rescue at the balcony.\n";
        } else {
            precautionSteps();
        }
    }
}
 
int main() {
    int trigger;
    std::cout << "Enter trigger type: 1(You see the fire), 2(Someone sees the fire), 3(Detector detects smoke): ";
    std::cin >> trigger;
 
    if (trigger == 1 || trigger == 2 || trigger == 3) {
        char inBuilding;
        std::cout << "Are you in the building? (y/n): ";
        std::cin >> inBuilding;
        inBuilding = std::tolower(inBuilding);
 
        if (inBuilding == 'n') {
            contactFireDepartment();
        } else {
            if (trigger == 3) {
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
        std::cout << "Invalid trigger type. No action taken.\n";
    }
 
    return 0;
}
 