// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 6
// =============================================================================
//
// TASK: Multiplication Table Generator
//
// Write a C++ program that generates multiplication tables using loops
// and functions.
//
// -----------------------------------------------------------------------------
// PART A — Single Table
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Print the multiplication table for that number from 1 to 12.
//
// Expected output (if user enters 5):
//
//   Multiplication Table for 5:
//   5  x  1  =  5
//   5  x  2  =  10
//   5  x  3  =  15
//   ...
//   5  x  12 =  60
//
// -----------------------------------------------------------------------------
// PART B — Bonus: Tables from 1 to N
// -----------------------------------------------------------------------------
// - Ask the user to enter a number N.
// - Print the full multiplication table for every number from 1 to N.
// - Add a separator line (e.g. "---") between each table.
//
// Expected output (if user enters 3):
//
//   Multiplication Table for 1:
//   1  x  1  =  1
//   ...
//   1  x  12 =  12
//   ---------------------------
//   Multiplication Table for 2:
//   2  x  1  =  2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - N must be a positive integer. If the user enters an invalid value,
//   print an error message and stop.
// - Each part must be in its own function (see scaffold below).
// - Complete Part A before attempting Part B.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

// Function declarations (Prototypes)
void printSingleTable(int number);
void printMultipleTables(int limit);

int main() {
    int choice;
    int number;

    cout << "=== Multiplication Table Generator ===\n";
    cout << "1. Part A: Single Table\n";
    cout << "2. Part B: Bonus Tables from 1 to N\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        // ==========================================
        // PART A - Single Table
        // ==========================================
        cout << "\nEnter a number: ";
        cin >> number;

        // Requirement: N must be a positive integer
        if (number <= 0) {
            cout << "Error: The number must be a positive integer." << endl;
            return 0; // Stop execution
        }

        printSingleTable(number);

    } else if (choice == 2) {
        // ==========================================
        // PART B - Tables from 1 to N
        // ==========================================
        cout << "\nEnter a number N: ";
        cin >> number;

        // Requirement: N must be a positive integer
        if (number <= 0) {
            cout << "Error: The number must be a positive integer." << endl;
            return 0; // Stop execution
        }

        printMultipleTables(number);

    } else {
        cout << "Invalid choice! Program stopping." << endl;
    }

    return 0;
}

// ==========================================
// FUNCTION DEFINITIONS
// ==========================================

// PART A: Prints a single table for a given number from 1 to 12
void printSingleTable(int num) {
    cout << "\nMultiplication Table for " << num << ":\n";
    for (int i = 1; i <= 12; i++) {
        cout << num << " x " << i << " = " << (num * i) << endl;
    }
}

// PART B: Prints all tables from 1 up to the specified limit N
void printMultipleTables(int limit) {
    for (int currentNum = 1; currentNum <= limit; currentNum++) {
        printSingleTable(currentNum);
        
        // Add a separator line between tables, except after the final one
        if (currentNum < limit) {
            cout << "------------------------\n";
        }
    }
}
