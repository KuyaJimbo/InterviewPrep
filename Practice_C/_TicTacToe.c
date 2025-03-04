#include <stdio.h>
#include <math.h>

// Function to check for a winner
char check_winner(char grid[3][3])
{
    // Check rows
    for (int r = 0; r < 3; r++)
    {
        if (grid[r][0] == grid[r][1] && grid[r][1] == grid[r][2] && grid[r][0] != ' ')
        {
            return grid[r][0];
        }
    }
    // Check columns
    for (int c = 0; c < 3; c++)
    {
        if (grid[0][c] == grid[1][c] && grid[1][c] == grid[2][c] && grid[0][c] != ' ')
        {
            return grid[0][c];
        }
    }
    // Check diagonals
    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] != ' ')
    {
        return grid[0][0];
    }
    if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[0][2] != ' ')
    {
        return grid[0][2];
    }
    return ' ';
}

// Function to determine the current symbol
char current_symbol(int turn)
{
    // Determine who's turn it is
    if (turn % 2 == 0) // X goes first
    {
        return 'X';
    }
    else
    {
        return 'O';
    }
}

// Function to display the grid
void displayGrid(char grid[3][3])
{
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            printf(" %c ", grid[r][c]);
            if (c != 2)
            {
                printf("|");
            }
            else
            {
                printf("\n");
            }
        }

        if (r != 2)
            printf("---|---|---\n");
    }
}

// Main Game Loop
int main()
{
    char grid[3][3] = {{' ', ' ', ' '},
                       {' ', ' ', ' '},
                       {' ', ' ', ' '}};

    int rows = sizeof(grid) / sizeof(grid[0]);
    int columns = sizeof(grid[0]) / sizeof(grid[0][0]);

    int row, column, choice;
    char symbol;

    for (int turn = 0; turn < 9; turn++)
    {
        symbol = current_symbol(turn);
        do
        {
            printf("Enter your choice (1-9): ");
            scanf("%d", &choice);

            // Ensure valid input (1-9)
            if (choice < 1 || choice > 9)
            {
                printf("Invalid choice. Please enter a number between 1 and 9.\n");
                continue;
            }

            // Adjust the user input to correspond to the grid positions
            // Mapping: 7 8 9 -> row 0, 4 5 6 -> row 1, 1 2 3 -> row 2
            if (choice >= 7 && choice <= 9)
            {
                row = 0; // top row
                column = choice - 7;
            }
            else if (choice >= 4 && choice <= 6)
            {
                row = 1; // middle row
                column = choice - 4;
            }
            else // choice between 1 and 3
            {
                row = 2; // bottom row
                column = choice - 1;
            }

            // Check if the selected cell is empty
            if (grid[row][column] != ' ')
            {
                printf("Cell already occupied. Try again.\n");
            }
        } while (grid[row][column] != ' ');

        grid[row][column] = symbol;

        // display grid
        displayGrid(grid);

        // check for winner
        if (check_winner(grid) != ' ')
        {
            printf("Player %c wins!\n", symbol);
            break;
        }
    }
}