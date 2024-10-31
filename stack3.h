#ifndef STACK2_H
#define STACK2_H

#include <stdbool.h>

// Define structure for a point in 2D space (x, y)
typedef struct {
    double x;
    double y;
} Point;

// Define a node for the linked list
typedef struct Node {
    Point data;         // The data (a point in 2D space)
    struct Node* next;  // Pointer to the next node
} Node;

// Define the stack structure
typedef struct {
    Node* top;  // Pointer to the top of the stack
    int size;   // Size of the stack (number of elements)
} Stack;

// Global error flag
extern int stackErrorFlag;

// Function declarations
void CREATE(Stack* S);
void PUSH(Stack* S, Point elem);
Point POP(Stack* S);
Point TOP(Stack* S);
Point NEXT_TO_TOP(Stack* S);
bool ISEMPTY(const Stack* S);
bool ISFULL(const Stack* S);

#endif

