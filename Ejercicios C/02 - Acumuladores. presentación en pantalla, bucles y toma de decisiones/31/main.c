#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Toma datos de un empleado.\n");
    printf("Imprime el ticket de su venta.\n\n");

    char nombre[20];
    short hora;
    short horasEnElMes;
    short antiguedad;
    int totalBruto;
    float descuento;
    float total;

    printf("Nombre:\t\t");
    fflush(stdin);
    gets(nombre);
    printf("Valor hora:\t");
    scanf("%hi", &hora);
    printf("Cantidad de horas:\t");
    scanf("%hi", &horasEnElMes);
    printf("Antiguedad:\t");
    scanf("%hi", &antiguedad);

    totalBruto = (hora*horasEnElMes)+(antiguedad*30);
    descuento = totalBruto*0.13;
    total = (float)totalBruto-descuento;

    printf("\n\nNOMBRE:  %s\n", nombre);
    printf("ANTIGUEDAD:  %hi\n", antiguedad);
    printf("VALOR HORA:  %hi\n", hora);
    printf("-----------------------------\n");
    printf("TOTAL EN BRUTO:  %d\n", totalBruto);
    printf("DESCUENTO:  -%.2f\n", descuento);
    printf("TOTAL A COBRAR:  %.2f\n", total);

    return 0;
}
