#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    printf("Limpia la pantalla. Lee dos n%cmeros.\nLos multiplica y saca el cuadrado del primero.\n\n" , 163);

    int n1;
    int n2;
    char aux;
    double producto;
    double potencia;

    printf("'Enter' para limpiar la pantalla.");
    scanf("%c" , &aux);
    system("cls");

    printf("N%cmero uno:\t" , 163);
    scanf("%i" , &n1);
    printf("N%cmero dos:\t" , 163);
    scanf("%i" , &n2);

    producto = n1*n2;
    potencia = pow(n1 , 2);
    printf("\nPRODUCTO:\t\t%g\n" , producto);
    printf("POTENCIA DEL PRIMERO:\t%g\n" , potencia);


    return 0;
}
