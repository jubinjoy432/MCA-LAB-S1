/*
Perform the respective operations on Linked Queue

17/09/2025
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node node;

node* front = NULL;
node* rear = NULL;
void enqueue(int value) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Queue overflow.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL; 

    if (rear == NULL) { 
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued to queue.\n", value);
}

void dequeue() {
    if (front == NULL) { 
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    node* temp = front;
    int dequeuedValue = front->data;
    front = front->next;

    if (front == NULL) { 
        rear = NULL;
    }
    free(temp);
    printf("%d dequeued from queue.\n", dequeuedValue);
}

void getFront() {
    if (front == NULL) {
        printf("Queue is empty. No front element.\n");
        return;
    }
    printf("Front element: %d\n", front->data);
}

void display() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    node* current = front;
    printf("Queue elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int menu() {
    int choice;
    printf("\n--- Linked Queue Operations ---\n");
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
            case 2: dequeue(); break;
            case 3: getFront(); break;
            case 4: display(); break;
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