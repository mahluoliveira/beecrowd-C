#include <stdio.h>
int main()
{
    double nota1, nota2, nota3, A, B, C, media;
    scanf("%lf", &nota1);
    scanf("%lf", &nota2);
    scanf("%lf", &nota3);

    A = nota1 * 2;
    B = nota2 * 3;
    C = nota3 * 5;
    media = (A + B + C) / 10;

    printf("MEDIA = %.1lf\n", media);
}