/*
Name: Lucas Hasting
Description: Compute and display the volume of a cylinder until the user decides to stop
Course: CS 155 Computer Science I
Date: 6-25-2022
*/

#include <iostream>
#include <cmath>
using namespace std;

//declare function prototypes
double cylinderVolume(double diameter, double height);
void dataValidation(string output, double &input);
void dataValidation(string output, string &input); //function overloading to support string input
void printSeparator();

int main() //main driver program
{
    //calls the printSeparator function to separate output
    printSeparator();

    //declares the local variables used in the program
    double cylinderHeight, volume, cylinderDiameter;
    string yesOrNo;
    bool verify;

    //loops until the user no longer wants to compute a cylinder
    do
    {
        //calls the dataValidation function to get validated input
        dataValidation("What is the diameter of the cylinder", cylinderDiameter);
        dataValidation("What is the height of the cylinder", cylinderHeight);

        //uses the cylinderVolume function to compute the volume of a cylinder and outputs the result
        volume = cylinderVolume(cylinderDiameter, cylinderHeight);
        cout << "the volume of the cylinder is: " << volume << endl;

        //calls the overloaded dataValidation function to get validated input
        dataValidation("Would you like to compute another cylinder (yes or no)", yesOrNo);

        //verifies if the user wants to do another computation
        verify = (yesOrNo == "yes");

        //calls the printSeparator function to separate output
        printSeparator();

    } while (verify);

    return 0;
}

/*
Name: cylinderVolume
Purpose: compute the volume of a cylinder
Incoming: diameter (double), height (double)
Outgoing: volume
Return: volume
*/
double cylinderVolume(double diameter, double height)
{
    double raidus = diameter / 2;
    double volume = M_PI * (pow(raidus, 2)) * height;
    return volume;
}

/*
Name: dataValidation
Purpose: Validates the input by continuously asking the question until the condition is false
Incoming: OUTPUT (constant string), input (double reference)
Outgoing: OUTPUT (constant string) + ": ", input (double reference)
Return: Nothing
*/
void dataValidation(const string OUTPUT, double &input)
{
    do
    {
        cout << OUTPUT << ": ";
        cin >> input;
    } while (input <= 0);
}

/*
Name: dataValidation
Purpose: Overloads previous function to support string input
Incoming: OUTPUT (constant string), input (string reference)
Outgoing: OUTPUT (constant string) + ": ", input (string reference)
Return: Nothing
*/
void dataValidation(const string OUTPUT, string &input)
{
    do
    {
        cout << OUTPUT << ": ";
        cin >> input;
    } while ((input != "yes") && (input != "no"));
}

/*
Name: printSeparator
Purpose: To separate multiple sections of output
Incoming: Nothing
Outgoing: "="(65)
Return: Nothing
*/
void printSeparator()
{
    for (int iteration = 0; iteration < 65; iteration++)
        cout << "=";
    cout << endl;
}
