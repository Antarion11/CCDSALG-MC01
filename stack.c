#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// CREATE
void CREATE(Stack* S, int capacity) {
 S->top = NULL;    // Stack is empty, so top is set to NULL
    S->size = 0;      // Stack size is initially 0
    S->capacity = capacity;  // Initialize the stack's capacity
}



// PUSH
void PUSH(Stack* S, Point elem) {
    // Allocate memory for a new node
    Node* newNode = (Node*) malloc(sizeof(Node));
    
    // Assign the point to the new node
    newNode->data = elem;
    
    // The new node's next will point to the current top
    newNode->next = S->top;
    
    // Update the top pointer to the new node
    S->top = newNode;
    
    // Increment the size of the stack
    S->size++;
}


// ISEMPTY
bool 
ISEMPTY(Stack * S){
	return S->top == NULL; //stack is empty if the top pointer is NULL
}

// ISFULL
bool 
ISFULL(Stack * S){
	return S->size == S->capacity; //stack is full if size equals capacity
}

// POP
Point
POP(Stack *S){
	
	// check for empty stack
	if (ISEMPTY(S)){
		printf("Error: Stack Empty. \n");
		exit(1); // we can figure out how to do better error handling for this
	}
	
	Node* temp = S->top;
	Point popped = temp->data;
	S->top = S->top->next;
	free (temp);
	S->size--;
	
	
	return popped;		
}

// TOP
Point
TOP(Stack *S){

	// check for empty stack
	if (ISEMPTY(S)){
		printf("Error: Stack Empty. \n");
		exit(1);
	}
	
	return S->top->data;
}

// NEXT_TO_TOP
Point
NEXT_TO_TOP(Stack *S){
	    if (S->size < 2) {
        printf("Error: Less than two elements in stack.\n");
        Point empty = {-1, -1};  // Return a default/sentinel value
        return empty;
    }
    return S->top->next->data;
}

