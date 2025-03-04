#include <stdio.h>
#include <string.h>

int main()
{
    char firstName[] = "John";
    char lastName[] = "Doe";

    // CASING
    strlwr(firstName); // Convert to lowercase
    strupr(lastName);  // Convert to uppercase

    // CONCATENATION
    strcat(firstName, " ");      // Append a space
    strcat(firstName, lastName); // Append the last name

    printf("Full name: %s\n", firstName);

    // COPY
    strcpy(lastName, firstName); // Copy first name (now Full Name) to last name
    printf("Last name (now full name): %s\n", lastName);
    char first_letter;
    strncpy(&first_letter, firstName, 1); // Copy the first letter of the first name

    printf("First letter: %c\n", first_letter);

    // LENGTH
    int length = strlen(firstName); // Get the length of the first name
    printf("Length: %d\n", length);

    // COMPARISON
    if (strcmp(firstName, lastName) == 0)
    {
        printf("Names are the same\n");
    }
    else
    {
        printf("Names are different\n");
    }

    // comparing first letter of first name with first letter of last name
    if (strncmp(firstName, lastName, 1) == 0)
    {
        printf("First letters are the same\n");
    }
    else
    {
        printf("First letters are different\n");
    }

    // compare all ignoring case
    if (strcmpi(firstName, lastName) == 0)
    {
        printf("Names are the same (ignoring case)\n");
    }
    else
    {
        printf("Names are different (ignoring case)\n");
    }
}