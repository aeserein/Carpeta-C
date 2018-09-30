#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define TAM_ARRAY 5


/** printf a. Alta de alumno - o. Ordenar lista - m. MostrarLista - M. modificar
 *  case a : cargarListadoDeAlumnos(listadoMain, A);
 *  case o : ordenarListadoDeAlumnosPorNombre(listadoMain, A);
 *  case m : mostrarListaDeAlumnos(listadoMain, A);
 *  case M : modificarNota
 *  para funcion inicializar -> agregar un 'short estado' como bandera
 *
 *  tunear la funcion de modificar
 *      Mostrar lista antes de pedir legajo
 *      Mostrar bien bonito el alumno del legajo
 *      Preguntar si es ese el alumno
 *      Submenú para modificar nombre o nota, no solo nombre
 *      Preguntar si esta seguro
 *
 *  No olvidar buscar libre
 *  También van las opciones de antes
 *  Github de Scarafilo
 */

void inicializarArray(short[], short);
void mostrarArray(short[], short);

/** \brief  Busca espacio disponible en un array
 *
 * \param   short[] -   Lista de shorts
 * \param   short   -   Tamaño de la lista
 * \param   int     -   Valor ilógico
 * \return  int     -   -1 si no hay espacio
 *                  -   >=0 indice donde guardar
 *
 */
int buscarLibre(short[] , short, int);

int main() {

    char seguir;
    short array[TAM_ARRAY];
    short indice;
    short f;

    inicializarArray(array, TAM_ARRAY);
    mostrarArray(array, TAM_ARRAY);
    printf("\n");

    do {
        indice = buscarLibre(array , TAM_ARRAY, -1);
        if (indice!=-1) {
            printf("Ingresar n%cmero:\t", 163);
            scanf("%hi" , &array[indice]);
        } else {
            printf("No hay m%cs espacio", 160);
            break;
        }
        printf("\n");
        mostrarArray(array, TAM_ARRAY);
        printf("\n;");
        printf("Desea ingresar otro? S/N   ");
        seguir = getche();
        printf("\n");

    } while (seguir=='s');
    return 0;

}

void inicializarArray(short array[] , short tam) {
    for ( ; tam>0 ; tam--) {
        array[tam-1] = -1;
    }
}

void mostrarArray(short array[], short tam) {
    short f;
    for (f=0 ; f<tam ; f++) {
        printf("%hi\n" , array[f]);
    }
}

int buscarLibre(short array[], short tam, int valorIlogico) {
    int index = -1;
    int f;
    for (f=0 ; f<tam ; f++) {
        if (array[f]==valorIlogico) {
            index = f;
            break;
        }
    }
    return index;
}
