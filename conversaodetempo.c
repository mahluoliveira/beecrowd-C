#include <stdio.h>

int main() {
    int tempo, horas, minutos, segundos;
    scanf("%d", &tempo);

    horas = tempo / 3600;           // cada hora tem 3600 segundos
    tempo = tempo % 3600;           // resto depois de tirar as horas

    minutos = tempo / 60;           // cada minuto tem 60 segundos
    segundos = tempo % 60;          // o que sobrou são os segundos

    printf("%d:%d:%d\n", horas, minutos, segundos);
    return 0;
}