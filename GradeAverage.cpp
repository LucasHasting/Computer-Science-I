/*
Name: Lucas Hasting
Description: Computes and displays the average of 4 exam scores that are entered by a user.
Course: CS 155 Computer Science I
Date: 5-30-2022
*/

#include <iostream>
using namespace std;

int main()
{
  //Create an array to store the scores, and a variable to store the mean
  double Scores[4];
  double Mean;

  for(int i = 0; i != 4; i++) //loops through the process of outputting and inputing scores
  {
      cout << "Score " << i + 1 << ": "; //outputs the current score being entered
      cin >> Scores[i]; //inputs the current score
      Mean += Scores[i]; //adds the current score to the mean variable
  }

  Mean /= 4; //divides the added up scores by the number of scores to get the mean
  cout << "The mean of the scores is ";
  cout << Mean; //outputs the mean to the terminal
}
