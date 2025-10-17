/*
Perform the respective operations on Doubly Linked List

26/09/2025
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

typedef struct Node node;

node* head = NULL;

void insertAtBeginning(int value) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
    printf("Inserted %d at the beginning.\n", value);
}

void insertAtEnd(int value) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    } else {
        node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
    printf("Inserted %d at the end.\n", value);
}

void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    node* temp = head;
    int deletedValue = temp->data;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    printf("Deleted %d from the beginning.\n", deletedValue);
}

void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    node* temp = head;
    if (temp->next == NULL) {
        head = NULL;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->prev->next = NULL;
    }
    int deletedValue = temp->data;
    free(temp);
    printf("Deleted %d from the end.\n", deletedValue);
}

void displayForward() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    node* current = head;
    printf("List (Forward): NULL <-> ");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void displayBackward() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    printf("List (Backward): NULL <-> ");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}

int menu() {
    int choice;
    printf("\n--- Doubly Linked List Operations ---\n");
    printf("1. Insert at Beginning\n");
    printf("2. Insert at End\n");
    printf("3. Delete from Beginning\n");
    printf("4. Delete from End\n");
    printf("5. Display Forward\n");
    printf("6. Display Backward\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void process() {
    int choice, value;
    do {
        choice = menu();
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3: deleteFromBeginning(); break;
            case 4: deleteFromEnd(); break;
            case 5: displayForward(); break;
            case 6: displayBackward(); break;
            case 7: printf("Exiting program.\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);
}

int main() {
    process();
    return 0;
}