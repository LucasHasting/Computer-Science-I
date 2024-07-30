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
    double totalBurned;
    const int TOTAL_MINUTES = 40;
    const int MINUTE_INCREASE = 5;

    //loops through 7 iterations, calculates and outputs the amount of calories burned
    for (int minutes = 10; minutes <= TOTAL_MINUTES; minutes += MINUTE_INCREASE)
    {
        //calculates the total calories that were burned during the current time frame
        totalBurned = minutes * CALORIES_BURNED;

        //outputs the total calories that were burned during the current time frame
        cout << "The amount of calories burned after " << minutes << " minutes is " << totalBurned << "." << endl;
    }
}
