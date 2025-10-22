#include <stdio.h>
int main (){
    int num, horas, valor, salario; 
    scanf ("%d", &num);
    scanf ("%d", &horas);
    scanf ("%d", &valor);

    salario=horas*valor;

    printf ("NUMBER = %d\n", num);
    printf ("SALARY = U$ %d\n", salario);

    return 0;
}