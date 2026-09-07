#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum capacity of the stack

int stack[MAX];
int top = -1; // Initializing top to -1 indicates the stack is empty

// Function prototypes
void push();
void pop();
void display();

int main() {
    int choice;

    while (1) {
        printf("\n*** STACK OPERATIONS ***\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        // Switch case handles user operations based on input
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0); // Terminates the program
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    }
    return 0;
}

// Function to add an element to the stack
void push() {
    int value;
    
    // Check for Stack Overflow
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push more elements.\n");
    } else {
        printf("Enter the value to push: ");
        scanf("%d", &value);
        top++;                // Increment top index
        stack[top] = value;   // Insert element at the top
        printf("%d pushed onto the stack.\n", value);
    }
}

// Function to remove an element from the stack
void pop() {
    // Check for Stack Underflow
    if (top == -1) {
        printf("Stack Underflow! The stack is empty.\n");
    } else {
        printf("Popped element: %d\n", stack[top]);
        top--; // Decrement top index to remove the element
    }
}

// Function to print all elements in the stack
void display() {
    if (top == -1) {
        printf("The stack is empty.\n");
    } else {
        printf("Stack elements (from top to bottom):\n");
        for (int i = top; i >= 0; i--) {
            printf("| %d |\n", stack[i]);
        }
        printf("-----\n");
    }
}


