#include <stdio.h>
int main()
{
    char nome[10];
    double salario, vendas;

    scanf("%s", nome);
    scanf("%lf", &salario);
    scanf("%lf", &vendas);

    salario = (0.15 * vendas);

    printf("TOTAL = R$ %.2lf\n", salario);
    return 0;
}