#include <stdio.h>
#include <stdlib.h>

int main() {
    int size, sum = 0;
    float average;
    int *myData;
    int i;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Dynamically allocate memory for the array
    myData = (int*) malloc(size * sizeof(int));

    // Initialize the array member values
    for(i=0; i<size; i++) {
        *(myData + i) = i;
    }

    // Print the array contents
    printf("Array contents: ");
    for(i=0; i<size; i++) {
        printf("%d ", *(myData + i));
        sum += *(myData + i);
    }

    // Calculate and print the average
    average = (float) sum / size;
    printf("\nAverage: %.2f\n", average);

    // Free the dynamically allocated memory
    free(myData);

    return 0;
}
