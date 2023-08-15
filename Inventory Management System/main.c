#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    int id;
    char name[50];
    int quantity;
    float price;
};

void addProduct(FILE *file) {
    struct Product product;

    printf("Enter product ID: ");
    scanf("%d", &product.id);
    printf("Enter product name: ");
    scanf("%s", product.name);
    printf("Enter product quantity: ");
    scanf("%d", &product.quantity);
    printf("Enter product price: ");
    scanf("%f", &product.price);

    fseek(file, 0, SEEK_END);
    fwrite(&product, sizeof(struct Product), 1, file);
    printf("Product added successfully!\n");
}

void displayProducts(FILE *file) {
    struct Product product;

    printf("Product List:\n");
    printf("%-10s%-20s%-10s%-10s\n", "ID", "Name", "Quantity", "Price");
    printf("------------------------------------------------\n");

    fseek(file, 0, SEEK_SET);
    while (fread(&product, sizeof(struct Product), 1, file) == 1) {
        printf("%-10d%-20s%-10d%-10.2f\n", product.id, product.name, product.quantity, product.price);
    }
}

int main() {
    FILE *file = fopen("inventory.dat", "ab+"); // Open file for binary read and append

    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    int choice;
    do {
        printf("\nInventory Management System\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(file);
                break;
            case 2:
                displayProducts(file);
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
