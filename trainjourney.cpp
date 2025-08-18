#include <iostream>
#include <string>
#include <cctype>
 
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
 