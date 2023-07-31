// Repository link: https://github.com/wintersoldiercoding/100-projects-in-c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 1000

struct WordCount {
    char word[MAX_WORD_LENGTH];
    int count;
};

struct WordCount wordCounts[MAX_NUM_WORDS];
int numWords = 0;

// Function to add a word to the wordCounts array
void addWord(const char *word) {
    for (int i = 0; i < numWords; i++) {
        if (strcmp(wordCounts[i].word, word) == 0) {
            wordCounts[i].count++;
            return;
        }
    }

    if (numWords < MAX_NUM_WORDS) {
        strcpy(wordCounts[numWords].word, word);
        wordCounts[numWords].count = 1;
        numWords++;
    }
}

// Function to convert a word to lowercase
void convertToLowercase(char *word) {
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
}

int main() {
    char filename[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];

    printf("Welcome to the Advanced File Word Counter!\n");

    printf("Enter the filename (including the path) to read: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file. Please check the filename and try again.\n");
        return 1;
    }

    // Read words from the file and count their occurrences
    while (fscanf(file, "%s", word) == 1) {
        // Remove any non-alphanumeric characters from the word
        int i, j;
        for (i = 0, j = 0; word[i]; i++) {
            if (isalpha(word[i])) {
                word[j++] = word[i];
            }
        }
        word[j] = '\0';

        if (strlen(word) > 0) {
            // Convert word to lowercase for case-insensitive counting
            convertToLowercase(word);
            addWord(word);
        }
    }

    fclose(file);

    // Display the word counts
    printf("\nWord Count:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    return 0;
}
