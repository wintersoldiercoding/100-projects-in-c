// Project: File Encryption/Decryption (Image Files)
// Repository link: https://github.com/wintersoldiercoding/100-projects-in-c

#include <stdio.h>
#include <string.h>
// Function to encrypt or decrypt the image file
void encryptDecryptImage(const char* inputFile, const char* outputFile, const char* key) {
    FILE* inputFilePtr = fopen(inputFile, "rb");
    FILE* outputFilePtr = fopen(outputFile, "wb");

    if (inputFilePtr == NULL || outputFilePtr == NULL) {
        printf("Error opening files.\n");
        return;
    }

    char ch;
    int i = 0;
    while ((ch = fgetc(inputFilePtr)) != EOF) {
        // XOR the character with the key to encrypt/decrypt
        ch ^= key[i % strlen(key)];
        fputc(ch, outputFilePtr);
        i++;
    }

    fclose(inputFilePtr);
    fclose(outputFilePtr);
}

int main() {
    char inputFile[100], outputFile[100], key[100];
    int choice;

    printf("Welcome to the File Encryption/Decryption (Image Files)!\n");

    printf("Enter the input image file name: ");
    scanf("%s", inputFile);

    printf("Enter the output image file name: ");
    scanf("%s", outputFile);

    printf("Enter the encryption/decryption key: ");
    scanf("%s", key);

    printf("Enter your choice (1 for encryption, 2 for decryption): ");
    scanf("%d", &choice);

    if (choice == 1) {
        encryptDecryptImage(inputFile, outputFile, key);
        printf("Image file encrypted successfully!\n");
    } else if (choice == 2) {
        encryptDecryptImage(inputFile, outputFile, key);
        printf("Image file decrypted successfully!\n");
    } else {
        printf("Invalid choice. Please enter 1 for encryption or 2 for decryption.\n");
    }

    return 0;
}
