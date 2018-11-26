#include "programa.h"

int programa(void) {

    int debug = 0;
    short opcion;
    short archivoCargado = 0;
    LinkedList *listaEstructura;

    listaEstructura = ll_newLinkedList();

    do {
        printf("1 - Leer archivo de texto\n"
           "2 - Leer archivo binario\n"
           "  -----------------------------\n"
           "3 - Alta\n"
           "4 - Baja\n"
           "5 - Modificar\n"
           "6 - Listar\n"
           "7 - Ordenar\n"
           "8 - Filtrar\n"
           "  -----------------------------\n"
           "9 - Guardar archivo de texto\n"
           "10- Guardar archivo binario\n"
           "  -----------------------------\n"
           "11- Salir\n\n");
        opcion = getShortBetween(1,10, "Ingrese opcion:\t");

        switch (opcion) {
            case 1 : {  /* Leer texto */
                if (!archivoCargado) {
                    controller_loadFromText("archivo.csv", listaEstructura);
                    archivoCargado = 1;
                    printf("\nLEIDO archivo.csv\n");
                } else {
                    printf("\nYA ESTA CARGADO\n");
                }
                pausaYClear();
                break;
            }
            case 2 : {  /* Leer binario */
                if (!archivoCargado) {
                    controller_loadFromBinary("archivo.bin", listaEstructura);
                    printf("\nLEIDO archivo.bin\n");
                    archivoCargado = 1;
                } else {
                    printf("\nYA ESTA CARGADO\n");
                }
                pausaYClear();
                break;
            }
            case 3 : {  /* Alta */
                if (archivoCargado) {
                    controller_addEstructura(listaEstructura);
                } else {
                    system("cls");
                    printf("PRIMERO CARGUE ARCHIVO\n");
                    pausaYClear();
                }
                break;
            }
            case 4 : {  /* Baja */
                if (!ll_isEmpty(listaEstructura)) {
                    controller_removeEstructura(listaEstructura);
                } else {
                    system("cls");
                    printf("NO HAY\n");
                }
                pausaYClear();
                break;
            }
            case 5 : {  /* Modificación */
                if (!ll_isEmpty(listaEstructura)) {
                    controller_editEstructura(listaEstructura);
                } else {
                    system("cls");
                    printf("NO HAY\n");
                    pausaYClear();
                }
                break;
            }
            case 6 : {  /* Listar */
                if (!ll_isEmpty(listaEstructura)) {
                    ll_sort(listaEstructura, sortByID, 1);
                    controller_listEstructura(listaEstructura);
                } else {
                    system("cls");
                    printf("NO HAY\n");
                }
                pausaYClear();
                break;
            }
            case 7 : {  /* Ordenar */
                if (!ll_isEmpty(listaEstructura)) {
                    controller_sortEstructura(listaEstructura);
                } else {
                    system("cls");
                    printf("NO HAY\n");
                    pausaYClear();
                }
                break;
            }
            case 8 : {  /* Filtrar */
                if (!ll_isEmpty(listaEstructura)) {
                    controller_filterEstructura(listaEstructura);
                } else {
                    system("cls");
                    printf("NO HAY\n");
                    pausaYClear();
                }
                break;
            }
            case 9 : {  /* Guardar texto */
                if (!ll_isEmpty(listaEstructura)) {
                    controller_saveAsText("archivo.csv", listaEstructura);
                    printf("\nGUARDADO archivo.csv");
                } else {
                    system("cls");
                    printf("NO HAY\n");
                }
                pausaYClear();
                break;
            }
            case 10: {  /* Guardar binario */
                if (!ll_isEmpty(listaEstructura)) {
                    controller_saveAsBinary("archivo.bin", listaEstructura);
                    printf("\nGUARDADO archivo.bin\n");
                } else {
                    system("cls");
                    printf("NO HAY\n");
                }
                pausaYClear();
                break;
            }
        }
    } while(opcion!=11);

    return debug;
}
