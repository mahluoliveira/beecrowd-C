#include <stdio.h>
#include <math.h>

int main()
{
    double r, a;
    scanf("%lf", &r);

    a = 3.14159 * pow(r, 2);

    printf("A=%.4f\n", a);
    return 0;
}