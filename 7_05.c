/* Exercise 7.05: Reads an array of "student number, mark" pairs and sorts
 * according to student number
 * Matt De Bono, June 2015
 * (c) University of Melbourne */

#include <stdio.h>
#include <stdlib.h>

#define MAX_VALS 1000

/* function prototypes */

int read_int_arrays(int stud_nos[], int marks[], int maxvals);
void sort_int_arrays(int stud_nos[], int marks[], int n);
void int_swap(int *p1, int *p2);
void print_int_arrays(int stud_nos[], int marks[], int n);

int
main(int argc, char *argv[]) {
    /* get the input */
    int stud_nos[MAX_VALS], marks[MAX_VALS];
    int n = read_int_arrays(stud_nos, marks, MAX_VALS);

    sort_int_arrays(stud_nos, marks, n);
    print_int_arrays(stud_nos, marks, n);

    return 0;
}

/* reading function with safety for excess values
 * returns the number of pairs successfully read in
 * based on read_int_array in insertionsort.c (pages 102-107 PPSAA) */
int
read_int_arrays(int stud_nos[], int marks[], int maxvals) {
    int n = 0, excess = 0;
    printf("Enter as many as %d \"studnum mark\" pairs, ^D to end\n", maxvals);
    int next_stud, next_mark;
    while (scanf("%d %d", &next_stud, &next_mark) == 2) {
        if (n == maxvals) {
            excess += 1;
        } else {
            stud_nos[n] = next_stud;
            marks[n] = next_mark;
            n += 1;
        }
    }
    printf("%d pairs read into arrays", n);
    if (excess) {
        printf(", %d excess pairs discarded", excess);
    }
    printf("\n");
    return n;
}

/* Insertion sorting both parallel arrays based on student number value only.
 * Note the corresponding mark value are also swapped to keep rows intact.
 * based on sort_int_array in insertionsort.c (pages 102-107 PPSAA) */
void
sort_int_arrays(int stud_nos[], int marks[], int n) {
    /* assume that A[0] to A[n-1] have valid values */
    for (int i = 1; i < n; i++) {
        /* swap A[i] left into correct position,
           the array is in the "correct" position when it is increasing based
           on student number */
        for (int j = i - 1; j >= 0 && stud_nos[j + 1] < stud_nos[j]; j--) {
            int_swap(&stud_nos[j], &stud_nos[j + 1]);
            int_swap(&marks[j], &marks[j + 1]);
        }
    }
}

/* exchange the values of the two variables indicated by the arguments */
void
int_swap(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

/* print output from parallel arrays
 * based on print_int_array in insertionsort.c (pages 102-107 PPSAA) */
void
print_int_arrays(int stud_nos[], int marks[], int n) {
    printf("studnum  mark\n");
    for (int i = 0; i < n; i++) {
        printf("%6d  %3d\n", stud_nos[i], marks[i]);
    }
}
