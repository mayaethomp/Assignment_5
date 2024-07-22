// Maya Thompson
// CS 1, Section #0107
// Assignment #5, Problem #2
// Summary: This program sells tickets for performances at a small theatre

#include <iostream>
#include <iomanip>

using namespace std;




// Arrays
const int ROWS = 15;
const int SEATS = 20;

int Theater[ROWS][SEATS];



// Function Prototypes //
void displaySeats(char Array, int, int);


int main() {

// Initialize array to all available
for (int r = 0; r < ROWS; r++) {
    for (int s = 0; s < SEATS; s++) {
        Theater[r][s] == '*';
    }

// Display Theatre availability
displaySeats(Theater, ROWS, SEATS);

}

    return 0;
}


// Function Definitions
void displaySeats(int Array, int ROWS, int SEATS) {

}




