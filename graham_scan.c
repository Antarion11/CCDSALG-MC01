#include "graham_scan.h"
#include <stdio.h>

// Graham's Scan using Selection Sort
Stack grahamScanSelection(Point points[], int n) {
    Stack stack;
    CREATE(&stack);                      // Initialize the stack
    Point anchor = findAnchor(points, n); // Find the anchor point
    
    // Sort the points based on polar angle using Selection Sort
    selectionSort(points, n, anchor);

    // Push the first three points onto the stack
    PUSH(&stack, points[0]);
    PUSH(&stack, points[1]);
    PUSH(&stack, points[2]);

    // Process remaining points
    for (int i = 3; i < n; i++) {
        // Remove points from the stack if they do not make a left turn
        while (stack.size >= 2 && crossProduct(NEXT_TO_TOP(&stack), TOP(&stack), points[i]) <= 0) {
            POP(&stack);
        }
        PUSH(&stack, points[i]);
    }

    // Output the convex hull points in the stack
    printf("Convex Hull (Selection Sort):\n");
    while (!ISEMPTY(&stack)) {
        Point p = POP(&stack);
        printf("(%.2f, %.2f)\n", p.x, p.y);
    }
}

// Graham's Scan using Quick Sort
Stack grahamScanQuick(Point points[], int n) {
    Stack stack;
    CREATE(&stack);                      // Initialize the stack
    Point anchor = findAnchor(points, n); // Find the anchor point
    
    // Sort the points based on polar angle using Quick Sort
    quickSort(points, 0, n - 1, anchor);

    // Push the first three points onto the stack
    PUSH(&stack, points[0]);
    PUSH(&stack, points[1]);
    PUSH(&stack, points[2]);

    // Process remaining points
    for (int i = 3; i < n; i++) {
        // Remove points from the stack if they do not make a left turn
        while (stack.size >= 2 && crossProduct(NEXT_TO_TOP(&stack), TOP(&stack), points[i]) <= 0) {
            POP(&stack);
        }
        PUSH(&stack, points[i]);
    }

    // Output the convex hull points in the stack
    printf("Convex Hull (Quick Sort):\n");
    while (!ISEMPTY(&stack)) {
        Point p = POP(&stack);
        printf("(%.2f, %.2f)\n", p.x, p.y);
    }
}
