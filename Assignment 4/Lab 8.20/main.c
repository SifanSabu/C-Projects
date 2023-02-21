#include <stdio.h>
#include "functions.h"

int main() {
    int arr[LENGTH];
    int i;

    // Read in array values
    for (i = 0; i < LENGTH; i++) {
        printf("Enter value %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    // Read in a, b, and c values
    double a, b, c, x1, x2;
    printf("Enter a, b, and c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    // Compute average of array
    double avg = average(arr);

    // Compute quadratic formula
    quadraticFormula(a, b, c, &x1, &x2);

    // Print results
    printf("average: %.2lf\n", avg);
    printf("x1: %.2lf\n", x1);
    printf("x2: %.2lf\n", x2);

    return 0;
}
