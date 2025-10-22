#include <stdio.h>
#include <locale.h>
int main () {
    double a, b, c, final;
    setlocale(LC_ALL, "portuguese");
    printf ("Digite suas 3 notas:");
    scanf ("%lf", &a);
    scanf ("%lf", &b);
    scanf ("%lf", &b);

    final=(a+b+c)/3;
    printf ("Média %.1lf\n", final);
    return 0; 


}