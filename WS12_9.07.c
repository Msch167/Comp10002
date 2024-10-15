/* Exercise 9.07: Maximum subset sum problem
 * Approach 2: Kadane's Algorithm
 * Kancelot To, May 2015
 * Alireza Ostovar, October 2020  (Kadane Solution)
 * (c) University of Melbourne */

#include <stdio.h>
#include <stdlib.h>
#include "arrayops.h"
/* maximum number of elements that can be stored in the array */
#define MAXVALS 1000

/* function prototypes */

int max_subarray(int[], int, int *, int *);

int
main(int argc, char *argv[]) {
    /* get the input */
    int A[MAXVALS];
    int n = read_int_array(A, MAXVALS);

    /* print the whole array */
    printf("original array:\n");
    print_int_array(A, n);

    int from, to;
    int sum = max_subarray(A, n, &from, &to);

    /* print the result */
    printf("maximum subarray:\n");
    print_int_array(A + from,
                    to - from + 1);   /* print A[from]..A[to] (inclusive) */
    printf("sum = %d\n", sum);

    return 0;
}

/* compute the maximum subarray sum of A with n elements
 * Uses Kadane's algorithm to work in O(n) time instead of brute force's O(n^2)
 *
 * returns the maximum subarray sum, stores the indices for where the
 * maximum subarray starts (from) and ends (to).
 * Note: both A[from] and A[to] are included in the maximum subarray
 */
int
max_subarray(int A[], int n, int *from, int *to) {
    
    if (n <= 0) {   /* base case: empty array sums to 0 */
        return 0;
    }

    int max_sum = 0;

    int sum = 0; /* the sum of A[i] .. A[j], inclusive */

  
    ...
      
      
    return max_sum;
}

/* Kadane's key observation: any subarray with negative value cannot
 *                           contribute to the maximum sum.
 *
 * Consider the array:      {1, -6, 4, -1, 5, -6, 4}.
 *
 * Starting from i=0, adding -6 is useless, as we already have a negative
 * value.  The sum of the empty array {} is 0, so we can take that instead.
 * To start summing again, we can start with 4.  Each subsequent value
 * adds value to the sum, so we include it.
 * Overall, we get the (maximum) subarray {4, -1, 5, -6, 4}, with sum 6.
 * There is no need to check the subarrays {-1, ...}, {5, ...}, etc as
 * we know that their sums must be smaller -- otherwise at some point we would
 * have a negative sum. */
