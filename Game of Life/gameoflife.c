// Game of Life (ASCII Art Visualization) in C
// Project Link: https://github.com/wintersoldiercoding/100-projects-in-c

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#define ROWS 20
#define COLS 50

// Function to clear the terminal screen
void clearScreen() {
    printf("\033[2J\033[1;1H");
}

// Function to print the current state of the grid
void printGrid(bool grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf(grid[i][j] ? "#" : " ");
        }
        printf("\n");
    }
}

// Function to count the number of live neighbors for a given cell
int countLiveNeighbors(bool grid[ROWS][COLS], int row, int col) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int neighborRow = (row + i + ROWS) % ROWS;
            int neighborCol = (col + j + COLS) % COLS;
            if (grid[neighborRow][neighborCol] && !(i == 0 && j == 0)) {
                count++;
            }
        }
    }
    return count;
}

// Function to update the grid according to the Game of Life rules
void updateGrid(bool grid[ROWS][COLS]) {
    bool newGrid[ROWS][COLS];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int liveNeighbors = countLiveNeighbors(grid, i, j);
            if (grid[i][j]) {
                // Cell is alive
                newGrid[i][j] = (liveNeighbors == 2 || liveNeighbors == 3);
            } else {
                // Cell is dead
                newGrid[i][j] = (liveNeighbors == 3);
            }
        }
    }

    // Copy the new grid to the original grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main() {
    bool grid[ROWS][COLS] = {0};

    // Initialize the grid with some initial pattern
    // For example, a glider pattern
    grid[1][2] = grid[2][3] = grid[3][1] = grid[3][2] = grid[3][3] = true;

    while (true) {
        clearScreen();
        printGrid(grid);
        updateGrid(grid);
        usleep(100000); // Add a small delay (100ms) to slow down the visualization
    }

    return 0;
}
