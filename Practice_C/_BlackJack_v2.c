// Strategic Black Jack Game - James Ocampo 3/4/2025
// This is a simple implementation of the game BlackJack in C
// The game is played between a player and a dealer
// The player is dealt two cards and can choose to hit or stand
// The dealer is dealt two cards and must hit until the sum of their hand is 17 or more (House Rules)
// The player wins if they have a Blackjack (sum of 21) or if the dealer busts

#include <stdio.h>  // Include the standard input/output library
#include <stdlib.h> // Include the standard library for the rand() function
#include <time.h>   // Include the time library for the time() function

// Define the strategy!!

// Restore Cards
void restoreCards(int deck[])
{
    for (int i = 0; i < 52; i++)
    {
        deck[i] = (i % 13) + 1;
    }
}

// Shuffle Cards
void shuffleCards(int deck[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int j = rand() % size; // pick a random index j
        int temp = deck[i];    // swap the card at index i with the card at index j
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
void dealToHand(int deck[], int *deckTop, int hand[], int *handTop)
{
    // restore the cards if the deck is empty
    if (*deckTop == -1)
    {
        restoreCards(deck);
        shuffleCards(deck, sizeof(deck) / sizeof(deck[0]));
        *deckTop = 51;
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
    int deck[52];
    // Keep track of the top card
    int deckTop = 51;

    // Fill the deck with values 1 to 13
    restoreCards(deck);
    // Shuffle the deck
    shuffleCards(deck, sizeof(deck) / sizeof(deck[0]));

    // (DEBUG) Print the shuffled deck
    printDeck(deck, sizeof(deck) / sizeof(deck[0]));
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

    // --------------- GAME STARTS HERE ---------------

    // Deal the first card to the player
    dealToHand(deck, &deckTop, playerHand, &playerTop);

    // Deal the second card to the player
    dealToHand(deck, &deckTop, playerHand, &playerTop);

    // Deal the first card to the dealer
    dealToHand(deck, &deckTop, dealerHand, &dealerTop);

    // Deal the second card to the dealer
    dealToHand(deck, &deckTop, dealerHand, &dealerTop);

    // Print the player's hand
    printf("Player's hand: ");
    playerSum = showHand(playerHand, playerTop);

    // Print the dealer's hand
    printf("Dealer's hand: %d, ?\n", dealerHand[0]);

    // --------------- Player's Turn ---------------
    while (playerSum < 21)
    {
        // Ask the player if they want to hit or stand
        choice = strategy(type, threshold, playerHand, deck, playerSum);

        // Player chooses to hit
        if (choice == 'h')
        {
            // Deal a card to the player
            dealToHand(deck, &deckTop, playerHand, &playerTop);

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
        dealToHand(deck, &deckTop, dealerHand, &dealerTop);

        // Print the dealer's hand
        printf("Dealer's hand: ");
        dealerSum = showHand(dealerHand, dealerTop);
    }

    // --------------- Determine the Winner ---------------
    printf("\nFinal hands:\n");
    printf("Player's hand: %d\n", playerSum);
    printf("Dealer's hand: %d\n", dealerSum);

    // Check if the player or dealer has a blackjack
    if (playerSum == 21)
    {
        printf("Player has a Blackjack! Player wins!\n");
    }
    else if (dealerSum == 21)
    {
        printf("Dealer has a Blackjack! Dealer wins!\n");
    }
    // Check if the player busts
    else if (playerSum > 21)
    {
        printf("Player busts! Dealer wins!\n");
    }
    // Check if the dealer busts
    else if (dealerSum > 21)
    {
        printf("Dealer busts! Player wins!\n");
    }
    // Compare the sums if no one busts
    else
    {
        if (playerSum > dealerSum)
        {
            printf("Player wins!\n");
        }
        else if (playerSum < dealerSum)
        {
            printf("Dealer wins!\n");
        }
        else
        {
            printf("It's a tie!\n");
        }
    }
}