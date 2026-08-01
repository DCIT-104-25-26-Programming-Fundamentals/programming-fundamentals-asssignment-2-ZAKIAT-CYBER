// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Maximum allowed dimensions as per instructions
const int MAX_SIZE = 10;

// Helper function to read a matrix from user input
void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, string name) {
    cout << "\nEnter elements for " << name << ": (" << rows << "x" << cols << ")\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void displayMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(6) << matrix[i][j];
        }
        cout << endl;
    }
}
// PART A: Transpose a Matrix 
void transposeMatrix(const int src[MAX_SIZE][MAX_SIZE], int dest[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            dest[j][i] = src[i][j];
        }
    }
}

// PART B: Add Two Matrices
void addMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int rows, int cols, int sum[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum[i][j] = A[i][j] + B[i][j];
        }
    }
}

// PART C: Multiply Two Matrices
void multiplyMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int M, int N, int P, int product[MAX_SIZE][MAX_SIZE]) {
    // Initialize product matrix to zero
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            product[i][j] = 0;
            for (int k = 0; k < N; k++) {
                product[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

    int main() {
        // Fixed allocation allocations as mandated
        int matrixA[MAX_SIZE][MAX_SIZE];
        int matrixB[MAX_SIZE][MAX_SIZE];   
        int result[MAX_SIZE][MAX_SIZE]; 

        int rowsA, colsA, rowsB, colsB;

        cout << "===PART A: Transpose a Matrix===\n";
        cout << "Enter number of rows: ";
        cin >> rowsA;
        cout << "Enter number of columns: ";
        cin >> colsA;

        readMatrix(matrixA, rowsA, colsA, "A");

        cout << "\nOriginal Matrix:\n";
        displayMatrix(matrixA, rowsA, colsA);

        // For transpose, destination dimensions are inverted
        transposeMatrix(matrixA, result, rowsA, colsA);
        cout << "\nTransposed Matrix:\n";
        displayMatrix(result, colsA, rowsA);

        cout << "\n----------------------------\n";
        cout << "===PART B: Add Two Matrices===\n";
        cout << "Using the same dimensions (" << rowsA << "x" << colsA << ") for matrix B:\n";

        readMatrix(matrixB, rowsA, colsA, "B");

        addMatrices(matrixA, matrixB, rowsA, colsA, result);
        cout << "\nResultant  Sum Matrix:\n";
        displayMatrix(result, rowsA, colsA);

        cout << "\n----------------------------\n";
        cout << "===PART C: Multiply Two Matrices===\n";
        cout << "Matrix A is currently " << rowsA << "x" << colsA << ".\n";
        cout << "Matrix B must have " << colsA << "rows.\n";
        rowsB = colsA; //Required for validity
        cout << "Enter number of columns for Matrix B: ";
        cin >> colsB;

        readMatrix(matrixB, rowsB, colsB, "B (for multiplication)");

        multiplyMatrices(matrixA, matrixB, rowsA, colsA, colsB, result);
        cout << "\nResultant Product Matrix (" << rowsA << "x" << colsB << "):\n";
        displayMatrix(result, rowsA, colsB);

        return 0;
    
    }