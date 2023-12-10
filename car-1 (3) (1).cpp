/*
Name: Lucas Hasting
Description: Display the car inventory, add and subtract from it
Course: CS 155 Computer Science I
Date: 7-17-2022
*/

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//Declare function prototypes
int storeStop(const string INPUT_FILE);
void readArr(int arr[], const string INPUT_FILE, const int finalStore);
void writeArr(const int ARR[], const string OUTPUT_FILE, const int finalStore);
void DisplayInventory(const int ARR[], const int finalStore);
void addCars(int arr[], const int finalStore);
void sub(int arr[], const int finalStore);
int menu();
void func(int arr[], const int finalStore);
void dataValidation(const string OUTPUT, int &input, const int RANGE_MIN, const int RANGE_MAX);
void dataValidation(const string OUTPUT, int &input, const int RANGE_MIN);
void printSeparator(const string OUTPUT);

//Declare global constants
const string FILE_NAME = "cars.txt";
const int SIZE = 250,
OUTPUT_SEPERATION = 70,
SPACES = 15,
ERROR = -1,
BLANK = 0;

int main() //main driver program
{
    //declare local variable that stores the amount of stores in use
    int lastStore = storeStop(FILE_NAME);

    //stops the program if the file can not be read
    if (lastStore == ERROR)
    {
        cout << "Error reading file!" << endl;
        return 1;
    }

    //declare array and call the readArr function to add data to the array
    int arr[SIZE] = {BLANK};
    readArr(arr, FILE_NAME, lastStore);

    //use the func function to modify the values in arr
    func(arr, lastStore);
    return 0;
}

/*
Name: fileSize
Purpose: Find the size of the array from the first line of the file
Incoming: INPUT_FILE
Outgoing: ERROR or amount
Return: ERROR or amount
*/
int storeStop(const string INPUT_FILE)
{
    //declare local variables
    ifstream input;
    int amount;

    //open the input file
    input.open(INPUT_FILE);

    //check for errors opening the file
    if (input.fail())
    {
        return ERROR;
    }

    //get the size of the array
    input >> amount;

    //close the file
    input.close();

    return amount;
}

/*
Name: readArr
Purpose: Write the information from an input file to an array
Incoming: arr, INPUT_FILE
Outgoing: arr
Return: nothing
*/
void readArr(int arr[], const string INPUT_FILE, const int finalStore)
{
    //declare local variables
    ifstream input;
    int placeholder;

    //open the input file
    input.open(INPUT_FILE);

    //store the first line in a placeholder as it will not be used for further use
    input >> placeholder;

    //stores the numbers from the input file into an array
    for (int element = 0; element < finalStore; element++)
    {
        input >> arr[element];
    }
    return;
}

/*
Name: writeArr
Purpose: Write the information from an array to an input file
Incoming: ARR, OUTPUT_FILE
Outgoing: ARR
Return: nothing
*/
void writeArr(const int ARR[], const string OUTPUT_FILE, const int finalStore)
{
    //declare local variable
    ofstream output;

    //open the output file
    output.open(OUTPUT_FILE);

    //write the size of the array to the file
    output << finalStore << endl;

    //stores the numbers from the array to an input file
    for (int element = 0; element < finalStore; element++)
    {
        output << ARR[element] << endl;
    }
    return;
}

/*
Name: DisplayInventory
Purpose: Output the array
Incoming: ARR
Outgoing: ARR
Return: nothing
*/
void DisplayInventory(const int ARR[], const int finalStore)
{
    cout << "Store" << setw(SPACES) << "Count" << endl;
    for (int element = 0; element < finalStore; element++)
    {
        cout << element + 1 << setw(SPACES + 2) << ARR[element] << endl;
    }
    return;
}

/*
Name: addCars
Purpose: add cars to a store
Incoming: arr
Outgoing: arr
Return: nothing
*/
void addCars(int arr[], const int finalStore)
{
    //declare local variables
    int add, storeNumber;

    //call the dataValidation function to validate input
    dataValidation("Store Number: ", storeNumber, 1, finalStore);
    dataValidation("How Many: ", add, 0);

    //add cars to the selected store number
    arr[storeNumber - 1] += add;
    return;
}

/*
Name: subCars
Purpose: subtract cars from a store
Incoming: arr
Outgoing: arr
Return: nothing
*/
void subCars(int arr[], const int finalStore)
{
    //declare local variables
    int sub, storeNumber;

    //call the dataValidation function to validate input
    dataValidation("Store Number: ", storeNumber, 1, finalStore);
    dataValidation("How Many: ", sub, 0, arr[storeNumber - 1]);

    //subtract cars from the selected store number
    arr[storeNumber - 1] -= sub;
    return;
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
    << "Display Inventory: 1" << endl
    << "addCars: 2" << endl
    << "subCars: 3" << endl
    << "Quit: 4" << endl << endl
    << "Enter: ";
    cin >> decide; //get's the number that will be used for the func function
    return decide;
}

/*
Name: func
Purpose: Use a switch statement to call functions or quit
Incoming: arr
Outgoing: arr
Return: nothing
*/
void func(int arr[], const int finalStore)
{
    int decide;
    do
    {
        printSeparator("="); //separate output
        decide = menu();
        printSeparator("-"); //separate output
        switch(decide)
        {
        case 1:
            DisplayInventory(arr, finalStore);
            break;
        case 2:
            addCars(arr, finalStore);
            break;
        case 3:
            subCars(arr, finalStore);
            break;
        case 4:
            //writes to the input file
            writeArr(arr,FILE_NAME,finalStore);
            cout << "Save Complete!" << endl;
            printSeparator("="); //separate output
            break;
        default:
            cout << "Error! invalid option" << endl;
        }
    }while (decide != 4);
    return;
}

/*
Name: dataValidation
Purpose: To validate data input
Incoming: OUTPUT, input, RANGE_MIN, RANGE_MAX
Outgoing: input
Return: nothing
*/
void dataValidation(const string OUTPUT, int &input, const int RANGE_MIN, const int RANGE_MAX)
{
    do
    {
        cout << OUTPUT;
        cin >> input;
    } while (input < RANGE_MIN || input > RANGE_MAX);
    return;
}

/*
Name: dataValidation
Purpose: overloaded function of dataValidation that has no max range
Incoming: OUTPUT, input, RANGE_MIN
Outgoing: input
Return: nothing
*/
void dataValidation(const string OUTPUT, int &input, const int RANGE_MIN)
{
    do
    {
        cout << OUTPUT;
        cin >> input;
    } while (input < RANGE_MIN);
    return;
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
