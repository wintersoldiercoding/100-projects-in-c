// Caesar Cipher Brute-Force Cracker (Advanced) in C
// Project Link: https://github.com/wintersoldiercoding/100-projects-in-c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

// Function to calculate letter frequency in a given message
void calculateLetterFrequency(const char *message, int *frequency) {
    for (int i = 0; i < strlen(message); i++) {
        char ch = message[i];
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            frequency[ch - base]++;
        }
    }
}

// Function to find the most likely shift based on letter frequency
int findMostLikelyShift(const int *frequency) {
    int maxCount = frequency[0];
    int mostLikelyShift = 0;

    for (int i = 1; i < ALPHABET_SIZE; i++) {
        if (frequency[i] > maxCount) {
            maxCount = frequency[i];
            mostLikelyShift = i;
        }
    }

    // Shift 'E' (most common letter in English) to its corresponding letter in the encrypted message
    mostLikelyShift = (mostLikelyShift + ('E' - 'A')) % ALPHABET_SIZE;
    return mostLikelyShift;
}

// Function to decrypt the message with a given shift
void decryptMessage(char *message, int shift) {
    for (int i = 0; i < strlen(message); i++) {
        char ch = message[i];

        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            message[i] = (ch - base - shift + ALPHABET_SIZE) % ALPHABET_SIZE + base;
        }
    }
}

int main() {
    char encryptedMessage[1000];

    printf("Caesar Cipher Brute-Force Cracker (Advanced)\n");
    printf("Enter the encrypted message: ");
    fgets(encryptedMessage, sizeof(encryptedMessage), stdin);

    // Initialize letter frequency array
    int letterFrequency[ALPHABET_SIZE] = {0};
    calculateLetterFrequency(encryptedMessage, letterFrequency);

    // Find the most likely shift based on letter frequency
    int mostLikelyShift = findMostLikelyShift(letterFrequency);

    printf("\nDecrypting...\n");
    printf("Most Likely Shift: %d\n", mostLikelyShift);
    printf("Decrypted Message:\n");

    // Decrypt the message with the most likely shift
    char decryptedMessage[1000];
    strcpy(decryptedMessage, encryptedMessage);
    decryptMessage(decryptedMessage, mostLikelyShift);
    printf("%s", decryptedMessage);

    return 0;
}
