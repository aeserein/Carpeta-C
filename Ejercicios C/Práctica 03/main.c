#include <stdio.h>
#include <stdlib.h>

int sumaDos(int x, int y);      // [declaración/prototipo/firma] de la función
                                // puede declarar solo el tipo en los parámetros formales -> int sumaDos (int,int);
                                // se definen los nombres de las variables en las implementaciones abajo

int main() {

    printf("Suma dos n%cmeros.\n" , 163);
    printf("-----------------\n\n");
    int numero1;
    int numero2;
    int suma;

    printf("Primer n%cmero:\t" , 163);
    scanf("%d" , &numero1);
    printf("Segundo n%cmero:\t" , 163);
    scanf("%d" , &numero2);

    suma = sumaDos(numero1, numero2); //numero1 y numero2 son parámetros "actuales"
    printf("\nSUMA:\t%d\n" , suma);

    return 0;

}

int sumaDos(int numero1, int numero2) { //numero1 y numero2 son parametros "formales"
    int suma;
    suma = numero1+numero2;
    return suma;
}

    /*
    void    void   ->   Declara y opera la función y solo llamo desde main.                         void sumaDos(void);
    void    valor  ->   Declara y opera la función. Devuelve a una variable local de main.          int sumaDos(void);
    valor   void   ->   Recibe y opera. Muestra el resultado.                                       void SumaDos (int n1, int n2);
    valor   valor  ->   Recibe y opera. Devuelve a una variable local de main.                      int sumaDos (int x, int y);

    void sumaDos(void) {
        int numero1;
        int numero2;
        int suma;

        printf("Primer n%cmero:\t" , 163);
        scanf("%d" , &numero1);
        printf("Segundo n%cmero:\t" , 163);
        scanf("%d" , &numero2);

        suma = numero1+numero2;
        printf("\nSUMA:\t%d\n" , suma);
    }

    int sumaDos(void) {
        int numero1;
        int numero2;
        int suma;

        printf("Primer n%cmero:\t" , 163);
        scanf("%d" , &numero1);
        printf("Segundo n%cmero:\t" , 163);
        scanf("%d" , &numero2);

        suma = numero1+numero2;
        return suma;
    }

    void sumaDos(int n1, int n2) {
        suma = n1+n2;
        printf("\nSUMA:\t%d\n" , suma);
    }

    int sumaDos(int n1, int n2) {
        int suma;
        resultado = x+y;
        return suma;
    }

    CONCEPTOS:  Variables globales y locales
                Parámetros actuales y formales
                Variables globales = mal
                Lo ideal es trabajar con la función más acotada posible ( 1/1  o  valor/valor)
    */
