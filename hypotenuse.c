#include <stdio.h>
#include <math.h>

int main()
{
    double A, B, C;

    printf("Enter the side A: ");
    scanf("%lf", &A);

    printf("Enter the side B: ");
    scanf("%lf", &B);

    C = sqrt(A * A + B * B);

    printf("The hypotenuse is: %.2lf\n", C);

    return 0;
}