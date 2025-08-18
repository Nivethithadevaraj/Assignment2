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
void collectTicket() {
    std::cout << "Collect your ticket.\n";
    std::cout << "Check the letter box within 3 days or collect from the machine.\n";
}
 
void boarding(bool hasReservation) {
    char haveReservation;
    std::cout << "Do you have a reservation? (y/n): ";
    std::cin >> haveReservation;
    haveReservation = std::tolower(haveReservation);
 
    if (haveReservation == 'y' && hasReservation) {
        std::cout << "Look for your assigned seat.\n";
    } else {
        std::cout << "Look for an unassigned seat.\n";
    }
}
 
bool journey() {
    char ticketChecked;
    std::cout << "Has your ticket been checked by the inspector? (y/n): ";
    std::cin >> ticketChecked;
    ticketChecked = std::tolower(ticketChecked);
 
    if (ticketChecked == 'n') {
        char discountTicket;
        std::cout << "Do you have a discounted ticket? (y/n): ";
        std::cin >> discountTicket;
        discountTicket = std::tolower(discountTicket);
 
        if (discountTicket == 'y') {
            std::cout << "Show valid discount documentation.\n";
            return true;
        } else {
            std::cout << "Ticket invalid. Please buy a valid ticket.\n";
            return false;
        }
    }
    return true;
}
 
void arrivalExit() {
    char arrived;
    std::cout << "Have you arrived at your destination? (y/n): ";
    std::cin >> arrived;
    arrived = std::tolower(arrived);
 
    if (arrived == 'y') {
        std::cout << "Leave the train.\n";
    } else {
        std::cout << "Enjoy your journey!\n";
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
 