#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

// stores x & y coordinates
typedef struct {
	double x;
	double y;
} Point;

// defines a node for linked list
typedef struct Node{
	Point data;
	struct  Node* next;
} Node;

// stack structure
typedef struct {
	Node* top; // pointer to the top of the stack
	int size; // size of stack
	int capacity; // max size of the stack
} Stack;

// stack operations (feel free to edit)
void CREATE(Stack* S, int capacity);
void PUSH(Stack* S, Point elem);
bool ISFULL(Stack* S);
bool ISEMPTY(Stack* S);
Point POP(Stack* S);
Point TOP(Stack* S);
Point NEXT_TO_TOP(Stack* S);

#endif
