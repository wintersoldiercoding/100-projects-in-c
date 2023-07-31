// Repository link: https://github.com/wintersoldiercoding/100-projects-in-c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_TASK_LENGTH 100

struct Task {
    char description[MAX_TASK_LENGTH];
    int completed;
};

struct Task todoList[MAX_TASKS];
int numTasks = 0;

// Function to add a new task to the todo list
void addTask(const char *description) {
    if (numTasks < MAX_TASKS) {
        strcpy(todoList[numTasks].description, description);
        todoList[numTasks].completed = 0;
        numTasks++;
        printf("Task added successfully!\n");
    } else {
        printf("Todo list is full. Cannot add more tasks.\n");
    }
}

// Function to mark a task as completed
void markTaskAsCompleted(int taskIndex) {
    if (taskIndex >= 0 && taskIndex < numTasks) {
        todoList[taskIndex].completed = 1;
        printf("Task marked as completed!\n");
    } else {
        printf("Invalid task index.\n");
    }
}

// Function to view all tasks in the todo list
void viewTasks() {
    printf("\nTodo List:\n");
    for (int i = 0; i < numTasks; i++) {
        printf("%d. [%c] %s\n", i + 1, todoList[i].completed ? 'X' : ' ', todoList[i].description);
    }
    printf("\n");
}

// Function to delete a task from the todo list
void deleteTask(int taskIndex) {
    if (taskIndex >= 0 && taskIndex < numTasks) {
        for (int i = taskIndex; i < numTasks - 1; i++) {
            strcpy(todoList[i].description, todoList[i + 1].description);
            todoList[i].completed = todoList[i + 1].completed;
        }
        numTasks--;
        printf("Task deleted successfully!\n");
    } else {
        printf("Invalid task index.\n");
    }
}

int main() {
    int choice;
    char taskDescription[MAX_TASK_LENGTH];

    printf("Welcome to the Advanced Todo List!\n");

    do {
        printf("\nMenu:\n");
        printf("1. Add Task\n");
        printf("2. Mark Task as Completed\n");
        printf("3. View Tasks\n");
        printf("4. Delete Task\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the task description: ");
                getchar(); // Clear the newline character from the buffer
                fgets(taskDescription, sizeof(taskDescription), stdin);
                taskDescription[strcspn(taskDescription, "\n")] = '\0'; // Remove the trailing newline
                addTask(taskDescription);
                break;
            case 2:
                if (numTasks > 0) {
                    printf("Enter the task index to mark as completed: ");
                    int taskIndex;
                    scanf("%d", &taskIndex);
                    markTaskAsCompleted(taskIndex - 1);
                } else {
                    printf("Todo list is empty. No tasks to mark as completed.\n");
                }
                break;
            case 3:
                if (numTasks > 0) {
                    viewTasks();
                } else {
                    printf("Todo list is empty.\n");
                }
                break;
            case 4:
                if (numTasks > 0) {
                    printf("Enter the task index to delete: ");
                    int taskIndex;
                    scanf("%d", &taskIndex);
                    deleteTask(taskIndex - 1);
                } else {
                    printf("Todo list is empty. No tasks to delete.\n");
                }
                break;
            case 5:
                printf("Exiting the Advanced Todo List. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
