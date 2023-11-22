#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Linked list structure
struct LinkedList {
    struct Node* head;
};

// Function to initialize the linked list
void initializeList(struct LinkedList* list) {
    list->head = NULL;
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert an element at the front of the list
void insertAtFront(struct LinkedList* list, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = list->head;
    list->head = newNode;
}

// Function to insert an element at the end of the list
void insertAtEnd(struct LinkedList* list, int data) {
    struct Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        struct Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to delete an element from the front of the list
void deleteFromFront(struct LinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty, cannot delete from front\n");
    } else {
        struct Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
    }
}

// Function to delete an element from the end of the list
void deleteFromEnd(struct LinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty, cannot delete from end\n");
    } else if (list->head->next == NULL) {
        free(list->head);
        list->head = NULL;
    } else {
        struct Node* current = list->head;
        struct Node* prev = NULL;
        while (current->next != NULL) {
            prev = current;
            current = current->next;
        }
        free(current);
        prev->next = NULL;
    }
}

// Function to delete a specific element from the list
void deleteElement(struct LinkedList* list, int key) {
    if (list->head == NULL) {
        printf("List is empty, cannot delete element\n");
    } else {
        struct Node* current = list->head;
        struct Node* prev = NULL;
        while (current != NULL && current->data != key) {
            prev = current;
            current = current->next;
        }
        if (current == NULL) {
            printf("Element not found in the list\n");
        } else {
            if (prev == NULL) {
                list->head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
        }
    }
}

// Function to display the elements of the list
void displayList(struct LinkedList* list) {
    struct Node* current = list->head;
    if (current == NULL) {
        printf("List is empty\n");
    } else {
        printf("Elements in the list: ");
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    struct LinkedList list;
    initializeList(&list);

    insertAtFront(&list, 10);
    insertAtFront(&list, 20);
    insertAtEnd(&list, 30);
    insertAtEnd(&list, 40);

    printf("Initial list:\n");
    displayList(&list);

    deleteFromFront(&list);
    printf("List after deleting from front:\n");
    displayList(&list);

    deleteFromEnd(&list);
    printf("List after deleting from end:\n");
    displayList(&list);

    deleteElement(&list, 20);
    printf("List after deleting element 20:\n");
    displayList(&list);

    return 0;
}
