/*
Name: Lucas Hasting
Description: Sort and display the contents of a string array
Course: CS 155 Computer Science I
Date: 7-22-2022
*/

#include <iostream>
using namespace std;

//declare function prototypes
void selectionSort (string array[], const int NUM);
void display (const string ARRAY[], const int NUM);
void printSeparator(const string OUTPUT);

//declare global constant
const int SIZE = 10, OUTPUT_SEPERATION = 85;

int main() //main driver
{
    //separate output
    printSeparator("=");

    //declare string array with assigned values
    string arr[SIZE] = {"Banana", "Donut", "Walnuts", "Barbecue", "Almonds", "Apple", "Chicken", "Steak", "Pizza", "Pineapple"};

    //sort the array and display the process
    selectionSort(arr, SIZE);

    //separate output
    printSeparator("=");
    return 0;
}

/*
Name: selectionSort
Purpose: to sort a string array
Incoming: array, NUM
Outgoing: array
Return: nothing
*/
void selectionSort (string array[], const int NUM)
{
  //declare local variables
  string temp= "";
  int minIndex=0;

  //output the old array and it's contents (using the display function)
  cout << "Old Array: ";
  display(array, NUM);

  //separate output
  printSeparator("-");

  //loop through every element in the array
  for (int i=0; i<NUM-1; i++)
  {
    //set the minimum index to i
    minIndex=i;

    //loop through future elements in the array
    for (int j=i+1; j<NUM; j++)

       //if the future element is less than the minimum index, update the minimum index
       if (array[j] < array[minIndex])
         minIndex=j;

    // Swap positions i and minIndex
    temp            = array[i];
    array[i]        = array[minIndex];
    array[minIndex] = temp;

    //output the current array and it's contents
    cout << "Step " << i + 1 << ": ";
    display(array, NUM);
   }

  //separate output
  printSeparator("-");

  //output the new array and it's contents
  cout << "New Array: ";
  display(array, NUM);

  return;
}

/*
Name: display
Purpose: to display the contents of an array on one line
Incoming: ARRAY[], NUM
Outgoing: contents of the array
Return: nothing
*/
void display (const string ARRAY[], const int NUM)
{
    for (int i = 0; i < NUM; i++)
        cout << ARRAY[i] << " ";
    cout << endl;
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
