/*
Name: Lucas Hasting
Description: Compute and display the amount and cost of paint and carpet needed in a room
Course: CS 155 Computer Science I
Date: 7-2-2022

Sources:
Data Validation for room size: https://www.crddesignbuild.com/blog/average-bedroom-size#:~:text=Minimum%20Bedroom%20Size,least%20120%20square%20feet%20total).
Amount of paint: https://www.thisoldhouse.com/painting/21097077/how-much-paint-do-i-need
Amount of carpet: https://sloanescarpetsecret.com/carpet-measuring/#:~:text=Basically%2C%20measuring%20for%20carpet%20is,of%20carpet%20for%20that%20room.
Cost of paint: https://thd.co/3A68Xka
Cost of carpet: https://thd.co/39Wg1VN
*/

#include <iostream>
#include <iomanip>
using namespace std;

//Declare global constants
const double
PAINT_COST_GALLON = 19.98,
PAINT_COST_QUART = 9.98,
PAINT_COST_OUNCE = 4.98,
CARPET_COST_SQUARE_FOOT = 3.19,
SALES_TAX = 0.04;

const int
SQUARE_FEET_IN_GALLON = 400,
WALLS_IN_ROOM = 4,
QUARTS_IN_GALLON = 4,
OUNCES_IN_QUART = 32,
MIN_DIMENSION = 7,
MIN_SQUARE_FEET = 70,
INCH_TO_FOOT = 12;

//Declare function prototypes
void report(string roomName,double length, double height, double width, double gallon, double quart, double ounce);
void dataValidation(double &length, double &width);
void dataValidation(double &height);
void dataValidation(char &yesOrNo);
int amountOfCarpet(double lengthInches, double widthInches);
double costOfCarpet(double lengthInches, double widthInches);
double paintCalculations(double lengthInches, double heightInches, double &amountOfGallons, double &amountOfQuarts, double &amountOfOunces);
void printSeperator(string output);

int main() //main driver program
{
    //Declare variables to be used in main
    double length, width, height;
    double gallon=0, quart=0, ounce=0;
    char yesOrNo;
    string roomName;

    //Starts the separation of the output
    printSeperator("=");

    //Loops until user decides to stop it
    do
    {
        //Get's the room name
        cout << "What is the name of this room: ";
        getline(cin, roomName);

        //calls the dataValidation function to validate inputs
        dataValidation(length,width);
        dataValidation(height);

        //Separates the sub output sections
        printSeperator("-");

        //calls the report function to output the results
        report(roomName,length,height,width,gallon,quart,ounce);

        //Separates the sub output sections
        printSeperator("-");

        //calls the dataValidation function to validate input
        dataValidation(yesOrNo);

        //clears the input stream so getline() can be used again
        cin.ignore();

        //Separates the main output sections
        printSeperator("=");

    } while (yesOrNo == 'Y');
    return 0; //ends the program
}

/*
Name: report
Purpose: Output the report
Incoming: roomName, length, height, width, gallon, quart, ounce
Outgoing: roomName, newLength, newHeight, newWidth, gallon, quart, ounce
Return: Nothing
*/
void report(string roomName, double length, double height, double width, double gallon, double quart, double ounce)
{
        //Declare variables used in the function
        double totalPaintCost, totalCarpetCost, totalCost, newLength, newWidth, newHeight;

        //calls the appropriate functions ti get the total paint cost, total carpet cost, and the total cost
        totalPaintCost = paintCalculations(length,height,gallon,quart,ounce);
        totalCarpetCost = costOfCarpet(length,width);
        totalCost = totalPaintCost + totalCarpetCost;

        //converts all dimensions to feet
        newLength = length / INCH_TO_FOOT;
        newWidth = width / INCH_TO_FOOT;
        newHeight = height / INCH_TO_FOOT;

        //Output's the room name, the width of the room, the length of the room, and the height of the room
        cout << "The " << roomName << " has a length of " << setprecision(2) << fixed << newLength << "ft"
        << ", a width of: " << newWidth << "ft"
        << ", and a height of " << newHeight << "ft" << endl

        //Output's the square footage of the room and the perimeter of each wall (not all walls combined)
        << "The total square footage of the room is " << (double)(newLength * newWidth) << "ft" << endl
        << "The perimeter of each wall is " << (double)(newLength * newHeight) << "ft" << endl
        << "The total perimeter of all the walls is " << (double)(newLength * newHeight) * WALLS_IN_ROOM << "ft" << endl;

        //Separates the sub output sections
        printSeperator("-");

        //output's the amount of gallons to buy, quarts to buy, and ounces to buy for paint
        cout << "Gallon(s) of paint to buy: " << (int)gallon << " for $" << gallon * PAINT_COST_GALLON << endl
        << "Quarts(s) of paint to buy: " << (int)quart << " for $" << quart * PAINT_COST_QUART << endl
        << "Ounces(s) of paint to buy: " << (int)ounce << " for $" << ounce * PAINT_COST_OUNCE << endl

        //Output's the amount of carpet to buy
        << "Piece(s) of carpet to buy: " << amountOfCarpet(length,width) << " for $" << totalCarpetCost << endl;

        //Separates the sub output sections
        printSeperator("-");

        //Output's all of the costs including total cost
        cout << "The cost of the carpet is $" << totalCarpetCost << endl
        << "The cost of the paint is $" << totalPaintCost << endl
        << "Sales tax: $" << SALES_TAX << endl
        << "The total cost is $" << totalCost + (totalCost * SALES_TAX) << endl;
}

/*
Name: dataValidation
Purpose: keeps asking the same question until it is a valid number
Incoming: length, width
Outgoing: length, width
Return: nothing
*/
void dataValidation(double &length, double &width)
{
    do
    {
        do
        {
            cout << "What is the length of the room (inches): ";
            cin >> length;
        } while ((length / INCH_TO_FOOT) < MIN_DIMENSION);

        do
        {
            cout << "What is the width of the room (inches): ";
            cin >> width;
        } while ((width / INCH_TO_FOOT) < MIN_DIMENSION);
    } while (((length / INCH_TO_FOOT) * (width / INCH_TO_FOOT)) < MIN_SQUARE_FEET);

}

/*
Name: dataValidation
Purpose: an overloaded function of dataValidation to work with the height variable
Incoming: height
Outgoing: height
Return: nothing
*/
void dataValidation(double &height)
{
    do
    {
        cout << "What is the height of the room (inches): ";
        cin >> height;
    } while ((height / INCH_TO_FOOT) < MIN_DIMENSION);
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
    do
    {
        cout << "Would you like to do another room (Y or N): ";
        cin >> yesOrNo;
    } while (yesOrNo != 'Y' && yesOrNo != 'N');
}

/*
Name: amountOfCarpet
Purpose: to calculate the total amount of carpet needed
Incoming: lengthInches, widthInches
Outgoing: totalSquareFeet
Return: totalSquareFeet
*/
int amountOfCarpet(double lengthInches, double widthInches)
{
    double totalSquareFeet;

    //converts inches to feet fir proper calculation
    lengthInches /= INCH_TO_FOOT;
    widthInches /= INCH_TO_FOOT;

    //calculates the totalSquare feet
    totalSquareFeet = lengthInches * widthInches;

    //if a there is a decimal on the total square feet, another piece of carpet will be needed to finish the job
    if (int(totalSquareFeet) < totalSquareFeet)
        totalSquareFeet += 1;
    return totalSquareFeet;
}

/*
Name: costOfCarpet
Purpose: to return the total cost of the carpet
Incoming: lengthInches, widthInches
Outgoing: totalCost
Return: totalCost
*/
double costOfCarpet(double lengthInches, double widthInches)
{
    int totalCarpet;
    double totalCost;

    //calls the amountOfCarpet function to get the total carpet needed
    totalCarpet = amountOfCarpet(lengthInches, widthInches);
    totalCost = totalCarpet * CARPET_COST_SQUARE_FOOT;
    return totalCost;
}

/*
Name: paintCalculations
Purpose: calculate the amount of paint needed, and the total cost of the paint
Incoming: lengthInches, heightInches, amountOfGallons, amountOfQuarts, amountOfOunces
Outgoing: amountOfGallons, amountOfQuarts, amountOfOunces, totalCost
Return: totalCost
*/
double paintCalculations(double lengthInches, double heightInches, double &amountOfGallons, double &amountOfQuarts, double &amountOfOunces)
{
    double perimeter, squareFeet, quarts, ounces, costForGallon, costForQuart, costForOunces, totalCost;

    //gives quarts and ounces a value if there not given one in the future
    amountOfQuarts = 0;
    amountOfOunces = 0;

    //converts inches to feet
    lengthInches /= INCH_TO_FOOT;
    heightInches /= INCH_TO_FOOT;

    //finds the perimeter and the total squareFeet for the walls
    perimeter = lengthInches * WALLS_IN_ROOM;
    squareFeet = perimeter * heightInches;

    //calculates the amount of gallons
    amountOfGallons = squareFeet / SQUARE_FEET_IN_GALLON;

    //stores the decimal from amountOfGallons into quarts
    quarts = amountOfGallons - int(amountOfGallons);
    if (int(amountOfGallons) < amountOfGallons) //checks for a decimal in quarts
        amountOfQuarts = quarts * QUARTS_IN_GALLON; //converts the decimal to the amount of quarts

    //stores the decimal from amountOfQuarts into ounces
    ounces = amountOfQuarts - int(amountOfQuarts);
    if (int(amountOfQuarts) < amountOfQuarts) //checks for a decimal in ounces
        amountOfOunces = ounces * OUNCES_IN_QUART; //converts the decimal to the amount of ounces

    //if there is a decimal in amountOfOunces add 1 more to finish the paint job
    if (int(amountOfOunces) < amountOfOunces)
        amountOfOunces += 1;

    //changes all doubles to ints
    amountOfGallons = int(amountOfGallons);
    amountOfQuarts = int(amountOfQuarts);
    amountOfOunces = int(amountOfOunces);

    //if the cost of ounces is more expensive than a quart, buy one more quart and no ounces
    if ((amountOfOunces * PAINT_COST_OUNCE) > PAINT_COST_QUART)
    {
        amountOfQuarts += 1;
        amountOfOunces = 0;
    }

    //if the cost of quarts is more expensive than a gallon, buy one more gallon and no quarts
    else if ((amountOfQuarts * PAINT_COST_QUART) > PAINT_COST_GALLON)
    {
        amountOfGallons += 1;
        amountOfOunces = 0;
    }

    //re-calculates the cost of each paint size
    costForGallon = amountOfGallons * PAINT_COST_GALLON;
    costForQuart = amountOfQuarts * PAINT_COST_QUART;
    costForOunces = amountOfOunces * PAINT_COST_OUNCE;
    totalCost = costForGallon + costForQuart + costForOunces;
    return totalCost;
}

/*
Name: printSeparator
Purpose: To separate multiple sections of output
Incoming: output
Outgoing: output(90)
Return: nothing
*/
void printSeperator(string output)
{
    for (int itteration = 0; itteration < 90; itteration++)
        cout << output;
    cout << endl;
}
