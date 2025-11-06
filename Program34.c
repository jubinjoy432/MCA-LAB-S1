/*
Define a structure for employees (eno, ename, esal, dno). Read n employees and write functions to search by number, sort by name/salary, and delete an employee.
@Jubin Joy
Roll no: 35
Date:27-09-2025
*/


#include <stdio.h>
#include <string.h>

struct Employee {
    int eno;
    char ename[50];
    float esal;
    int dno;
};

void readEmployees(struct Employee e[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("\nEnter details of Employee %d:\n", i + 1);
        printf("Employee No: ");
        scanf("%d", &e[i].eno);
        printf("Name: ");
        scanf("%s", e[i].ename);
        printf("Salary: ");
        scanf("%f", &e[i].esal);
        printf("Dept No: ");
        scanf("%d", &e[i].dno);
    }
}

void displayEmployees(struct Employee e[], int n) {
    int i;
    printf("\n%-10s %-15s %-10s %-10s\n", "Eno", "Ename", "Salary", "Dno");
    for (i = 0; i < n; i++) {
        printf("%-10d %-15s %-10.2f %-10d\n", e[i].eno, e[i].ename, e[i].esal, e[i].dno);
    }
}

// a. Search employee by number
void searchByNo(struct Employee e[], int n, int eno) {
    int i, found = 0;
    for (i = 0; i < n; i++) {
        if (e[i].eno == eno) {
            printf("\nEmployee Found:\n");
            printf("%-10d %-15s %-10.2f %-10d\n", e[i].eno, e[i].ename, e[i].esal, e[i].dno);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("\nEmployee not found!\n");
}

// b1. Sort employees by name
void sortByName(struct Employee e[], int n) {
    int i, j;
    struct Employee temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(e[i].ename, e[j].ename) > 0) {
                temp = e[i];
                e[i] = e[j];
                e[j] = temp;
            }
        }
    }
    printf("\nEmployees sorted by name:\n");
    displayEmployees(e, n);
}

// b2. Sort employees by salary
void sortBySalary(struct Employee e[], int n) {
    int i, j;
    struct Employee temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (e[i].esal > e[j].esal) {
                temp = e[i];
                e[i] = e[j];
                e[j] = temp;
            }
        }
    }
    printf("\nEmployees sorted by salary:\n");
    displayEmployees(e, n);
}

// c. Delete employee by number
int deleteEmployee(struct Employee e[], int n, int eno) {
    int i, pos = -1;
    for (i = 0; i < n; i++) {
        if (e[i].eno == eno) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        printf("\nEmployee not found!\n");
        return n;
    } else {
        for (i = pos; i < n - 1; i++) {
            e[i] = e[i + 1];
        }
        printf("\nEmployee %d deleted successfully!\n", eno);
        return n - 1;
    }
}

int main() {
    struct Employee e[50];
    int n, choice, eno;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    readEmployees(e, n);

    do {
        printf("\n--- Employee Menu ---\n");
        printf("1. Display Employees\n2. Search by Employee No\n3. Sort by Name\n4. Sort by Salary\n5. Delete Employee\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayEmployees(e, n);
                break;
            case 2:
                printf("Enter Employee No to search: ");
                scanf("%d", &eno);
                searchByNo(e, n, eno);
                break;
            case 3:
                sortByName(e, n);
                break;
            case 4:
                sortBySalary(e, n);
                break;
            case 5:
                printf("Enter Employee No to delete: ");
                scanf("%d", &eno);
                n = deleteEmployee(e, n, eno);
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}

