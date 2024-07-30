/*
Name: Lucas Hasting
Description: Generate 4 random digits as many times as the user decides
Course: CS 155 Computer Science I
Date: 7-6-2022
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <unistd.h>
using namespace std;

//function prototypes
void lottery(int amount);
void dataValidation(int &lotteryNumbers);

int main() //main driver program
{
    //declare variable
    int lotteryNumbers;

    //finds the working directory
    char buff[CHAR_MAX];
    string directory = getcwd(buff, CHAR_MAX);

    //call the dataValidation function for input validation
    dataValidation(lotteryNumbers);

    //calls the lottery function to generate a 4 digit lottery number
    lottery(lotteryNumbers);

    //outputs the result, and the directory the numbers can be found
    cout << "Process complete!" << endl
    << "The lottery numbers can be found in: " << directory << "\\data.txt" << endl;
    return 0;
}

/*
Name: lottery
Purpose: Generates a random 4 digit number
Incoming: amount
Outgoing: 4 digits (to a file)
Return: nothing
*/
void lottery(int amount)
{
    //declare local variables
    ofstream lottery;
    int digit1,digit2,digit3,digit4,lotteryNumber;

    //opens the output file stream
    lottery.open("data.txt");

    //generates a random number
    srand(time(0));

    //loops through the amount of times the user says
    for (int number = 0; number < amount; number++)
    {
        //generates 4 random digits
        digit1 = rand() % 10;
        digit2 = rand() % 10;
        digit3 = rand() % 10;
        digit4 = rand() % 10;

        //sends the digits to the output file
        lottery << digit1 << digit2 << digit3 << digit4 << endl << endl;
    }
    //closes the output file stream
    lottery.close();
}

/*
Name: dataValidation
Purpose: validates input for the amount of lottery numbers
Incoming: lotteryNumbers
Outgoing: lotteryNumbers
Return: nothing
*/
void dataValidation(int &lotteryNumbers)
{
    do
    {
        cout << "How many lottery numbers: ";
        cin >> lotteryNumbers;
    }while (lotteryNumbers <= 0 || lotteryNumbers > 52);
}
