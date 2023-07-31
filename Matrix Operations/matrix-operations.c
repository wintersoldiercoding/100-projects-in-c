// Basic Matrix Calculator (Inverse, Transpose, Addition, Multiplication) in C
// Project Link: https://github.com/wintersoldiercoding/100-projects-in-c

#include <stdio.h>

#define MAX_SIZE 10

// Function to print a matrix
void printMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int rows, int cols, int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int rows1, int cols1, int matrix1[MAX_SIZE][MAX_SIZE], int rows2, int cols2, int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Function to find the transpose of a matrix
void transposeMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

// Function to find the determinant of a 2x2 matrix
int determinant2x2(int matrix[2][2]) {
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}

// Function to find the inverse of a 2x2 matrix
void inverse2x2(int matrix[2][2], int result[2][2]) {
    int det = determinant2x2(matrix);
    if (det == 0) {
        printf("The matrix is not invertible (non-singular).\n");
        return;
    }

    int temp = matrix[0][0];
    matrix[0][0] = matrix[1][1];
    matrix[1][1] = temp;

    matrix[0][1] = -matrix[0][1];
    matrix[1][0] = -matrix[1][0];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = matrix[i][j] / det;
        }
    }
}

int main() {
    int rows1, cols1;
    int matrix1[MAX_SIZE][MAX_SIZE];

    printf("Enter the number of rows and columns for matrix 1 (maximum size %d x %d): ", MAX_SIZE, MAX_SIZE);
    scanf("%d %d", &rows1, &cols1);

    printf("Enter the elements of matrix 1:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Matrix 1:\n");
    printMatrix(rows1, cols1, matrix1);

    int choice;
    printf("Select an operation:\n");
    printf("1. Transpose\n");
    printf("2. Add another matrix\n");
    printf("3. Multiply with another matrix\n");
    printf("4. Find inverse (only for 2x2 matrices)\n");
    printf("Choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        int transpose[MAX_SIZE][MAX_SIZE];
        transposeMatrix(rows1, cols1, matrix1, transpose);
        printf("Transpose of Matrix 1:\n");
        printMatrix(cols1, rows1, transpose);
    } else if (choice == 2 || choice == 3) {
        int rows2, cols2;
        int matrix2[MAX_SIZE][MAX_SIZE];

        printf("Enter the number of rows and columns for matrix 2 (maximum size %d x %d): ", MAX_SIZE, MAX_SIZE);
        scanf("%d %d", &rows2, &cols2);

        if (choice == 2 && (rows1 != rows2 || cols1 != cols2)) {
            printf("Matrix dimensions do not match for addition.\n");
            return 1;
        } else if (choice == 3 && cols1 != rows2) {
            printf("Matrix dimensions do not match for multiplication.\n");
            return 1;
        }

        printf("Enter the elements of matrix 2:\n");
        for (int i = 0; i < rows2; i++) {
            for (int j = 0; j < cols2; j++) {
                scanf("%d", &matrix2[i][j]);
            }
        }

        printf("Matrix 2:\n");
        printMatrix(rows2, cols2, matrix2);

        if (choice == 2) {
            int result[MAX_SIZE][MAX_SIZE];
            addMatrices(rows1, cols1, matrix1, matrix2, result);
            printf("Result of Addition:\n");
            printMatrix(rows1, cols1, result);
        } else {
            int result[MAX_SIZE][MAX_SIZE];
            multiplyMatrices(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
            printf("Result of Multiplication:\n");
            printMatrix(rows1, cols2, result);
        }
    } else if (choice == 4) {
        if (rows1 != 2 || cols1 != 2) {
            printf("Inverse can only be found for 2x2 matrices.\n");
            return 1;
        }

        int inverse[MAX_SIZE][MAX_SIZE];
        inverse2x2(matrix1, inverse);
        printf("Inverse of Matrix 1:\n");
        printMatrix(2, 2, inverse);
    } else {
        printf("Invalid choice. Please try again.\n");
    }

    return 0;
}
