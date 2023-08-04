// Project: Simple Budget Tracker
// Repository link: https://github.com/wintersoldiercoding/100-projects-in-c

#include <stdio.h>

// Function to calculate the total income
float calculateTotalIncome(float incomes[], int numIncomes) {
    float totalIncome = 0.0;

    for (int i = 0; i < numIncomes; i++) {
        totalIncome += incomes[i];
    }

    return totalIncome;
}

// Function to calculate the total expenses
float calculateTotalExpenses(float expenses[], int numExpenses) {
    float totalExpenses = 0.0;

    for (int i = 0; i < numExpenses; i++) {
        totalExpenses += expenses[i];
    }

    return totalExpenses;
}

int main() {
    int numIncomes, numExpenses;
    float incomes[100], expenses[100];

    printf("Welcome to the Simple Budget Tracker!\n");

    printf("Enter the number of income entries: ");
    scanf("%d", &numIncomes);

    printf("Enter the income values:\n");
    for (int i = 0; i < numIncomes; i++) {
        scanf("%f", &incomes[i]);
    }

    printf("Enter the number of expense entries: ");
    scanf("%d", &numExpenses);

    printf("Enter the expense values:\n");
    for (int i = 0; i < numExpenses; i++) {
        scanf("%f", &expenses[i]);
    }

    float totalIncome = calculateTotalIncome(incomes, numIncomes);
    float totalExpenses = calculateTotalExpenses(expenses, numExpenses);
    float netBalance = totalIncome - totalExpenses;

    printf("\n----- Budget Summary -----\n");
    printf("Total Income: $%.2f\n", totalIncome);
    printf("Total Expenses: $%.2f\n", totalExpenses);
    printf("Net Balance: $%.2f\n", netBalance);
    printf("--------------------------\n");

    return 0;
}
