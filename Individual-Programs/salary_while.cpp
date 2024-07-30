/*
Name: Lucas Hasting
Description: Compute and display a users salary where it starts as a quarter and doubles everyday
Course: CS 155 Computer Science I
Date: 6-17-2022
*/

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    //declares the total days, and starting day for later
    int totalDays, day = 1;

    //gain the input for the total days working
    cout << "How many days are you working: ";
    cin >> totalDays;

    //declares the starting salary
    double totalSalary = 0.25;

    //checks for invalid data
    if (totalDays <= 0)
    {
        cout << "Invalid Data!";
        return 0;
    }

    //loops through the amount of days inputed
    while (day <= totalDays)
    {
        //outputs the current day and current salary
        cout << "Day " << day << ": $" << setprecision(2) << fixed << totalSalary << endl;

        //salary is doubled after every day
        totalSalary *= 2;

        day++; //goes to the next day
    }
    return 0;
}
