#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

void addEmployee(FILE *file) {
    struct Employee emp;

    printf("Enter employee ID: ");
    scanf("%d", &emp.id);
    printf("Enter employee name: ");
    scanf("%s", emp.name);
    printf("Enter employee salary: ");
    scanf("%f", &emp.salary);

    fseek(file, 0, SEEK_END);
    fwrite(&emp, sizeof(struct Employee), 1, file);
    printf("Employee added successfully!\n");
}

void displayEmployees(FILE *file) {
    struct Employee emp;

    printf("Employee List:\n");
    printf("%-10s%-20s%-10s\n", "ID", "Name", "Salary");
    printf("-----------------------------------\n");

    fseek(file, 0, SEEK_SET);
    while (fread(&emp, sizeof(struct Employee), 1, file) == 1) {
        printf("%-10d%-20s%-10.2f\n", emp.id, emp.name, emp.salary);
    }
}

int main() {
    FILE *file = fopen("employee.dat", "ab+"); // Open file for binary read and append

    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    int choice;
    do {
        printf("\nEmployee Payroll System\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(file);
                break;
            case 2:
                displayEmployees(file);
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
