/*
Name: Lucas Hasting
Description: Compute and display a users payroll
Course: CS 155 Computer Science I
Date: 6-25-2022
*/

#include <fstream>
#include <iostream>
using namespace std;
int main()
{
 //declare variables to be used in the program
 ifstream inputFile;
 ofstream outputFile;
 string userName;
 double hourlyRate, totalPay;
 double hoursWorked;
 string cool, cooler, coolest;

 //open the input and output files
 inputFile.open("input-Hasting.txt");
 outputFile.open("output-Hasting.txt");

 //checks if the input file could be opened
 if (inputFile.fail())
 {
     cout << "ERROR: Could not open the file";
     return 0;
 }

 //loops through the input file until it reaches the end of the file
 while (!inputFile.eof())
 {
    //receives inputs
    getline(inputFile, userName);
    inputFile >> hoursWorked;
    inputFile >> hourlyRate;

    //checks for invalid data
    if (hourlyRate <= 0 || hoursWorked <= 0)
    {
      cout << "ERROR: Invalid Data!";
      return 0; //ends the program
    }

    //declare the constants used for computing the total pay, outputs the user's name to console and file
    const double REGULAR = hourlyRate, DOUBLE = hourlyRate * 2, TRIPLE = hourlyRate * 3;
    outputFile << "Hello " << userName
    << ", Below is the amount of hours you worked and the amount of money you have earned"
    << endl;

    cout << "Hello " << userName
    << ", Below is the amount of hours you worked and the amount of money you have earned"
    << endl;

    //all branches return the hours worked and computes total pay
    if (hoursWorked < 7) //checks for only regular pay
    {
     outputFile << "Regular Time: " << hoursWorked << " hours: " << hoursWorked * REGULAR << endl;
     cout << "Regular Time: " << hoursWorked << " hours: " << hoursWorked * REGULAR << endl;
     totalPay = hoursWorked * REGULAR;
    }
    else if (hoursWorked < 15) //checks for double-time and regular pay
    {
     hoursWorked -= 6;
     outputFile << "Regular Time: 6 hours: $" << (6 * REGULAR) << endl;
     outputFile << "Double-Time: " << hoursWorked << " hours: $" << (hoursWorked * DOUBLE) << endl;
     cout << "Regular Time: 6 hours: $" << (6 * REGULAR) << endl;
     cout << "Double-Time: " << hoursWorked << " hours: $" << (hoursWorked * DOUBLE) << endl;
     totalPay = (6 * REGULAR) + (hoursWorked * DOUBLE);
    }
    else //used for triple-time, double-time, and regular pay
    {
     hoursWorked -= 14;
     outputFile << "Regular Time: 6 hours: $" << (6 * REGULAR) << endl;
     outputFile << "Double-Time: 8 hours: $" << (8 * DOUBLE) << endl;
     outputFile << "Triple-Time: " << hoursWorked << " hours: $" << (hoursWorked * TRIPLE) << endl;
     cout << "Regular Time: 6 hours: $" << (6 * REGULAR) << endl;
     cout << "Double-Time: 8 hours: $" << (8 * DOUBLE) << endl;
     cout << "Triple-Time: " << hoursWorked << " hours: $" << (hoursWorked * TRIPLE) << endl;
     totalPay = (6 * REGULAR) + (8 * DOUBLE) + (hoursWorked * TRIPLE);
    }

    //outputs the total pay and the user name
    outputFile << "your total pay is $" << totalPay << "." << endl << endl;
    cout << "your total pay is $" << totalPay << "." << endl << endl;
    inputFile.ignore(); //clear the input buffer so getline() can be used again
}

 //close the input and output files
 inputFile.close();
 outputFile.close();
 return 0;
}

