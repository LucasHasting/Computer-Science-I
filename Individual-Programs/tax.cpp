/*
Name: Lucas Hasting
Description: Compute and display the amount of tax a user owes
Course: CS 155 Computer Science I
Date: 6-13-2022
*/

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    //declare variables
    double taxableIncome, taxOwed;
    char singleMarried;

    //get inputs for taxable income and if the user is single or married
    cout << "Taxable income: ";
    cin >> taxableIncome;
    cout << "Single or Married (s or m): ";
    cin >> singleMarried;

    //checks for invalid taxable income
    if (taxableIncome < 0)
    {
        cout << "Invalid Data!";
        return 0;
    }

    //switch to separate single and married incomes
    switch (singleMarried)
    {
    //computes the single tax owed
    case 's':
        if (taxableIncome <= 30000)
            taxOwed = taxableIncome * 0.12;
        else
            taxOwed = 3000 + ((taxableIncome - 30000) * 0.24);
        break;

    //computes the married tax owed
    case 'm':
        if (taxableIncome <= 60000)
            taxOwed = taxableIncome * 0.12;
        else
            taxOwed = 6000 + ((taxableIncome - 60000) * 0.24);
        break;

    //any other character or number would be invalid data
    default:
        cout << "Invalid Data!";
        return 0;
    }

    //outputs the total tax owed
    cout << "The total tax owed is $" << setprecision(2) << fixed << taxOwed << "." << endl;
    return 0;
}

