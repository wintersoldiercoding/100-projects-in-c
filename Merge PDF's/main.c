// Project: Merge Two PDF Files
// Repository link: https://github.com/wintersoldiercoding/100-projects-in-c

#include <stdio.h>
#include <stdlib.h>

// Function to merge two PDF files
void mergePDFs(const char* source1, const char* source2, const char* output) {
    FILE *file1, *file2, *outputFile;

    file1 = fopen(source1, "rb");
    file2 = fopen(source2, "rb");
    outputFile = fopen(output, "wb");

    if (file1 == NULL || file2 == NULL || outputFile == NULL) {
        printf("Error opening files.\n");
        return;
    }

    char ch;
    while ((ch = fgetc(file1)) != EOF) {
        fputc(ch, outputFile);
    }

    while ((ch = fgetc(file2)) != EOF) {
        fputc(ch, outputFile);
    }

    printf("PDF files merged successfully into '%s'.\n", output);

    fclose(file1);
    fclose(file2);
    fclose(outputFile);
}

int main() {
    char source1[100], source2[100], output[100];

    printf("Welcome to the Merge Two PDF Files!\n");

    printf("Enter the filename of the first PDF: ");
    scanf("%99s", source1);

    printf("Enter the filename of the second PDF: ");
    scanf("%99s", source2);

    printf("Enter the filename for the merged PDF: ");
    scanf("%99s", output);

    mergePDFs(source1, source2, output);

    return 0;
}
