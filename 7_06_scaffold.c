#include <stdio.h>
#include "arrayops.h"

// Maximum size of numbers array
#define MAXVALS 1000

/* function prototypes */

int index_of_largest(int[], int);
void selection_sort(int[], int);

int
main(int argc, char *argv[]) {
    /* get the input */
    int numbers[MAXVALS];
    int valid = read_int_array(numbers, MAXVALS);

    printf("Before: ");
    print_int_array(numbers, valid);
    selection_sort(numbers, valid);

    printf("After : ");
    print_int_array(numbers, valid);

    return 0;
}

/* returns index of largest value in the supplied array * another name for this function is argmax 
 * iterative version */
int
index_of_largest(int A[], int n) {
    ...
    return big;
}

/* implements selection sort by repeatedly swapping the next largest item in the array into the last position of a
   decreasing array segment iterative version */
void
selection_sort(int A[], int n) {
    ...
}
