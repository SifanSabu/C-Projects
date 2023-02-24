#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dicegame.h"
#include "dicegame.c"

int main() {
    // Initialize the srand() to start the random generator
    srand(time(NULL));

    // Initialize the player-1 and player-2 points to 0
    int player1Points = 0;
    int player2Points = 0;

    // Initialize all other required variables
    int roundNumber = 0;
    int numberOfRounds = 0;
    int diceValue = 0;
    int roundPoints = 0;
    int currentPlayer = 1;
    ROUNDTYPE roundType;

    // Ask the user for the number of rounds to run the game
    printf("Enter the number of rounds: ");
    scanf("%d", &numberOfRounds);
    printf("P1      : %d\n", player1Points);
    printf("P1      : %d\n", player2Points);

    // Set up the loop to go through all the rounds one at a time
    while (roundNumber < numberOfRounds) {
        roundNumber++;

        // Call the corresponding functions to get the information for this round - type, dice, points
        roundType = getRoundType();
        diceValue = getRandomNumber(1, 6);
        roundPoints = getRoundPoints(roundType);

        // Print round number
        printf("\nROUND %d\n", roundNumber);
	printf("--------\n");

        // Print current player
        printf("Player  : %d\n", currentPlayer);

        // Call printRoundInfo() to print the round information
        printRoundInfo(roundType, diceValue, roundPoints);

        // MAIN GAME LOGIC
        if ((currentPlayer % 2 == 1 && diceValue % 2 == 1) || (currentPlayer % 2 == 0 && diceValue % 2 == 0)) {
            // Success: Player 1 is the current player and the dice rolled is odd
            // OR Player 2 is the current player and the dice rolled is even.
            // Current player gains the points, based on the type of the round. The current player’s turn continues in the next round.
            if (currentPlayer == 1) {
                player1Points += roundPoints;
            } else {
                player2Points += roundPoints;
            }
            // printf("Success! Player %d gains %d points.\n", currentPlayer, roundPoints);
        } else {
            // Failure: Player 1 is the current player and the dice rolled is even
            // OR Player 2 is the current player and the dice rolled is odd.
            // Current player incurs penalty of the same number of points, based on the type of the round. In the next round, the current player is changed to the other player.
            if (currentPlayer == 1) {
                player1Points -= roundPoints;
                currentPlayer = 2;
            } else {
                player2Points -= roundPoints;
                currentPlayer = 1;
            }
            /// printf("Failure! Player %d incurs a penalty of %d points.\n", currentPlayer, roundPoints);
        }

        // Call printPlayerPoints() to print the player information at the end of the round
        printPlayerPoints(player1Points, player2Points);
    }

    // Print game over message
    printf("\nGAME OVER!!\n");
    if (player1Points > player2Points) {
        printf("P1 Won\n");
    } else {
	printf("P2 Won\n");
    }
}
