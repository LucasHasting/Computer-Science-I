/*
Name: Lucas Hasting
Description: Compute and display the total value of chess pieces.
Course: CS 155 Computer Science I
Date: 6-02-2022
*/

#include <iostream>
using namespace std;
int main()
{
 //Declare Variables
 const int queen = 9, rook = 5, knight = 3, bishop = 3, pawn = 1;
 int totalValue = 0, pieces;

 //Get all pieces and multiply them by they're points, add the points to total value
 cout << "How many queen pieces: ";
 cin >> pieces;
 totalValue += pieces * queen;

 cout << "How many rook pieces: ";
 cin >> pieces;
 totalValue += pieces * rook;

 cout << "How many knight pieces: ";
 cin >> pieces;
 totalValue += pieces * knight;

 cout << "How many bishop pieces: ";
 cin >> pieces;
 totalValue += pieces * bishop;

 cout << "How many pawn pieces: ";
 cin >> pieces;
 totalValue += pieces * pawn;

 //output the total value
 cout << "The value of your pieces is " << totalValue;
 return 0;
}
