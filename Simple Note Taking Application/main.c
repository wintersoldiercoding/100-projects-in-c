// Project: Simple Note Taking Application
// Repository link: https://github.com/wintersoldiercoding/100-projects-in-c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOTES 100
#define MAX_TITLE_LENGTH 100
#define MAX_CONTENT_LENGTH 500

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} Note;

Note notes[MAX_NOTES];
int numNotes = 0;

// Function to add a new note
void addNote() {
    if (numNotes >= MAX_NOTES) {
        printf("Cannot add more notes. The limit has been reached.\n");
        return;
    }

    Note newNote;
    printf("Enter note title: ");
    fgets(newNote.title, sizeof(newNote.title), stdin);
    newNote.title[strcspn(newNote.title, "\n")] = '\0';

    printf("Enter note content:\n");
    fgets(newNote.content, sizeof(newNote.content), stdin);
    newNote.content[strcspn(newNote.content, "\n")] = '\0';

    notes[numNotes++] = newNote;
    printf("Note added successfully.\n");
}

// Function to view all notes
void viewNotes() {
    if (numNotes == 0) {
        printf("No notes available.\n");
        return;
    }

    printf("Notes:\n");
    for (int i = 0; i < numNotes; i++) {
        printf("Title: %s\n", notes[i].title);
        printf("Content: %s\n", notes[i].content);
        printf("-------------------------\n");
    }
}

// Function to delete a note
void deleteNote() {
    int noteIndex;
    if (numNotes == 0) {
        printf("No notes available to delete.\n");
        return;
    }

    viewNotes();
    printf("Enter the note number to delete: ");
    scanf("%d", &noteIndex);

    if (noteIndex <= 0 || noteIndex > numNotes) {
        printf("Invalid note number.\n");
        return;
    }

    // Shift the notes array to delete the selected note
    for (int i = noteIndex - 1; i < numNotes - 1; i++) {
        notes[i] = notes[i + 1];
    }

    numNotes--;
    printf("Note deleted successfully.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nSimple Note Taking Application\n");
        printf("1. Add Note\n");
        printf("2. View Notes\n");
        printf("3. Delete Note\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character from the input buffer

        switch (choice) {
            case 1:
                addNote();
                break;
            case 2:
                viewNotes();
                break;
            case 3:
                deleteNote();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
