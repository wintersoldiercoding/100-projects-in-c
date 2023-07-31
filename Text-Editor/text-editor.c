// Advanced Text Editor in C
// Project Link: https://github.com/wintersoldiercoding/100-projects-in-c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_TEXT_SIZE 10000

void createFile(const char *filename);
void openFile(const char *filename);
void saveFile(const char *filename, const char *text);
void editFile(char *text);

int main() {
    char filename[MAX_FILE_NAME_LENGTH];
    char text[MAX_TEXT_SIZE];

    int choice;
    do {
        printf("Advanced Text Editor\n");
        printf("1. Create a new file\n");
        printf("2. Open an existing file\n");
        printf("3. Save the current file\n");
        printf("4. Edit the file\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the filename: ");
                scanf("%s", filename);
                createFile(filename);
                break;
            case 2:
                printf("Enter the filename: ");
                scanf("%s", filename);
                openFile(filename);
                break;
            case 3:
                printf("Enter the filename: ");
                scanf("%s", filename);
                saveFile(filename, text);
                break;
            case 4:
                editFile(text);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void createFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error creating the file.\n");
        return;
    }
    fclose(file);
    printf("File '%s' created successfully.\n", filename);
}

void openFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
}

void saveFile(const char *filename, const char *text) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error saving the file.\n");
        return;
    }

    fputs(text, file);

    fclose(file);
    printf("File saved successfully.\n");
}

void editFile(char *text) {
    printf("Enter your text (End with '$'): \n");
    text[0] = '\0'; // Initialize the text as an empty string

    char buffer[256];
    while (1) {
        fgets(buffer, sizeof(buffer), stdin);
        if (strcmp(buffer, "$\n") == 0) // Stop taking input when user enters '$'
            break;
        strcat(text, buffer);
    }
}
