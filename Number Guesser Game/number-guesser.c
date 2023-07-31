// Repository link: https://github.com/wintersoldiercoding/100-projects-in-c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 'min' and 'max'
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    // Seed the random number generator with current time
    srand(time(NULL));

    // Constants for the range of the random number
    const int MIN_NUMBER = 1;
    const int MAX_NUMBER = 100;

    // Generate a random number between 1 and 100
    int secretNumber = generateRandomNumber(MIN_NUMBER, MAX_NUMBER);

    int guess;
    int attempts = 0;
    int maxAttempts = 7; // You can change this to customize the number of attempts

    printf("Welcome to the Guess the Number Game!\n");
    printf("Try to guess the secret number between %d and %d.\n", MIN_NUMBER, MAX_NUMBER);

    // Loop until the user guesses the correct number or runs out of attempts
    while (attempts < maxAttempts) {
        printf("Attempt #%d: Enter your guess: ", attempts + 1);
        scanf("%d", &guess);

        // Check if the guess is correct
        if (guess == secretNumber) {
            printf("Congratulations! You guessed the secret number %d in %d attempts.\n", secretNumber, attempts + 1);
            break;
        } else if (guess < secretNumber) {
            printf("Too low! Try again.\n");
        } else {
            printf("Too high! Try again.\n");
        }

        attempts++;
    }

    // If the user runs out of attempts
    if (attempts == maxAttempts) {
        printf("Sorry, you've run out of attempts. The secret number was %d.\n", secretNumber);
    }

    return 0;
}
