// Project: Number Guessing Game (Computer vs. Player)
// Repository link: https://github.com/wintersoldiercoding/100-projects-in-c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max (inclusive)
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    int playerNumber, computerNumber, tries = 0;
    int minRange = 1, maxRange = 100;

    // Set a seed for the random number generator based on current time
    srand(time(0));

    printf("Welcome to the Number Guessing Game!\n");
    printf("I, the computer, have chosen a number between 1 and 100.\n");

    // Generate a random number for the computer
    computerNumber = generateRandomNumber(minRange, maxRange);

    // Start the guessing process
    do {
        printf("Guess the number between %d and %d: ", minRange, maxRange);
        scanf("%d", &playerNumber);

        // Increment the number of tries
        tries++;

        if (playerNumber == computerNumber) {
            printf("Congratulations! You guessed the correct number %d in %d tries!\n", computerNumber, tries);
        } else if (playerNumber < computerNumber) {
            printf("Too low! Try again.\n");
            // Update the minimum range for the next guess
            minRange = playerNumber + 1;
        } else {
            printf("Too high! Try again.\n");
            // Update the maximum range for the next guess
            maxRange = playerNumber - 1;
        }
    } while (playerNumber != computerNumber);

    return 0;
}
