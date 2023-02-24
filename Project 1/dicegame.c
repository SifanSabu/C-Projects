#include <stdio.h>
#include <stdlib.h>
#include "dicegame.h"

int getRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

ROUNDTYPE getRoundType() {
    int randomValue = getRandomNumber(0, 9);
    if (randomValue < 2) {
        return BONUS;
    } else if (randomValue < 5) {
        return DOUBLE;
    } else {
        return REGULAR;
    }
}

int getRoundPoints(ROUNDTYPE roundType) {
    int points;
    switch (roundType) {
        case BONUS:
            points = 200;
            break;
        case DOUBLE:
            points = 10 * getRandomNumber(1, 10);
            points *= 2;
            break;
        case REGULAR:
            points = 10 * getRandomNumber(1, 10);
            break;
    }
    return points;
}

void printPlayerPoints(int p1, int p2) {
    printf("P1      : %d\n", p1);
    printf("P2      : %d\n", p2);
}

void printRoundInfo(ROUNDTYPE t, int dice, int points) {
    printf("Type    : ");
    switch (t) {
        case BONUS:
            printf("BONUS\n");
            break;
        case DOUBLE:
            printf("DOUBLE\n");
            break;
        case REGULAR:
            printf("REGULAR\n");
            break;
    }
    printf("Dice    : %d\n", dice);
    printf("Points  : %d\n", points);
}
