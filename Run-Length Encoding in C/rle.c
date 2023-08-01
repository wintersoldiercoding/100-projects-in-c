// Run-Length Encoding/Decoding in C
// Project Link: https://github.com/wintersoldiercoding/100-projects-in-c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to perform Run-Length Encoding
char* runLengthEncode(const char* input) {
    int inputLength = strlen(input);
    char* encoded = (char*)malloc(2 * inputLength * sizeof(char)); // Allocate memory for the encoded string

    int count = 1;
    int encodedIndex = 0;

    for (int i = 0; i < inputLength; i++) {
        if (input[i] == input[i + 1]) {
            count++;
        } else {
            encoded[encodedIndex++] = count + '0'; // Convert count to char and store it
            encoded[encodedIndex++] = input[i];
            count = 1;
        }
    }

    encoded[encodedIndex] = '\0'; // Null-terminate the encoded string
    return encoded;
}

// Function to perform Run-Length Decoding
char* runLengthDecode(const char* encoded) {
    int encodedLength = strlen(encoded);
    char* decoded = (char*)malloc(encodedLength * sizeof(char)); // Allocate memory for the decoded string

    int decodedIndex = 0;
    for (int i = 0; i < encodedLength; i += 2) {
        int count = encoded[i] - '0'; // Convert count character to integer
        char character = encoded[i + 1];
        for (int j = 0; j < count; j++) {
            decoded[decodedIndex++] = character;
        }
    }

    decoded[decodedIndex] = '\0'; // Null-terminate the decoded string
    return decoded;
}

int main() {
    const char* inputString = "aaabbbbcccddeee";
    char* encodedString = runLengthEncode(inputString);
    printf("Encoded: %s\n", encodedString);

    char* decodedString = runLengthDecode(encodedString);
    printf("Decoded: %s\n", decodedString);

    free(encodedString);
    free(decodedString);

    return 0;
}
