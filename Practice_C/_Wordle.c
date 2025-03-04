#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool in_word(char letter, char word[])
{
    for (int i = 0; i < 5; i++)
    {
        if (letter == word[i])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    char word[6], guess[6], guess_letter, word_letter; // Increased size to accommodate the null terminator
    strcpy(word, "shape");

    while (1)
    {
        printf("Enter a word: ");
        scanf("%s", guess); // Removed the '&' because guess is already a pointer

        if (strcmp(guess, word) == 0)
        { // Use strcmp for string comparison
            printf("Correct!\n");
            break;
        }
        else
        {
            printf("Incorrect:    ");

            for (int i = 0; i < 5; i++)
            {
                guess_letter = guess[i];
                word_letter = word[i];

                // if same letter, print letter
                if (guess_letter == word_letter)
                {
                    printf("%c", guess_letter);
                }
                // if different letter but in word, print ?
                else if (in_word(guess_letter, word)) // q: why can we pass word and not &word? a: because word is already a pointer
                {
                    printf("?");
                }
                // if different letter not in word, print _
                else
                {
                    printf("_");
                }
            }
            printf("\n"); // Print newline after each incorrect guess
        }
    }

    return 0;
}
