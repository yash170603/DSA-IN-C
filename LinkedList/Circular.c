#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Circular linked list structure
struct CircularLinkedList {
    struct Node* head;
};

// Function to initialize the circular linked list
void initializeList(struct CircularLinkedList* list) {
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
void insertAtFront(struct CircularLinkedList* list, int data) {
    struct Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        newNode->next = newNode; // Circular reference to itself
    } else {
        struct Node* temp = list->head;
        while (temp->next != list->head) {
            temp = temp->next;
        }
        newNode->next = list->head;
        temp->next = newNode;
        list->head = newNode;
    }
}

// Function to remove the first element from the list
void removeFirstElement(struct CircularLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty, cannot remove first element\n");
    } else if (list->head->next == list->head) {
        free(list->head);
        list->head = NULL;
    } else {
        struct Node* temp = list->head;
        while (temp->next != list->head) {
            temp = temp->next;
        }
        struct Node* first = list->head;
        list->head = list->head->next;
        temp->next = list->head;
        free(first);
    }
}



// Function to insert an element at the end of the list
void insertAtEnd(struct CircularLinkedList* list, int data) {
    struct Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        newNode->next = newNode; // Circular reference to itself
    } else {
        struct Node* temp = list->head;
        while (temp->next != list->head) {
            temp = temp->next;
        }
        newNode->next = list->head;
        temp->next = newNode;
    }
}

// Function to delete an element from the front of the list
void deleteFromFront(struct CircularLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty, cannot delete from front\n");
    } else {
        struct Node* temp = list->head;
        if (temp->next == list->head) { // Only one node in the list
            free(temp);
            list->head = NULL;
        } else {
            struct Node* current = list->head;
            while (current->next != list->head) {
                current = current->next;
            }
            list->head = temp->next;
            current->next = list->head;
            free(temp);
        }
    }
}

// Function to delete an element from the end of the list
void deleteFromEnd(struct CircularLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty, cannot delete from end\n");
    } else {
        struct Node* current = list->head;
        struct Node* prev = NULL;
        while (current->next != list->head) {
            prev = current;
            current = current->next;
        }
        if (prev == NULL) { // Only one node in the list
            free(current);
            list->head = NULL;
        } else {
            prev->next = list->head;
            free(current);
        }
    }
}

// Function to delete a specific element from the list
void deleteElement(struct CircularLinkedList* list, int key) {
    if (list->head == NULL) {
        printf("List is empty, cannot delete element\n");
    } else {
        struct Node* current = list->head;
        struct Node* prev = NULL;
        while (current->data != key) {
            if (current->next == list->head) {
                printf("Element not found in the list\n");
                return;
            }
            prev = current;
            current = current->next;
        }
        if (current == list->head) {
            deleteFromFront(list);
        } else {
            prev->next = current->next;
            free(current);
        }
    }
}

// Function to display the elements of the list
void displayList(struct CircularLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
    } else {
        struct Node* temp = list->head;
        printf("Elements in the list: ");
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != list->head);
        printf("\n");
    }
}

int main() {
    struct CircularLinkedList list;
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

    deleteElement(&list,
