#include "functions.h"
#include <math.h>

double average(int arr[]) {
    int sum = 0;
    int i;
    for (i = 0; i < LENGTH; i++) {
        sum += arr[i];
    }
    return (double) sum / LENGTH;
}

void quadraticFormula(double a, double b, double c, double *x1, double *x2) {
    double d = b * b - 4 * a * c;
    *x1 = (-b + sqrt(d)) / (2 * a);
    *x2 = (-b - sqrt(d)) / (2 * a);
}

