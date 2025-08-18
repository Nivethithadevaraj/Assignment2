#include <iostream>
#include <cctype>
int main() {
    contactCustomerService();
 
    char issueType;
    std::cout << "Is there an issue? (y/n): ";
    std::cin >> issueType;
    issueType = std::tolower(issueType);
 
    if (issueType == 'n') {
        std::cout << "No issues. Ending process.\n";
        feedback();
        return 0;
    }
 
    char salesIssue;
    std::cout << "Is this a sales issue? (y/n): ";
    std::cin >> salesIssue;
    salesIssue = std::tolower(salesIssue);
 
    if (salesIssue == 'y') {
        redirectSalesSupport();
        feedback();
        return 0;
    }
 
    char techIssue;
    std::cout << "Is this a technical issue? (y/n): ";
    std::cin >> techIssue;
    techIssue = std::tolower(techIssue);
 
    if (techIssue == 'y') {
        contactTechnicalTeam();
 
        char newIssue;
        std::cout << "Is this a new issue? (y/n): ";
        std::cin >> newIssue;
        newIssue = std::tolower(newIssue);
 
        if (newIssue == 'y') {
            testAndResolveIssue();
 
            char fixed;
            std::cout << "Is the issue fixed? (y/n): ";
            std::cin >> fixed;
            fixed = std::tolower(fixed);
 
            if (fixed != 'y') {
                std::cout << "Issue still not fixed. Contacting technical team again...\n";
                testAndResolveIssue();
            }
        }
        feedback();
        return 0;
    }
 
    std::cout << "No sales or technical issue. Proceeding to feedback.\n";
    feedback();
 
    return 0;
}