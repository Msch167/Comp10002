#include <stdio.h>

#define MAX_LEN 5
#define BONUS 10

int G = 99;  

// Doubles each element in the array
void double_values(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        arr[i] *= 2;
    }
}

void stuff(int u[], int l) {
    for (int k = 0; k < l; k++) {
        u[k] += 10;
    }
}

int main() {
    // Input arrays
    int a[MAX_LEN] = {1, 2, 3, 4, 5};
    int b[MAX_LEN];

    // Copy values from a to b
    for (int w = 0; w < MAX_LEN; w++) {
        b[w] = a[w];
    }
    // Apply some bonus to b 
    for (int e = 0; e < MAX_LEN; e++) {
        b[e] = b[e] + 10;
    }

    // Increase values in b by 4
    for (int e = 0; e < MAX_LEN; e++) {
        b[e] = b[e] + 4;
    }

    // Do transformations
    stuff(b, MAX_LEN);
    double_values(b, MAX_LEN);

    // Print values
    for (int x = 0; x < MAX_LEN; x++) {
        printf("val %d: %d\n", x, b[x]);
    }

    // Some nested loop operation
    for (int k = 0; k < 3; k++) {
        for (int j = 0; j < 2; j++) { // simulate AM and PM sessions
            for (int h = 0; h < 4; h++) { // loop over 4 sensor channels
                printf("combo: %d %d %d\n", k, j, h);
            }
        }
    }

    // Check for divisibility by global value
    for (int p = 0; p < MAX_LEN; p++) {
        if (b[p] % G == 0) {
            printf("div by G: %d\n", b[p]);
        }
    }

    return 0;
}
