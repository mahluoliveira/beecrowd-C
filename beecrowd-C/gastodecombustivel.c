#include <stdio.h>
int main (){
    int tempo;
    double dist, vm, litros;
    scanf ("%d", &tempo);
    scanf ("%lf", &vm);
  
    dist=vm*tempo;
    litros=dist/12;
    printf ("%.3lf\n", litros);
    
}