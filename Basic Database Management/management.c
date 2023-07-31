// Basic Database Management System (File-Based) in C (Interactive)
// Project Link: https://github.com/wintersoldiercoding/100-projects-in-c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define DATABASE_FILE "students.db"

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
} Student;

// Function to add a new student record to the database
void addStudentRecord(Student student) {
    FILE *database = fopen(DATABASE_FILE, "ab");
    if (database == NULL) {
        printf("Error opening database file.\n");
        return;
    }

    fwrite(&student, sizeof(Student), 1, database);
    fclose(database);
}

// Function to retrieve a student record from the database by ID
Student getStudentRecord(int id) {
    FILE *database = fopen(DATABASE_FILE, "rb");
    if (database == NULL) {
        printf("Error opening database file.\n");
        Student emptyStudent = {0, "", 0};
        return emptyStudent;
    }

    Student student;
    while (fread(&student, sizeof(Student), 1, database) == 1) {
        if (student.id == id) {
            fclose(database);
            return student;
        }
    }

    fclose(database);
    Student emptyStudent = {0, "", 0};
    return emptyStudent;
}

// Function to update a student record in the database
void updateStudentRecord(Student student) {
    FILE *database = fopen(DATABASE_FILE, "r+b");
    if (database == NULL) {
        printf("Error opening database file.\n");
        return;
    }

    Student existingStudent;
    while (fread(&existingStudent, sizeof(Student), 1, database) == 1) {
        if (existingStudent.id == student.id) {
            fseek(database, -sizeof(Student), SEEK_CUR);
            fwrite(&student, sizeof(Student), 1, database);
            break;
        }
    }

    fclose(database);
}

// Function to delete a student record from the database by ID
void deleteStudentRecord(int id) {
    FILE *database = fopen(DATABASE_FILE, "r+b");
    if (database == NULL) {
        printf("Error opening database file.\n");
        return;
    }

    FILE *tempFile = fopen("temp.db", "wb");
    if (tempFile == NULL) {
        printf("Error creating temporary file.\n");
        fclose(database);
        return;
    }

    Student student;
    while (fread(&student, sizeof(Student), 1, database) == 1) {
        if (student.id != id) {
            fwrite(&student, sizeof(Student), 1, tempFile);
        }
    }

    fclose(database);
    fclose(tempFile);
    remove(DATABASE_FILE);
    rename("temp.db", DATABASE_FILE);
}

// Function to print the details of a student
void printStudentDetails(Student student) {
    printf("ID: %d\nName: %s\nAge: %d\n", student.id, student.name, student.age);
}

// Function to get student details from user input
Student getStudentDetailsFromUser() {
    Student student;

    printf("Enter ID: ");
    scanf("%d", &student.id);

    printf("Enter Name: ");
    getchar(); // To consume the newline character left by scanf
    fgets(student.name, MAX_NAME_LENGTH, stdin);
    student.name[strcspn(student.name, "\n")] = '\0'; // Remove newline from fgets input

    printf("Enter Age: ");
    scanf("%d", &student.age);

    return student;
}

int main() {
    int choice;
    Student student;

    while (1) {
        printf("\nSelect an option:\n");
        printf("1. Add Student\n");
        printf("2. Retrieve Student\n");
        printf("3. Update Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                student = getStudentDetailsFromUser();
                addStudentRecord(student);
                printf("Student added successfully.\n");
                break;
            case 2:
                printf("Enter Student ID to retrieve: ");
                int id;
                scanf("%d", &id);
                student = getStudentRecord(id);
                if (student.id != 0) {
                    printf("Student Details:\n");
                    printStudentDetails(student);
                } else {
                    printf("Student with ID %d not found.\n", id);
                }
                break;
            case 3:
                printf("Enter Student ID to update: ");
                scanf("%d", &id);
                student = getStudentRecord(id);
                if (student.id != 0) {
                    student = getStudentDetailsFromUser();
                    updateStudentRecord(student);
                    printf("Student updated successfully.\n");
                } else {
                    printf("Student with ID %d not found.\n", id);
                }
                break;
            case 4:
                printf("Enter Student ID to delete: ");
                scanf("%d", &id);
                student = getStudentRecord(id);
                if (student.id != 0) {
                    deleteStudentRecord(id);
                    printf("Student deleted successfully.\n");
                } else {
                    printf("Student with ID %d not found.\n", id);
                }
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
