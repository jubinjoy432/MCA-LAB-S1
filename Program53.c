/*
Perform the respective operations on Circular Linked List

26/09/2025
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node node;

node* tail = NULL;

void insertAtBeginning(int value) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;

    if (tail == NULL) { 
        tail = newNode;
        tail->next = tail; 
    } else {
        newNode->next = tail->next; 
        tail->next = newNode;     
    }
    printf("Inserted %d at the beginning.\n", value);
}

void insertAtEnd(int value) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;

    if (tail == NULL) { 
        tail = newNode;
        tail->next = tail;
    } else {
        newNode->next = tail->next; 
        tail->next = newNode;     
        tail = newNode;           
    }
    printf("Inserted %d at the end.\n", value);
}

void deleteFromBeginning() {
    if (tail == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    node* temp = tail->next; 
    int deletedValue = temp->data;

    if (tail->next == tail) { 
        tail = NULL;
    } else {
        tail->next = temp->next; 
    }
    free(temp);
    printf("Deleted %d from the beginning.\n", deletedValue);
}

void display() {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }

    node* current = tail->next; 
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != tail->next);
    printf(" (Head: %d)\n", tail->next->data);
}

int menu() {
    int choice;
    printf("\n--- Circular Linked List Operations ---\n");
    printf("1. Insert at Beginning\n");
    printf("2. Insert at End\n");
    printf("3. Delete from Beginning\n");
    printf("4. Display\n");
    printf("5. Exit\n");
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
            case 3:
                deleteFromBeginning();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
}


int main() {
    process();
    return 0;
}