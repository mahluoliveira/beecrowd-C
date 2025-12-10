#include <stdio.h>
int main () {
    int dias, meses, anos, resto;
    scanf ("%d", &dias);
    
    anos=dias/365;
    resto=dias%365;

    meses=resto/30;
    dias=resto%30;

    printf ("%d ano(s)\n", anos);
    printf ("%d mes(es)\n", meses);
    printf ("%d dia(s)\n", dias);
    
    return 0; 

}