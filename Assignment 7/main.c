#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flights.h"
#include <ctype.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("ERROR NO ARGS\n");
        return 1;
    }

    FILE* fp = fopen("passenger-data-short.csv", "r");
    if (fp == NULL) {
        printf("ERROR FILE NOT OPEN\n");
        return 1;
    }

    struct Flight* flights = malloc(NUM_FLIGHTS * sizeof(struct Flight));

    char line[50];
    char* token;
    int i = 0;

    fgets(line, sizeof(line), fp); // skip header line

    while (fgets(line, sizeof(line), fp)) {
        token = strtok(line, ",");
        strcpy(flights[i].origin, token);

        token = strtok(NULL, ",");
        strcpy(flights[i].destination, token);

        token = strtok(NULL, ",");
        strcpy(flights[i].airline, token);

        token = strtok(NULL, ",");
        flights[i].passengers = atoi(token);

        i++;
    }

    fclose(fp);

    char airlineCode[3];
    printf("Enter a two letter airline code: ");
    scanf("%s", airlineCode);

    int numFlights = 0;
    int totalPassengers = 0;
    int j;
    int k;

    // Convert airline code to uppercase
    for (k = 0; k < 2; k++) {
        airlineCode[k] = toupper(airlineCode[k]);
    }
    for (j = 0; j < NUM_FLIGHTS; j++) {
        if (strcmp(flights[j].airline, airlineCode) == 0) {
            numFlights++;
            totalPassengers += flights[j].passengers;
        }
    }

    printf("airline: %s\n", airlineCode);
    printf("flights: %d\n", numFlights);
    printf("passengers: %d\n", totalPassengers);

    free(flights);

    return 0;
}
