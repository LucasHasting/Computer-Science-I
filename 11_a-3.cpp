/*
Name: Lucas Hasting
Description: Compute and display how much the ocean has risen over 20 years
Course: CS 155 Computer Science I
Date: 6-17-2022
*/

#include <iostream>
using namespace std;
int main()
{
    //Declares the variables used in the program
    const double RISE = 1.8;
    const int AMOUNT_OF_YEARS = 20;
    double newOceanLevel = 0;
    int year = 1;

    //loops through 20 iterations to simulate calculations for 20 years
    while (year <= AMOUNT_OF_YEARS)
    {
        //Computes the amount of millimeters the ocean has risen for the current year
        newOceanLevel += RISE;

        //outputs the current year and current amount the ocean has risen
        cout << "Year " << year << ": The ocean has risen a total of " << newOceanLevel << " millimeters" << "." << endl;

        year++; //goes to the next year
    }
    return 0;
}

