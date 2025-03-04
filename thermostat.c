#include <stdio.h>

int main()
{

    char unit;
    float temp;

    printf("Is temp in C or F? \n");
    scanf("%c", &unit);

    if (unit == 'C')
    {
        printf("Enter temp in C: \n");
        scanf("%f", &temp);
        temp = (temp * 9 / 5) + 32;
        printf("Temp in F is: %.2f\n", temp);
    }
    else if (unit == 'F')
    {
        printf("Enter temp in F: \n");
        scanf("%f", &temp);
        temp = (temp - 32) * 5 / 9;
        printf("Temp in C is: %.2f\n", temp);
    }
    else
    {
        printf("Invalid unit\n");
    }
}