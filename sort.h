#ifndef SORT_H
#define SORT_H

#include "stack3.h" // for point struct
#include <stdbool.h>

// finds anchor point (coordinate w lowest y value or x value when tied)
Point findAnchor(Point points[], int n);

// calculates cross product between vectors (anchor -> p1) and (anchor -> p2)
double crossProduct(Point anchor, Point p1, Point p2);

// determines order of points based on polar angle
int compPolar(Point anchor, Point p1, Point p2);

// selection sort function that sorts points based on polar angle relative to the anchor
void selectionSort(Point points[], int n, Point anchor);

// insert quick sort functions


#endif 

