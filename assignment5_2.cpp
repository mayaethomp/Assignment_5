// Maya Thompson
// CS 1, Section #0107
// Assignment #5, Problem #2
// Summary: This program sells tickets for performances at a small theatre

// PSEUDOCODE //

// Declare and initialize variables, arrays, and functions
// Initialize theater array to all available with *
// Input prices of seats
// Display the seats available
// Display menu 
// Input user's menu choice, including row and seat
// Check if seat is available
// If seat is taken, prompt user to select another seat
// If seat is available, update seating chart with # for taken seat
// Look up price of that seat and add it to the total revenue 
// Update the total tickets sold count
// Reprompt the user if they want to sell another ticket
// Once user is finished selling tickets, print an updated seating chart and display total tickets sold and total revenue generated


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// Declare and initialize variables
char menuChoice = '1';
int userRow = 0;
const int MAXROWS = 14;
const int MINROWS = 0;
int userSeat = 0;
const int MAXSEATS = 19;
const int MINSEATS = 0;

double totalRevenue = 0;
int seatsSold = 0;

// Arrays
const int ROWS = 15;
const int SEATS = 20;

char Theater[ROWS][SEATS];

double rowPrice[ROWS];

// Function Prototypes //
void showSeats();
void readPrices();


int main() {

// Initialize array to all available
    for (int r = 0; r < ROWS; r++) {
        for (int s = 0; s < SEATS; s++) {
            Theater[r][s] = '*';
        }
    }

// Read in price of each row from prices.txt
    readPrices();

// Display Theatre availability
    showSeats();

// Prompt user to choose a menu selection
    cout << "Menu: " << endl
         << "1) Buy Ticket" << endl
         << "2) Total sell and exit" << endl << endl
         << "Enter your choice: ";
    cin >> menuChoice;

// Validate user selection
    while (menuChoice != '1' && menuChoice != '2')
            {
                cout << "Invalid selection. Please try again" << endl;
                cout << "Menu: " << endl
                     << "1) Buy Ticket" << endl
                     << "2) Total sell and exit" << endl << endl
                     << "Enter your choice: ";
                cin >> menuChoice;
            }

    if (menuChoice == '1') {
        do {

// Prompt user for what seats they want
        cout << "Enter row: ";
        cin >> userRow;
        // Validate user response
        while (userRow < MINROWS || userRow > MAXROWS) 
            {
                cout << "Invalid selection. Please try again." << endl;
                cout << "Enter row: ";
                cin >> userRow;
            }

        cout << "Enter seat: ";
        cin >> userSeat;

            while (userSeat < MINSEATS || userSeat > MAXSEATS) 
            {
                cout << "Invalid selection. Please try again." << endl;
                cout << "Enter seat: ";
                cin >> userSeat;
            }

    // Check if seat is available
        if (Theater[userRow][userSeat] == '#') {
            // This seat is taken, prompt user to select new seat
            cout << endl << "Invalid seat choice" << endl;
        } else {
            // Seat is available, update seating chart with # for taken seat
            Theater[userRow][userSeat] = '#';
        }


    // Add seat price to the total revenue 
        totalRevenue = totalRevenue + rowPrice[userRow];

    // Update the total tickets sold count
        seatsSold = seatsSold + 1;

    // Reprompt the user if they want to sell another ticket
        cout << "Menu: " << endl
             << "1) Buy Ticket" << endl
             << "2) Total sell and exit" << endl << endl
             << "Enter your choice: ";
        cin >> menuChoice;

        while (menuChoice != '1' && 
                menuChoice != '2')
            {
                cout << "Invalid selection. Please try again" << endl;
                cout << "Menu: " << endl
                     << "1) Buy Ticket" << endl
                     << "2) Total sell and exit" << endl << endl
                     << "Enter your choice: ";
                cin >> menuChoice;
            }


 } while (menuChoice == '1');

}

// Once user is finished selling tickets, print an updated seating chart and display total tickets sold and total revenue generated
    showSeats();
    cout << "TOTAL TICKETS SOLD: " << seatsSold << endl;
    cout << "TOTAL REVENUE: $ " << setprecision(2) << fixed << totalRevenue << endl;


    return 0;
}


// Function Definitions

// Function that displays the available seats
void showSeats() {

    cout << "* Seats available" << endl
         << "# Reserved Seats" << endl
         << "Seats: 0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19" << endl;
    
    for (int r = 0; r < ROWS; r++) {
        cout << "Row " << r << " ";
        if (r < 10) {
            cout << " ";
        }
        for (int s = 0; s < SEATS; s++) {
            cout << Theater[r][s] << "  ";
        }
        cout << endl;
    }
}

// Function that opens, reads, and closes prices.txt file
void readPrices() {
    fstream infile("prices.txt", ios::in); // open the file

    for (int i = 0;  i < ROWS; i++) {
        infile >> rowPrice[i]; // use the file<< endl;
    }
    infile.close(); // close the file
}




