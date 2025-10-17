/*Program to add two polynomials
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
    struct Term poly1[20], poly2[20], result[20];
    int deg1, deg2, maxDeg;
    int i;

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

    // Determine maximum degree
    maxDeg = (deg1 > deg2) ? deg1 : deg2;

    // Add the two polynomials
    for (i = 0; i <= maxDeg; i++) {
        int c1 = (i <= deg1) ? poly1[i].coeff : 0;
        int c2 = (i <= deg2) ? poly2[i].coeff : 0;
        result[i].coeff = c1 + c2;
        result[i].exp = i;
    }

    // Display result
    printf("\nResultant polynomial after addition:\n");
    for (i = maxDeg; i >= 0; i--) {  // print in descending order
        if (result[i].coeff != 0) {
            printf("%dx^%d", result[i].coeff, result[i].exp);
            if (i != 0)
                printf(" + ");
        }
    }
    printf("\n");

    return 0;
}
