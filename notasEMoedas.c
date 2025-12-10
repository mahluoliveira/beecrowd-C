#include <stdio.h>

int main() {
    double valor;
    int centavos;
    int notas[] = {10000, 5000, 2000, 1000, 500, 200};
    int moedas[] = {100, 50, 25, 10, 5, 1};
    int i;

    scanf("%lf", &valor);

    centavos = (int)(valor * 100 + 0.5); 

    printf("NOTAS:\n");
    for (i = 0; i < 6; i++) {
        printf("%d nota(s) de R$ %.2f\n", centavos / notas[i], notas[i] / 100.0);
        centavos %= notas[i];
    }

    printf("MOEDAS:\n");
    for (i = 0; i < 6; i++) {
        printf("%d moeda(s) de R$ %.2f\n", centavos / moedas[i], moedas[i] / 100.0);
        centavos %= moedas[i];
    }

    return 0;
}
