// Generate Random Maze (using Recursive Backtracking) in C
// Project Link: https://github.com/wintersoldiercoding/100-projects-in-c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 25

#define PATH ' '
#define WALL '#'

// Function to initialize the maze with walls
void initializeMaze(char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = WALL;
        }
    }
}

// Function to print the maze
void printMaze(char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the given cell is within the maze bounds
int isInsideMaze(int row, int col) {
    return row >= 0 && row < ROWS && col >= 0 && col < COLS;
}

// Function to check if the cell has unvisited neighbors
int hasUnvisitedNeighbors(char maze[ROWS][COLS], int row, int col) {
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        int newRow = row + 2 * dr[i];
        int newCol = col + 2 * dc[i];
        if (isInsideMaze(newRow, newCol) && maze[newRow][newCol] == WALL) {
            return 1;
        }
    }

    return 0;
}

// Function to perform recursive backtracking to generate the maze
void generateMaze(char maze[ROWS][COLS], int row, int col) {
    int dr[] = {-2, 2, 0, 0};
    int dc[] = {0, 0, -2, 2};
    int directions[] = {0, 1, 2, 3};

    for (int i = 0; i < 4; i++) {
        int r = rand() % 4;
        int temp = directions[i];
        directions[i] = directions[r];
        directions[r] = temp;
    }

    for (int i = 0; i < 4; i++) {
        int newRow = row + dr[directions[i]];
        int newCol = col + dc[directions[i]];

        if (isInsideMaze(newRow, newCol) && maze[newRow][newCol] == WALL) {
            maze[newRow][newCol] = PATH;
            maze[row + dr[directions[i]] / 2][col + dc[directions[i]] / 2] = PATH;
            generateMaze(maze, newRow, newCol);
        }
    }
}

int main() {
    char maze[ROWS][COLS];
    srand(time(NULL));

    initializeMaze(maze);

    // Start generating the maze from a random cell (odd row and column)
    int startRow = rand() % (ROWS / 2) * 2 + 1;
    int startCol = rand() % (COLS / 2) * 2 + 1;
    maze[startRow][startCol] = PATH;
    generateMaze(maze, startRow, startCol);

    printf("Randomly Generated Maze:\n");
    printMaze(maze);

    return 0;
}
