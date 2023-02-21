#include <stdio.h>
#include <stdbool.h>

int i;

bool IsArrayMult10(int inputVals[], int numVals) {
    for (i = 0; i < numVals; i++) {
        if (inputVals[i] % 10 != 0) {
            return false;
        }
    }
    return true;
}

bool IsArrayNoMult10(int inputVals[], int numVals) {
    for (i = 0; i < numVals; i++) {
        if (inputVals[i] % 10 == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int numVals;
    scanf("%d", &numVals);
    
    int inputVals[20];
    for (i = 0; i < numVals; i++) {
        scanf("%d", &inputVals[i]);
    }
    
    bool allMult10 = IsArrayMult10(inputVals, numVals);
    bool noMult10 = IsArrayNoMult10(inputVals, numVals);
    
    if (allMult10) {
        printf("all multiples of 10\n");
    } else if (noMult10) {
        printf("no multiples of 10\n");
    } else {
        printf("mixed values\n");
    }
    
    return 0;
}
