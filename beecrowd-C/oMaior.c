#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c, abmaior, maior;
    scanf("%d"
          "%d"
          "%d",
          &a, &b, &c);

    abmaior = (a + b + abs(a - b)) / 2;
    maior = (abmaior + c + abs(abmaior - c)) / 2;

    printf("%d eh o maior\n", maior);
    return 0;
}