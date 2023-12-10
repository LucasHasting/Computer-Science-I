/*
Name: Lucas Hasting
Description: Display the different types of arrays
Course: CS 155 Computer Science I
Date: 7-15-2022
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

//Declare function prototypes
void FillInOrder(int arr[], int Size);
void FillReverseOrder (int arr[], int Size);
void FillRandomOrder (int arr[], int Size);
void DisplayArray (int arr[], int Size);
int menu();
void func(int arr[], int Size);
void dataValidation(int &input);
void printSeparator(string output);

int main() //main driver program
{
    //declare the first local variable
    int Size;

    //call the printSeparator function to separate the output
    printSeparator("=");

    //call the dataValidation function to validate Size input
    dataValidation(Size);

    //create an array which will be used to store the values from other functions
    int arr[Size] = {0};

    //use the func function to modify the values in arr
    func(arr, Size);
    return 0;
}

/*
Name: FillInOrder
Purpose: start at 100 and add 100 for every element in the array
Incoming: arr, Size
Outgoing: arr
Return: nothing
*/
void FillInOrder(int arr[], int Size)
{
    int number = 0;
    for (int element = 0; element < Size; element++)
    {
        number += 100;
        arr[element] = number;
    }
}

/*
Name: FillReverseOrder
Purpose: start at 5010 and subtract 10 for every element in the array
Incoming: arr, Size
Outgoing: arr
Return: nothing
*/
void FillReverseOrder (int arr[], int Size)
{
    int number = 5010;
    for (int element = 0; element < Size; element++)
    {
        arr[element] = number;
        number -= 10;
    }
}

/*
Name: FillRandomOrder
Purpose: Put a random number (300-600) in every element of the array
Incoming: arr, Size
Outgoing: arr
Return: nothing
*/
void FillRandomOrder (int arr[], int Size)
{
    srand(time(0)); //makes the numbers random
    for (int element = 0; element < Size; element++)
    {
        arr[element] = (rand() % 300 ) + 300;
    }
}

/*
Name: DisplayArray
Purpose: Output the array
Incoming: arr, Size
Outgoing: arr
Return: nothing
*/
void DisplayArray (int arr[], int Size)
{
    printSeparator("-"); //separate output
    for (int element = 0; element < Size; element++)
    {
        for (int itteration = 0; (itteration < 4 && element < Size-1); itteration++, element++)
            cout << arr[element] << setw(20);
        cout << arr[element] << endl;
    }
}

/*
Name: menu
Purpose: To display a menu
Incoming: nothing
Outgoing: decide
Return: decide
*/
int menu()
{
    int decide;
    cout << "Choose one of the following:" << endl
    << "Fill In Order: 1" << endl
    << "Fill Reverse Order: 2" << endl
    << "Fill Random Order: 3" << endl
    << "Display Array: 4" << endl
    << "Quit: 5" << endl << endl
    << "Enter: ";
    cin >> decide; //get's the number that will be used for the func function
    return decide;

}

/*
Name: func
Purpose: Use a switch statement to call functions or quit
Incoming: arr, Size
Outgoing: arr
Return: nothing
*/
void func(int arr[], int Size)
{
    while (true)
    {
        printSeparator("=");
        int decide = menu();
        switch(decide)
        {
        case 1:
            FillInOrder(arr, Size);
            break;
        case 2:
            FillReverseOrder(arr, Size);
            break;
        case 3:
            FillRandomOrder(arr, Size);
            break;
        case 4:
            DisplayArray(arr, Size);
            break;
        case 5:
            printSeparator("="); //separate output
            return; //ends the function
        default:
            cout << "Error! try again";
        }
    }
}

/*
Name: dataValidation
Purpose: To validate input for the size of the array
Incoming: input
Outgoing: input
Return: nothing
*/
void dataValidation(int &input)
{
    do
    {
        cout << "What is the size of the array: ";
        cin >> input;
    } while (input < 1 || input > 300);
}

/*
Name: printSeparator
Purpose: To separate the output
Incoming: output
Outgoing: output(90)
Return: nothing
*/
void printSeparator(string output)
{
    for (int itteration = 0; itteration < 90; itteration++)
        cout << output;
    cout << endl;
    return;
}
