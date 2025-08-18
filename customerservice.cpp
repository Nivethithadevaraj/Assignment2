#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

// --- Basic Output Functions ---

void contactCustomerService() {
    cout << "Customer contacts Customer Service.\n";
}

void answerQuestion() {
    cout << "Answering customer's question.\n";
}

void redirectSalesSupport() {
    cout << "Redirecting to Sales Support.\nIssue resolved.\n";
}

void contactTechnicalTeam() {
    cout << "Contacting Technical Team.\nIssue resolved.\n";
}

void testIssue() {
    cout << "Testing the issue.\n";
}

bool simulateIssue() {
    char simulate;
    cout << "Can you simulate the issue? (y/n): ";
    cin >> simulate;
    return tolower(simulate) == 'y';
}

void contactCustomerForMoreInfo() {
    cout << "Contacting customer for more information...\n";
}

void errorAnalysis() {
    cout << "Performing error analysis.\n";
}

void solveIssue() {
    cout << "Solving the issue.\n";
}

void updateErrorReport() {
    cout << "Updating Error Report...\n";
    ofstream report("error_report.csv", ios::app);
    if (report.is_open()) {
        report << "Issue Recorded\n";
        report.close();
        cout << "Error Report updated successfully.\n";
    } else {
        cout << "Error: Unable to open error_report.csv\n";
    }
}

void updateErrorDatabase() {
    cout << "Updating Error Database...\n";
    ofstream db("error_database.csv", ios::app);
    if (db.is_open()) {
        db << "Error logged\n";
        db.close();
        cout << "Error Database updated successfully.\n";
    } else {
        cout << "Error: Unable to open error_database.csv\n";
    }
}

bool confirmIssueFixed() {
    char fixed;
    cout << "Has the issue been fixed? Confirm with customer (y/n): ";
    cin >> fixed;
    return tolower(fixed) == 'y';
}

void feedbackAndSurvey() {
    char feedback;
    cout << "Would you like to give feedback? (y/n): ";
    cin >> feedback;
    if (tolower(feedback) == 'y') {
        cout << "Redirecting to survey...\n";
    } else {
        cout << "No feedback given.\n";
    }
}

// --- Main Issue Handlers ---

void handleNewTechnicalIssue() {
    testIssue();

    bool simulated = simulateIssue();

    while (!simulated) {
        contactCustomerForMoreInfo();
        simulated = simulateIssue();
    }

    updateErrorReport();
    updateErrorDatabase();

    errorAnalysis();
    solveIssue();

    if (!confirmIssueFixed()) {
        cout << "Issue not fixed after initial resolution.\n";

        simulated = false;
        while (!simulated) {
            contactCustomerForMoreInfo();
            simulated = simulateIssue();
        }

        updateErrorReport();
        updateErrorDatabase();

        errorAnalysis();
        solveIssue();

        if (!confirmIssueFixed()) {
            cout << "Issue still not fixed after second attempt.\n";
        }
    }
}

void handleExistingTechnicalIssue() {
    solveIssue();

    if (!confirmIssueFixed()) {
        cout << "Issue not fixed after resolution attempt.\n";
    }
}

void handleNoTechnicalIssueBranch() {
    char newIssue;
    cout << "Is this a new issue? (y/n): ";
    cin >> newIssue;

    if (tolower(newIssue) == 'y') {
        testIssue();

        bool simulated = simulateIssue();

        while (!simulated) {
            contactCustomerForMoreInfo();
            simulated = simulateIssue();
        }

        updateErrorReport();
        updateErrorDatabase();

        errorAnalysis();
        solveIssue();

        if (!confirmIssueFixed()) {
            cout << "Issue not fixed after initial resolution.\n";

            simulated = false;
            while (!simulated) {
                contactCustomerForMoreInfo();
                simulated = simulateIssue();
            }

            updateErrorReport();
            updateErrorDatabase();

            errorAnalysis();
            solveIssue();

            if (!confirmIssueFixed()) {
                cout << "Issue still not fixed after second attempt.\n";
            }
        }
    } else {
        solveIssue();

        bool simulated = simulateIssue();
        while (!simulated) {
            contactCustomerForMoreInfo();
            simulated = simulateIssue();
        }

        updateErrorReport();
        updateErrorDatabase();

        if (!confirmIssueFixed()) {
            cout << "Issue not fixed after resolution attempt.\n";
        }
    }
}

// --- Main Driver ---

int main() {
    cout << "Customer found an issue.\n";
    contactCustomerService();

    char enquiry;
    cout << "Is the customer enquiry? (y/n): ";
    cin >> enquiry;
    if (tolower(enquiry) == 'y') {
        answerQuestion();
        feedbackAndSurvey();
        cout << "End of process.\n";
        return 0;
    }

    char salesIssue;
    cout << "Is this a sales issue? (y/n): ";
    cin >> salesIssue;
    if (tolower(salesIssue) == 'y') {
        redirectSalesSupport();
        feedbackAndSurvey();
        cout << "End of process.\n";
        return 0;
    }

    char technicalIssue;
    cout << "Is this a technical issue? (y/n): ";
    cin >> technicalIssue;
    if (tolower(technicalIssue) == 'y') {
        contactTechnicalTeam();

        char newIssue;
        cout << "Is this a new issue? (y/n): ";
        cin >> newIssue;

        if (tolower(newIssue) == 'y') {
            handleNewTechnicalIssue();
        } else {
            handleExistingTechnicalIssue();
        }

        feedbackAndSurvey();
        return 0;
    }

    // If not enquiry, sales, or technical, fallback to general issue resolution
    handleNoTechnicalIssueBranch();

    feedbackAndSurvey();
    cout << "End of process.\n";
    return 0;
}
