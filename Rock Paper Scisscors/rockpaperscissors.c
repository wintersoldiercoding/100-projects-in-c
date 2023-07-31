// Rock, Paper, Scissors Game in C
// Project Link: https://github.com/wintersoldiercoding/100-projects-in-c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random move for the computer
int generateComputerMove() {
    return rand() % 3; // 0: Rock, 1: Paper, 2: Scissors
}

// Function to determine the winner
int determineWinner(int playerMove, int computerMove) {
    if (playerMove == computerMove)
        return 0; // It's a tie
    else if ((playerMove == 0 && computerMove == 2) || // Rock beats Scissors
             (playerMove == 1 && computerMove == 0) || // Paper beats Rock
             (playerMove == 2 && computerMove == 1))   // Scissors beats Paper
        return 1; // Player wins
    else
        return -1; // Computer wins
}

int main() {
    int playerMove, computerMove;
    char moves[3][10] = {"Rock", "Paper", "Scissors"};
    
    printf("Welcome to Rock, Paper, Scissors!\n");

    while (1) {
        printf("\nSelect your move:\n");
        printf("0 - Rock\n1 - Paper\n2 - Scissors\n3 - Exit\n");
        scanf("%d", &playerMove);

        if (playerMove == 3) {
            printf("Thanks for playing!\n");
            break;
        }

        if (playerMove < 0 || playerMove > 2) {
            printf("Invalid move! Please select a valid move.\n");
            continue;
        }

        computerMove = generateComputerMove();

        printf("\nYou chose: %s\n", moves[playerMove]);
        printf("Computer chose: %s\n", moves[computerMove]);

        int result = determineWinner(playerMove, computerMove);
        if (result == 0)
            printf("It's a tie!\n");
        else if (result == 1)
            printf("Congratulations! You win!\n");
        else
            printf("Sorry, the computer wins!\n");
    }

    return 0;
}
