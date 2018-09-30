#include <stdio.h>
#include <stdlib.h>

typedef struct {
    short dia;
    short mes;
    short anio;
} fecha;

typedef struct {
    int id;
    char nombre[50];
    fecha nacimiento;
    fecha ingreso;
} empleado;

int main() {

    empleado cacho;

    cacho.nacimiento.dia = 10;
    cacho.nacimiento.mes = 5;
    cacho.nacimiento.anio = 3;

    printf("\n");
    return 0;
}
