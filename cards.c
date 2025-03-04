#include <stdio.h>

// Deck of cards array
int main()
{
    char *ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
    // *ranks[] is an array of pointers to strings

    int deck[52];

    // Initialize deck
    for (int i = 0; i < 52; i++)
    {
        deck[i] = i;
    }

    // Print deck
    for (int i = 0; i < 52; i++)
    {
        int rank = deck[i] % 13;
        printf("%s ", ranks[rank]);
    }

    return 0;
}