#include <stdio.h>
#include <stdlib.h>
#include "stack3.h"

#define MAX_CAPACITY 32768

// global error flag (0 = no error, 1 = error)
int stackErrorFlag = 0;

// default error value for points
const Point ERROR_POINT = {0, 0};

// CREATE: Initializes the stack
void CREATE(Stack* S) {
    S->top = NULL;
    S->size = 0;
    stackErrorFlag = 0;  // Reset error flag
}

// PUSH: Push a point onto the stack
void PUSH(Stack* S, Point elem) {
    stackErrorFlag = 0;  // Reset error flag

    if (ISFULL(S)) {
        fprintf(stderr, "Error: Stack Overflow. Unable to push element.\n");
        stackErrorFlag = 1;  // Set error flag for overflow
        return;
    }

    // Attempt to allocate memory for a new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        stackErrorFlag = 1;  // Set error flag for memory allocation failure
        return;
    }

    newNode->data = elem;     // Set the data
    newNode->next = S->top;   // Link new node to the current top
    S->top = newNode;         // Update the top to the new node
    S->size++;                // Increment the size
}

// POP: Pop the top element from the stack
Point POP(Stack* S) {
    stackErrorFlag = 0;  // Reset error flag

    if (ISEMPTY(S)) {
        fprintf(stderr, "Error: Stack is empty. Cannot pop element.\n");
        stackErrorFlag = 1;  // Set error flag for underflow
        return ERROR_POINT;  // Return a default/sentinel value
    }

    Node* temp = S->top;        // Store the current top node
    Point popped = temp->data;  // Store the data to return
    S->top = S->top->next;      // Update the top to the next node
    free(temp);                 // Free the memory of the popped node
    S->size--;                  // Decrement the size

    return popped;              // Return the popped element
}

// TOP: Get the top element from the stack
Point TOP(Stack* S) {
    stackErrorFlag = 0;  // Reset error flag

    if (ISEMPTY(S)) {
        fprintf(stderr, "Error: Stack is empty. Cannot get top element.\n");
        stackErrorFlag = 1;  // Set error flag for underflow
        return ERROR_POINT;  // Return a default/sentinel value
    }

    return S->top->data;  // Return the data at the top of the stack
}

// NEXT-TO-TOP: Get the element below the top
Point NEXT_TO_TOP(Stack* S) {
    stackErrorFlag = 0;  // Reset error flag

    if (S->size < 2) {
        fprintf(stderr, "Error: Less than two elements in stack.\n");
        stackErrorFlag = 1;  // Set error flag for underflow
        return ERROR_POINT;  // Return a default/sentinel value
    }

    return S->top->next->data;  // Return the element below the top
}

// ISEMPTY: Check if the stack is empty
bool ISEMPTY(const Stack* S) {
    return S->top == NULL;
}

// ISFULL: Check if the stack is full
bool ISFULL(const Stack* S) {
    return S->size == MAX_CAPACITY;
}

