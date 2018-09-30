#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#define DIR 1000

int main() {

    int vector[DIR];

    cargarVectorInt(vector, DIR, -1);
    mostrarVectorInt(vector, DIR);

    printf("\n");
    return 0;

}
