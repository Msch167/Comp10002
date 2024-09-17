/* Exercise 8.03: Polygons and perimeters
 * Alistair Moffat, May 2014
 * Liam Saliba, December 2021
 * (c) University of Melbourne */

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* two-d points */
typedef struct {
    double x;
    double y;
} vector_t;

/* polygons */
#define MAXPTS 100
#define MINPTS 3
typedef struct {
    vector_t pts[MAXPTS]; // struct in struct
    int npts; /* the buddy variable */
} poly_t;

/* function prototypes */
double distance(vector_t, vector_t);
double perimeter(poly_t P);
int read_vector(vector_t *pt);
poly_t read_poly();

## zusammen machen

int
main(int argc, char *argv[]) {
    printf("Enter (%d-%d) points counter-clockwise:\n", MINPTS, MAXPTS);
    poly_t testP = read_poly();
    printf("Perimeter is %.4f\n", perimeter(testP));

    return 0;
}

/* compute the perimeter (sum of all lengths of edges) of a polygon */
double
perimeter(poly_t P) {
    ...
    return perim;
}

/* reuse the function we've already written! */
/* return the Euclidean distance between the given vectors (ex8-02 soln.) */
double
distance(vector_t p1, vector_t p2) {
    double deltax = p1.x - p2.x;
    double deltay = p1.y - p2.y;
    return sqrt(deltax * deltax + deltay * deltay);
}

/* functions to read in polygon */

// reads in a point from input and returns 1 if successful
int
read_vector(vector_t *pt) {
    ...
}

// reads in a polygon from input and returns 1 if successful
poly_t
read_poly() {
    poly_t poly;
    poly.npts = 0;
    // read in points until EOF is read.
    ...
    return poly;
}
