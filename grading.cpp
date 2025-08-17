#include <iostream>
using namespace std;

 
// Step 2: Get Score
int GetScore() {
    int score;
    cout << "Enter the score (0-100): ";
    cin >> score;
    return score;
}
// Step 1: Main Flow
int main() {
    cout << "---- Student Grading System ----\n";
 
    int score = GetScore();
    score = ValidateScore(score);
    DetermineGrade(score);
    return 0;
}