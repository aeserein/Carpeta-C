#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Lee 20 caracteres. Devuelve la cantidad de vocales.\n\n");
    char letra;
    int f;
    int cantidadA = 0;
    int cantidadE = 0;
    int cantidadI = 0;
    int cantidadO = 0;
    int cantidadU = 0;

    for (f=0 ; f<20 ; f++){
        fflush(stdin);
        printf("Ingrese letra:\t");
        scanf("%c" , &letra);

        letra = tolower(letra);
        switch (letra) {
            case 'a' : {
                cantidadA++;
                break;
            }
            case 'e' : {
                cantidadE++;
                break;
            }
            case 'i' : {
                cantidadI++;
                break;
            }
            case 'o' : {
                cantidadO++;
                break;
            }
            case 'u' : {
                cantidadU++;
            }
        }

    }

    printf("\nLetras 'a':\t%d" , cantidadA);
    printf("\nLetras 'e':\t%d" , cantidadE);
    printf("\nLetras 'i':\t%d" , cantidadI);
    printf("\nLetras 'o':\t%d" , cantidadO);
    printf("\nLetras 'u':\t%d\n" , cantidadU);
    return 0;

}
