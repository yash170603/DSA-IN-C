#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to initialize the queue
void initializeQueue(struct Queue* queue) {
    queue->front = NULL; // Set front to NULL to indicate an empty queue
    queue->rear = NULL; // Set rear to NULL to indicate an empty queue
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
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

// Function to enqueue an element into the queue
void enqueue(struct Queue* queue, int value) {
    struct Node* newNode = createNode(value);
    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("Enqueued %d into the queue\n", value);
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow, cannot dequeue\n");
        return -1; // Return a value indicating an error or an empty queue
    } else {
        struct Node* temp = queue->front;
        int dequeued = temp->data;
        queue->front = queue->front->next;
        if (queue->front == NULL) {
            queue->rear = NULL; // Update rear to NULL when the last element is dequeued
        }
        free(temp);
        printf("Dequeued %d from the queue\n", dequeued);
        return dequeued;
    }
}

// Function to peek at the front element of the queue without removing it
int peek(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty, cannot peek\n");
        return -1; // Return a value indicating an error or an empty queue
    } else {
        return queue->front->data;
    }
}

int main() {
    struct Queue queue;
    initializeQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Front element of the queue: %d\n", peek(&queue));

    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue); // Trying to dequeue from an empty queue

    return 0;
}
