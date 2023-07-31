// Sudoku Solver (Optimized with Backtracking and User Input) in C
// Project Link: https://github.com/wintersoldiercoding/100-projects-in-c

#include <stdio.h>
#include <stdbool.h>

#define N 9

// Function to check if a given number can be placed in a specific cell of the Sudoku grid
bool isValidMove(int grid[N][N], int row, int col, int num) {
    // Check if 'num' is already present in the same row or column
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }

    // Check if 'num' is already present in the same 3x3 subgrid
    int subgridStartRow = row - row % 3;
    int subgridStartCol = col - col % 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + subgridStartRow][j + subgridStartCol] == num) {
                return false;
            }
        }
    }

    return true;
}

// Function to find an unassigned cell (with value 0) in the Sudoku grid
bool findUnassignedCell(int grid[N][N], int *row, int *col) {
    for (*row = 0; *row < N; (*row)++) {
        for (*col = 0; *col < N; (*col)++) {
            if (grid[*row][*col] == 0) {
                return true;
            }
        }
    }
    return false;
}

// Function to solve the Sudoku puzzle using the backtracking algorithm
bool solveSudoku(int grid[N][N]) {
    int row, col;

    if (!findUnassignedCell(grid, &row, &col)) {
        // All cells are assigned, the Sudoku puzzle is solved
        return true;
    }

    // Try numbers from 1 to 9
    for (int num = 1; num <= N; num++) {
        if (isValidMove(grid, row, col, num)) {
            // Try placing the number in the current cell
            grid[row][col] = num;

            // Recursively check if this move leads to a solution
            if (solveSudoku(grid)) {
                return true;
            }

            // If the current move doesn't lead to a solution, backtrack and try the next number
            grid[row][col] = 0;
        }
    }

    // No valid number can be placed in the current cell, backtrack to the previous cell
    return false;
}

// Function to print the solved Sudoku grid
void printGrid(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to take input Sudoku puzzle from the user
void takeInput(int grid[N][N]) {
    printf("Enter the Sudoku puzzle row by row (use 0 for empty cells):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
}

int main() {
    int grid[N][N];

    takeInput(grid);

    printf("\nOriginal Sudoku puzzle:\n");
    printGrid(grid);

    if (solveSudoku(grid)) {
        printf("\nSudoku puzzle solved:\n");
        printGrid(grid);
    } else {
        printf("\nNo solution exists for the given Sudoku puzzle.\n");
    }

    return 0;
}
