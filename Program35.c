/*Program to read a polynomial and display it using structure array
@Jubin Joy 
Roll No 35 
26/09/2025
*/
#include <stdio.h>

// Structure to represent a term in the polynomial
struct Term {
    int coeff;
    int exp;
};

int main() {
    struct Term poly[20];
    int deg, i;

    // Ask for the degree of the polynomial
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &deg);

    // Input coefficients for each term (ascending order)
    printf("Enter coefficients for x^0 to x^%d:\n", deg);
    for (i = 0; i <= deg; i++) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &poly[i].coeff);
        poly[i].exp = i;  // exponent = index
    }

    // Display polynomial in standard (descending) order
    printf("\nThe polynomial is:\n");
    for (i = deg; i >= 0; i--) {
        if (poly[i].coeff != 0) {
            printf("%dx^%d", poly[i].coeff, poly[i].exp);
            if (i != 0)
                printf(" + ");
        }
    }
    printf("\n");

    return 0;
}
