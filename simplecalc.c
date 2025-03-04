#include <stdio.h>
#include <math.h>

int main()
{
    char op;
    float num1, num2;

    printf("What operation?\n");
    scanf("%c", &op);

    printf("Enter first number: ");
    scanf("%f", &num1);

    printf("Enter second number: ");
    scanf("%f", &num2);

    switch (op)
    {
    case '+':
        printf("%.2f + %.2f = %.2f\n", num1, num2, num1 + num2);
        break;
    case '-':
        printf("%.2f - %.2f = %.2f\n", num1, num2, num1 - num2);
        break;
    case '*':
        printf("%.2f * %.2f = %.2f\n", num1, num2, num1 * num2);
        break;
    case '/':
        if (num2 == 0)
        {
            printf("Division by zero\n");
        }
        else
        {
            printf("%.2f / %.2f = %.2f\n", num1, num2, num1 / num2);
        }
        break;
    case '%':
        if ((int)num2 == 0)
        {
            printf("Division by zero\n");
        }
        else
        {
            printf("%.2f %% %.2f = %.2f\n", num1, num2, (int)num1 % (int)num2);
            // % is the modulo operator, it returns the remainder of the division
            // q: why doesn't this work?
            // a: because the modulo operator only works with integers
        }
        break;

    case '^':
        printf("%.2f ^ %.2f = %.2f\n", num1, num2, pow(num1, num2));
        break;
    default:
        printf("Invalid operation\n");
    }
}
