#include <stdio.h>
#include <stdlib.h>
#define DIR 10

void puntero(int*,int);

int main() {

    int s = 10;
    int q = 20;

    int vNumeros[DIR] = {4,5,3,1,5,34,33,8,9,12};
    int i;
    int p; //pivot
    int r; //relativo
    int aux;

    for(i=0 ; i<DIR ; i++) {
        printf("%d     " , vNumeros[i]);
    }
    printf("\n\n");
    for (p=0 ; p<DIR-1 ; p++){
        for (r=p+1 ; r<DIR ; r++) {
            if (vNumeros[p]<vNumeros[r]) {
                aux = vNumeros[r];
                vNumeros[r] = vNumeros[p];
                vNumeros[p] = aux;
            }
        }
    }
    printf("\n");
    for(i=0 ; i<DIR ; i++) {
        printf("%d     " , vNumeros[i]);
    }
    printf("\n");
    system("pause");
    printf("\n");
    for(i=0 ; i<DIR ; i++) {
        printf("Ingresar n%cmero\t" , 163);
        scanf("%d" , &vNumeros[i]);
    }
    printf("\n");
    for(i=0 ; i<DIR ; i++) {
        printf("%d     " , vNumeros[i]);
    }
    printf("\n----------------------------------------------\n");
    vNumeros[2] = 9;
    printf("%d \n\n" , vNumeros[2]);
    puntero(&s,q);

    printf("Cuanto vale p y q?\n\n");
    system("pause");
    printf("\np = %d" , s);
    printf("\nq = %d" , q);
    printf("\n");
    return 0;

}

void puntero(int* a, int b) {
    *a = b+5;
    b = 9;
}

/** memoria en pila = pila de platos
 *  memoria en cola = cola de supermercado
 *
 *  pasar puntero desde main con &
 *  recibir en *a
 *  trabajar con *a
 *  si trabajo con a, estoy cambiando la direcci�n de la variable, no el valor
 *  para hacer ejercicios con punteros, hacer el dibujo de la memoria
 */

/** VECTORES
 *  los slots de memoria est�n uno atr�s del otro
 *  todos responden al mismo nombre + la direcci�n en el corchete (sub�ndice)
 *  todos ocupan el mismo espacio (4 byte c/u si es int, 1 byte c/u si es char
 *
 *  se declara ->   tipo nombre[n]
 *  primer sub�ndice = l�mite inferior = 0
 *  �ltimo sub�ndice = l�mite superior = n-1
 *  el �ndice se multiplica por las cantidad de bytes que ocupa cada slot
 *  el nombre de la variable solo est� asignado al primer slot
 *  a partir de la primer variable, hace aritm�tica con las direcci�nes y el sub�ndice
 *
 *  se usa constante para cambiar el tama�o de los vectores y en todos los for que trabajan con el vector
 *  'define' en c no es una constante, sino que es un valor que se reemplaza en el programa antes de compilar
 *
 *  carga secuencial -> con for
 *  carga aleatoria  -> con do while e ingresando manualmente el �ndice y el valor
 *
 *  definir por extensi�n -> int vector[5] = (0,1,2,3,4);
 *  definir a cero        -> int vector[5] = ();
 *  solo se puede definir as� en la declaraci�n
 */

/** Para ordenar vectores -> m�todo de burbujeo
 *  Pivot y relativo a partir de pivot
 *  Pivot compara con cada relativo
 *  Pivot se desplaza uno
 *  Pivot se compara con cada relativo
 *  Pivot llega hasta el ante�ltimo �ndice (n-2)
 *  Relativo empieza a partir del segundo �ndice (1)
 *  Depende de la longitud y la condici�n del vector
 */
