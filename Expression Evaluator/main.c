// Project: Expression Evaluator (with Infix to Postfix Conversion)
// Repository link: https://github.com/wintersoldiercoding/100-projects-in-c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPRESSION_LENGTH 100
#define MAX_STACK_SIZE 100

// Function to check if the character is an operator (+, -, *, /)
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to convert an infix expression to postfix notation
void infixToPostfix(char infix[], char postfix[]) {
    char stack[MAX_STACK_SIZE];
    int top = -1; // Initialize the stack top

    int i, j;
    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (ch == ' ') {
            continue; // Skip whitespaces
        }

        if (isdigit(ch) || isalpha(ch)) {
            postfix[j++] = ch; // Append operands to the postfix expression
        } else if (ch == '(') {
            stack[++top] = ch; // Push '(' onto the stack
        } else if (ch == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[j++] = stack[top--]; // Pop operators from stack to postfix until '(' is encountered
            }
            if (top >= 0 && stack[top] == '(') {
                top--; // Pop '(' from the stack
            }
        } else if (isOperator(ch)) {
            while (top >= 0 && (stack[top] == '*' || stack[top] == '/') && (ch == '+' || ch == '-')) {
                postfix[j++] = stack[top--]; // Pop higher precedence operators from stack to postfix
            }
            stack[++top] = ch; // Push the current operator onto the stack
        }
    }

    while (top >= 0) {
        postfix[j++] = stack[top--]; // Pop remaining operators from stack to postfix
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}

// Function to evaluate a postfix expression
int evaluatePostfix(char postfix[]) {
    int stack[MAX_STACK_SIZE];
    int top = -1; // Initialize the stack top

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            stack[++top] = ch - '0'; // Convert character to integer and push onto the stack
        } else if (isOperator(ch)) {
            int operand2 = stack[top--];
            int operand1 = stack[top--];

            // Perform the operation based on the operator
            switch (ch) {
                case '+':
                    stack[++top] = operand1 + operand2;
                    break;
                case '-':
                    stack[++top] = operand1 - operand2;
                    break;
                case '*':
                    stack[++top] = operand1 * operand2;
                    break;
                case '/':
                    stack[++top] = operand1 / operand2;
                    break;
            }
        }
    }

    return stack[top]; // The result of the expression is at the top of the stack
}

int main() {
    char infix[MAX_EXPRESSION_LENGTH];
    char postfix[MAX_EXPRESSION_LENGTH];

    printf("Welcome to the Expression Evaluator (with Infix to Postfix Conversion)!\n");

    printf("Enter the infix expression: ");
    scanf(" %[^\n]", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}
