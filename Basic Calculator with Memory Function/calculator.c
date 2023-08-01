// Basic Calculator with Memory Function in C
// Project Link: https://github.com/wintersoldiercoding/100-projects-in-c

#include <stdio.h>

// Function to clear the input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    double memory = 0.0;
    double result = 0.0;
    char operator;
    double operand;

    while (1) {
        printf("Current Result: %.2f\n", result);
        printf("M - Memory, C - Clear Memory, + - Addition, - - Subtraction, * - Multiplication, / - Division, Q - Quit\n");
        printf("Enter an operator: ");

        scanf(" %c", &operator);

        switch (operator) {
            case 'M':
            case 'm':
                printf("Memory Value: %.2f\n", memory);
                break;
            case 'C':
            case 'c':
                memory = 0.0;
                printf("Memory cleared.\n");
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                printf("Enter first operand: ");
                scanf("%lf", &result);

                printf("Enter second operand: ");
                scanf("%lf", &operand);

                switch (operator) {
                    case '+':
                        result += operand;
                        break;
                    case '-':
                        result -= operand;
                        break;
                    case '*':
                        result *= operand;
                        break;
                    case '/':
                        if (operand != 0.0) {
                            result /= operand;
                        } else {
                            printf("Error: Division by zero.\n");
                        }
                        break;
                }

                printf("Result: %.2f\n", result);
                break;
            case 'Q':
            case 'q':
                printf("Exiting the calculator.\n");
                return 0;
            default:
                printf("Invalid operator. Please try again.\n");
                clearInputBuffer(); // Clear any remaining characters in the input buffer
        }

        printf("Do you want to store the current result in memory? (Y/N): ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'Y' || choice == 'y') {
            memory = result;
            printf("Result stored in memory.\n");
        }

        clearInputBuffer(); // Clear any remaining characters in the input buffer
    }

    return 0;
}
