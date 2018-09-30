#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Intercambia dos variables\n\n");

    int num1, num2;
    int aux;

    printf("Ingresar num1:\t");
    scanf("%d" , &num1);
    printf("Ingresar num2:\t");
    scanf("%d" , &num2);

    printf("NUM1:\t%d\n", num1);
    printf("NUM2:\t%d\n\n", num2);
    printf("----Swap----\n\n");

    aux = num1;
    num1 = num2;
    num2 = aux;

    printf("NUM1:\t%d\n", num1);
    printf("NUM2:\t%d\n\n", num2);

    return 0;
}
