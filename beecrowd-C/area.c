#include <stdio.h>
#include <math.h>
int main()
{
    double A, B, C, pi, aTri, aCir, aTra, aQua, aRet;
    scanf("%lf", &A);
    scanf("%lf", &B);
    scanf("%lf", &C);

    pi = 3.14159;
    aTri = (A * C) / 2;
    aCir = pi * pow(C, 2);
    aTra = ((A + B) * C) / 2;
    aQua = pow(B, 2);
    aRet = (A * B);

    printf("TRIANGULO: %.3lf\n", aTri);
    printf("CIRCULO: %.3lf\n", aCir);
    printf("TRAPEZIO: %.3lf\n", aTra);
    printf("QUADRADO: %.3lf\n", aQua);
    printf("RETANGULO: %.3lf\n", aRet);
    return 0;
}