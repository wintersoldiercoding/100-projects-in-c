// Advanced File Encryption/Decryption using AES
// Project Link: https://github.com/wintersoldiercoding/100-projects-in-c
/*you need to ensure that you have OpenSSL installed on your system, 
as this code relies on the OpenSSL library for AES encryption/decryption.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <openssl/aes.h>

#define AES_KEY_SIZE 256 // AES-256
#define BUFFER_SIZE 1024

void encryptFile(const char *inputFilePath, const char *outputFilePath, const uint8_t *key);
void decryptFile(const char *inputFilePath, const char *outputFilePath, const uint8_t *key);

int main() {
    const uint8_t key[AES_KEY_SIZE / 8] = {
        // Replace with your 32-byte (256-bit) encryption key
        // For demonstration purposes, use a random key here
        0x2F, 0xA1, 0x10, 0xC3, 0x6B, 0x71, 0x9D, 0x86,
        0x92, 0xBA, 0x3F, 0x2E, 0x7D, 0x40, 0x8F, 0xF3,
        0xD7, 0xE8, 0xA4, 0x0C, 0x18, 0x98, 0x5F, 0xB3,
        0x13, 0xD0, 0x87, 0xC9, 0x34, 0x57, 0x90, 0x2A
    };

    const char *inputFile = "input_file.txt";
    const char *encryptedFile = "encrypted_file.enc";
    const char *decryptedFile = "decrypted_file.txt";

    // Encrypt the file
    encryptFile(inputFile, encryptedFile, key);
    printf("File encrypted successfully.\n");

    // Decrypt the file
    decryptFile(encryptedFile, decryptedFile, key);
    printf("File decrypted successfully.\n");

    return 0;
}

void encryptFile(const char *inputFilePath, const char *outputFilePath, const uint8_t *key) {
    FILE *inputFile = fopen(inputFilePath, "rb");
    FILE *outputFile = fopen(outputFilePath, "wb");

    if (!inputFile || !outputFile) {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }

    AES_KEY aesKey;
    if (AES_set_encrypt_key(key, AES_KEY_SIZE, &aesKey) != 0) {
        fprintf(stderr, "AES key initialization failed\n");
        exit(EXIT_FAILURE);
    }

    unsigned char inputBuffer[BUFFER_SIZE];
    unsigned char outputBuffer[BUFFER_SIZE + AES_BLOCK_SIZE];

    int bytesRead = 0;
    while ((bytesRead = fread(inputBuffer, sizeof(unsigned char), BUFFER_SIZE, inputFile)) > 0) {
        AES_cbc_encrypt(inputBuffer, outputBuffer, bytesRead, &aesKey, NULL, AES_ENCRYPT);
        fwrite(outputBuffer, sizeof(unsigned char), bytesRead + AES_BLOCK_SIZE, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
}

void decryptFile(const char *inputFilePath, const char *outputFilePath, const uint8_t *key) {
    FILE *inputFile = fopen(inputFilePath, "rb");
    FILE *outputFile = fopen(outputFilePath, "wb");

    if (!inputFile || !outputFile) {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }

    AES_KEY aesKey;
    if (AES_set_decrypt_key(key, AES_KEY_SIZE, &aesKey) != 0) {
        fprintf(stderr, "AES key initialization failed\n");
        exit(EXIT_FAILURE);
    }

    unsigned char inputBuffer[BUFFER_SIZE + AES_BLOCK_SIZE];
    unsigned char outputBuffer[BUFFER_SIZE];

    int bytesRead = 0;
    while ((bytesRead = fread(inputBuffer, sizeof(unsigned char), BUFFER_SIZE + AES_BLOCK_SIZE, inputFile)) > 0) {
        AES_cbc_encrypt(inputBuffer, outputBuffer, bytesRead, &aesKey, NULL, AES_DECRYPT);
        fwrite(outputBuffer, sizeof(unsigned char), bytesRead - AES_BLOCK_SIZE, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
}
