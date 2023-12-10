/*
Name: Lucas Hasting
Description: Compute the future value and the total interest earned.
Course: CS 155 Computer Science I
Date: 6-05-2022
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
 //Declare the variables used
 string userName;
 double principal, annualInterestRate, compoundingsPerYear, yearsOfInvestment, futureValue, totalIntrest;

 //Receive all inputs
 cout << "What is your name: ";
 getline(cin, userName);
 cout << "Principal Amount: ";
 cin >> principal;
 cout << "Annual Interest Rate (in decimal form): ";
 cin >> annualInterestRate;
 cout << "Compoundings Per Year: ";
 cin >> compoundingsPerYear;
 cout << "Years of Investment: ";
 cin >> yearsOfInvestment;

 //Calculate the future value and total intrest
 futureValue = principal * pow((1 + annualInterestRate/compoundingsPerYear),(compoundingsPerYear * yearsOfInvestment));
 totalIntrest = futureValue - principal;

 //Output the users name, future amount and the total intrest
 cout << userName << ", your future amount is $" << fixed << setprecision(2) << futureValue << " and your total interest is $" << totalIntrest << ".";
 return 0;
}

