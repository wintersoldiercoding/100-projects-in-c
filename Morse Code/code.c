// Morse Code Translator in C (with User Input)
// Project Link: https://github.com/wintersoldiercoding/100-projects-in-c

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Morse Code Table
const char* morseTable[] = {
    ".-",   // A
    "-...", // B
    "-.-.", // C
    "-..",  // D
    ".",    // E
    "..-.", // F
    "--.",  // G
    "....", // H
    "..",   // I
    ".---", // J
    "-.-",  // K
    ".-..", // L
    "--",   // M
    "-.",   // N
    "---",  // O
    ".--.", // P
    "--.-", // Q
    ".-.",  // R
    "...",  // S
    "-",    // T
    "..-",  // U
    "...-", // V
    ".--",  // W
    "-..-", // X
    "-.--", // Y
    "--.."  // Z
};

// Function to convert a single character to Morse code
const char* charToMorse(char c) {
    if (isalpha(c)) {
        c = toupper(c);
        return morseTable[c - 'A'];
    } else if (isdigit(c)) {
        return morseTable[c - '0' + 25]; // Offset for digits in the table
    } else {
        switch (c) {
            case ' ':
                return " ";
            case '.':
                return ".-.-.-"; // Period
            case ',':
                return "--..--"; // Comma
            case '?':
                return "..--.."; // Question mark
            case '!':
                return "-.-.--"; // Exclamation mark
            default:
                return ""; // Unsupported characters are ignored
        }
    }
}

// Function to convert a string to Morse code
void stringToMorse(const char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        const char* morseChar = charToMorse(str[i]);
        printf("%s ", morseChar);
    }
    printf("\n");
}

int main() {
    char input[100]; // Maximum input length
    printf("Enter the message to convert to Morse code: ");
    fgets(input, sizeof(input), stdin);

    // Remove trailing newline from user input
    input[strcspn(input, "\n")] = '\0';

    printf("Original Message: %s\n", input);

    printf("Morse Code: ");
    stringToMorse(input);

    return 0;
}
