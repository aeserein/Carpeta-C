#include <stdio.h>
#include <stdlib.h>

float ingresarFloat(char texto[32]) {
    float n;
    printf("%s" , texto);
    scanf("%f" , &n);
    return n;
}

int ingresarInt(char texto[32]) {
    int n;
    printf("%s" , texto);
    scanf("%d" , &n);
    return n;
}
