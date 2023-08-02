// Tic-Tac-Toe AI (Against Computer) in C
// Project Link: https://github.com/wintersoldiercoding/100-projects-in-c

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// Function to print the Tic-Tac-Toe board
void printBoard(char board[3][3]) {
    printf("-------------\n");
    for (int i = 0; i < 3; i++) {
        printf("| %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
        printf("-------------\n");
    }
}

// Function to check if the game is over
bool isGameOver(char board[3][3]) {
    // Check rows and columns for a win
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')) {
            return true;
        }
    }

    // Check diagonals for a win
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')) {
        return true;
    }

    // Check if the board is full (draw)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }

    return true;
}

// Function to check if the move is valid
bool isValidMove(char board[3][3], int row, int col) {
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
}

// Function to check if the player wins
bool checkWin(char board[3][3], char player) {
    // Check rows and columns for a win
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    // Check diagonals for a win
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

// Function to find the best move for the computer (minimax algorithm)
int findBestMove(char board[3][3], char computer, char player);

// Minimax function for the computer's move
int minimax(char board[3][3], int depth, bool isMaximizer, char computer, char player) {
    if (checkWin(board, computer)) {
        return 10 - depth;
    }

    if (checkWin(board, player)) {
        return depth - 10;
    }

    if (isGameOver(board)) {
        return 0;
    }

    if (isMaximizer) {
        int bestScore = -1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = computer;
                    int score = minimax(board, depth + 1, false, computer, player);
                    board[i][j] = ' ';
                    bestScore = score > bestScore ? score : bestScore;
                }
            }
        }
        return bestScore;
    } else {
        int bestScore = 1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = player;
                    int score = minimax(board, depth + 1, true, computer, player);
                    board[i][j] = ' ';
                    bestScore = score < bestScore ? score : bestScore;
                }
            }
        }
        return bestScore;
    }
}

// Function to find the best move for the computer (minimax algorithm)
int findBestMove(char board[3][3], char computer, char player) {
    int bestMove = -1;
    int bestScore = -1000;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = computer;
                int score = minimax(board, 0, false, computer, player);
                board[i][j] = ' ';

                if (score > bestScore) {
                    bestScore = score;
                    bestMove = i * 3 + j;
                }
            }
        }
    }

    return bestMove;
}

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    char player, computer;
    printf("Choose your symbol (X or O): ");
    scanf(" %c", &player);

    if (player == 'X' || player == 'x') {
        computer = 'O';
    } else {
        computer = 'X';
    }

    printBoard(board);

    int turn;
    if (computer == 'X') {
        turn = 1;
    } else {
        turn = 0;
    }

    while (!isGameOver(board)) {
        if (turn % 2 == 0) {
            int row, col;
            printf("Your turn (Enter row [0-2] and column [0-2] separated by space): ");
            scanf("%d %d", &row, &col);
            if (isValidMove(board, row, col)) {
                board[row][col] = player;
                turn++;
            } else {
                printf("Invalid move. Try again.\n");
            }
        } else {
            printf("Computer's turn...\n");
            int bestMove = findBestMove(board, computer, player);
            board[bestMove / 3][bestMove % 3] = computer;
            turn++;
        }

        printBoard(board);
    }

    if (checkWin(board, player)) {
        printf("Congratulations! You win!\n");
    } else if (checkWin(board, computer)) {
        printf("Computer wins!\n");
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}
