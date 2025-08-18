#include <iostream>
#include <string>
#include <cctype>
 

 
int main() {
    std::string studentName;
    bool formVerified = false;
 
    std::cout << "Enter your name: ";
    std::getline(std::cin, studentName);
 
    registrationFormVerification(formVerified);
 
    if (!formVerified) {
        std::cout << "Please verify your form before proceeding.\n";
        return 0;
    }
    std::cout << "Form verified successfully.\n";
 
    if (!visaProcess()) {
        return 0;
    }
 
    if (!feePayment()) {
        return 0;
    }
 
    accommodationAssignment();
 
    tutorAssignment();
 
    std::cout << "\nRegistration process completed successfully for " << studentName << "!\n";
 
    return 0;
}
 