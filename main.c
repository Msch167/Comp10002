#include <stdio.h>

int main() {
    double degF;
    printf("Enter a temperature in Fahrenheit: ");
    int result = scanf("%lf", &degF);
    if(result == 1) {
        printf("You entered b: %lf\n", degF);
    } else {
        printf("Failed to read input\n");
    }
    printf("Hello, World!\n");
    return 0;
}
