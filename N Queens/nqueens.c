// N-Queens Problem Solver in C
// Project Link: https://github.com/wintersoldiercoding/100-projects-in-c

#include <stdio.h>
#include <stdbool.h>

#define N 8 // Change N to the desired board size

// Function to print the chessboard
void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", board[i][j] ? 'Q' : '-');
        }
        printf("\n");
    }
}

// Function to check if a queen can be placed at a given position
bool isSafe(int board[N][N], int row, int col) {
    int i, j;

    // Check this row on the left side
    for (i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }

    // Check upper diagonal on the left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    // Check lower diagonal on the left side
    for (i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

// Recursive function to solve the N-Queens problem
bool solveNQueens(int board[N][N], int col) {
    // Base case: All queens are placed
    if (col >= N) {
        return true;
    }

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            // Place the queen at position (i, col)
            board[i][col] = 1;

            // Recur to place the rest of the queens
            if (solveNQueens(board, col + 1)) {
                return true;
            }

            // If placing the queen at (i, col) doesn't lead to a solution, backtrack
            board[i][col] = 0;
        }
    }

    // If no queen can be placed in this column, return false
    return false;
}

int main() {
    int board[N][N] = {0};

    if (solveNQueens(board, 0)) {
        printf("Solution:\n");
        printBoard(board);
    } else {
        printf("No solution found for N = %d.\n", N);
    }

    return 0;
}
