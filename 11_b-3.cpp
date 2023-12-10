/*
Name: Lucas Hasting
Description: Compute and display the amount of calories someone has burned per minute
Course: CS 155 Computer Science I
Date: 6-17-2022
*/

#include <iostream>
using namespace std;
int main()
{
    //Declares the variables that will be used in the program
    const double CALORIES_BURNED = 3.75;
    const int TOTAL_MINUTES = 40;
    const int MINUTE_INCREASE = 5;
    double totalBurned;
    int currentMinutes = 10;


    //loops through 7 iterations, calculates and outputs the amount of calories burned
    while (currentMinutes <= TOTAL_MINUTES)
    {
        //calculates the total calories that were burned during the current time frame
        totalBurned = currentMinutes * CALORIES_BURNED;

        //outputs the total calories that were burned during the current time frame
        cout << "The amount of calories burned after " << currentMinutes << " minutes is " << totalBurned << "." << endl;

        currentMinutes += MINUTE_INCREASE; //goes up 5 minutes
    }
}
