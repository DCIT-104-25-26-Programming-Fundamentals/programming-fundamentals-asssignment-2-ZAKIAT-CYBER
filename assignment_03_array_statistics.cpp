// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the sum of numbers in the array
int calculateSum(const vector<int>& numbers) {
    int sum = 0;
    for (int i = 0; i < numbers.size(); i++) {
        sum += numbers[i];
    }
    return sum;
}

// Function to calculate the average of numbers in the array
double calculateAverage(const vector<int>& numbers) {
    if (numbers.empty()) 
        return 0.0; // Avoid division by zero
    return static_cast<double>(calculateSum(numbers)) / numbers.size();
}

// Function to find the maximum number in the array
int findMaximum(const vector<int>& numbers) {
    int max = numbers[0];
    for (int i = 1; i < numbers.size(); i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    return max;
}

// Function to find the minimum number in the array
int findMinimum(const vector<int>& numbers) {
    int min = numbers[0];
    for (int i = 1; i < numbers.size(); i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }
    return min;
}

int main() {
    int N;

    cout << "How many numbers? ";
    if (!(cin >> N) || N <= 0) {
        cout << "Error: Please enter a positive integer for the number of elements." << endl;
        return 1; 
    }

    vector<int> numbers(N);
    for (int i = 0; i < N; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        if (!(cin >> numbers[i])) {
            cout << "Error: Invalid input. Please enter an integer." << endl;
            return 1; 
        }
    }

    cout << "\nResults:" << endl;
    cout << "Sum:     " << calculateSum(numbers) << endl;
    cout << "Average: " << calculateAverage(numbers) << endl;
    cout << "Maximum: " << findMaximum(numbers) << endl;
    cout << "Minimum: " << findMinimum(numbers) << endl;

    return 0;
}