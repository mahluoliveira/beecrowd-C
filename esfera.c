#include <stdio.h>
#include <math.h>
int main()
{
    double R, volume, pi;
    scanf("%lf", &R);

    pi = 3.14159;
    volume = (4 / 3.0) * pi * pow(R, 3);

    printf("VOLUME = %.3lf\n", volume);
    return 0;
}