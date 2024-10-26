#include <stdio.h>
#include <stdlib.h>
#include "stack2.h"

// CREATE: Initialize the stack
void CREATE(Stack* S) {
    S->top = NULL;       // Initially, the stack is empty
    S->size = 0;         // Stack size is 0
}

// PUSH: Push a point onto the stack
void PUSH(Stack* S, Point elem, bool* error) {
    *error = false;  // Reset the error flag
    
    if (ISFULL(S)) {
        fprintf(stderr, "Error: Stack Overflow. Unable to push element.\n");
        *error = true;  // Set error flag for overflow
        return;
    }
    
    // Attempt to allocate memory for a new node
    Node* newNode = (Node*) malloc(sizeof(Node));  
    if (!newNode) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        *error = true;  // Set error flag for memory allocation failure
        return;
    }
    
    newNode->data = elem;     // Set the data
    newNode->next = S->top;   // Link new node to the current top
    S->top = newNode;         // Update the top to the new node
    S->size++;                // Increment the size
}

// POP: Pop the top element from the stack
Point POP(Stack* S, bool* error) {
    *error = false;  // Reset the error flag
    
    if (ISEMPTY(S)) {
        fprintf(stderr, "Error: Stack is empty. Cannot pop element.\n");
        *error = true;  // Set error flag for underflow
        Point emptyPoint = {0, 0};  // Return a default/sentinel value
        return emptyPoint;
    }
    
    Node* temp = S->top;        // Store the current top node
    Point popped = temp->data;  // Store the data to return
    S->top = S->top->next;      // Update the top to the next node
    free(temp);                 // Free the memory of the popped node
    S->size--;                  // Decrement the size
    
    return popped;              // Return the popped element
}

// TOP: Get the top element from the stack
Point TOP(Stack* S, bool* error) {
    *error = false;  // Reset the error flag
    
    if (ISEMPTY(S)) {
        fprintf(stderr, "Error: Stack is empty. Cannot get top element.\n");
        *error = true;  // Set error flag for underflow
        Point emptyPoint = {0, 0};  // Return a default/sentinel value
        return emptyPoint;
    }
    
    return S->top->data;  // Return the data at the top of the stack
}

// NEXT-TO-TOP: Get the element below the top
Point NEXT_TO_TOP(Stack* S, bool* error) {
    *error = false;  // Reset the error flag
    
    if (S->size < 2) {
        fprintf(stderr, "Error: Less than two elements in stack.\n");
        *error = true;  // Set error flag for underflow
        Point emptyPoint = {0, 0};  // Return a default/sentinel value
        return emptyPoint;
    }
    
    return S->top->next->data;  // Return the element below the top
}

// ISEMPTY: Check if the stack is empty
bool ISEMPTY(Stack* S) {
    return S->top == NULL;
}

// ISFULL: Check if the stack is full
bool ISFULL(Stack* S) {
    return S->size == MAX_CAPACITY;
}

