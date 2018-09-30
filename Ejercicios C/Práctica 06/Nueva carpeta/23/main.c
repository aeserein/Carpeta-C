#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Lee tres n%cmeros. Devuelve el mayor\n\n" , 163);
    int numero1;
    int numero2;
    int numero3;
    int max;

    printf("Primer n%cmero:\t" , 163);
    scanf("%d" , &numero1);
    printf("Segundo n%cmero:\t" , 163);
    scanf("%d" , &numero2);
    printf("Tercer n%cmero:\t" , 163);
    scanf("%d" , &numero3);

    if (numero1>=numero2) {
        if (numero1>=numero3) {
            max = numero1;
        } else {
            max = numero3;
        }
    } else {
        if (numero2>=numero3) {
            max = numero2;
        } else {
            max = numero3;
        }
}

    printf("MAX:\t%d" , max);
    return 0;
}
