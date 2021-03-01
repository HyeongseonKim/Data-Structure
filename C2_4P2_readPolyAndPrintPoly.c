#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 100 /* 배열 terms의 크기 */

typedef struct {
    float coef;
    int expon;
} polynomial;
polynomial terms[MAX_TERMS];
int avail = 0;

void readPoly(polynomial terms[], int* n);
void printPoly(polynomial terms[], int n);

int main(void) {

    int n = 0;

    readPoly(terms, &n);
    printPoly(terms, n);
}

void readPoly(polynomial terms[], int* n)
{ /* read in a polynomial */
    int i, expon;
    float coef;
    printf("Enter the number of terms in your polynomial: ");
    scanf_s("%d", n);

    while (*n >= MAX_TERMS)
    {
        printf("Too many terms in the polynomial\n");
        printf("Number of terms: ");
        scanf_s("%d", n);
    }

    for (i = 0; i < *n; i++)
    {
        printf("Coefficient: ");
        scanf_s("%f", &coef);
        printf("Exponent: ");
        scanf_s("%d", &expon);
        terms[i].coef = coef;
        terms[i].expon = expon;
    }
}

void printPoly(polynomial terms[], int n)
{ /*print the polynomial*/
    int i;
    for (i = 0; i < n - 1; i++)
        printf("%5.2fx^%d+", terms[i].coef, terms[i].expon);
    printf("%5.2fx^%d\n", terms[i].coef, terms[i].expon);
}
