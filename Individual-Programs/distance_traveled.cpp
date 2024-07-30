/*
Name: Lucas Hasting
Description: Compute and display the distance traveled/the average speed the car traveled during the trip.
Course: CS 155 Computer Science I
Date: 6-08-2022
*/

#include <iostream>
using namespace std;
int main()
{
 //Declare Variables
 double odometerReadingsBefore, odometerReadingsAfter, hoursOfDriving, distance, averageSpeed;

 //Get all Inputs
 cout << "Odometer readings before the trip: ";
 cin >> odometerReadingsBefore;
 cout << "Odometer readings after the trip: ";
 cin >> odometerReadingsAfter;

 if (odometerReadingsBefore > odometerReadingsAfter) //Checks for accurate odometer readings
 {
     cout << "ERROR: Invalid Data!";
     return 0; //Stops the program
 }

 cout << "Amount of hours driven: ";
 cin >> hoursOfDriving;

 //Calculate the distance and total speed
 distance = odometerReadingsAfter - odometerReadingsBefore;
 averageSpeed = distance / hoursOfDriving;

 //Output the distance and average speed
 cout << "The car traveled a total of " << distance << " miles." << endl;
 cout << "The car traveled at an average of " << averageSpeed << " miles per hour." << endl;
 return 0;
}
