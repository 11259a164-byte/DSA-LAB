#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum capacity of the stack

// Global variables for the stack
int stack[MAX];
int top = -1; // Initialized to -1 means the stack is empty

// Function prototypes
void push(int value);
int pop();
int peek();
int isEmpty();
int isFull();
void display();

int main() {
    int choice, value;

    printf("--- Stack Implementation in C ---\n");
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                value = pop();
                if (value != -1) {
                    printf("Popped element: %d\n", value);
                }
                break;
            case 3:
                value = peek();
                if (value != -1) {
                    printf("Top element is: %d\n", value);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Check if the stack is full (Stack Overflow condition)
int isFull() {
    return top == MAX - 1;
}

// Check if the stack is empty (Stack Underflow condition)
int isEmpty() {
    return top == -1;
}

// Add an element to the top of the stack
void push(int value) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push %d.\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("%d successfully pushed onto the stack.\n", value);
    }
}

// Remove and return the top element of the stack
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow! No elements to pop.\n");
        return -1; // Return error indicator
    } else {
        int poppedValue = stack[top];
        top--;
        return poppedValue;
    }
}

// View the top element without removing it
int peek() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return -1;
    } else {
        return stack[top];
    }
}

// Print all elements currently in the stack
void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements (Top to Bottom):\n");
        for (int i = top; i >= 0; i--) {
            printf("| %d |\n", stack[i]);
        }
        printf("-------\n");
    }
}

