/*Program to multiply two polynomials
@Jubin Joy 
Roll No 35 
26/09/2025
*/
#include <stdio.h>

struct Term {
    int coeff;
    int exp;
};

int main() {
    struct Term poly1[20], poly2[20], result[40];
    int deg1, deg2, maxDeg, i, j, k;

    // Input degree of first polynomial
    printf("Enter degree of first polynomial: ");
    scanf("%d", &deg1);
    printf("Enter coefficients for x^0 to x^%d:\n", deg1);
    for (i = 0; i <= deg1; i++) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &poly1[i].coeff);
        poly1[i].exp = i;
    }

    // Input degree of second polynomial
    printf("\nEnter degree of second polynomial: ");
    scanf("%d", &deg2);
    printf("Enter coefficients for x^0 to x^%d:\n", deg2);
    for (i = 0; i <= deg2; i++) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &poly2[i].coeff);
        poly2[i].exp = i;
    }

    // Initialize result
    maxDeg = deg1 + deg2;
    for (i = 0; i <= maxDeg; i++) {
        result[i].coeff = 0;
        result[i].exp = i;
    }

    // Multiply the polynomials
    for (i = 0; i <= deg1; i++) {
        for (j = 0; j <= deg2; j++) {
            k = poly1[i].exp + poly2[j].exp;
            result[k].coeff += poly1[i].coeff * poly2[j].coeff; // combine like terms
        }
    }

    // Display result in descending order
    printf("\nResultant polynomial after multiplication:\n");
    for (i = maxDeg; i >= 0; i--) {
        if (result[i].coeff != 0) {
                if (i != maxDeg && result[i].coeff > 0)
                    printf(" + ");
            printf("%dx^%d", result[i].coeff, result[i].exp);
           
        }
    }
    printf("\n");

    return 0;
}
