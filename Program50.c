/* Linked list using names - insert, delete, display, sort, reverse, count

26-09-2025 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char name[50];
    struct node* next;
};

typedef struct node node;
node* head = NULL;

void insert(char a[]) {
    node* new_node = (node*)malloc(sizeof(node));
    strcpy(new_node->name, a);
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        node* t = head;
        while (t->next != NULL) {
            t = t->next;
        }
        t->next = new_node;
    }
    printf("Inserted %s into list.\n", a);
}

void delete(char a[]) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    } else if (strcmp(head->name, a) == 0) {
        node* temp = head;
        head = head->next;
        free(temp);
        printf("Deleted %s from list.\n", a);
    } else {
        node* t = head;
        while (t->next != NULL && strcmp(t->next->name, a) != 0) {
            t = t->next;
        }
        if (t->next == NULL) {
            printf("Element not found.\n");
        } else {
            node* temp = t->next;
            t->next = t->next->next;
            free(temp);
            printf("Deleted %s from list.\n", a);
        }
    }
}

void disp() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    node* t = head;
    printf("Linked List: ");
    while (t != NULL) {
        printf("%s -> ", t->name);
        t = t->next;
    }
    printf("NULL\n");
}

int countnodes() {
    int c = 0;
    node* temp = head;
    while (temp != NULL) {
        c++;
        temp = temp->next;
    }
    return c;
}

void sort() {
    if (head == NULL) {
        printf("List is empty, cannot sort.\n");
        return;
    }
    node*i, *j;
    char temp[50];

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (strcmp(i->name, j->name) > 0) {
                strcpy(temp, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, temp);
            }
        }
    }
    printf("List sorted in ascending order.\n");
}

void reverse() {
    if (head == NULL) {
        printf("List is empty, cannot reverse.\n");
        return;
    }

    node* prev = NULL;
    node* current = head;
    node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    printf("List reversed.\n");
}

int choice() {
    int ch;
    printf("\n1.Insert\n2.Delete\n3.Display\n4.Sort\n5.Count\n6.Reverse\n7.Exit\nEnter your choice: ");
    scanf("%d", &ch);
    return ch;
}

void process() {
    int ch;
    char name[50];
    for (ch = choice(); ch != 7; ch = choice()) {
        switch (ch) {
            case 1:
                printf("Enter the name to insert: ");
                scanf("%s", name);
                insert(name);
                break;
            case 2:
                printf("Enter the name to delete: ");
                scanf("%s", name);
                delete(name);
                break;
            case 3:
                disp();
                break;
            case 4:
                sort();
                break;
            case 5:
                printf("Number of nodes: %d\n", countnodes());
                break;
            case 6:
                reverse();
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

int main() {
    process();
    return 0;
}
