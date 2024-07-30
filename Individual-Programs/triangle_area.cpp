/*
Name: Lucas Hasting
Description: Compute and display the area of a triangle
Course: CS 155 Computer Science I
Date: 7-6-2022
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>
using namespace std;

//declare function prototypes
void fileOutput(string output);
void fileClear();
void stringAppend(string output1, double output2, string &newOutput);
void stringAppend(string output1, string output2, string &newOutput);
void dataValidation(double &side, int sideNumber);
void dataValidation(char &yesOrNo);
void getSides(double &side1, double &side2, double &side3);
double triangleArea (double side1, double side2, double side3);
void printSeparator(string output);

int main() //main driver program
{
    //declare local variables
    double sideA, sideB, sideC, areaOfTriangle;
    string output;
    char yesOrNo;

    //calls the fileClear function to clear the output file for further use
    fileClear();

    //call the printSeparator function to separate output
    printSeparator("=");

    //Loops until the user decides to stop
    do
    {
        //calls the getSides function to validate input for the 3 sides
        getSides(sideA, sideB, sideC);

        //calls thr triangleArea function to calculate the area of a triangle and store it in areOfTriangle
        areaOfTriangle = triangleArea(sideA, sideB, sideC);

        //output the area of a triangle
        cout << "The area of the triangle is: "
        << setprecision(2) << fixed << areaOfTriangle << endl;

        //calls the stringAppend function to append to a string
        stringAppend("The area of the triangle is: ", areaOfTriangle, output);

        //calls the fileOutput function to output the area of a triangle to a file
        fileOutput(output);

        //call the printSeparator function to separate output
        printSeparator("-");

        //calls the overloaded dataValidation function to validate input for yesOrNo
        dataValidation(yesOrNo);

        //call the printSeparator function to separate output
        printSeparator("=");

    }while(yesOrNo == 'Y');
    return 0; //end the program
}

void fileOutput(string output)
{
    //create the output file stream
    ofstream out;

    //open the output file stream
    out.open("triangles.txt", ios_base::app); //appends the file

    //outputs to a file
    out << output << endl;

    //close the output file stream
    out.close();
    return;
}

void fileClear()
{
    //creates the output file stream
    ofstream output;

    //opens the output file stream to clear the file
    output.open("triangles.txt");

    //closes the output file stream
    output.close();
}

void stringAppend(string output1, double output2, string &newOutput)
{
    //opens the string stream
    stringstream output;

    //if the number has a decimal display 2 decimals otherwise show no decimals
    if (output2 > (int)output2)
        output << setprecision(2) << fixed << output1 << output2;
    else
        output << output1 << output2;

    //the new string from the string stream
    newOutput = output.str();
    return;
}

void stringAppend(string output1, string output2, string &newOutput)
{
    //opens the string stream
    stringstream output;

    //appends the string
    output << output1 << output2;

    //the new string from the string stream
    newOutput = output.str();
}

/*
Name: dataValidation
Purpose: validates input for any of the sides of a triangle
Incoming: side, sideNumber
Outgoing: side
Return: nothing
*/
void dataValidation(double &side, int sideNumber)
{
    string output;
    do
    {
        cout << "What is side " << sideNumber << ": ";
        cin >> side;
    } while (side <= 0);

    //calls the stringAppend function to append the output
    stringAppend("side ", sideNumber, output);
    stringAppend(output, ": ", output);
    stringAppend(output, side, output);

    //sends the output to a file
    fileOutput(output);
    return;
}

/*
Name: dataValidation
Purpose: an overloaded function of dataValidation to work with the yesOrNo variable
Incoming: yesOrNo
Outgoing: yesOrNo
Return: nothing
*/
void dataValidation(char &yesOrNo)
{
    string output;
    do
    {
        cout << "Would you like to do another triangle (Y or N): ";
        cin >> yesOrNo;
    } while (yesOrNo != 'Y' && yesOrNo != 'N');

    //stores yesOrNo into a string so it can be compared
    output = yesOrNo;

    //calls the stringAppend function to append the output
    stringAppend("Would you like to do another triangle (Y or N): ", output, output);

    //sends the output to a file
    fileOutput(output);
    return;
}

/*
Name: getSides
Purpose: to use the dataValidation function to validate input for all sides
Incoming: side1, side2, side3
Outgoing: side1, side2, side3
Return: nothing
*/
void getSides(double &side1, double &side2, double &side3)
{
    dataValidation(side1, 1);
    dataValidation(side2, 2);
    dataValidation(side3, 3);
    return;
}

/*
Name: triangleArea
Purpose: to calculate the area of a triangle
Incoming: side1, side2, side3
Outgoing: area
Return: area
*/
double triangleArea (double side1, double side2, double side3)
{
    //declare local variables and assign them values to calculate the triangles area
    double semiperimeter = (side1 + side2 + side3) / 2,
    area = semiperimeter * (semiperimeter - side1) *
    (semiperimeter - side2) * (semiperimeter - side3);

    //use sqrt to calculate the square root
    area = sqrt(area);

    return area; //end the function
}

/*
Name: printSeparator
Purpose: To separate multiple sections of output
Incoming: output
Outgoing: output(60)
Return: nothing
*/
void printSeparator(string output)
{
    string out = "";

    //stores the separator into a variable
    for (int itteration = 0; itteration < 60; itteration++)
        out += output;

    //send the separator to the screen and a file
    cout << out << endl;
    fileOutput(out);
    return;
}
