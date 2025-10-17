/*
Perform the respective operations on Circular Linked Queue

26/09/2025
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node node;

node* rear = NULL;

void enqueue(int value) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Queue overflow.\n");
        return;
    }
    newNode->data = value;

    if (rear == NULL) { 
        rear = newNode;
        rear->next = rear; 
    } else {
        newNode->next = rear->next; 
        rear->next = newNode;       
        rear = newNode;             
    }
    printf("%d enqueued to queue.\n", value);
}

void dequeue() {
    if (rear == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    node* front = rear->next; 
    int dequeuedValue = front->data;

    if (rear == front) { 
        rear = NULL;
    } else {
        rear->next = front->next; 
    }
    free(front);
    printf("%d dequeued from queue.\n", dequeuedValue);
}

void getFront() {
    if (rear == NULL) {
        printf("Queue is empty. No front element.\n");
        return;
    }
    printf("Front element: %d\n", rear->next->data);
}

void display() {
    if (rear == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    node* current = rear->next; 
    printf("Queue elements: ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != rear->next);
    printf("\n");
}

int menu() {
    int choice;
    printf("\n--- Circular Linked Queue Operations ---\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Get Front Element\n");
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
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                getFront();
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