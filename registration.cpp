#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

// Utility function to get 'y' or 'n' input
char getYesNoInput(const string &prompt) {
    char input;
    while (true) {
        cout << prompt << " (y/n): ";
        cin >> input;
        input = tolower(input);
        cin.ignore();
        if (input == 'y' || input == 'n') {
            return input;
        }
        cout << "Invalid input. Please enter y or n.\n";
    }
}

// Save student info to CSV
void saveToCSV(
    const string &name, const string &dob, const string &department, const string &place,
    bool visaNeeded, bool visaApplied, bool feePaid,
    bool accommodationNeeded, bool extraCredits, bool additionalCourseChosen
) {
    ofstream db("student_database.csv", ios::app);
    if (!db) {
        cerr << "Error opening database file.\n";
        return;
    }
    db << name << "," << dob << "," << department << "," << place << ","
       << (visaNeeded ? "Yes" : "No") << ","
       << (visaApplied ? "Yes" : "No") << ","
       << (feePaid ? "Yes" : "No") << ","
       << (accommodationNeeded ? "Yes" : "No") << ","
       << (extraCredits ? "Yes" : "No") << ","
       << (additionalCourseChosen ? "Yes" : "No") << "\n";
    db.close();
    cout << "\nStudent information saved to CSV database successfully.\n";
}

// Form verification
bool registrationFormVerification() {
    char verified = getYesNoInput("Is your registration form verified?");
    return (verified == 'y');
}

// Visa processing
bool visaProcess(bool &visaNeeded, bool &visaApplied) {
    char needVisa = getYesNoInput("Do you need a visa?");
    visaNeeded = (needVisa == 'y');

    if (visaNeeded) {
        while (true) {
            cout << "Inform student for visa application.\n";
            char appliedVisa = getYesNoInput("Have you applied for the visa?");
            if (appliedVisa == 'y') {
                visaApplied = true;
                break;
            } else {
                cout << "Please apply for the visa before proceeding.\n";
            }
        }
    } else {
        visaApplied = false;
        cout << "Visa not needed. Proceeding...\n";
    }

    return true;
}

// Fee payment
bool feePayment(bool &feePaid) {
    while (true) {
        char feesPaid = getYesNoInput("Have you paid the tuition fees?");
        if (feesPaid == 'y') {
            feePaid = true;
            return true;
        } else {
            cout << "Tuition fee payment is mandatory. Please pay the fee.\n";
        }
    }
}

// Accommodation
void accommodationAssignment(bool &accommodationNeeded) {
    char needAcc = getYesNoInput("Do you need accommodation?");
    accommodationNeeded = (needAcc == 'y');

    if (accommodationNeeded) {
        cout << "Accommodation will be assigned to you.\n";
    } else {
        cout << "Accommodation not needed. Proceeding...\n";
    }
}

// Tutor assignment and course selection
void tutorAssignment(bool &extraCredits, bool &additionalCourseChosen) {
    cout << "\nAssigning personal tutor...\n";
    cout << "Meeting personal tutor...\n";

    char hasCredits = getYesNoInput("Do you have extra credits?");
    extraCredits = (hasCredits == 'y');

    if (extraCredits) {
        char chooseCourse = getYesNoInput("Would you like to choose an additional course?");
        additionalCourseChosen = (chooseCourse == 'y');

        if (additionalCourseChosen) {
            cout << "Additional course chosen.\n";
        } else {
            cout << "Additional course skipped.\n";
        }
    } else {
        additionalCourseChosen = false;
        cout << "No extra credits.\n";
    }
}

// Main registration flow
int main() {
    string name, dob, department, place;
    bool visaNeeded = false, visaApplied = false;
    bool feePaid = false, accommodationNeeded = false;
    bool extraCredits = false, additionalCourseChosen = false;
    
    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter date of birth (DD/MM/YYYY): ";
    getline(cin, dob);

    cout << "Enter department: ";
    getline(cin, department);

    cout << "Enter place: ";
    getline(cin, place);

    if (!registrationFormVerification()) {
        cout << "Please verify your form before proceeding.\n";
        return 0;
    }
    cout << "Form verified successfully.\n";

    // Save to CSV before proceeding (like in your original code)
    saveToCSV(name, dob, department, place, visaNeeded, visaApplied, feePaid, accommodationNeeded, extraCredits, additionalCourseChosen);

    if (!visaProcess(visaNeeded, visaApplied)) return 0;
    if (!feePayment(feePaid)) return 0;
    accommodationAssignment(accommodationNeeded);
    tutorAssignment(extraCredits, additionalCourseChosen);

    cout << "\nRegistration process completed successfully for " << name << "!\n";
    return 0;
}
