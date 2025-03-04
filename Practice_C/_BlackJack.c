#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 11 // Maximum possible cards in a hand (in case of multiple Aces)

// Card values (Ace = 11 initially, but may be adjusted)
int get_card()
{
    int card = rand() % 13 + 1;
    if (card > 10)
        return 10; // Face cards (J, Q, K) are worth 10
    return card;   // Aces initially count as 11
}

// Calculate hand value and adjust for Aces
int calculate_hand(int hand[], int count)
{
    int sum = 0, ace_count = 0;

    for (int i = 0; i < count; i++)
    {
        sum += hand[i];
        if (hand[i] == 1)
            ace_count++; // Track Aces
    }

    // Convert Ace from 11 to 1 if needed
    while (sum > 21 && ace_count > 0)
    {
        sum -= 10;
        ace_count--;
    }

    return sum;
}

// Display hand
void display_hand(char *name, int hand[], int count)
{
    printf("%s's hand: ", name);
    for (int i = 0; i < count; i++)
    {
        printf("%d ", hand[i]);
    }
    printf("(Total: %d)\n", calculate_hand(hand, count));
}

int main()
{
    srand(time(NULL)); // Seed random number generator

    int player_hand[MAX_CARDS] = {get_card(), get_card()};
    int dealer_hand[MAX_CARDS] = {get_card(), get_card()};

    int player_count = 2, dealer_count = 2;
    char choice;

    printf("Welcome to Blackjack!\n");
    display_hand("Dealer", (int[]){dealer_hand[0], 0}, 2); // Show only one dealer card
    display_hand("Player", player_hand, player_count);

    // Player's turn
    while (calculate_hand(player_hand, player_count) < 21)
    {
        printf("Hit (h) or Stand (s)? ");
        scanf(" %c", &choice);

        if (choice == 'h')
        {
            player_hand[player_count++] = get_card();
            display_hand("Player", player_hand, player_count);
        }
        else
        {
            break;
        }
    }

    int player_total = calculate_hand(player_hand, player_count);
    if (player_total > 21)
    {
        printf("Player busts! Dealer wins.\n");
        return 0;
    }

    // Dealer's turn
    printf("\nDealer reveals cards:\n");
    display_hand("Dealer", dealer_hand, dealer_count);

    while (calculate_hand(dealer_hand, dealer_count) < 17)
    {
        dealer_hand[dealer_count++] = get_card();
        display_hand("Dealer", dealer_hand, dealer_count);
    }

    int dealer_total = calculate_hand(dealer_hand, dealer_count);

    // Determine winner
    if (dealer_total > 21)
    {
        printf("Dealer busts! Player wins.\n");
    }
    else if (player_total > dealer_total)
    {
        printf("Player wins!\n");
    }
    else if (player_total < dealer_total)
    {
        printf("Dealer wins!\n");
    }
    else
    {
        printf("It's a tie!\n");
    }

    return 0;
}
