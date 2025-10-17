/*
Perform the respective operations on Circular doubly linked list - store string values as data part

26/09/2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data[50];
    struct Node* prev;
    struct Node* next;
};

typedef struct Node node;

node* head = NULL;

void insertAtBeginning(const char* value) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    strcpy(newNode->data, value);

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
    } else {
        node* tail = head->prev;
        newNode->next = head;
        head->prev = newNode;
        newNode->prev = tail;
        tail->next = newNode;
        head = newNode;
    }
    printf("Inserted \"%s\" at the beginning.\n", value);
}

void insertAtEnd(const char* value) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    strcpy(newNode->data, value);

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
    } else {
        node* tail = head->prev;
        newNode->next = head;
        head->prev = newNode;
        tail->next = newNode;
        newNode->prev = tail;
    }
    printf("Inserted \"%s\" at the end.\n", value);
}

void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    char deletedValue[50];
    strcpy(deletedValue, head->data);
    node* temp = head;

    if (head->next == head) {
        head = NULL;
    } else {
        node* tail = head->prev;
        head = head->next;
        head->prev = tail;
        tail->next = head;
    }
    free(temp);
    printf("Deleted \"%s\" from the beginning.\n", deletedValue);
}

void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    node* tail = head->prev;
    char deletedValue[50];
    strcpy(deletedValue, tail->data);

    if (head->next == head) {
        head = NULL;
    } else {
        node* newTail = tail->prev;
        newTail->next = head;
        head->prev = newTail;
    }
    free(tail);
    printf("Deleted \"%s\" from the end.\n", deletedValue);
}

void displayForward() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    node* current = head;
    printf("List (Forward): ... <-> ");
    do {
        printf("%s <-> ", current->data);
        current = current->next;
    } while (current != head);
    printf("...\n");
}

void displayBackward() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    node* current = head->prev;
    printf("List (Backward): ... <-> ");
    do {
        printf("%s <-> ", current->data);
        current = current->prev;
    } while (current != head->prev);
    printf("...\n");
}

int menu() {
    int choice;
    printf("\n--- Circular Doubly Linked List (String) ---\n");
    printf("1. Insert at Beginning\n");
    printf("2. Insert at End\n");
    printf("3. Delete from Beginning\n");
    printf("4. Delete from End\n");
    printf("5. Display Forward\n");
    printf("6. Display Backward\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    while (getchar() != '\n');
    return choice;
}

void process() {
    int choice;
    char value[50];
    do {
        choice = menu();
        switch (choice) {
            case 1:
                printf("Enter string to insert: ");
                scanf("%49s", value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter string to insert: ");
                scanf("%49s", value);
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