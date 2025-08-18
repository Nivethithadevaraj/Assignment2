#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;
 
struct Student {
    string name;
    string dob;
    string department;
    string place;
    bool visaNeeded;
    bool visaApplied;
    bool feePaid;
    bool accommodationNeeded;
    bool extraCredits;
    bool additionalCourseChosen;
};
 
void saveToCSV(const Student &s) {
    ofstream db("student_database.csv", ios::app);
    if (!db) {
        cerr << "Error opening database file.\n";
        return;
    }
    db << s.name << ","
       << s.dob << ","
       << s.department << ","
       << s.place << ","
       << (s.visaNeeded ? "Yes" : "No") << ","
       << (s.visaApplied ? "Yes" : "No") << ","
       << (s.feePaid ? "Yes" : "No") << ","
       << (s.accommodationNeeded ? "Yes" : "No") << ","
       << (s.extraCredits ? "Yes" : "No") << ","
       << (s.additionalCourseChosen ? "Yes" : "No") << "\n";
    db.close();
 
    cout << "\nStudent information saved to CSV database successfully.\n";
}
 
char getYesNoInput(const string &prompt) {
    char choice;
    while (true) {
        cout << prompt << " (y/n): ";
        cin >> choice;
        cin.ignore();
        choice = tolower(choice);
        if (choice == 'y' || choice == 'n') {
            return choice;
        }
        cout << "Invalid input, please enter y or n.\n";
    }
}
 
void visa(Student &s) {
    char visaNeed = getYesNoInput("\nDoes the student need a visa?");
    s.visaNeeded = (visaNeed == 'y');
 
    if (s.visaNeeded) {
        while (true) {
            cout << "Inform student for visa application.\n";
            char visaApplied = getYesNoInput("Has the student applied for visa?");
            if (visaApplied == 'y') {
                s.visaApplied = true;
                break;
            } else {
                cout << "Please inform student to apply for visa.\n";
            }
        }
    } else {
        s.visaApplied = false;
        cout << "Visa not needed. Proceeding...\n";
    }
}
 
void fee(Student &s) {
    while (true) {
        cout << "\nPay tuition fee.\n";
        char feePaid = getYesNoInput("Has the tuition fee been paid?");
        if (feePaid == 'y') {
            s.feePaid = true;
            break;
        } else {
            cout << "Tuition fee payment is mandatory. Please pay the fee.\n";
        }
    }
}
 
void accommodation(Student &s) {
    char needAcc = getYesNoInput("\nDoes the student need accommodation?");
    s.accommodationNeeded = (needAcc == 'y');
 
    if (s.accommodationNeeded) {
        cout << "Assigning accommodation.\n";
    } else {
        cout << "Accommodation not needed. Proceeding...\n";
    }
}
 
void assignTutor(Student &s) {
    cout << "\nAssigning personal tutor.\n";
    cout << "Meeting personal tutor.\n";
 
    char credits = getYesNoInput("Does the student have extra credits?");
    s.extraCredits = (credits == 'y');
 
    if (s.extraCredits) {
        char chooseCourse = getYesNoInput("Would the student like to choose an additional course?");
        s.additionalCourseChosen = (chooseCourse == 'y');
        if (s.additionalCourseChosen) {
            cout << "Additional course chosen.\n";
        } else {
            cout << "Additional course skipped.\n";
        }
    } else {
        s.additionalCourseChosen = false;
        cout << "No extra credits.\n";
    }
}
 
void department(Student &s) {
    cout << "\nSending student to Department...\n";
    saveToCSV(s);
 
    visa(s);
    fee(s);
    accommodation(s);
    assignTutor(s);
}
 
void registration() {
    Student s;
 
    while (true) {
        cout << "\nComplete Registration Form\n";
        cout << "Enter student name: ";
        getline(cin, s.name);
 
        cout << "Enter date of birth (DD/MM/YYYY): ";
        getline(cin, s.dob);
 
        cout << "Enter department: ";
        getline(cin, s.department);
 
        cout << "Enter place: ";
        getline(cin, s.place);
 
        cout << "\nVerified by admission office?\n";
        char verified = getYesNoInput("Is the registration verified?");
        if (verified == 'y') {
            break;
        } else {
            cout << "Verification failed, please complete form again.\n";
        }
    }
 
    department(s);
}
 
int main() {
    registration();
    cout << "\nStudent fully registered!\n";
    return 0;
}
 
 