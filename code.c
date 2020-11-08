#include <stdint.h>
#include <stdio.h>

#define PLAYER_COUNT 4


int main()
{
    // Variables
    int destinationTileFrom[101];
    int playerPositions[PLAYER_COUNT];
    int currentPlayerIndex;


    // init
    for (int i=0; i < 101; ++i)
    {
        destinationTileFrom[i] = i;
    }

    // init - ladders 
    destinationTileFrom[4]  = 18; 
    destinationTileFrom[57] = 78; 
    ...

    // init - snakes
    destinationTileFrom[50] = 32;
    ...


    for (int i=0; i < PLAYER_COUNT; ++i)
    {
        playerPositions[i] = 0;
    }

    currentPlayerIndex = 0;


    // Game Loop
    while (true)
    {
        int diceRoll = random_int(1, 6);
        printf("Player %d rolled a %d while being on case %d\n", currentPlayerIndex + 1, diceRoll, playerPositions[ currentPlayerIndex ]);

        int tileAfterDiceRoll = playerPositions[ currentPlayerIndex ] + diceRoll;
        playerPositions[ currentPlayerIndex ] = destinationTileFrom[ tileAfterDiceRoll ];

        if (destinationTileFrom[ tileAfterDiceRoll ] > tileAfterDiceRoll)
        {
            printf("Player %d landed on %d BUT took a ladder to %d\n", currentPlayerIndex + 1, tileAfterDiceRoll, destinationTileFrom[ tileAfterDiceRoll ]);
        }
        else if (destinationTileFrom[ tileAfterDiceRoll ] < tileAfterDiceRoll)
        {
            printf("Player %d landed on %d BUT took a snake to %d\n", currentPlayerIndex + 1, tileAfterDiceRoll, destinationTileFrom[ tileAfterDiceRoll ]);
        }
        else if (destinationTileFrom[ tileAfterDiceRoll ] == 100)
        {
            printf("Player %d WON !!!!!", currentPlayerIndex + 1);
            return 0;
        }
        else
        {
            printf("Player %d landed %u\n", currentPlayerIndex + 1, destinationTileFrom[ tileAfterDiceRoll ]);
        }
        
        currentPlayerIndex = (currentPlayerIndex + 1) % PLAYER_COUNT;
    }
}
