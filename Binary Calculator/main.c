// Project: Binary Calculator (Addition & Subtraction)
// Repository link: https://github.com/wintersoldiercoding/100-projects-in-c

#include <stdio.h>
#include <string.h>

// Function to perform binary addition
char* binaryAddition(const char* binary1, const char* binary2) {
    static char result[100];
    int carry = 0;
    int i = strlen(binary1) - 1;
    int j = strlen(binary2) - 1;
    int k = 0;

    while (i >= 0 || j >= 0 || carry == 1) {
        int sum = carry;

        if (i >= 0)
            sum += binary1[i--] - '0';
        if (j >= 0)
            sum += binary2[j--] - '0';

        result[k++] = (sum % 2) + '0';
        carry = sum / 2;
    }

    result[k] = '\0';
    strrev(result); // Reverse the result to get the correct binary representation

    return result;
}

// Function to perform binary subtraction
char* binarySubtraction(const char* binary1, const char* binary2) {
    static char result[100];
    int borrow = 0;
    int i = strlen(binary1) - 1;
    int j = strlen(binary2) - 1;
    int k = 0;

    while (i >= 0 || j >= 0) {
        int sub = borrow + (i >= 0 ? binary1[i--] - '0' : 0) - (j >= 0 ? binary2[j--] - '0' : 0);

        if (sub < 0) {
            sub += 2;
            borrow = -1;
        } else {
            borrow = 0;
        }

        result[k++] = sub + '0';
    }

    result[k] = '\0';
    strrev(result); // Reverse the result to get the correct binary representation

    return result;
}

int main() {
    char binary1[100], binary2[100];

    printf("Welcome to the Binary Calculator (Addition & Subtraction)!\n");

    printf("Enter the first binary number: ");
    scanf("%s", binary1);

    printf("Enter the second binary number: ");
    scanf("%s", binary2);

    char* additionResult = binaryAddition(binary1, binary2);
    printf("Binary Addition Result: %s\n", additionResult);

    char* subtractionResult = binarySubtraction(binary1, binary2);
    printf("Binary Subtraction Result: %s\n", subtractionResult);

    return 0;
}
