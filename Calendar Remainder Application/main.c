// Project: Calendar Reminder Application
// Repository link: https://github.com/wintersoldiercoding/100-projects-in-c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REMINDERS 100
#define MAX_TITLE_LENGTH 100
#define MAX_DATE_LENGTH 20
#define MAX_NOTES_LENGTH 200

// Structure to hold a reminder
struct Reminder {
    char title[MAX_TITLE_LENGTH];
    char date[MAX_DATE_LENGTH];
    char notes[MAX_NOTES_LENGTH];
};

// Function to add a reminder
void addReminder(struct Reminder reminders[], int *numReminders) {
    if (*numReminders >= MAX_REMINDERS) {
        printf("Sorry, the maximum number of reminders has been reached.\n");
        return;
    }

    struct Reminder newReminder;
    printf("Enter the title of the reminder: ");
    scanf(" %[^\n]", newReminder.title);

    printf("Enter the date of the reminder (dd/mm/yyyy format): ");
    scanf(" %[^\n]", newReminder.date);

    printf("Enter any notes for the reminder: ");
    scanf(" %[^\n]", newReminder.notes);

    reminders[*numReminders] = newReminder;
    (*numReminders)++;

    printf("Reminder added successfully!\n");
}

// Function to display all reminders
void displayReminders(struct Reminder reminders[], int numReminders) {
    printf("\n----- Reminders -----\n");
    for (int i = 0; i < numReminders; i++) {
        printf("Title: %s\n", reminders[i].title);
        printf("Date: %s\n", reminders[i].date);
        printf("Notes: %s\n", reminders[i].notes);
        printf("---------------------\n");
    }
}

int main() {
    struct Reminder reminders[MAX_REMINDERS];
    int numReminders = 0;
    int choice;

    printf("Welcome to the Calendar Reminder Application!\n");

    do {
        printf("\nMenu:\n");
        printf("1. Add Reminder\n");
        printf("2. View Reminders\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addReminder(reminders, &numReminders);
                break;
            case 2:
                displayReminders(reminders, numReminders);
                break;
            case 3:
                printf("Exiting the Calendar Reminder Application. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
