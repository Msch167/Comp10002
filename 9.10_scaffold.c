#include <math.h>
#include <stdio.h>

#define MAXSIZE 100

int subsetsum(int[], int, int);
int read_int_array(int[], int);

int
main(int argc, char *argv[]) {
    int numbers[MAXSIZE];
    int size = read_int_array(numbers, MAXSIZE);
    printf("Enter required subset sum:\n");
    int k;
    scanf("%d", &k);
    if (subsetsum(numbers, size, k) == 1) {
        printf("There is a subset summing to %d\n", k);
    } else {
        printf("There is no subset summing to %d\n", k);
    }
    return 0;
}

/* An iterative approach to the subset sum problem. This simulates bitmasks
 * by using integer division.
 */
int
subsetsum(int A[], int n, int k) {
    for (int i = 0; i < (int) pow(2.0, (double) n); i++) {
        ...
        for (int j = 0; j < n; j++) {
            if ((i / (int) pow(2.0, (double) j)) % 2 == 1) {
                ...
            }
        }
        if (...) {
            return 1;
        }
    }
    return 0;
}

int
read_int_array(int A[], int maxvals) {
    int n = 0, excess = 0, next;

    printf("Enter as many as %d values:\n", maxvals);

    while (scanf("%d", &next) == 1) {
        if (n == maxvals) {
            excess++;
        } else {
            A[n] = next;
            n++;
        }
    }
    return n;
}
