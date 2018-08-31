#include <stdio.h>
#include <stdlib.h>

int main() {

    char aux;
    int n1;
    int n2;
    int resta;

    printf("Limpia la pantalla. Lee dos valores y muestra la resta positiva o negativa.\n\n");

    printf("'Enter' para limpiar la pantalla");
    scanf("%c" , &aux);
    system("cls");

    printf("N%cmero uno:\t" , 163);
    scanf("%i" , &n1);
    printf("N%cmero dos:\t" , 163);
    scanf("%i" , &n2);

    resta = n1-n2;

    if (resta==0) {
        printf("\nRESTA:\t%i\n" , resta);
    } else if (resta<0) {
        printf("\nRESTA NEGATIVA:\t%i\n" , resta);
    } else {
        printf("\nRESTA POSITIVA:\t%i\n" , resta);
    }

    return 0;

}
