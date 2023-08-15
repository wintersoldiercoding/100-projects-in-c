#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define FILENAME "library.txt"

struct Book {
    char title[100];
    char author[100];
    int year;
    int is_available;
};

struct Library {
    struct Book books[MAX_BOOKS];
    int num_books;
};

void saveLibraryToFile(const struct Library *library) {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    fprintf(file, "%d\n", library->num_books);
    for (int i = 0; i < library->num_books; i++) {
        fprintf(file, "%s\n%s\n%d\n%d\n",
                library->books[i].title,
                library->books[i].author,
                library->books[i].year,
                library->books[i].is_available);
    }

    fclose(file);
}

void loadLibraryFromFile(struct Library *library) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    fscanf(file, "%d", &library->num_books);
    for (int i = 0; i < library->num_books; i++) {
        fscanf(file, " %[^\n]", library->books[i].title);
        fscanf(file, " %[^\n]", library->books[i].author);
        fscanf(file, "%d", &library->books[i].year);
        fscanf(file, "%d", &library->books[i].is_available);
    }

    fclose(file);
}

void addBook(struct Library *library, const char *title, const char *author, int year) {
    if (library->num_books < MAX_BOOKS) {
        struct Book new_book;
        strcpy(new_book.title, title);
        strcpy(new_book.author, author);
        new_book.year = year;
        new_book.is_available = 1;

        library->books[library->num_books] = new_book;
        library->num_books++;
        saveLibraryToFile(library);
        printf("Book added successfully.\n");
    } else {
        printf("Library is full. Cannot add more books.\n");
    }
}

void displayBooks(const struct Library *library) {
    printf("Library Catalog:\n");
    for (int i = 0; i < library->num_books; i++) {
        printf("%d. %s by %s (%d)\n", i + 1, library->books[i].title, library->books[i].author, library->books[i].year);
        printf("   Status: %s\n", library->books[i].is_available ? "Available" : "Not Available");
    }
}

void borrowBook(struct Library *library, int book_index) {
    if (book_index >= 0 && book_index < library->num_books) {
        if (library->books[book_index].is_available) {
            library->books[book_index].is_available = 0;
            saveLibraryToFile(library);
            printf("Book borrowed successfully.\n");
        } else {
            printf("Book is not available for borrowing.\n");
        }
    } else {
        printf("Invalid book index.\n");
    }
}

void returnBook(struct Library *library, int book_index) {
    if (book_index >= 0 && book_index < library->num_books) {
        if (!library->books[book_index].is_available) {
            library->books[book_index].is_available = 1;
            saveLibraryToFile(library);
            printf("Book returned successfully.\n");
        } else {
            printf("Book is already available.\n");
        }
    } else {
        printf("Invalid book index.\n");
    }
}

int main() {
    struct Library library;
    library.num_books = 0;

    loadLibraryFromFile(&library);

    displayBooks(&library);

    borrowBook(&library, 0);
    returnBook(&library, 1);

    displayBooks(&library);

    return 0;
}
