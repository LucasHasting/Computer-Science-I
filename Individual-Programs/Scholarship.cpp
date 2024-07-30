/*
Name: Lucas Hasting
Description: Computes a score for a scholarship
Course: CS 155 Computer Science I
Date: 6-25-2022
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

 //declare variables to be used in the program
 double gpa, score;
 int act, applicant, applicantNum;
 string scholarship;

 //data validation for amount of applicants
 do
 {
    cout << "How many applicants to process: ";
    cin >> applicantNum;
 } while (applicantNum < 1 || applicantNum > 6);

 //asks question for every applicant and gain input for gpa and act Score
 for (applicant = 1; applicant <= applicantNum; applicant++)
 {
    //Data validation: keeps asking the question until valid data is read
    do
    {
     cout << "What is the applicant #" << applicant << "'s High School Grade Point Average: ";
     cin >> gpa;
    } while (gpa < 0 || gpa > 4);

    //Data validation: keeps asking the question until valid data is read
    do
    {
     cout << "What is applicant #" << applicant << "'s ACT Score: ";
     cin >> act;
    } while (act < 1 || act > 36);

    //calculates the score
    score = 20 + (12 * gpa) + (1.5 * act);

    //determines the scholarship level
    if (score >= 100)
        scholarship = "Lion Scholarship";
    else if (score >= 90)
        scholarship = "Cub Scholarship";
    else
        scholarship = "None";

    //outputs the applicant, their score, and their scholarship level
    cout << "Applicant #" << applicant << " your score is: "
    << setprecision(1) << fixed << score << endl
    << "Applicant #" << applicant << " your scholarship is: "
    << scholarship << endl << endl;
 }

 return 0; //ends the program

}
