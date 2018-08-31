#include <stdio.h>
#include <stdlib.h>

int main() {

    int unInt = 1; //4 bytes
    float unFloat = 3.5; //4 bytes
    char unChar = 'a'; //1 byte
    float suma;
    float division;
    int n1;
    int n2;

    printf("Int: %d\n" , unInt);    // para int %d
    printf("Float: %f\n" , unFloat);  // para float %f
    printf("Char: %c\n\n\n" , unChar);       // para char %c

    unInt = 2;
    unFloat = 4.6;
    unChar = 'A';

    printf("   ooooooo           ooooooo           ooooooo           ooooooo   \n");
    printf(" ooooooooooo       ooooooooooo       ooooooooooo       ooooooooooo \n");
    printf("oooo     oooo     oooo     oooo     oooo     oooo     oooo     oooo\n");
    printf("ooo   X   ooo     ooo   X   ooo     ooo   X   ooo     ooo   X   ooo\n");
    printf("oooo     oooo     oooo     oooo     oooo     oooo     oooo     oooo\n");
    printf(" ooooooooooo       ooooooooooo       ooooooooooo       ooooooooooo \n");
    printf("   ooooooo           ooooooo           ooooooo           ooooooo   \n\n\n");

    printf("Int: %d\nFloat: %f\nChar: %c\n\n" , unInt , unFloat , unChar);

    // scanf(máscara , dirección de la memoria de la variable);
    printf("Ingresar int:\t");
    scanf("%d" , &unInt); // & antes de la variable me devuelve la dirección de la variable

    printf("Ingresar float:\t");
    scanf("%f" , &unFloat);

    printf("Ingresar char:\t");
    scanf("%c" , &unChar);

    printf("\n\nInt: %d\n" , unInt);
    printf("Float: %f\n" , unFloat);
    printf("Float con tres decimales: %.3f\n" , unFloat); //%.3f -> 3 decimales
    printf("Float con un decimal: %.1f\n" , unFloat);
    printf("Char: %c\n" , unChar);

    /* El char guarda automáticamente lo último que se ingresó al buffer
       en la interacción anteror. En este caso, el enter de cuando
       terminé de mandar el dato anterior del float.    */

    printf("Ingresar char bien:\t");
    fflush(stdin);      // o bien setbuf(stdin,NULL);
    scanf("%c" , &unChar);

    printf("\nDirecci%cn decimal del int: %d\n" , 162 , &unInt);
    printf("Direcci%cn decimal del float: %d\n" , 162 , &unFloat);
    printf("Direcci%cn decimal del char: %d\n\n" , 162 , &unChar); // warning: format '%d' expects argument of type int

    printf("Direcci%cn hexadecimal del int: %p\n" , 162 , &unInt); //%p para hexadecimal
    printf("Direcci%cn hexadecimal del float: %p\n" , 162 , &unFloat);
    printf("Direcci%cn hexadecimal del char: %p\n\n" , 162 , &unChar);

    suma = unInt + unFloat;
    division = unInt / unFloat;

    printf("Int + float: %.3f\n" , suma);
    printf("Int / float: %.3f\n\n" , division);

    printf("Ingresar int N1:\t");
    scanf("%d" , &n1);
    printf("Ingresar int N2:\t");
    scanf("%d" , &n2);

    division = (float)n1 / n2;

    printf("\nDivisi%cn: %.1f\n" , 162 , division);

    return 0;

}
