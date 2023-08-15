#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Reservation {
    int roomNumber;
    char guestName[50];
    int numGuests;
};

void reserveRoom(FILE *file) {
    struct Reservation reservation;

    printf("Enter room number: ");
    scanf("%d", &reservation.roomNumber);
    printf("Enter guest name: ");
    scanf("%s", reservation.guestName);
    printf("Enter number of guests: ");
    scanf("%d", &reservation.numGuests);

    fseek(file, 0, SEEK_END);
    fwrite(&reservation, sizeof(struct Reservation), 1, file);
    printf("Room reserved successfully!\n");
}

void displayReservations(FILE *file) {
    struct Reservation reservation;

    printf("Reservation List:\n");
    printf("%-15s%-20s%-15s\n", "Room Number", "Guest Name", "Number of Guests");
    printf("-----------------------------------------\n");

    fseek(file, 0, SEEK_SET);
    while (fread(&reservation, sizeof(struct Reservation), 1, file) == 1) {
        printf("%-15d%-20s%-15d\n", reservation.roomNumber, reservation.guestName, reservation.numGuests);
    }
}

int main() {
    FILE *file = fopen("reservations.dat", "ab+"); // Open file for binary read and append

    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    int choice;
    do {
        printf("\nHotel Reservation System\n");
        printf("1. Reserve Room\n");
        printf("2. Display Reservations\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                reserveRoom(file);
                break;
            case 2:
                displayReservations(file);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);

    fclose(file);
    return 0;
}
