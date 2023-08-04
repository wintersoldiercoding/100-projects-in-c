// Project: Command-Line File Manager
// Repository link: https://github.com/wintersoldiercoding/100-projects-in-c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100

// Function to create a new file
void createFile() {
    char filename[MAX_FILENAME_LENGTH];

    printf("Enter the name of the file to create: ");
    scanf(" %[^\n]", filename);

    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        printf("Error creating the file.\n");
    } else {
        printf("File '%s' created successfully.\n", filename);
        fclose(file);
    }
}

// Function to delete an existing file
void deleteFile() {
    char filename[MAX_FILENAME_LENGTH];

    printf("Enter the name of the file to delete: ");
    scanf(" %[^\n]", filename);

    if (remove(filename) == 0) {
        printf("File '%s' deleted successfully.\n", filename);
    } else {
        printf("Error deleting the file or file not found.\n");
    }
}

int main() {
    int choice;

    printf("Welcome to the Command-Line File Manager!\n");

    do {
        printf("\nMenu:\n");
        printf("1. Create a new file\n");
        printf("2. Delete an existing file\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createFile();
                break;
            case 2:
                deleteFile();
                break;
            case 3:
                printf("Exiting the Command-Line File Manager. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
