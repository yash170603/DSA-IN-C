#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

struct Stack {
    char items[MAX_SIZE];
    int top;
};

void initializeStack(struct Stack *stack) {
    stack->top = -1;
}

int isEmpty(struct Stack *stack) {
    return (stack->top == -1);
}

int isFull(struct Stack *stack) {
    return (stack->top == MAX_SIZE - 1);
}

void push(struct Stack *stack, char value) {
    if (isFull(stack)) {
        printf("Stack overflow, cannot push %c\n", value);
    } else {
        stack->top++;
        stack->items[stack->top] = value;
    }
}

char pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow, cannot pop\n");
        return -1; // Return a value indicating an error or an empty stack
    } else {
        char popped = stack->items[stack->top];
        stack->top--;
        return popped;
    }
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    return 0;
}

void infixToPostfix(char *infix, char *postfix) {
    struct Stack stack;
    initializeStack(&stack);

    int i, j;
    i = j = 0;

    while (infix[i] != '\0') {
        char token = infix[i];

        if (isdigit(token) || isalpha(token)) {
            postfix[j++] = token;
        } else if (token == '(') {
            push(&stack, token);
        } else if (token == ')') {
            while (!isEmpty(&stack) && stack.items[stack.top] != '(') {
                postfix[j++] = pop(&stack);
            }
            if (!isEmpty(&stack) && stack.items[stack.top] == '(') {
                pop(&stack); // Discard the '('
            } else {
                printf("Invalid expression\n");
                return;
            }
        } else { // Operator
            while (!isEmpty(&stack) && precedence(token) <= precedence(stack.items[stack.top])) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, token);
        }
        i++;
    }

    while (!isEmpty(&stack)) {
        if (stack.items[stack.top] == '(') {
            printf("Invalid expression\n");
            return;
        }
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    fgets(infix, MAX_SIZE, stdin);
    infix[strlen(infix) - 1] = '\0'; // Remove newline character

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
