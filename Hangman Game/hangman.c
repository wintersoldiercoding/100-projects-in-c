// Hangman Game (with ASCII Art Display) in C
// Project Link: https://github.com/wintersoldiercoding/100-projects-in-c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100

// Hangman ASCII art display
const char *hangmanArt[] = {
    "  +---+\n"
    "  |   |\n"
    "      |\n"
    "      |\n"
    "      |\n"
    "      |\n"
    "=========\n",
    "  +---+\n"
    "  |   |\n"
    "  O   |\n"
    "      |\n"
    "      |\n"
    "      |\n"
    "=========\n",
    "  +---+\n"
    "  |   |\n"
    "  O   |\n"
    "  |   |\n"
    "      |\n"
    "      |\n"
    "=========\n",
    "  +---+\n"
    "  |   |\n"
    "  O   |\n"
    " /|   |\n"
    "      |\n"
    "      |\n"
    "=========\n",
    "  +---+\n"
    "  |   |\n"
    "  O   |\n"
    " /|\\  |\n"
    "      |\n"
    "      |\n"
    "=========\n",
    "  +---+\n"
    "  |   |\n"
    "  O   |\n"
    " /|\\  |\n"
    " /    |\n"
    "      |\n"
    "=========\n",
    "  +---+\n"
    "  |   |\n"
    "  O   |\n"
    " /|\\  |\n"
    " / \\  |\n"
    "      |\n"
    "=========\n"
};

// Function to choose a random word from an array of words
const char *chooseRandomWord() {
    const char *wordList[] = {
        "apple", "banana", "orange", "grape", "strawberry", "watermelon",
        "pineapple", "apricot", "kiwi", "peach", "mango", "blueberry"
    };

    int numWords = sizeof(wordList) / sizeof(wordList[0]);
    int randomIndex = rand() % numWords;
    return wordList[randomIndex];
}

// Function to display the current state of the hangman
void displayHangman(int incorrectAttempts) {
    printf("%s", hangmanArt[incorrectAttempts]);
}

int main() {
    const char *wordToGuess = chooseRandomWord();
    int wordLength = strlen(wordToGuess);
    char guessedLetters[MAX_WORD_LENGTH] = {'\0'};
    int incorrectAttempts = 0;

    printf("Welcome to Hangman!\n");
    printf("Try to guess the word. Good luck!\n");

    while (incorrectAttempts < 6) {
        bool guessedAllLetters = true;

        // Display the word with correctly guessed letters and underscores for unknown letters
        for (int i = 0; i < wordLength; i++) {
            if (strchr(guessedLetters, wordToGuess[i]) != NULL) {
                printf("%c ", wordToGuess[i]);
            } else {
                printf("_ ");
                guessedAllLetters = false;
            }
        }

        printf("\n");
        displayHangman(incorrectAttempts);

        // Check if all letters have been guessed correctly
        if (guessedAllLetters) {
            printf("\nCongratulations! You guessed the word: %s\n", wordToGuess);
            break;
        }

        // Get user's guess
        char guess;
        printf("Enter a letter: ");
        scanf(" %c", &guess);

        // Check if the guessed letter is correct
        if (strchr(guessedLetters, guess) != NULL) {
            printf("You already guessed that letter. Try again.\n");
        } else if (strchr(wordToGuess, guess) != NULL) {
            guessedLetters[strlen(guessedLetters)] = guess;
        } else {
            incorrectAttempts++;
            printf("Incorrect guess! You have %d attempts left.\n", 6 - incorrectAttempts);
        }
    }

    if (incorrectAttempts >= 6) {
        printf("\nSorry, you lost! The word was: %s\n", wordToGuess);
    }

    return 0;
}
