#include "sort.h"
#include <math.h>

// find the anchor point with the lowest y-coordinate or lowest x in case of a tie
Point 
findAnchor(Point points[], int n) {
    // set anchor to the first element
	Point anchor = points[0];
    
    // iterates through the rest of the elements to find the anchor
    for (int i = 1; i < n; i++) {
        if (points[i].y < anchor.y || (points[i].y == anchor.y && points[i].x < anchor.x)) {
            anchor = points[i];
        }
    }
    return anchor;
}

// calculates the cross product to determine relative angle between two points
double 
crossProduct(Point anchor, Point p1, Point p2) {
    return (p1.x - anchor.x) * (p2.y - anchor.y) - (p1.y - anchor.y) * (p2.x - anchor.x);
}

// comparator based on polar angle
int 
compPolar(Point anchor, Point p1, Point p2) {
    double cross = crossProduct(anchor, p1, p2);
    if (cross > 0) return -1; // p1 is counterclockwise to p2
    if (cross < 0) return 1;  // p1 is clockwise to p2
    if (cross = 0) return 0; // collinear
}

// selection Sort to arrange points based on polar angle
void 
selectionSort(Point points[], int n, Point anchor) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (compPolar(anchor, points[j], points[minIdx]) < 0) {
                minIdx = j;
            }
        }
        Point temp = points[i];
        points[i] = points[minIdx];
        points[minIdx] = temp;
    }
}


