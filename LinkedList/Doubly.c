#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Doubly linked list structure
struct DoublyLinkedList {
    struct Node* head;
    struct Node* tail;
};

// Function to initialize the doubly linked list
void initializeList(struct DoublyLinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
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
    newNode->prev = NULL;
    return newNode;
}

// Function to insert an element at the front of the list
void insertAtFront(struct DoublyLinkedList* list, int data) {
    struct Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
}

// Function to insert an element at the end of the list
void insertAtEnd(struct DoublyLinkedList* list, int data) {
    struct Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        newNode->prev = list->tail;
        list->tail = newNode;
    }
}

// Function to delete an element from the front of the list
void deleteFromFront(struct DoublyLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty, cannot delete from front\n");
    } else {
        struct Node* temp = list->head;
        list->head = list->head->next;
        if (list->head != NULL) {
            list->head->prev = NULL;
        } else {
            list->tail = NULL;
        }
        free(temp);
    }
}

// Function to delete an element from the end of the list
void deleteFromEnd(struct DoublyLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty, cannot delete from end\n");
    } else {
        struct Node* temp = list->tail;
        list->tail = list->tail->prev;
        if (list->tail != NULL) {
            list->tail->next = NULL;
        } else {
            list->head = NULL;
        }
        free(temp);
    }
}

// Function to delete a specific element from the list
void deleteElement(struct DoublyLinkedList* list, int key) {
    if (list->head == NULL) {
        printf("List is empty, cannot delete element\n");
    } else {
        struct Node* current = list->head;
        while (current != NULL && current->data != key) {
            current = current->next;
        }
        if (current == NULL) {
            printf("Element not found in the list\n");
        } else {
            if (current == list->head) {
                deleteFromFront(list);
            } else if (current == list->tail) {
                deleteFromEnd(list);
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                free(current);
            }
        }
    }
}

// Function to display the elements of the list
void displayList(struct DoublyLinkedList* list) {
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
    struct DoublyLinkedList list;
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
