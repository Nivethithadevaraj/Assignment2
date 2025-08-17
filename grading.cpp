#include <iostream>
using namespace std;

 
// Step 2: Get Score
int GetScore() {
    int score;
    cout << "Enter the score (0-100): ";
    cin >> score;
    return score;
}


// Step 3: Validate Score
int ValidateScore(int score) {
    while (score < 0 || score > 100) {
        cout << "Invalid score! Please enter a score between 0 and 100: ";
        score = GetScore();
    }
    return score;
}
 
// Step 4: Determine Grade
void DetermineGrade(int score) {
    if (score >= 80)
        cout << "Grade A\n";
    else if (score >= 60)
        cout << "Grade B\n";
    else if (score >= 50)
        cout << "Grade C\n";
    else
        cout << "Fail\n";
}
 
// Step 1: Main Flow
int main() {
    cout << "---- Student Grading System ----\n";
 
    int score = GetScore();
    score = ValidateScore(score);
    DetermineGrade(score);
    return 0;
}