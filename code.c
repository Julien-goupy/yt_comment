#define PLAYER_COUNT 4


int main()
{
    // Variables
    uint8_t  destinationTileFrom[101];
    uint8_t  playerPositions[PLAYER_COUNT];
    uint32_t currentPlayerIndex;


    // init
    for (uint32_t i=0; i < 101; ++i)
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


    for (uint32_t i=0; i < PLAYER_COUNT; ++i)
    {
        playerPositions[i] = 0;
    }

    currentPlayerIndex = 0;


    // Game Loop
    while (true)
    {
        uint32_t diceRoll = random_int(1, 6);
        printf("Player %u rolled a %u while being on case %u\n", currentPlayerIndex + 1, diceRoll, playerPositions[ currentPlayerIndex ]);

        uint32_t tile = playerPositions[ currentPlayerIndex ] + diceRoll;
        playerPositions[ currentPlayerIndex ] = destinationTileFrom[tile];

        if (destinationTileFrom[tile] > tile)
        {
            printf("Player %u landed on %u BUT took a ladder to %u\n", currentPlayerIndex, tile, destinationTileFrom[tile]);
        }
        else if (destinationTileFrom[tile] < tile)
        {
            printf("Player %u landed on %u BUT took a snake to %u\n", currentPlayerIndex, tile, destinationTileFrom[tile]);
        }
        else if (destinationTileFrom[tile] == 100)
        {
            puts("Player %u WON !!!!!", currentPlayerIndex);
            return 0;
        }
        else
        {
            printf("Player %u landed %u\n", currentPlayerIndex, destinationTileFrom[tile]);
        }
        
        currentPlayerIndex = (currentPlayerIndex + 1) % PLAYER_COUNT;
    }
}