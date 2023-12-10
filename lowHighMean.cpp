/*
Name: Lucas Hasting
Description: Compute and display the lower and higher mean of 4 scores
Course: CS 155 Computer Science I
Date: 7-5-2022
*/

#include <iostream>
#include <iomanip>
using namespace std;

//declare function prototypes
void dataValidation(double &score, int scoreNumber);
void scores(double score1, double score2, double score3, double score4, double &meanLowest, double &meanHighest);

int main() //main driver program
{
    //declare variables
    double low, high, score1, score2, score3, score4;

    //calls the dataValidation function to validate input for the 4 scores
    dataValidation(score1, 1);
    dataValidation(score2, 2);
    dataValidation(score3, 3);
    dataValidation(score4, 4);

    //calls the score function to compute the low mean and high mean
    scores(score1, score2, score3, score4, low, high);

    //output both means
    cout << setprecision(2) << fixed
    << "Mean with the lowest score dropped: " << low << endl
    << "Mean with the highest score dropped: " << high << endl;

    return 0; //ends the program
}

/*
Name: dataValidation
Purpose: validates input for the score variable
Incoming: score, scoreNumber
Outgoing: score
Return: nothing
*/
void dataValidation(double &score, int scoreNumber)
{
    do
    {
        cout << "What is score " << scoreNumber << ": ";
        cin >> score;
    } while (score < 0);

    return;
}

/*
Name: scores
Purpose: compute the lower and higher mean
Incoming: score1, score2, score3, score4, meanLowest, meanHighest
Outgoing: meanLowest, meanHighest
Return: nothing
*/
void scores(double score1, double score2, double score3, double score4, double &meanLowest, double &meanHighest)
{
    //declare local variables
    double allScores [4] = {score1, score2, score3, score4},
    maxScore = allScores[0], minScore = allScores[0];

    //finds the minimum and maximum scores
    for (int score = 0; score < 4; score++)
    {
        if (allScores[score] > maxScore)
            maxScore = allScores[score];
        else if (allScores[score] < minScore)
            minScore = allScores[score];
    }

    //drops the highest score to compute the higher mean
    for (int score = 0; score < 4; score++)
    {
        if (allScores[score] == maxScore)
            continue;
        meanHighest += allScores[score];
    }

    //computes the higher mean
    meanHighest /= 3;

    //drops the lowest score to compute the higher mean
    for (int score = 0; score < 4; score++)
    {
        if (allScores[score] == minScore)
            continue;
        meanLowest += allScores[score];
    }

    //computes the lower mean
    meanLowest /= 3;

    return; //end the function
}
