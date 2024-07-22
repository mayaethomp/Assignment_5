
// Maya Thompson
// CS 1, Section #0107
// Assignment #5, Problem #1
// Summary: This program allows the user to play a lotto game by allowing the user to select lotto numbers, and comparing them to randomized computer-generated lotto numbers to determine if/what the user wins

/* 

LOTTO RULES
1. 7 lotto numbers
2. numbers drawn 2x/week
3. 6 matching numbers --> million $ prize
4. 5 --> $5000
5. 4 --> $100
6. 3 --> free ticket

*/

#include <iostream>
#include <stdlib.h> 
#include <iomanip>
#include <cmath>
#include <ctime> 

using namespace std;



// FUNCTION PROTOTYPES //
const int tickets = 7;
int userTickets[tickets];
const int winningNums = 7;
int winningNums[7];

void getLottoPicks();
bool noDuplicates();

int main() {

    char menuSelection = 'A';
    cout << "LITTLE CITY LOTTO MODEL:" << endl << "------------------------" << endl << "1) Play lotto" << endl << "Q) Quit Program" << endl;

    cin >> menuSelection;

    string userName;
    if (menuSelection == '1') {
        cout << "Please enter your name";
        cin >> userName;
    } else if (menuSelection == 'Q' || menuSelection == 'q') {
        return 0;
    }


    return 0;
}



// FUNCTION DEFINITIONS //

void getLottoPicks() {
    for (int i = 1; i <= tickets; i++) {    
        cout << "Please enter number " << i << endl;
        cin >> userTickets[i];
        if (userTickets[i] < 1 || userTickets[i] > 40) {
                cout << "The number must be between 1 and 40. Please enter another number: " << endl;
                cin >> userTickets[i];
            }
        }
    }


// Function to check if user's lotto selection is already in the userTickey array
bool noDuplicates() {

}


