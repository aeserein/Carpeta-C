#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Lee dos valores en una variable cada uno.\n");
    printf("Intecambia los valores de ambas variables.\n\n");
    int num1;
    int num2;
    int aux;

    printf("Ingresar n%cmero 1:\t" , 163);
    scanf("%d" , &num1);
    printf("Ingresar n%cmero 2:\t" , 163);
    scanf("%d" , &num2);

    printf("\n");
    printf("NUM1:\t%d\n" , num1);
    printf("NUM2:\t%d\n" , num2);

    aux = num1;
    num1 = num2;
    num2 = aux;

    printf("\n");
    printf("NUM1:\t%d\n" , num1);
    printf("NUM2:\t%d\n" , num2);

    return 0;
}
