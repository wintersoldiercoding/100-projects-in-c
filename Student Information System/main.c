#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define FILENAME "students.txt"

struct Student {
    char name[100];
    int roll_no;
    float marks;
};

struct School {
    struct Student students[MAX_STUDENTS];
    int num_students;
};

void saveSchoolToFile(const struct School *school) {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    fprintf(file, "%d\n", school->num_students);
    for (int i = 0; i < school->num_students; i++) {
        fprintf(file, "%s\n%d\n%f\n",
                school->students[i].name,
                school->students[i].roll_no,
                school->students[i].marks);
    }

    fclose(file);
}

void loadSchoolFromFile(struct School *school) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    fscanf(file, "%d", &school->num_students);
    for (int i = 0; i < school->num_students; i++) {
        fscanf(file, " %[^\n]", school->students[i].name);
        fscanf(file, "%d", &school->students[i].roll_no);
        fscanf(file, "%f", &school->students[i].marks);
    }

    fclose(file);
}

void addStudent(struct School *school, const char *name, int roll_no, float marks) {
    if (school->num_students < MAX_STUDENTS) {
        struct Student new_student;
        strcpy(new_student.name, name);
        new_student.roll_no = roll_no;
        new_student.marks = marks;

        school->students[school->num_students] = new_student;
        school->num_students++;
        saveSchoolToFile(school);
        printf("Student added successfully.\n");
    } else {
        printf("School is full. Cannot add more students.\n");
    }
}

void displayStudents(const struct School *school) {
    printf("Student Information:\n");
    for (int i = 0; i < school->num_students; i++) {
        printf("Name: %s\n", school->students[i].name);
        printf("Roll No: %d\n", school->students[i].roll_no);
        printf("Marks: %.2f\n\n", school->students[i].marks);
    }
}

int main() {
    struct School school;
    school.num_students = 0;

    loadSchoolFromFile(&school);

    displayStudents(&school);

    addStudent(&school, "John Doe", 101, 95.5);
    addStudent(&school, "Jane Smith", 102, 89.0);

    displayStudents(&school);

    return 0;
}
