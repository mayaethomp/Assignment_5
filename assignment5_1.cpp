
// Maya Thompson
// CS 1, Section #0107
// Assignment #5, Problem #1
// Summary: This program allows the user to play a lotto game by allowing the user to select lotto numbers, and comparing them to randomized computer-generated lotto numbers to determine if/what the user wins

/* 

-------LOTTO RULES-------
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


// Declare and initialize variables
char menuSelection = '1';
string userName;
int userMatchCount;

// ARRAYS //
const int LOTTONUMS = 7;
const int LOTTOMAX = 40;
const int LOTTOMIN = 1;

int UserTicket[LOTTONUMS];
int WinningNums[LOTTONUMS];
string ResultString[LOTTONUMS + 1] = 
{"SORRY NOTHING", 
 "SORRY NOTHING", 
 "SORRY NOTHING", 
 "FREE TICKET", 
 "NOT BAD - $100", 
 "LUCKY YOU - $5,000",
 "GREAT! - $100,000",
 "JACKPOT!!! - $1 MILLION"}; 



// FUNCTION PROTOTYPES //
void getLottoPicks();
int GenRandNum();
void GenWinNums();
bool noDuplicates(int ArrayName[], int IndexNumber);
int matchCount(int ArrayName1[], int ArrayName2[]);

int main() {

while (menuSelection == '1') {

// Play lotto menu - prompt user to play the lotto game
        cout << "LITTLE CITY LOTTO MODEL:" << endl
         << "------------------------" << endl
         << "1) Play lotto" << endl
         << "q) Quit Program" << endl
         << "Please make a selection: " << endl;

        cin >> menuSelection;

        if (menuSelection == 'q' || 'Q') {
            break;
        }

// Validate user has inputted an acceptable response
    while (menuSelection != '1' && 
           menuSelection != 'Q' && 
           menuSelection != 'q') 
    {
        cout << "Invalid selection. Please try again" << endl;
        cout << endl << "LITTLE CITY LOTTO MODEL:" << endl 
        << "------------------------" << endl 
        << "1) Play lotto" << endl 
        << "q) Quit Program" << endl << endl
        << "Please make a selection: " << endl; 
        
        cin >> menuSelection;
    }

// Prompt user for their name
    cout << "Please enter your name: " << endl;
    cin >> userName;

// Prompt user for their lotto numbers
    getLottoPicks();
   
// Generate and store winning lotto numbers
    GenWinNums();

// Count matching numbers
    userMatchCount = matchCount(UserTicket, WinningNums);

// DISPLAY LOTTO RESULTS
cout << userName << "'s LOTTO RESULTS" << endl
<< "-----------------------" << endl
<< "WINNING TICKET NUMBERS:"; //array loop // << endl

for (int i = 0; i < LOTTONUMS; i++) {
    cout << " " << WinningNums[i];
}

cout << endl << userName << "'s TICKET:";

for (int i = 0; i < LOTTONUMS; i++) {
    cout << " " << UserTicket[i];
}

cout << endl << "RESULTS:" << endl
<< "--------" << endl
<< "Number Matches: " << userMatchCount << endl
<< "Winnings      : " << ResultString[userMatchCount] << endl << endl;
}
    return 0;
}


// FUNCTION DEFINITIONS //

void getLottoPicks() {
    for (int i = 0; i < LOTTONUMS; i++) {    
        cout << "Please enter number " << i + 1 << ": " << endl;
        cin >> UserTicket[i];

        // validate number is between 1 and 40
        while (UserTicket[i] < LOTTOMIN || UserTicket[i] > LOTTOMAX) {
                cout << "The number must be between " << LOTTOMIN << " and " << LOTTOMAX << "." << endl
                << "Please enter another number: " << endl;
                cin >> UserTicket[i];
            }

        // check for duplicates
        while (noDuplicates(UserTicket, i) == false) {
            cout << "No duplicate numbers are accepted. Please enter another number." << endl;
            cin >> UserTicket[i];
        }
        }
    }

// Function to generate random numbers for the winning numbers
int GenRandNum() {
    // make ranNum outside of accepted bounds
    int ranNum = 0;
    // while outside of bounds, assign a new random number
        ranNum = rand() % 41 + 1;
        cout << "This is our random number: " << ranNum << endl;

    return ranNum;
}

// Function to store random generated numbers in our winning lotto numbers array
void GenWinNums() {
    for (int i = 0; i < LOTTONUMS; i++) {
        WinningNums[i] = GenRandNum();
     // check for duplicates
     while (noDuplicates(WinningNums, i) == false) {
        cout << "Duplicate detected: " << i << "Equals " << WinningNums[i] << endl;
        WinningNums[i] = GenRandNum();
    
     }
    }
     
    }


// Function to check if user's lotto selection is already in the userTickey array
bool noDuplicates(int ArrayName[], int IndexNumber) {
    bool noDup = true;
     int p = 0;
    // while we have numbers to check, compare this index value to all the preceding index values
   
    while (p < IndexNumber && noDup) {
        if (ArrayName[IndexNumber] == ArrayName[p]) {
            noDup = false;
        }
        p++;
    }
    return noDup;
}

// Check each lotto number entered against the generated winning numbers to see if they match
int matchCount(int ArrayName1[], int ArrayName2[]) {
    int matchCount = 0;
    for (int i = 0; i < LOTTONUMS; i++) {
        for (int j = 0; j < LOTTONUMS; j++) {
            if (ArrayName1[i] == ArrayName2[j]) {
                matchCount++;
            }
        }
    }
    return matchCount;
}
