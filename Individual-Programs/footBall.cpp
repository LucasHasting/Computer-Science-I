/*
Name: Lucas Hasting
Description: Compute the total points that a football team scored
Course: CS 155 Computer Science I
Date: 6-02-2022
*/

#include <iostream>
using namespace std;
int main()
{
 //Declare Variables
 int touchdowns, one_pointPATs, two_pointPATs, fieldGoals, safety, totalPoints;

 //Get all Inputs
 cout << "How Many Touchdowns: ";
 cin >> touchdowns;
 cout << "How Many 1-point PATs: ";
 cin >> one_pointPATs;
 cout << "How Many 2-point PATs: ";
 cin >> two_pointPATs;
 cout << "How Many field goals: ";
 cin >> fieldGoals;
 cout << "How Many safeties: ";
 cin >> safety;

 //Computes all of the points and adds it to the total
 touchdowns *= 6;
 two_pointPATs *= 2;
 fieldGoals *= 3;
 safety *= 2;
 totalPoints = touchdowns + one_pointPATs + two_pointPATs + fieldGoals + safety;

 //Outputs the total points scored
 cout << "The total points the football team scored is " << totalPoints;
 return 0;
}
