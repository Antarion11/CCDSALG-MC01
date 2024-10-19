#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// CREATE
void
CREATE(Stack* S){

}


//PUSH
void
PUSH(Stack* S, Point elem){
	
}

// ISEMPTY
bool 
ISEMPTY(Stack * S){
	
}

// ISFULL
bool 
ISFULL(Stack * S){
	
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
	
}

