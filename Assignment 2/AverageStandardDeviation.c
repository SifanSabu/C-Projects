#include <math.h>
#include <stdio.h>

#define LENGTH 10
int main(void) {

	double array[LENGTH];
	int i = 0;
	double input = 0.0;

	double sum = 0.0;
	double average = 0.0;

	double standardDev = 0.0;

	for(i = 0; i < LENGTH; ++i) {  // for loop gets input values and stores in array
		scanf("%lf", &input);
		array[i] = input;
		sum += input;
	}
	average = sum / LENGTH;  // averages all input values
	printf("average: %0.2lf\n", average);

	for(i = 0; i < LENGTH; ++i) {  // traverses array, calculates sum of difference of squares
		standardDev += pow((array[i] - average), 2);
	}
	standardDev = sqrt(standardDev / 10);  // calculates standard deviation
	printf("standard deviation: %0.2lf\n", standardDev);

	return 0;
}
