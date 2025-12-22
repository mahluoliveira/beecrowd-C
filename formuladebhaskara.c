#include <stdio.h>
#include <math.h>
// Leia 3 valores de ponto flutuante e efetue o cálculo das raízes da equação
// de Bhaskara. Se não for possível calcular as raízes, mostre a mensagem
// correspondente “Impossivel calcular”, caso haja uma divisão por 0 ou raiz
// de numero negativo.
int main()
{
    double a, b, c;
    double delta;
    double raiz1, raiz2;

    scanf("%lf %lf %lf", &a, &b, &c);
    if ((a == 0) || (delta < 0))
    {
        printf("Impossivel calcular\n");
    }
    else
    {

        delta = (b * b) - 4 * a * c;
        raiz1 = (-b-sqrt(delta)) / (2 * a);
        raiz2 = (-b + sqrt(delta)) / (2 * a);
        
        printf("Raiz 1= %lf\n", raiz1);
        printf("Raiz 2= %lf\n", raiz2);
    }
    return 0;
}