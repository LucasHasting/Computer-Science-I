/*
Name: Lucas Hasting
Description: Decide and display a users class
Course: CS 155 Computer Science I
Date: 6-13-2022
*/

#include <iostream>
using namespace std;
int main()
{
    //declare variables that will be used
    int creditsEarned;
    string currentClass;

    //gets the input for credits earned
    cout << "How many credits do you have: ";
    cin >> creditsEarned;

    if (creditsEarned < 0) //checks for invalid data
    {
        cout << "Invalid Data!";
        return 0;
    }

    //decides the class based on number of credits
    else if (creditsEarned >= 0 && creditsEarned <= 30)
        currentClass = "Freshman";
    else if (creditsEarned >= 31 && creditsEarned <= 60)
        currentClass = "Sophomore";
    else if (creditsEarned >= 61 && creditsEarned <= 90)
        currentClass = "Junior";
    else
        currentClass = "Senior";

    //outputs the class
    cout << "Your current class is " << currentClass << ".";
    return 0;
}

