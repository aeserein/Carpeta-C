#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    printf("Registra nombre y peso de empleados.\n");
    printf("Devuelve cu%cntos pesan hasta 80kg y cu%cntos pesan m%cs de 80\n\n", 160, 160, 160);

    char respuesta=' ';
    short peso;
    char nombre[50];
    short hasta80=0, masDe80=0;

    do {
        if (respuesta=='S') printf("\n");
        printf("Ingrese nombre:\t");
        fflush(stdin);
        gets(nombre);
        printf("Ingrese peso:\t");
        scanf("%hi", &peso);

        if(peso>80) {
            masDe80++;
        } else {
            hasta80++;
        }
        printf("\n%cDesea ingresar m%cs datos? S/N ", 168, 160);
        fflush(stdin);
        respuesta = getchar();
        respuesta = toupper(respuesta);
    } while (respuesta=='S');
    system("cls");
    printf("\nEmpleados hasta 80kg: %d", hasta80);
    printf("\nEmpleados sobre 80kg: %d\n", masDe80);

    return 0;
}
