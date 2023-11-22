#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Maximum size of the stack

struct Stack {
    int items[MAX_SIZE];
    int top;
};

// Function to initialize the stack
void initializeStack(struct Stack *stack) {
    stack->top = -1; // Set top to -1 to indicate an empty stack
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return (stack->top == -1);
}

// Function to check if the stack is full
int isFull(struct Stack *stack) {
    return (stack->top == MAX_SIZE - 1);
}

// Function to push an element onto the stack
void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow, cannot push %d\n", value);
    } else {
        stack->top++;
        stack->items[stack->top] = value;
        printf("Pushed %d onto the stack\n", value);
    }
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow, cannot pop\n");
        return -1; // Return a value indicating an error or an empty stack
    } else {
        int popped = stack->items[stack->top];
        stack->top--;
        printf("Popped %d from the stack\n", popped);
        return popped;
    }
}

// Function to peek at the top element of the stack without removing it
int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty, cannot peek\n");
        return -1; // Return a value indicating an error or an empty stack
    } else {
        return stack->items[stack->top];
    }
}

int main() {
    struct Stack stack;
    initializeStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element of the stack: %d\n", peek(&stack));

    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack); // Trying to pop from an empty stack

    return 0;
}
