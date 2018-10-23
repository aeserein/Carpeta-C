#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Una tienda tiene 3 empleados, cada uno con un n%cmero.\n", 163);
    printf("Se ingresa cada venta de cada uno\ny se calcula el 5%c de comisi%cn que se lleva cada uno\n\n", 37, 162);
    short empleados[3];
    short empleado;
    int venta;
    int ventaAcuumulada[3];
    short f;

    for (f=0; f<3; f++) {
        ventaAcuumulada[f] = 0;
    }

    for (f=0; f<3; f++) {
        printf("Ingrese n%cmero del empleado %d (Dif. a 0):\t", 163, f);
        do {
            scanf("%hi", &empleados[f]);
        } while (empleados[f]==0);
    }
    do {
        do {
            printf("\n");
            for (f=0; f<3; f++) {
                printf("Empleado %d\n", empleados[f]);
            }
            printf("\nIngrese empleado:\t");
            scanf("%hi", &empleado);
        } while (empleado!=empleados[0] && empleado!=empleados[1] && empleado!=empleados[2] && empleado!=0);
        if (empleado!=0) {
            printf("Ingrese venta:\t");
            scanf("%d", &venta);
            for (f=0 ; f<3 ; f++) {
                if (empleado==empleados[f]) {
                    ventaAcuumulada[f] += venta;
                }
            }
        }
    } while (empleado!=0);

    printf("\n");
    for (f=0 ; f<3 ; f++) {
        printf("Comisi%cn del empleado %hi: %.2f\n", 162, empleados[f], (float)(ventaAcuumulada[f]*0.05));
    }
    return 0;
}
