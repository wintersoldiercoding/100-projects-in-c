// Project: Polynomial Manipulation (Addition, Multiplication)
// Repository link: https://github.com/wintersoldiercoding/100-projects-in-c

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int degree;
    int coefficient;
} Term;

typedef struct {
    int size;
    Term* terms;
} Polynomial;

Polynomial* createPolynomial(int size) {
    Polynomial* poly = (Polynomial*)malloc(sizeof(Polynomial));
    poly->size = size;
    poly->terms = (Term*)malloc(size * sizeof(Term));
    return poly;
}

void inputPolynomial(Polynomial* poly) {
    printf("Enter the degree and coefficient of each term:\n");
    for (int i = 0; i < poly->size; i++) {
        printf("Degree of term %d: ", i + 1);
        scanf("%d", &poly->terms[i].degree);
        printf("Coefficient of term %d: ", i + 1);
        scanf("%d", &poly->terms[i].coefficient);
    }
}

void displayPolynomial(Polynomial* poly) {
    printf("Polynomial: ");
    for (int i = 0; i < poly->size; i++) {
        if (i > 0 && poly->terms[i].coefficient >= 0) {
            printf("+ ");
        }
        printf("%dx^%d ", poly->terms[i].coefficient, poly->terms[i].degree);
    }
    printf("\n");
}

Polynomial* addPolynomials(Polynomial* poly1, Polynomial* poly2) {
    int size = poly1->size + poly2->size;
    Polynomial* result = createPolynomial(size);

    int i = 0, j = 0, k = 0;
    while (i < poly1->size && j < poly2->size) {
        if (poly1->terms[i].degree > poly2->terms[j].degree) {
            result->terms[k++] = poly1->terms[i++];
        } else if (poly1->terms[i].degree < poly2->terms[j].degree) {
            result->terms[k++] = poly2->terms[j++];
        } else {
            result->terms[k].degree = poly1->terms[i].degree;
            result->terms[k++].coefficient = poly1->terms[i++].coefficient + poly2->terms[j++].coefficient;
        }
    }

    while (i < poly1->size) {
        result->terms[k++] = poly1->terms[i++];
    }

    while (j < poly2->size) {
        result->terms[k++] = poly2->terms[j++];
    }

    result->size = k;
    return result;
}

Polynomial* multiplyPolynomials(Polynomial* poly1, Polynomial* poly2) {
    int size = poly1->size * poly2->size;
    Polynomial* result = createPolynomial(size);

    int k = 0;
    for (int i = 0; i < poly1->size; i++) {
        for (int j = 0; j < poly2->size; j++) {
            result->terms[k].degree = poly1->terms[i].degree + poly2->terms[j].degree;
            result->terms[k++].coefficient = poly1->terms[i].coefficient * poly2->terms[j].coefficient;
        }
    }

    // Combine like terms (terms with the same degree)
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            if (result->terms[i].degree == result->terms[j].degree) {
                result->terms[i].coefficient += result->terms[j].coefficient;
                result->terms[j].coefficient = 0;
            }
        }
    }

    // Remove terms with zero coefficients
    int newSize = 0;
    for (int i = 0; i < k; i++) {
        if (result->terms[i].coefficient != 0) {
            result->terms[newSize++] = result->terms[i];
        }
    }

    result->size = newSize;
    return result;
}

void freePolynomial(Polynomial* poly) {
    free(poly->terms);
    free(poly);
}

int main() {
    printf("Polynomial Manipulation (Addition, Multiplication)\n");

    int size1, size2;

    printf("Enter the number of terms in polynomial 1: ");
    scanf("%d", &size1);

    Polynomial* poly1 = createPolynomial(size1);
    inputPolynomial(poly1);

    printf("Enter the number of terms in polynomial 2: ");
    scanf("%d", &size2);

    Polynomial* poly2 = createPolynomial(size2);
    inputPolynomial(poly2);

    Polynomial* sumResult = addPolynomials(poly1, poly2);
    printf("\nSum of the polynomials:\n");
    displayPolynomial(sumResult);

    Polynomial* productResult = multiplyPolynomials(poly1, poly2);
    printf("\nProduct of the polynomials:\n");
    displayPolynomial(productResult);

    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(sumResult);
    freePolynomial(productResult);

    return 0;
}
