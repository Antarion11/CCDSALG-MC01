#ifndef STACK_H
#define STACK_h

#include <stdbool.h>

// stores x & y coordinates
typedef struct {
	double x;
	double y;
}Point;

// defines a node for linked list
typedef struct Node{
	Point data;
	struct  Node* next;
}Node;

// stack structure
typedef struct {
	Node* top; // pointer to the top of the stack
	int size; // size of stack
}Stack;

// stack operations (feel free to edit)
void CREATE(Stack* S);
void PUSH(Stack* S, Point elem);
bool ISFULL(Stack* S);
bool ISEMPTY(Stack* S);
Point POP(Stack* S);
Point TOP(Stack* S);
Point NEXT_TO_TOP(Stack* S);

#endif
