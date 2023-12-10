/*
Name: Lucas Hasting
Description: Carry out tasks with 2D arrays
Course: CS 155 Computer Science I
Date: 7-24-2022
*/

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//declare global constants
const string FILENAME = "file.txt";
const int MAX_ROW = 8,
MAX_COL = 8,
SEPERATION = 5,
OUTPUT_SEPERATION = 70,
ERROR = 1;

//declare function prototypes
void fillMatrix(int data[MAX_ROW][MAX_COL], int &numRows, int &numCols);
void printMatrixRow(const int DATA[MAX_ROW][MAX_COL], const int NUM_ROWS, const int NUM_COLS);
void printMatrixCol(const int DATA[MAX_ROW][MAX_COL], const int NUM_ROWS, const int NUM_COLS);
void printColSum(const int DATA[MAX_ROW][MAX_COL], const int NUM_ROWS, const int NUM_COLS);
int RowProduct(const int DATA[MAX_ROW][MAX_COL], const int NUM_ROWS, const int NUM_COLS, const int MAX_ROW );
int menu();
void func(int data[MAX_ROW][MAX_COL], int numRows, int numCols);
void validateRow(int &row, const int NUM_ROWS);
void printSeparator(const string OUTPUT);

int main() //main driver program
{
    //declare variables
    int numRows = 0, numCols = 0, data[MAX_ROW][MAX_COL] = {0};

    //call the func function to perform the tasks until the user decides to stop
    func(data, numRows, numCols);

    return 0;
}

/*
Name: fillMatrix
Purpose: input each element in the matrix
Incoming: data, numRows, numCols
Outgoing: data, numRows, numCols
Return: nothing
*/
void fillMatrix(int data[MAX_ROW][MAX_COL], int &numRows, int &numCols)
{
    //declare input file stream
    ifstream datafile;

    //open the data file
    datafile.open(FILENAME);

    //if the input file can not be opened exit with an error
    if(datafile.fail())
    {
        cout << "Error! Could not open the file" << endl;
        exit(ERROR);
    }

    //get the row size and col size from the input file
    datafile >> numRows >> numCols;

    //add the elements to the 2D array
    for (int row = 0; row < numRows; row++)
        for (int col = 0; col < numCols; col++)
            datafile >> data[row][col];

    //close the data file
    datafile.close();
}

/*
Name: printMatrixRow
Purpose: output each element in row order
Incoming: DATA, NUM_ROWS, NUM_COLS
Outgoing: matrix in row order
Return: nothing
*/
void printMatrixRow(const int DATA[MAX_ROW][MAX_COL], const int NUM_ROWS, const int NUM_COLS)
{
    //loop through the rows in the 2D array
    for (int row = 0; row < NUM_ROWS; row++)
    {
        //loop through the cols in the 2D array
        for (int col = 0; col < NUM_COLS; col++)
            cout << setw(5) << DATA[row][col];
        cout << endl;
    }
}

/*
Name: printMatrixCol
Purpose: output each element in column order
Incoming: DATA, NUM_ROWS, NUM_COLS
Outgoing: matrix in column order
Return: nothing
*/
void printMatrixCol(const int DATA[MAX_ROW][MAX_COL], const int NUM_ROWS, const int NUM_COLS)
{
    //loop through the cols in the 2D array
    for (int col = 0; col < NUM_COLS; col++)
    {
        //loop through the rows in the 2D array
        for (int row = 0; row < NUM_ROWS; row++)
            cout << setw(SEPERATION) << DATA[row][col];
        cout << endl;
    }
}

/*
Name: printColSum
Purpose: output the sum of each columns
Incoming: DATA, NUM_ROWS, NUM_COLS
Outgoing: sum of each column
Return: nothing
*/
void printColSum(const int DATA[MAX_ROW][MAX_COL], const int NUM_ROWS, const int NUM_COLS)
{
    //create an array to store all column's sum
    int sum[MAX_COL] = {0};

    //loop through the rows in the 2D array
    for (int row = 0; row < NUM_ROWS; row++)
    {
        //add all column values together
        for (int col = 0; col < NUM_COLS; col++)
        {
            //add the column values
            sum[col] += DATA[row][col];
        }
    }

    //loop through the cols in the 2D array
    for (int col = 0; col < NUM_COLS; col++)
    {
        cout << "Col #" << col + 1 << ": ";

        //output the column values
        for (int row = 0; row < NUM_ROWS; row++)
            cout << setw(SEPERATION) << DATA[row][col];

        //output the sum of the columns
        cout << ", Sum: " << sum[col];
        cout << endl;
    }

}

/*
Name: printRowProduct
Purpose: output the product of a given row
Incoming: DATA, NUM_ROWS, NUM_COLS
Outgoing: rowProd
Return: rowProd
*/
int RowProduct(const int DATA[MAX_ROW][MAX_COL], const int NUM_ROWS, const int NUM_COLS, const int ROW)
{
    //store the row product in rowProd
    int rowProd = 1;

    //loop through the cols in the 2D array
    for (int col = 0; col < NUM_COLS; col++)
    {
        //loop through the rows in the 2D array
        for (int row = 0; row < NUM_ROWS; row++)

            //if the row is the product wanted, calculate the product
            if (row + 1 == ROW)
                rowProd *= DATA[row][col];
    }

    //return the row's product
    return rowProd;
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
    << "Quit: 0" << endl
    << "Fill the Matrix: 1" << endl
    << "Print the Matrix in row order: 2" << endl
    << "Print the Matrix in column order: 3" << endl
    << "Find the sum of all columns: 4" << endl
    << "Print a row's product: 5" << endl << endl
    << "Enter: ";
    cin >> decide; //get's the number that will be used for the func function
    return decide;
}

/*
Name: func
Purpose: Use a switch statement to call functions or quit
Incoming:data, numRows, numCols
Outgoing: data
Return: nothing
*/
void func(int data[MAX_ROW][MAX_COL], int numRows, int numCols)
{
    int decide;
    do
    {
        //declare local variables
        int rowProd, row;

        printSeparator("="); //separate output

        //spawn the menu
        decide = menu();

        //decides which functions to call
        switch(decide)
        {
        case 1:
            fillMatrix(data, numRows, numCols);
            break;
        case 2:
            printSeparator("-"); //separate output
            printMatrixRow(data, numRows, numCols);
            break;
        case 3:
            printSeparator("-"); //separate output
            printMatrixCol(data, numRows, numCols);
            break;
        case 4:
            printSeparator("-"); //separate output
            printColSum(data, numRows, numCols);
            break;
        case 5:
            printSeparator("-"); //separate output

            //validates input for row
            validateRow(row, numRows);

            printSeparator("-"); //separate output

            //get the row product using the RowProduct function
            rowProd = RowProduct(data, numRows, numCols, row);

            //output the row and it's product
            if (row == 0)
                cout << "Row " << row << " product is non existent" << endl;
            else
            cout << "Row " << row << " product is: " << rowProd << endl;
            break;
        case 0:
            printSeparator("="); //separate output
            break;
        default:
            cout << "Error! invalid option" << endl;
        }
    }while (decide != 0);
    return;
}

/*
Name: validateRow
Purpose: To validate input for the row variable
Incoming: row, NUM_ROWS
Outgoing: row
Return: nothing
*/
void validateRow(int &row, const int NUM_ROWS)
{
    do
    {
        cout << "If the array is empty please select 0" << endl;
        cout << "What row would you like to find the product of: ";
        cin >> row;
    } while ((row < 0 || row > NUM_ROWS) && NUM_ROWS != 0);
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
