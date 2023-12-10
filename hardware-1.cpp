/*
Name: Lucas Hasting
Description: Return product info based on its ID
Course: CS 155 Computer Science I
Date: 7-21-2022
*/

#include <iostream>
#include <fstream>
using namespace std;

//Declare function prototypes
int linearSearch(const int DATA[], const int NUM_ELEMENTS, const int KEY);
int getArr(int ID[], string Device[], int &fileSize);
void getRequest(const int ID_DATA[], const string STRING_DATA[], const int NUM_ELEMENTS);
void getID(int &input);
void getYesOrNo(char &input);
void printSeparator(const string OUTPUT);

//Declare global constants
const int SIZE = 600,
OUTPUT_SEPERATION = 60,
ERROR = -1,
BLANK_INT = 0;
const string BLANK_STR = "";

int main() //main driver
{
    //Separate output
    printSeparator("=");

    //Declare arrays of size (SIZE) and fill them with blank data
    int fileSize, error, ID[SIZE] = {BLANK_INT};
    string Device[SIZE] = {BLANK_STR};

    //Use the getArr function to fill the arrays with data from an input file, check for errors opening the file
    error = getArr(ID, Device, fileSize);

    //if the file can not be opened report the error to the user
    if (error == -1)
    {
        cout << "Error! Could not read the file" << endl;
        printSeparator("=");
        return 1;
    }

    //Uses the linear search function to search for the requested ID
    getRequest(ID, Device, fileSize);

    //Separate output
    printSeparator("=");
    return 0;
}

/*
Name: linearSearch
Purpose: to perform a linear search on an array
Incoming: DATA[], NUM_ELEMENTS, KEY
Outgoing: position or -1
Return: position or -1
*/
int linearSearch(const int DATA[], const int NUM_ELEMENTS, const int KEY)
{
  //declare local variables
  bool found = false;
  int position=0;

  //goes through the array until it either finds the value or reaches the end of the array
  while ((!found) && (position<NUM_ELEMENTS))

    //value is found
    if (DATA[position] == KEY)
      found = true;

    //goes to the next element
    else
      position++;

  //returns either the position or an error
  if (found)
    return position;
  else
    return ERROR;
}

/*
Name: getArr
Purpose: fill an array with data from an input file
Incoming: ID[], Device[], fileSize
Outgoing: ID[], Device[], fileSize, either 0 or ERROR (depending on an error)
Return: either 0 or ERRROR (depending on an error)
*/
int getArr(int ID[], string Device[], int &fileSize)
{
    //declare local variables
    ifstream input;
    string temp;

    //open the input file
    input.open("hardware.txt");

    //set fileSize to 0 so it can increase
    fileSize = 0;

    //check for errors opening the file
    if(input.fail())
        return ERROR;

    //set the first ID to temp so it can be stored in the ID array in the loop
    input >> temp;

    //loops until the end of the file
    for (int element = 0; !input.eof(); element++)
    {
        //increase the file size by one
        fileSize++;

        //int of temp is stored in the element of ID
        ID[element] = stoi(temp);

        //The next line of input is stored in the element of Device
        input >> Device[element];

        //the next input is stored in temp
        input >> temp;

        //the first character in temp is checked for an int after every iteration
        //if it is an int stop the while loop and it will be added to ID in the next iteration of the for loop
        while (!isdigit(temp.c_str()[0]) && !input.eof())
        {
            //add the next input to the element of Device
            Device[element] += " " + temp;

            //Store the next input in temp so it can be checked
            input >> temp;
        }

        //if it is the last line in the input file, get the final addition for the element of Device
        if (input.eof())
        {
           Device[element] += " " + temp;
        }
    }
    //no errors occurred
    return 0;
}

/*
Name: getRequest
Purpose: search for a requested ID until the users wants to stop
Incoming: ID_DATA, STRING_DATA, NUM_ELEMENTS
Outgoing: Device: STRING_DATA or Could not find the requested ID
Return: nothing
*/
void getRequest(const int ID_DATA[], const string STRING_DATA[], const int NUM_ELEMENTS)
{
    //declare local variables
    int Search, Result;
    char yesOrNo;

    //runs the loop until the user stops it
    do
    {
        //get input for the ID
        getID(Search);

        //Search for the ID in an array
        Result = linearSearch(ID_DATA, NUM_ELEMENTS, Search);

        //if no error, output the device and it's description
        if (Result != ERROR)
            cout << "Device Description: " << STRING_DATA[Result] << endl;


        switch(Result)
        {
        case ERROR:
            //if there is an error let the user know the ID could not be found
            cout << "Could not find the requested ID." << endl;
        default:
            //get input for yesOrNo
            getYesOrNo(yesOrNo);

            if (yesOrNo == 'y')
                //separate output
                printSeparator("-");
        }
    } while (yesOrNo == 'y');
}

/*
Name: getID
Purpose: to get input for the ID
Incoming: input
Outgoing: input
Return: nothing
*/
void getID(int &input)
{
    cout << "Please enter a product ID: ";
    cin >> input;
}

/*
Name: getYesOrNo
Purpose: to get validated input for yesOrNo
Incoming: input
Outgoing: input
Return: nothing
*/
void getYesOrNo(char &input)
{
    do
    {
        cout << "Would you like to search again (y/n): ";
        cin >> input;
    } while (input != 'y' && input != 'n');
}

/*
Name: printSeparator
Purpose: To separate the output
Incoming: OUTPUT
Outgoing: OUTPUT(OUTPUT_SEPERATION)
Return: nothing
*/
void printSeparator(const string OUTPUT)
{
    for (int itteration = 0; itteration < OUTPUT_SEPERATION; itteration++)
        cout << OUTPUT;
    cout << endl;
    return;
}
