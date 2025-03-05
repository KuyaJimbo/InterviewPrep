// Strategic Black Jack Game - James Ocampo 3/5/2025
// Now the threshold changes according to the each game's results
// Increasing the risk if a win occurs and decreasing the risk if a loss occurs
// With "SUM" strategy, the player will stand if the sum of the hand is greater than or equal to the threshold
// With "CHANCE" strategy, the player will stand if the chance of going bust is less than the threshold

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52

// Modify function signatures to include deck size
float safe_chance(int playerSum, int deck[], int deckTop)
{
    int safe = 0;
    int unsafe = 0;
    for (int i = 0; i <= deckTop; i++)
    {
        if (playerSum + deck[i] <= 21)
        {
            safe++;
        }
        else
        {
            unsafe++;
        }
    }
    return (float)safe / (safe + unsafe) * 100;
}

// Restore Cards
void restoreCards(int deck[], int size)
{
    for (int i = 0; i < size; i++)
    {
        deck[i] = (i % 13) + 1;
    }
}

// Shuffle Cards
void shuffleCards(int deck[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int j = rand() % size;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Print the deck
void printDeck(int deck[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", deck[i]);
    }
    printf("\n");
}

// Deal a card to a person
void dealToHand(int deck[], int deckSize, int *deckTop, int hand[], int *handTop)
{
    // restore the cards if the deck is empty
    if (*deckTop == -1)
    {
        restoreCards(deck, deckSize);
        shuffleCards(deck, deckSize);
        *deckTop = deckSize - 1;
    }

    hand[*handTop] = deck[*deckTop]; // Assign the card from the deck to the hand
    (*handTop)++;                    // Move to the next index in the hand
    (*deckTop)--;                    // Move to the next card in the deck
}

// Show the hand
int showHand(int hand[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += hand[i];
        printf("%d ", hand[i]);
    }
    printf("(%d)\n", sum);
    return sum;
}

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // --------------- SET UP THE DECK ---------------
    // Initialize the deck
    int deck[DECK_SIZE];
    // Keep track of the top card
    int deckTop = DECK_SIZE - 1;

    // Fill the deck with values 1 to 13
    restoreCards(deck, DECK_SIZE);
    // Shuffle the deck
    shuffleCards(deck, DECK_SIZE);

    // --------------- Creating Player and Dealer Hands ---------------
    int playerHand[11]; // Array to hold the player's hand
    int playerTop = 0;  // Index of the top card in the player's hand
    int playerSum = 0;  // Sum of the player's hand

    int dealerHand[11]; // Array to hold the dealer's hand
    int dealerTop = 0;  // Index of the top card in the dealer's hand
    int dealerSum = 0;  // Sum of the dealer's hand

    // Set up the game variables
    int card;
    char choice;

    // Define the strategy
    char type;
    printf("Enter the type of strategy: sum (s) or chance (c)? ");
    scanf(" %c", &type); // Added space before %c to consume whitespace

    float threshold;
    printf("Enter the threshold: ");
    scanf("%f", &threshold);

    float threshold_change;
    printf("Enter the threshold change: ");
    scanf("%f", &threshold_change);

    int games;
    printf("Enter the number of games: ");
    scanf("%d", &games);

    int playerWins = 0;
    int playerBlackjacks = 0;
    int dealerWins = 0;

    // --------------- GAME STARTS HERE ---------------
    for (int game = 0; game < games; game++)
    {
        // Deal the first card to the player
        dealToHand(deck, DECK_SIZE, &deckTop, playerHand, &playerTop);

        // Deal the second card to the player
        dealToHand(deck, DECK_SIZE, &deckTop, playerHand, &playerTop);

        // Deal the first card to the dealer
        dealToHand(deck, DECK_SIZE, &deckTop, dealerHand, &dealerTop);

        // Deal the second card to the dealer
        dealToHand(deck, DECK_SIZE, &deckTop, dealerHand, &dealerTop);

        // Print the player's hand
        printf("Player's hand: ");
        playerSum = showHand(playerHand, playerTop);

        // Print the dealer's hand
        printf("Dealer's hand: %d, ?\n", dealerHand[0]);

        // --------------- Player's Turn ---------------
        while (playerSum < 21)
        {
            // if type is s
            if (type == 's')
            {
                if (playerSum >= threshold)
                {
                    choice = 's';
                }
                else
                {
                    choice = 'h';
                }
            }
            // if type is c
            else
            {
                if (100 - safe_chance(playerSum, deck, deckTop) < threshold)
                {
                    choice = 'h';
                }
                else
                {
                    choice = 's';
                }
            }

            // Player chooses to hit
            if (choice == 'h')
            {
                // Deal a card to the player
                dealToHand(deck, DECK_SIZE, &deckTop, playerHand, &playerTop);

                // Print the player's hand
                printf("Player's hand: ");
                playerSum = showHand(playerHand, playerTop);
            }
            // Player chooses to stand
            else
            {
                break;
            }
        }

        // --------------- Dealer's Turn ---------------
        // Print the dealer's hand
        printf("Dealer's hand: ");
        dealerSum = showHand(dealerHand, dealerTop);

        // Dealer hits until the sum is 17 or more
        while (dealerSum < 17 && playerSum <= 21)
        {
            // Deal a card to the dealer
            dealToHand(deck, DECK_SIZE, &deckTop, dealerHand, &dealerTop);

            // Print the dealer's hand
            printf("Dealer's hand: ");
            dealerSum = showHand(dealerHand, dealerTop);
        }

        // --------------- Determine the Winner ---------------
        printf("\nFinal hands:\n");
        printf("Player's hand: %d\n", playerSum);
        printf("Dealer's hand: %d\n", dealerSum);

        // both black jack is a tie
        if (playerSum == 21 && dealerSum == 21)
        {
            printf("It's a tie!\n");

            // No change in threshold because it was a tie
        }
        // Check if the player or dealer has a blackjack
        else if (playerSum == 21)
        {
            printf("Player has a Blackjack! Player wins!\n");
            playerWins++;
            playerBlackjacks++;

            // Dont change threshold because it was a blackjack
        }

        // Check if the player busts
        else if (playerSum > 21)
        {
            printf("Player busts! Dealer wins!\n");
            dealerWins++;

            // LOSS - Decrease the threshold because hit when it was too high
            threshold -= threshold_change;
        }

        else if (dealerSum == 21)
        {
            printf("Dealer has a Blackjack! Dealer wins!\n");
            dealerWins++;

            // LOSS - Not close enough to blackjack
            threshold += threshold_change;
        }
        // Check if the player busts
        else if (playerSum > 21)
        {
            printf("Player busts! Dealer wins!\n");
            dealerWins++;

            // LOSS - Decrease the threshold because hit when it was too high
            threshold -= threshold_change;
        }
        // Check if the dealer busts
        else if (dealerSum > 21)
        {
            printf("Dealer busts! Player wins!\n");
            playerWins++;

            // No change in threshold because dealer busts
        }
        // Compare the sums if no one busts
        else
        {
            if (playerSum > dealerSum)
            {
                printf("Player wins!\n");
                playerWins++;

                // WIN - Don't change threshold because it was a win
            }
            else if (playerSum < dealerSum)
            {
                printf("Dealer wins!\n");
                dealerWins++;

                // LOSS because of lower score, should try to get closer to 21
                threshold += threshold_change;
            }
            else
            {
                printf("It's a tie!\n");
            }
        }

        // Reset the player and dealer hands
        playerTop = 0;
        playerSum = 0;
        dealerTop = 0;
        dealerSum = 0;
    }

    // Print the results
    printf("\nPlayer wins: %d\n", playerWins);
    printf("Player blackjacks: %d\n", playerBlackjacks);
    printf("Dealer wins: %d\n", dealerWins);
    printf("Final Threshold: %.2f\n", threshold);
    return 0;
}