#include <stdio.h>
int main (){
    int num, horas;
    double valor, salario; 
    scanf ("%d", &num);
    scanf ("%d", &horas);
    scanf ("%lf", &valor);

    salario=horas*valor;

    printf ("NUMBER = %d\n", num);
    printf ("SALARY = U$ %.2lf\n", salario);

    return 0;
}