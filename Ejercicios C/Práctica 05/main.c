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
 *  si trabajo con a, estoy cambiando la dirección de la variable, no el valor
 *  para hacer ejercicios con punteros, hacer el dibujo de la memoria
 */

/** VECTORES
 *  los slots de memoria están uno atrás del otro
 *  todos responden al mismo nombre + la dirección en el corchete (subíndice)
 *  todos ocupan el mismo espacio (4 byte c/u si es int, 1 byte c/u si es char
 *
 *  se declara ->   tipo nombre[n]
 *  primer subíndice = límite inferior = 0
 *  último subíndice = límite superior = n-1
 *  el índice se multiplica por las cantidad de bytes que ocupa cada slot
 *  el nombre de la variable solo está asignado al primer slot
 *  a partir de la primer variable, hace aritmética con las direcciónes y el subíndice
 *
 *  se usa constante para cambiar el tamaño de los vectores y en todos los for que trabajan con el vector
 *  'define' en c no es una constante, sino que es un valor que se reemplaza en el programa antes de compilar
 *
 *  carga secuencial -> con for
 *  carga aleatoria  -> con do while e ingresando manualmente el índice y el valor
 *
 *  definir por extensión -> int vector[5] = (0,1,2,3,4);
 *  definir a cero        -> int vector[5] = ();
 *  solo se puede definir así en la declaración
 */

/** Para ordenar vectores -> método de burbujeo
 *  Pivot y relativo a partir de pivot
 *  Pivot compara con cada relativo
 *  Pivot se desplaza uno
 *  Pivot se compara con cada relativo
 *  Pivot llega hasta el anteúltimo índice (n-2)
 *  Relativo empieza a partir del segundo índice (1)
 *  Depende de la longitud y la condición del vector
 */
