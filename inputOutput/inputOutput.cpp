/*
Name: Lucas Hasting
Description: Use an input file to store results into an output file
Course: CS 155 Computer Science I
Date: 7-14-2022
*/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//Declare function prototypes
int fileSize (string inputFile);
int file(string inputFile, string outputFile);
void input (string output, string &input);

int main() //main driver program
{
    //declare variables
    int error;
    string inputFile, outputFile;

    //get input for the names of both files
    input("What is the name of the input file: ", inputFile);
    input("What is the name of the output file: ", outputFile);

    //calls the file function and stores the return type
    error = file(inputFile, outputFile);

    //if the file function returns 1, an error has occurred
    if (error == 1)
    {
     cout << "Error reading file" << endl;
     return 1;
    }

    //the file function returned no errors
    else
    {
        cout << "Process Complete!" << endl;
        return 0;
    }
}

/*
Name: fileSize
Purpose: get's the amount of lines in the file
Incoming: inputFile
Outgoing: Size
Return: Size
*/
int fileSize (string inputFile)
{
    //declare local variables
    ifstream input;
    double placeholder, Size = 0;

    //opens the input file
    input.open(inputFile);

    //counts the lines in a file
    for (int element = 0; input.is_open(); element++)
    {
        input >> placeholder >> placeholder;
        Size++;
        if (input.eof())
            break;
    }

    //closes the file
    input.close();

    return Size;
}

/*
Name: file
Purpose: output the result's to the output file
Incoming: inputFile, outputFile
Outgoing: 1 or 0 (based on errors)
Return: 1 or 0 (based on errors)
*/
int file(string inputFile, string outputFile)
{
    //declare local variables
    ifstream input;
    ofstream output;
    int Size;

    //get the file size by calling the fileSize function
    Size = fileSize(inputFile);

    //declare the arrays
    double num1[Size], num2[Size];

    //open both files
    input.open(inputFile);
    output.open(outputFile);

    //checks for errors opening the file
    if (input.fail())
    {
        return 1;
    }

    //stores the numbers from the input file into an array
    for (int element = 0; input.is_open(); element++)
    {
        input >> num1[element] >> num2[element];
        if (input.eof())
            break;
    }

    //output the results to the output file
    for (int element = 0; element < Size; element++)
    {
        output << setprecision(1) << fixed
        << num1[element] << "   " << num2[element] << "   Sum: "
        << num1[element] + num2[element] << "   Difference: ";
        if (num1[element] - num2[element] < 0)
            output << num2[element] - num1[element] << "   Product: ";
        else
            output << num1[element] - num2[element] << "   Product: ";
        output << num1[element] * num2[element] << "   Quotient: "
        << num1[element] / num2[element] << endl;
    }

    //close both files
    input.close();
    output.close();

    return 0;
}

/*
Name: input
Purpose: get input
Incoming: output, input
Outgoing: input
Return: Nothing
*/
void input (string output, string &input)
{
    cout << output;
    cin >> input;
}
