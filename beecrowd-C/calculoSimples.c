#include <stdio.h>
int main()
{
    int peca1, num1, peca2, num2;
    double valor1, valor2, resu1, resu2, soma;

    scanf("%d", &peca1);
    scanf("%d", &num1);
    scanf("%lf", &valor1);

    scanf("%d", &peca2);
    scanf("%d", &num2);
    scanf("%lf", &valor2);

    resu1 = num1 * valor1;
    resu2 = num2 * valor2;
    soma = resu1 + resu2;

    printf("VALOR A PAGAR: R$ %.2lf\n", soma);
    return 0;
}