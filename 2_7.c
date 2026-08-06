#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    double degF, degC;

    // get input value
    printf("Enter degrees F: ");
    if (scanf("%lf", &degF) != 1){ 
        printf("Error in input\n";
        exit(EXIT_FAILURE);
    }
    // look for a double (lf) and save it to the variable degF

    // do the conversion
    degC = (degF - 32.0) * 5.0/9.0; // integer division!!!!!

    // print output
    printf("In degrees C is: %.1f\n", degC);
    return 0;
}
