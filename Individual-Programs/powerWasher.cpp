/*
Name: Lucas Hasting
Description: Compute and display the total charge after using the power washer
Course: CS 155 Computer Science I
Date: 6-25-2022
*/

#include <iostream>
#include <iomanip>
using namespace std;
const double INITIAL_COST = 0.25, NEW_COST = 0.18;
const int HOUR = 60;

//Declare function prototypes
double PowerWasherRental(int minute);
void printSeperator();
int Customer(char yesOrNo);
void dataValidation(const string OUTPUT, int &input);
void dataValidation(const string OUTPUT, char input, int &decide);

int main() //main driver program
{
    //declare local variables used in the program
    int check, amountOfMinutes;
    char yesNo;
    double charge;

    //separates the output
    printSeperator();

    //loops until the user decides to stop the program
    do
    {
        //calls the dataValidation function to validate input
        dataValidation("How many minutes did you use the power washer", amountOfMinutes);

        //calls the PowerWasherRental function to determine the total charge
        charge = PowerWasherRental(amountOfMinutes);

        //outputs the total charge
        cout << "The total charge is $" <<setprecision(2) << fixed << charge << endl;

        //calls the overloaded dataValidation function to validate input
        dataValidation("Would you like to process another customer (Y or N)", yesNo, check);

        //separates the output sections
        printSeperator();

    } while (check);
    return 0;
}

/*
Name: PowerWasherRental
Purpose: computes the total charge
Incoming: minute (int)
Outgoing: totalPay (double)
Return: totalPay (double)
*/
double PowerWasherRental(int minute)
{
    double totalPay = 0;

    //checks if an hour has gone by to compute accurate charges
    if (minute >= HOUR)
    {
         totalPay = HOUR * INITIAL_COST;
         minute -= HOUR;
         totalPay += minute * NEW_COST;
    }
    else
        totalPay = minute * INITIAL_COST;

    return totalPay;
}

/*
Name: printSeparator
Purpose: To separate multiple sections of output
Incoming: Nothing
Outgoing: "="(80)
Return: Nothing
*/
void printSeperator()
{
    for (int itteration = 0; itteration < 80; itteration++)
        cout << "=";
    cout << endl;
}

/*
Name: Customer
Purpose: Validates if another customer should be added
Incoming: YES_OR_NO (constant char)
Outgoing: integer based on switch statement (1, 0, -1)
Return: integer based on switch statement (1, 0, -1)
*/
int Customer(const char YES_OR_NO)
{
    switch (YES_OR_NO)
    {
        case 'Y':
        case 'y':
            return 1;
        case 'N':
        case 'n':
            return 0;
        default:
            return -1;
    }
}

/*
Name: dataValidation
Purpose: Validates the input by continuously asking the question until the condition is false
Incoming: OUTPUT (constant string), input (int reference)
Outgoing: OUTPUT (constant string), input (int reference)
Return: Nothing
*/
void dataValidation(const string OUTPUT, int &input)
{
    do
    {
        cout << OUTPUT << ": ";
        cin >> input;
    } while (input <= 0);
}

/*
Name: dataValidation
Purpose: Overloads previous function to validate character data using the Customer function
Incoming: OUTPUT (constant string), input (char), decide (int reference)
Outgoing: OUTPUT (constant string) + ": ", decide (int reference)
Return: Nothing
*/
void dataValidation(const string OUTPUT, char input, int &decide)
{
    do
    {
        cout << OUTPUT << ": ";
        cin >> input;
        decide = Customer(input);
    } while (decide == -1);
}
