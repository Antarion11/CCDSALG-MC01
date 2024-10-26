#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

// Define a fixed maximum capacity for the stack
#define MAX_CAPACITY 32768

// Point structure to store x and y coordinates
typedef struct {
    double x;
    double y;
} Point;

// Node structure for linked list stack
typedef struct Node {
    Point data;
    struct Node* next;
} Node;

// Stack structure
typedef struct {
    Node* top;      // Pointer to the top of the stack
    int size;       // Current size of the stack
} Stack;

// Stack operations
void CREATE(Stack* S);
void PUSH(Stack* S, Point elem, bool* error);
Point POP(Stack* S, bool* error);
Point TOP(Stack* S, bool* error);
Point NEXT_TO_TOP(Stack* S, bool* error);
bool ISFULL(Stack* S);
bool ISEMPTY(Stack* S);

#endif

