#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Lee la caida de lluvia por d%ca durante un mes.\n" , 161);
    printf("Devuelve m%cximo, m%cnimo y promedio\n\n" , 160 , 161);

    int agua;
    int f;
    int minimo;
    int maximo;
    int aAgua = 0;
    float promedio;

    printf("Ingrese cantidad de agua en mil%cmetros:\n" , 161);
    for (f=0 ; f<30 ; f++) {
        printf("D%ca %d:\t" , 161 , f+1);
        scanf("%d" , &agua);
        if (f==0) {
            minimo = agua;
            maximo = agua;
        }
        if (agua>maximo) maximo=agua;
        if (agua<minimo) minimo=agua;
        aAgua += agua;
    }
    promedio = (float)aAgua/30;
    printf("\n");

    printf("Cantidad m%cxima de agua en un d%ca:\t%d mil%cmetros\n" , 160 , 161 , maximo , 161);
    printf("Cantidad m%cnima de agua en un d%ca:\t%d mil%cmetros\n" , 161 , 161 , minimo , 161);
    printf("Promedio:\t\t%.2f\n" , promedio);
    return 0;
}
