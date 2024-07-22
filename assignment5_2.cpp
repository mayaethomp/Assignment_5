// Maya Thompson
// CS 1, Section #0107
// Assignment #5, Problem #2
// Summary: This program sells tickets for performances at a small theatre

#include <iostream>
#include <iomanip>

using namespace std;

// declare and initialize variables
int 


// Arrays
const int ROWS = 15;
const int SEATS = 20;

char Theater[ROWS][SEATS];

// Function Prototypes //
void showSeats();


int main() {



// Initialize array to all available
    for (int r = 0; r < ROWS; r++) {
        for (int s = 0; s < SEATS; s++) {
            Theater[r][s] = '*';
        }
    }

// Display Theatre availability
    showSeats();

// Prompt user to choose a menu selection
    cout << "Menu: " << endl
         << "1) Buy Ticket" << endl
         << "2) Total sell and exit" << endl << endl
         << "Enter your choice";
    cin >> menuChoice;

    return 0;
}






// Function Definitions
void showSeats() {

    cout << "* Seats available" << endl
         << "# Reserved Seats" << endl
         << "Seats: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16  17 18 19" << endl;
    
    for (int r = 0; r < ROWS; r++) {
        cout << "Row " << r << " ";
        for (int s = 0; s < SEATS; s++) {
            cout << Theater[r][s] << "  ";
        }
        cout << endl;
    }
}





