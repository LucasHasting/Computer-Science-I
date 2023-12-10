/*
Name: Lucas Hasting
Description: Compute and display Student's score and there average, shows all grades above the average
Course: CS 155 Computer Science I
Date: 7-20-2022
*/

#include <iostream>
#include <iomanip>
using namespace std;

//declare global constants
const int MAX_SCORES = 1000,
MIN_SCORES = 1,
MAX_ID = 999,
MIN_ID = 100,
MAX_GRADE = 100,
MIN_GRADE = 0,
OUTPUT_SEPERATION = 90;

//declare function prototypes
void getScores (int ID[], int Score[], int &Size);
void showTopScores (const int ID[], const int SCORE[], const int SIZE);
void dataValidation(const string OUTPUT, int &input, const int RANGE_MIN, const int RANGE_MAX);
void printSeparator(const string OUTPUT);

int main() //main driver program
{
  //declare local variables
  int num, id[MAX_SCORES], exam[MAX_SCORES];

  //call the getScores function to get input from the user
  getScores (id,exam,num);

  //call the showTopScores function to output the data
  showTopScores (id,exam,num);
 return 0;

}

/*
Name: getScores
Purpose: use dataValidation to get validated input
Incoming: ID[], Score, Size
Outgoing: ID, Score, Size
Return: Nothing
*/
void getScores (int ID[], int Score[], int &Size)
{
    //separate output
    printSeparator("=");

    //call DataValidation to validate Size input
    dataValidation("How many scores: ", Size, MIN_SCORES, MAX_SCORES);

    //separate output
    printSeparator("-");
    for (int element = 0; element < Size; element++)
    {
        //call DataValidation to validate input
        dataValidation("Student ID: ", ID[element], MIN_ID, MAX_ID);
        dataValidation("Student Score: ", Score[element], MIN_GRADE, MAX_GRADE);

        //separate output
        printSeparator("-");
    }
    return;
}

/*
Name: showTopScores
Purpose: to output the top scores
Incoming: ID[], SCORE[], SIZE
Outgoing: Student ID and Exam Score, Scores over the mean
Return: Nothing
*/
void showTopScores (const int ID[], const int SCORE[], const int SIZE)
{
    //declare local variables
    double mean = 0;
    int displayScores = 0;

    //add the scores to the mean
    for (int element = 0; element < SIZE; element++)
    {
        mean += SCORE[element];
    }

    //divide the mean by the size to compute the mean
    mean /= SIZE;

    //output the mean
    cout << "Mean: " << setprecision(1) << fixed << mean << endl;

    //output the student ID, score
    for (int element = 0; element < SIZE; element++)
    {
        if(SCORE[element] > mean)
        {
            displayScores += 1;
            cout << "Student ID: " << ID[element]
            << " with exam score " << SCORE[element] << endl;
        }
    }

    //separate output
    printSeparator("-");

    //output number of scores over the mean
    cout << "Number of scores over the mean: " << displayScores << endl;

    //separate output
    printSeparator("=");
    return;
}

/*
Name: dataValidation
Purpose: to get validated input
Incoming: OUTPUT, input, RANGE_MIN, RANGE_MAX
Outgoing: input
Return: Nothing
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
Name: printSeparator
Purpose: to separate output
Incoming: OUTPUT
Outgoing: OUTPUT (OUTPUT_SEPERATION)
Return: Nothing
*/
void printSeparator(const string OUTPUT)
{
    for (int itteration = 0; itteration < OUTPUT_SEPERATION; itteration++)
        cout << OUTPUT;
    cout << endl;
    return;
}
