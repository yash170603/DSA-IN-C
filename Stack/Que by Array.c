#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Maximum size of the queue

struct Queue {
    int items[MAX_SIZE];
    int front, rear;
};

// Function to initialize the queue
void initializeQueue(struct Queue *queue) {
    queue->front = -1; // Set front to -1 to indicate an empty queue
    queue->rear = -1; // Set rear to -1 to indicate an empty queue
}

// Function to check if the queue is empty
int isEmpty(struct Queue *queue) {
    return (queue->front == -1);
}

// Function to check if the queue is full
int isFull(struct Queue *queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

// Function to add an element to the queue
void enqueue(struct Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue overflow, cannot enqueue %d\n", value);
    } else {
        if (isEmpty(queue)) {
            queue->front = 0;
        }
        queue->rear = (queue->rear + 1) % MAX_SIZE;
        queue->items[queue->rear] = value;
        printf("Enqueued %d into the queue\n", value);
    }
}

// Function to remove an element from the queue
int dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow, cannot dequeue\n");
        return -1; // Return a value indicating an error or an empty queue
    } else {
        int dequeued = queue->items[queue->front];
        if (queue->front == queue->rear) {
            // Queue is about to become empty after dequeue
            queue->front = -1;
            queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % MAX_SIZE;
        }
        printf("Dequeued %d from the queue\n", dequeued);
        return dequeued;
    }
}

// Function to peek at the front element of the queue without removing it
int peek(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty, cannot peek\n");
        return -1; // Return a value indicating an error or an empty queue
    } else {
        return queue->items[queue->front];
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
