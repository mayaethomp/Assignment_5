// Maya Thompson
// CS 1, Section #0107
// Assignment #5, Problem #3
// Summary: This program determines the median of an array using pointer notation and displays the result to the screen


// PSEUDOCODE //

// Declare and initialize two arrays and one function prototype
// Define a function to determine the median of an even or odd array using pointer notation
// Call the function to display the results to the screen


#include <iostream>
using namespace std;


// Arrays
const int ODDSIZE = 3;
const int EVENSIZE = 4;
int evenArray[EVENSIZE] = {2, 4, 5, 9};
int oddArray[ODDSIZE] = {1, 3, 7};
double median = 0;

// Function Prototype
double medianFunction(int array[], int arraysize);


int main() {

    // Determine median of odd array
    median = medianFunction(oddArray, 3);

    // Display the median of the odd array 
    cout << "The values of array one are " << oddArray[0] << " " << oddArray[1] << " " << oddArray[2] << endl
    << "The median of array one is " << median << endl << endl;
    
    // Determine median of even array
    median = medianFunction(evenArray, 4);

    // Display the median of the even array
    cout << "The values of array two are " << evenArray[0] << " " << evenArray[1] << " " << evenArray[2] << " " << evenArray[3] << endl
         << "The median of array two is " << median << endl;


    return 0;
}

// Function definition

// Function to return median of array using pointer notation
    /* I could have calculated out median to allow a function to work with an array of any number of elements, even or odd */
double medianFunction(int array[], int arraysize) {
    double median = 0;
    if (arraysize == 4) {
        // This is an EVEN number array
        median = (double)(*(array + 1) + *(array + 2)) / 2;
    } else {
        // This is an ODD number array
        median = (double)*(array + 1);
    }
    return median;
}

