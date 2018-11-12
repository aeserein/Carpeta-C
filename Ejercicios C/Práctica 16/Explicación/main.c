#include <stdio.h>
#include <stdlib.h>

void mostrar(int x);
void mostrarDos(int x);

int incrementar(int x);

void manejador(void (*pFunc)(int), int valor);

int main() {
    void (*pFunc)(int);
    int (*pFunc_Int)(int);
    void (*pFunc_Array[2])(int);
    int x = 0;
    short f;

    do {
        pFunc = mostrar;
        pFunc(55);

        pFunc = mostrarDos;
        pFunc(4123);
    } while(0);

    do {
        pFunc_Int = incrementar;
        printf("X: %d\n", x);
        x = pFunc_Int(x);
        printf("X: %d\n", x);
    } while(0);

    do {
        manejador(mostrar, 75);
    } while(0);

    do {
        pFunc_Array[0] = mostrar;
        pFunc_Array[1] = mostrarDos;

        for (f=0 ; f<2 ; f++) {
            pFunc_Array[f](100);
        }
    } while(0);

    return 0;
}

void mostrar(int x) {
    printf("MOSTRAR - %d\n", x);
}

void mostrarDos(int x) {
    printf("MOSTRAR DOS - %d\n", x);
}

int incrementar(int x) {
    x+=1000;
    return x;
}

void manejador(void (*pFunc)(int), int valor) {
    printf("\nMANEJADOR\n");
    pFunc(valor);
 }
