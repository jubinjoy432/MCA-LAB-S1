/*Program to convert an expression from infix expression to postfix using stack

26-09-2025
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    float coeff;
    int exp;
    struct Node* next;
};

struct Node* createNode(float coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void insertTerm(struct Node** poly, float coeff, int exp) {
    if (coeff == 0.0f) {
        return;
    }

    struct Node* newNode = createNode(coeff, exp);
    struct Node* current = *poly;
    struct Node* prev = NULL;

    if (*poly == NULL || exp > (*poly)->exp) {
        newNode->next = *poly;
        *poly = newNode;
        return;
    }

    while (current != NULL && exp < current->exp) {
        prev = current;
        current = current->next;
    }

    if (current != NULL && exp == current->exp) {
        current->coeff += coeff;
        free(newNode);
        if (current->coeff == 0.0f) {
            if (prev == NULL) {
                *poly = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
        }
    } else {
        newNode->next = current;
        if (prev != NULL) {
            prev->next = newNode;
        } else {
            *poly = newNode;
        }
    }
}

void display(struct Node* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }

    struct Node* temp = poly;
    while (temp != NULL) {
        printf("%.1fx^%d", temp->coeff, temp->exp);
        temp = temp->next;
        if (temp != NULL) {
            if (temp->coeff > 0) {
                printf(" + ");
            } else {
                 printf(" ");
            }
        }
    }
    printf("\n");
}

struct Node* add(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node* p1 = poly1;
    struct Node* p2 = poly2;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exp > p2->exp) {
            insertTerm(&result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p2->exp > p1->exp) {
            insertTerm(&result, p2->coeff, p2->exp);
            p2 = p2->next;
        } else { // Exponents are equal
            insertTerm(&result, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        insertTerm(&result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        insertTerm(&result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

struct Node* multiply(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node* p1 = poly1;

    if (poly1 == NULL || poly2 == NULL) {
        return NULL;
    }

    while (p1 != NULL) {
        struct Node* p2 = poly2;
        while (p2 != NULL) {
            float newCoeff = p1->coeff * p2->coeff;
            int newExp = p1->exp + p2->exp;
            insertTerm(&result, newCoeff, newExp);
            p2 = p2->next;
        }
        p1 = p1->next;
    }

    return result;
}

void freePolynomial(struct Node** poly) {
    struct Node* current = *poly;
    struct Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    *poly = NULL;
}

void readPolynomial(struct Node** poly, int polyNum) {
    int numTerms, i;
    float coeff;
    int exp;

    printf("Enter the number of terms for Polynomial %d: ", polyNum);
    scanf("%d", &numTerms);

    printf("Enter terms for Polynomial %d (coefficient exponent):\n", polyNum);
    for (i = 0; i < numTerms; i++) {
        printf("Term %d: ", i + 1);
        if (scanf("%f %d", &coeff, &exp) != 2) {
            printf("Invalid input. Please enter a float for coefficient and an integer for exponent.\n");
            while (getchar() != '\n');
            i--;
            continue;
        }
        insertTerm(poly, coeff, exp);
    }
}

void runPolynomialCalculator() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* sum = NULL;
    struct Node* product = NULL;

    printf("--- Polynomial Calculator ---\n\n");

    printf("--- Enter First Polynomial ---\n");
    readPolynomial(&poly1, 1);
    printf("Polynomial 1: ");
    display(poly1);
    printf("\n");

    printf("--- Enter Second Polynomial ---\n");
    readPolynomial(&poly2, 2);
    printf("Polynomial 2: ");
    display(poly2);
    printf("\n");

    printf("--- Results ---\n");
    sum = add(poly1, poly2);
    printf("Sum: ");
    display(sum);

    product = multiply(poly1, poly2);
    printf("Product: ");
    display(product);
    
}

int main() {
    runPolynomialCalculator();
    return 0;
}