#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "stack3.h"
#include "sort.h"
#include "graham_scan.h"

int main() {
    // Ask for input and output file names
    char inputFile[100], outputFile[100];
    printf("Enter the input filename: ");
    scanf("%s", inputFile);
    printf("Enter the output filename: ");
    scanf("%s", outputFile);

    // Open the input file
    FILE *input = fopen(inputFile, "r");
    if (!input) {
        fprintf(stderr, "Error: Could not open input file %s\n", inputFile);
        return 1;
    }
    printf("Input file %s opened successfully.\n", inputFile);

    // Read the number of points
    int n;
    fscanf(input, "%d", &n);
    if (n < 3) {
        fprintf(stderr, "Error: Number of points must be at least 3.\n");
        fclose(input);
        return 1;
    }

    // Read points from file
    Point points[n];
    for (int i = 0; i < n; i++) {
        fscanf(input, "%lf %lf", &points[i].x, &points[i].y);
    }
    fclose(input);

    // Measure elapsed time for Graham's Scan with Selection Sort
    clock_t start, end;
    start = clock();  // Start timing

    // Run Graham's Scan using Selection Sort
    Stack hull = grahamScanSelection(points, n);

    end = clock();  // End timing
    double time_taken = ((double)(end - start)) * 1000.0 / CLOCKS_PER_SEC; // Convert to milliseconds
    printf("Elapsed time (Selection Sort): %.2f ms\n", time_taken);

    // Open the output file
    FILE *output = fopen(outputFile, "w");
    if (!output) {
        fprintf(stderr, "Error: Could not open output file %s\n", outputFile);
        return 1;
    }

    // Write the convex hull points to the output file
    fprintf(output, "Convex Hull Points:\n");
    while (!ISEMPTY(&hull)) {
        Point p = POP(&hull);
        fprintf(output, "(%.2f, %.2f)\n", p.x, p.y);
    }
    fclose(output);
    printf("Convex hull written to %s\n", outputFile);

    return 0;
}


