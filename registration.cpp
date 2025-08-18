#include <iostream>
#include <string>
#include <cctype>
 
void registrationFormVerification(bool &isVerified) {
    char verified;
    std::cout << "Is your registration form verified? (y/n): ";
    std::cin >> verified;
    verified = std::tolower(verified);
    isVerified = (verified == 'y');
}
 

 
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
 