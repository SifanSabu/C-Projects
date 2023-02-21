#include <stdio.h>

int RemoveEvens(int arraySize, int numberArray[], int oddNumberArray[]) {

    int numOdds = 0; // variable to count number of odd elements in the array
    int i;

    for(i=0; i<arraySize; i++){
        if(numberArray[i] % 2 != 0){ // if the element is odd
            oddNumberArray[numOdds] = numberArray[i]; // add it to the odd number array
            numOdds++; // increment the count of odd elements
        }
    }

    return numOdds; // return the count of odd elements
}

int main(void) {

   int i;
   int input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
   int result[20];
   int numberOfOdds;

   numberOfOdds = RemoveEvens(9, input, result);

   for (i = 0; i < numberOfOdds; i++) {
      printf("%d, ", result[i]);
   }
   printf("\n");


   return 0;

}

