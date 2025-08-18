#include <iostream>
#include <string>
#include <cctype>
 
void ticketPurchase(bool &hasTicket, bool &needReservation) {
    char buyTicket;
    std::cout << "Do you want to buy a ticket? (y/n): ";
    std::cin >> buyTicket;
    buyTicket = std::tolower(buyTicket);
 
    if (buyTicket == 'y') {
        hasTicket = true;
        char needRes;
        std::cout << "Do you need a seat reservation? (y/n): ";
        std::cin >> needRes;
        needRes = std::tolower(needRes);
 
        if (needRes == 'y') {
            needReservation = true;
            std::cout << "Select your seat.\n";
        } else {
            needReservation = false;
        }
    } else {
        hasTicket = false;
        needReservation = false;
    }
}
int main() {
    bool hasTicket = false;
    bool needReservation = false;
 
    ticketPurchase(hasTicket, needReservation);
 
    if (!hasTicket) {
        std::cout << "You must buy a ticket to continue.\n";
        return 0;
    }
 
    collectTicket();
 
    boarding(needReservation);
 
    if (!journey()) {
        return 0;
    }
 
    arrivalExit();
 
    std::cout << "Journey completed. Thank you for travelling with us.\n";
 
    return 0;
}
 