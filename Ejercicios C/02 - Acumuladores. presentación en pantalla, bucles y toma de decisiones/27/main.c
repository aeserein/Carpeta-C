#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Lee los lados de un tri%cngulo.\n", 160);
    printf("Devuelve si los lados forman un tri%cngulo y de qu%c tipo es.\n\n", 160, 130);
    int lados[3];
    int menor, medio, mayor;
    short bEsTriangulo = 0;
    short f;

    for (f=0 ; f<3 ; f++) {
        printf("Lado %hi:\t", f);
        scanf("%d", &lados[f]);
    }
    if (lados[0]>=lados[1] && lados[0]>=lados[2]) {
        mayor = lados[0];
        if (lados[1]>=lados[2]) {
            medio = lados[1];
            menor = lados[2];
        } else {
            medio = lados[2];
            menor = lados[1];
        }
    } else if (lados[1]>=lados[0] && lados[1]>=lados[2]) {
        mayor = lados[1];
        if (lados[0]>=lados[2]) {
            medio = lados[0];
            menor = lados[2];
        } else {
            medio = lados[2];
            menor = lados[0];
        }
    } else {
        mayor = lados[2];
        if (lados[0]>=lados[1]) {
            medio = lados[0];
            menor = lados[1];
        } else {
            medio = lados[1];
            menor = lados[0];
        }
    }
    printf("\nMayor: %d\n", mayor);
    printf("Medio: %d\n", medio);
    printf("Menor: %d", menor);

    if ((menor+medio)>mayor) {
        bEsTriangulo = 1;
    }

    printf("\n");
    if (bEsTriangulo) {
        if(menor==medio && medio==mayor) {
            printf("Tri%cngulo equil%ctero", 160, 160);
        } else if (menor!=medio && medio!= mayor) {
            printf("Tri%cngulo escaleno", 160);
        } else if (mayor==medio && medio>menor) {
            printf("Tri%cngulo is%cceles", 160, 162);
        } else {
            printf("Error");
        }
    } else {
        printf("No es tri%cngulo", 160);
    }

    printf("\n");
    return 0;
}
