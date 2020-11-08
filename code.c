#include <stdint.h>
#include <stdio.h>

#define PLAYER_COUNT 4


int main()
{
    // Variables
    int destinationTileFrom[101];
    int tileOf[PLAYER_COUNT];
    int currentPlayer;


    // init
    for (int tile_i=0; tile_i < 101; ++tile_i)
    {
        destinationTileFrom[ tile_i ] = tile_i;
    }

    // init - ladders 
    destinationTileFrom[4]  = 18; 
    destinationTileFrom[57] = 78; 
    ...

    // init - snakes
    destinationTileFrom[50] = 32;
    ...


    for (int player_i=0; player_i < PLAYER_COUNT; ++player_i)
    {
        tileOf[ player_i ] = 0;
    }

    currentPlayer = 0;


    // Game Loop
    while (true)
    {
        int diceRoll = random_int(1, 6);
        printf("Player %d rolled a %d while being on case %d\n", currentPlayer + 1, diceRoll, tileOf[ currentPlayer ]);

        int tileAfterDiceRoll = tileOf[ currentPlayer ] + diceRoll;

        if (tileAfterDiceRoll > 100)
        {
            tileAfterDiceRoll = 100 - (tileAfterDiceRoll - 100);
            printf("Oups, you got too far...");
        }

        tileOf[ currentPlayer ] = destinationTileFrom[ tileAfterDiceRoll ];

        if (destinationTileFrom[ tileAfterDiceRoll ] > tileAfterDiceRoll)
        {
            printf("Player %d landed on %d BUT took a ladder to %d\n", currentPlayer + 1, tileAfterDiceRoll, tileOf[ currentPlayer ]);
        }
        else if (destinationTileFrom[ tileAfterDiceRoll ] < tileAfterDiceRoll)
        {
            printf("Player %d landed on %d BUT took a snake to %d\n", currentPlayer + 1, tileAfterDiceRoll, tileOf[ currentPlayer ]);
        }
        else if (tileOf[ currentPlayer ] == 100)
        {
            printf("Player %d WON !!!!!", currentPlayer + 1);
            return 0;
        }
        else
        {
            printf("Player %d landed %u\n", currentPlayer + 1, tileOf[ currentPlayer ]);
        }
        
        currentPlayer = (currentPlayer + 1) % PLAYER_COUNT;
    }
}
