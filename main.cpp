//
//  main.cpp
//  Jamir Nunley - MP3
//
//  Created by Jamir Nunley on 11/9/21.
//
//  Jet Plane
//

// This program displays a plane seating chart using a 2D array, while also being able to detect cases where a seat is already taken 
// or a seat that does not eist. The program displays a seating chart and then accepts seating requests based on the user input. 
// The program will accept user input until all seats are filled or until the user quits. The seating chart will update itself after every seat
// that is picked. 

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

const int ROWS = 8; // Set row and column to 8x13
const int COLUMNS = 13;

// findRowIndex: given user input, returns appropriate row index into arrays.
// @param thisRow - integer indicating row selected by the user
// @return appropriate index into 2-D array if the specified row is valid, ERROR otherwise
int findRowIndex(int thisRow);


// findSeatIndex: given user input, returns appropriate column index into seating chart array.
// @param thisSeat - character indicating selected seat within row
// @return appropriate index into 2-D array if the specified seat is valid, ERROR otherwise
int findSeatIndex(char thisSeat);


// displaySeatColumn: given a 2-D mapping of the seating chart in the form [columns][rows],
// will print out a "column" of seats on one row of output (i.e., seat 'A' for all rows in the plane)
// @param seats - reference to a 2-D character array
// @param column - reference to which column of seats to display
void displaySeatColumn(char seats[][ROWS], int COLUMNS);



void display2DArray(int my2DArray[3][4]) {
    cout << endl; // added to just add space to make things look nicer
    
    for(int row = 0; row < 3; row++) {
        cout << "[";
        for(int column = 0; column < 4; column++) {
            if(column < 3)
                cout << my2DArray[row][column] << " ";
            else
                cout << my2DArray[row][column];
        }
        cout << "]" << endl; // put a end line at the end of each row
    }
}


int main()
{
    int i, j;

    char my2Darray[ROWS][COLUMNS] = { // 2D array for entire seating chart

        {'D','D','D','D','D','D','D','D','D','D','D','D',' '},
        {'C','C','C','C','C','C','C','C','C','C','C','C',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ','1','1','1','1'},
        {'1','2','3','4','5','6','7','8','9','0','1','2','3'},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {'B','B','B','B','B','B','B','B','B','B','B','B','B'},
        {'A','A','A','A','A','A','A','A','A','A','A','A','A'},
        
    };
    
    for (i = 0; i < ROWS; i++) // Increment each Row
    {
        for (j = 0; j < COLUMNS; j++) // Increment each Column
        {
            cout << setw(5) << my2Darray[i][j]; // Display Seating chart and set field width parameter
        }
        cout << endl;
    }

    char again;
    do
    {
        int row;
        char seat;

        while(true)
        {
            cout << "\nEnter a row or 'Q' to quit: "; // Ask for user input
          
            if(cin >> row && row >= 1 && row <= 14) {row--; break;}

            if(!cin)
            {
                cin.clear(); // Clear error flag
                cin.ignore(1000, '\n'); // Ignore character from input to prevent failure
            }
        }

        while(true)
        {
            cout << "Enter a seat A,B,C,D or Q to Quit: ";
            cin >> seat;

            if(seat == 'A' && seat <= 'D') {seat = seat - 'A' + 7; break;} // Add each character to empty space
            if(seat == 'B' && seat <= 'D') {seat = seat - 'B' + 6; break;} // A is smallest, D is Greatest
            if(seat == 'C' && seat <= 'D') {seat = seat - 'C' + 1; break;}
            if(seat == 'D' && seat <= 'D') {seat = seat - 'D' + 0; break;}
        }
        
        if(seat != 'A' && 'B' && 'C' && 'D')
        {
            cout << "Sorry this seat does not exist on the CRJ-200 ";
        }
        
        if (my2Darray[row][seat] == 'X')
        {
            cout << "\nThat seat is taken. Pick another." << endl; // Prevents user from picking the same seat
        }
        else
        {
            cout << "Seat " << row + 1 << (char)(seat) << " is now taken." << endl;
            my2Darray[seat][row] = 'X';
        }
        
        cout << my2Darray[0][1] << endl;
        
        for (i = 0; i < ROWS; i++)
        {
            for (j = 0; j < COLUMNS; j++)
            {
                cout << setw(5) << my2Darray[i][j] << " ";
            }
            cout << endl;
        }
        
        cout << "\nPick Another Seat? (Y to continue) : "; // Ask user if they want to pick again
        cin >> again;
            
    } while (again == 'Y');
    
    return 0;
}
