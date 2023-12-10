/*
Name: Lucas Hasting
Description: Compute the missing side of a right triangle.
Course: CS 155 Computer Science I
Date: 6-08-2022
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
  double side1, side2, hypotenuse; //declare the variables used

  //receive all the inputs
  cout << "What is the first side: ";
  cin >> side1;
  cout << "What is the hypotenuse: ";
  cin >> hypotenuse;

  if (side1 <= 0 || hypotenuse <= 0 || hypotenuse <= side1) //Checks for accurate triangle sides
  {
    cout << "ERROR: Invalid Data!";
    return 0; //Stops the program
  }

  //compute the missing side of the triangle
  side1 *= side1;
  hypotenuse *= hypotenuse;
  side2 = hypotenuse - side1;
  side2 = sqrt(side2);

  //output the missing side to the user
  cout << "The missing side of the triangle is " << fixed << setprecision(2) << side2;
  return 0;
}
