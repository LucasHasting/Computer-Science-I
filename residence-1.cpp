/*
Name: Lucas Hasting
Description: Computes the percentage of rooms unavailable in a residence
Course: CS 155 Computer Science I
Date: 6-14-2022
*/

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    //declares variables that will be used in the program
    int residenceFloors = 0, currentFloor = 1, residenceRooms = 0, occupiedRooms = 0, currentRooms, currentOccupied;
    double percentage;

    //uses data validation to ensure correct data is used, inputs the amount of floors
    while (residenceFloors <= 0)
    {
        cout << "How many floor(s) does each residence hall have (minimum 1): ";
        cin >> residenceFloors;
    }

    //loops through all floors to input every room
    while (currentFloor <= residenceFloors)
    {
        //resets currentRooms and currentOccupied every iteration
        currentRooms = 0 ;
        currentOccupied = -1;

        //uses data validation to ensure correct data is used, inputs current rooms on the current floor
        while (currentRooms <= 4)
        {
            cout << "How many rooms does floor " << currentFloor << " have (minimum 5): ";
            cin >> currentRooms;
        }

        //adds the current rooms to the total rooms (residenceRooms)
        residenceRooms += currentRooms;

        //uses data validation to ensure correct data is used, inputs current occupied rooms
        while (currentOccupied <= -1 || currentOccupied > currentRooms)
        {
            cout << "How many rooms are occupied: ";
            cin >> currentOccupied;
        }

        //adds the current rooms occupied to the total occupied rooms (occupiedRooms)
        occupiedRooms += currentOccupied;
        //goes up to the next floor
        currentFloor++;
    }

    //computes the percentage of occupied rooms
    percentage = ((double)occupiedRooms / residenceRooms) * 100;

    //outputs the total rooms, occupied rooms, and the percentage of rooms taken
    cout << "Total rooms: " << residenceRooms << endl;
    cout << "Occupied rooms: " << occupiedRooms << endl;
    cout << "Percent of rooms taken: " << setprecision(1) << fixed << percentage << "%";
    return 0;
}
