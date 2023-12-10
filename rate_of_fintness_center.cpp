/*
Name: Lucas Hasting
Description: Calculate the rate of a fitness center for the next 8 years
Course: CS 155 Computer Science I
Date: 6-17-2022
*/

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    //Declare the variables that will be used in the program
    double yearlyMembership = 315;
    const double RATE_INCREASE = 0.04;
    const int AMOUNT_OF_YEARS = 8;

    //output the current rate
    cout << "Current rate: $" << setprecision(2) << fixed << yearlyMembership << endl;

    //calculate and output the rate for the next 8 years
    for (int year = 1; year <= AMOUNT_OF_YEARS; year++)
    {
        yearlyMembership += yearlyMembership * RATE_INCREASE;
        cout << "Rate in " << year << " year(s): $" << setprecision(2) << fixed << yearlyMembership << endl;
    }
    return 0;
}
