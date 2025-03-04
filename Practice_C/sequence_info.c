#include <stdio.h>
#include <limits.h>

int main()
{
    int count = 0;
    int sum = 0;
    int number, max = INT_MIN, min = INT_MAX, range;
    float average;

    do
    {
        // Get a number
        printf("Enter a number above 0: ");
        scanf("%d", &number);

        // Check if 0
        if (number == 0)
        {
            break;
        }
        else
        {
            count++;
            sum += number;
            if (max < number)
                max = number;
            if (min > number)
                min = number;
        }

    } while (number != 0);

    // Display Insights
    printf(" ----- INSIGHTS ----- \n");
    printf("Total count of sequence: %d\n", count);
    printf("Total sum of sequence: %d\n", sum);
    printf("Overall max of sequence: %d\n", max);
    printf("Overall min of sequence: %d\n", min);

    range = max - min;
    average = sum / count;
    printf("Overall range of the sequence: %d\n", range);
    printf("Overall average of the sequence: %.2f\n", average);
}