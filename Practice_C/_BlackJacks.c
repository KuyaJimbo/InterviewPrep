#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define MAX_CARDS 11 // Maximum number of cards a player can hold

typedef struct
{
    int value;  // Numeric value of the card (Ace=11 initially)
    char *name; // Card name (e.g., "Ace of Hearts", "10 of Spades")
} Card;

Card deck[DECK_SIZE];
int deck_index = 0;

// Card names
const char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
const char *ranks[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

// Function to initialize the deck
void initialize_deck()
{
    int index = 0;
    for (int suit = 0; suit < 4; suit++)
    {
        for (int rank = 0; rank < 13; rank++)
        {
            deck[index].value = (rank >= 10) ? 10 : (rank + 1); // Face cards = 10, Ace = 1 (adjust later)
            deck[index].name = (char *)malloc(20);
            sprintf(deck[index].name, "%s of %s", ranks[rank], suits[suit]);
            index++;
        }
    }
}

// Function to shuffle the deck
void shuffle_deck()
{
    srand(time(NULL));
    for (int i = 0; i < DECK_SIZE; i++)
    {
        int j = rand() % DECK_SIZE;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
    deck_index = 0;
}

// Function to draw a card from the deck
Card draw_card()
{
    if (deck_index >= DECK_SIZE)
    {
        printf("\nDeck empty! Reshuffling...\n");
        shuffle_deck();
    }
    return deck[deck_index++];
}

// Function to calculate hand value
int calculate_hand(Card hand[], int count)
{
    int sum = 0, ace_count = 0;
    for (int i = 0; i < count; i++)
    {
        sum += hand[i].value;
        if (hand[i].value == 1)
            ace_count++;
    }

    // Convert Ace from 11 to 1 if needed
    while (sum > 21 && ace_count > 0)
    {
        sum -= 10;
        ace_count--;
    }

    return sum;
}

// Function to display hand
void display_hand(char *name, Card hand[], int count)
{
    printf("%s's hand: ", name);
    for (int i = 0; i < count; i++)
    {
        printf("%s, ", hand[i].name);
    }
    printf("(Total: %d)\n", calculate_hand(hand, count));
}

int main()
{
    initialize_deck();
    shuffle_deck();

    char choice;
    do
    {
        Card player_hand[MAX_CARDS] = {draw_card(), draw_card()};
        Card dealer_hand[MAX_CARDS] = {draw_card(), draw_card()};
        int player_count = 2, dealer_count = 2;

        printf("\n=== New Game ===\n");

        // Fix: Define a proper hidden card
        Card hidden_card = {0, "Hidden"};
        display_hand("Dealer", (Card[]){dealer_hand[0], hidden_card}, 2);
        display_hand("Player", player_hand, player_count);

        // Player's turn
        while (calculate_hand(player_hand, player_count) < 21)
        {
            printf("Hit (h) or Stand (s)? ");
            scanf(" %c", &choice);

            if (choice == 'h')
            {
                player_hand[player_count++] = draw_card();
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
        }
        else
        {
            // Dealer's turn
            printf("\nDealer reveals cards:\n");
            display_hand("Dealer", dealer_hand, dealer_count);

            while (calculate_hand(dealer_hand, dealer_count) < 17)
            {
                dealer_hand[dealer_count++] = draw_card();
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
        }

        printf("\nPlay again? (Press 'q' to quit, any other key to continue): ");
        scanf(" %c", &choice);
    } while (choice != 'q');

    printf("Thanks for playing!\n");
    return 0;
}
