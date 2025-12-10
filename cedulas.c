#include <stdio.h>
int main () {
    int n, valor;
    int notas100, notas50, notas20, notas10, notas5, notas2,notas1;

    scanf ("%d", &n);
    valor=n;
   
     notas100 = n / 100;
        n = n % 100;
  
   
    notas50 = n / 50;
     n = n % 50;
   
  
    notas20 = n / 20;
      n = n % 20;
  
   
    notas10 = n / 10;
      n = n % 10;
   
    
    notas5 = n / 5;
     n = n % 5;
   
     
    notas2 = n / 2;
    n = n % 2;
   

    notas1 = n;

    printf("%d\n", valor);
    printf("%d nota(s) de R$ 100,00\n", notas100);
    printf("%d nota(s) de R$ 50,00\n", notas50);
    printf("%d nota(s) de R$ 20,00\n", notas20);
    printf("%d nota(s) de R$ 10,00\n", notas10);
    printf("%d nota(s) de R$ 5,00\n", notas5);
    printf("%d nota(s) de R$ 2,00\n", notas2);
    printf("%d nota(s) de R$ 1,00\n", notas1);

    return 0;

}