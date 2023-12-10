/*
Name: Lucas Hasting
Description: Compute and display a users payroll
Course: CS 155 Computer Science I
Date: 6-11-2022
*/

#include <iostream>
using namespace std;
int main()
{
 //declare variables to be used in the program
 string userName;
 double hourlyRate, totalPay;
 int hoursWorked;

 //receives inputs
 cout << "What is your name: ";
 cin >> userName;
 cout <<"hourly rate: ";
 cin >> hourlyRate;
 cout << "hours worked: ";
 cin >> hoursWorked;

 //checks for invalid data
 if (hourlyRate <= 0 || hoursWorked <= 0)
 {
     cout << "ERROR: Invalid Data!";
     return 0; //ends the program
 }

 //declare the constants used for computing the total pay
 const double REGULAR = hourlyRate, DOUBLE = hourlyRate * 2, TRIPLE = hourlyRate * 3;

 //all branches return the hours worked and computes total pay
 if (hoursWorked < 7) //checks for only regular pay
 {
    cout << "Regular Time: " << hoursWorked << " hours" << endl;
    totalPay = hoursWorked * REGULAR;
 }
 else if (hoursWorked < 15) //checks for double-time and regular pay
 {
    hoursWorked -= 6;
    cout << "Regular Time: 6 hours" << endl;
    cout << "Double-Time: " << hoursWorked << " hours" << endl;
    totalPay = (6 * REGULAR) + (hoursWorked * DOUBLE);
 }
 else //used for triple-time, double-time, and regular pay
 {
    hoursWorked -= 14;
    cout << "Regular Time: 6 hours" << endl;
    cout << "Double-Time: 8 hours" << endl;
    cout << "Triple-Time: " << hoursWorked << " hours" << endl;
    totalPay = (6 * REGULAR) + (8 * DOUBLE) + (hoursWorked * TRIPLE);
 }

 //outputs the total pay and the user name
 cout << "Hello " << userName << ", your total pay is $" << totalPay << ".";
 return 0;
}

