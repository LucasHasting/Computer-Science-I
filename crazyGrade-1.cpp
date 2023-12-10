/*
Name: Lucas Hasting
Description: Compute and display the crazy math teacher's grading policy
Course: CS 155 Computer Science I
Date: 7-12-2022
*/

#include <iostream>
#include <iomanip>
using namespace std;

//Declare constants
const int SEPARATE = 110,
SPACES = 40,
STUDENT_MIN = 1,
STUDENT_MAX = 25,
GRADE_MIN = 0,
GRADE_MAX = 100,
LOWEST_PASS = 48;

//Declare function prototypes
int multipleOfFive(int grade);
int newGrade (int grade);
int* originalGrades (int amount);
int* newGrades(int amount, int *original);
void dataValidation(int gradeNumber, int &grade);
void dataValidation(int &Student);
void printSeparator(string output);
void report(int Size);

int main() // main driver program
{
    //declares the local variable
    int Size;

    //Separates output
    printSeparator("=");

    //Calls the dataValidation function to get the size of the classroom
    dataValidation(Size);

    //Separates output
    printSeparator("-");

    //Calls the report function to generate the report to the screen
    report(Size);

    return 0; //ends the program
}

/*
Name: multipleOfFive
Purpose: finds the next multiple of 5 from a number
Incoming: grade
Outgoing: grade
Return: grade
*/
int multipleOfFive(int grade)
{
    //Finds the next multiple of 5:
    //if the number in the ones place is not a 5 or 0, keep adding the grade
    while (grade % 10 != 5 && grade % 10 != 0)
    {
        grade++;
    }
    return grade;
}

/*
Name: newGrade
Purpose: to round up the grades according to the math teacher's grading policy
Incoming: grade
Outgoing: grade
Return: grade
*/
int newGrade (int grade)
{
    //Uses the multipleOfFive function to make proper decsisions
    if (grade < LOWEST_PASS)
        return grade;
    else if (multipleOfFive(grade) - grade < 3)
        return multipleOfFive(grade);
    else
        return grade;
}

/*
Name: originalGrades
Purpose: to store the original grades into an array pointer
Incoming: amount
Outgoing: grades
Return: grades
*/
int* originalGrades (int amount)
{
    //declare an array pointer, and local variable
    int* grades = new int[amount], currentGrade;

    //stores the original grades in an array
    for (int grade = 0; grade < amount; grade++)
    {
        //calls the dataValidation function to validate input for the grades
        dataValidation(grade, currentGrade);

        //stores the grade
        grades[grade] = currentGrade;
    }

    //separates output from the input
    printSeparator("-");

    return grades;
}

/*
Name: newGrades
Purpose: to store the rounded grades into an array pointer
Incoming: amount, original
Outgoing: grades
Return: grades
*/
int* newGrades(int amount, int *original)
{
    //declare an array pointer
    int* grades = new int[amount];

    //stores the new grades in an array
    for (int grade = 0; grade < amount; grade++)
        grades[grade] = newGrade(original[grade]);

    return grades;
}

/*
Name: dataValidation
Purpose: to validate input for the student's grades
Incoming: gradeNumber, grade
Outgoing: grade
Return: Nothing
*/
void dataValidation(int gradeNumber, int &grade)
{
    do
    {
        cout << "What is student ID #" << gradeNumber << "'s grade: ";
        cin >> grade;
    } while (grade < GRADE_MIN || grade > GRADE_MAX);
    return;
}

/*
Name: dataValidation
Purpose: An overloaded version of the previous function to support the amount of students
Incoming: Student
Outgoing: Student
Return: Nothing
*/
void dataValidation(int &Student)
{
    do
    {
        cout << "How many students: ";
        cin >> Student;
    } while (Student < STUDENT_MIN || Student > STUDENT_MAX);
    return;
}

/*
Name: printSeparator
Purpose: To separate the output
Incoming: output
Outgoing: output(110)
Return: nothing
*/
void printSeparator(string output)
{
    for (int itteration = 0; itteration < SEPARATE; itteration++)
        cout << output;
    cout << endl;
    return;
}

/*
Name: report
Purpose: to generate a report of the class's grades
Incoming: Size
Outgoing: Student ID, Original Grade, New Grade
Return: Nothing
*/
void report(int Size)
{
    //declare local variables
    int *original = originalGrades(Size);
    int *New = newGrades(Size, original);

    //Loops through the report for each student
    for (int student = 0; student < Size; student++)
    {
        cout << "Student ID #" << student << ": "
        << setw(SPACES) << "Original Grade: " << original[student]
        << setw(SPACES) << "New Grade: " << New[student] << endl;
    }

    //Separates output
    printSeparator("=");

    return;
}
