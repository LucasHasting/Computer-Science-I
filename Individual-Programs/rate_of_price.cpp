/*
Name: Lucas Hasting
Description: Calculate the rate of a price given by the user for an amount of time given by the user
Course: CS 155 Computer Science I
Date: 6-17-2022
*/

#include <iostream>
#include <iomanip>
using namespace std;

//function for inputs, also checks for data validation
double dataValidation(string ask, double value)
{
    do
    {
        cout << ask << ": ";
        cin >> value;
    } while (value < 0); //if the value is negative the question is asked again
    return value;
}

int main()
{
    //declares variables to be used in the program
    double yearlyMembership, rateIncrease;
    int amountOfYears;

    //calls the function dataValidation() for inputs and assigns them to the appropriate variable
    yearlyMembership = dataValidation("Yearly Membership", yearlyMembership);
    rateIncrease = dataValidation("Rate Increase (Percentage)", rateIncrease);
    rateIncrease /= 100; //changes the percentage to a decimal for future calculations
    amountOfYears = (int)dataValidation("Period of time (years)", (double)amountOfYears);

    //outputs the current rate
    cout << "Current rate: $" << setprecision(2) << fixed << yearlyMembership << endl;

    //calculate and output the rate for the amount of years given by the user
    for (int year = 1; year <= amountOfYears; year++)
    {
        yearlyMembership += yearlyMembership * rateIncrease;
        cout << "Rate in " << year << " year(s): $" << setprecision(2) << fixed << yearlyMembership << endl;
    }
    return 0;
}

