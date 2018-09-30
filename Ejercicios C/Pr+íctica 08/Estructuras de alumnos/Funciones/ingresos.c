#include <stdio.h>
#include <stdlib.h>
#define MENSAJES 65

float getFloat(char texto[MENSAJES]) {
    float num;
    printf("%s" , texto);
    scanf("%f" , &num);
    return num;
}

float getFloatBetween(float min, float max, char texto[MENSAJES]) {
    float num;
    printf("%s" , texto);
    scanf("%f" , &num);
    while (num<min || num>max) {
        printf("\n  -Error-\n%s", texto);
        scanf("%f" , &num);
    }
    return num;
}

/////////////////////////////////////////////////////////////////

int getInt(char texto[MENSAJES]) {
    int num;
    printf("%s" , texto);
    scanf("%d" , &num);
    return num;
}

int getIntBetween(int min, int max, char texto[MENSAJES]) {
    int num;
    printf("%s" , texto);
    scanf("%d" , &num);
    while (num<min || num>max) {
        printf("\n  -Error-\n%s", texto);
        scanf("%d" , &num);
    }
    return num;
}

/////////////////////////////////////////////////////////////////

short getShort(char texto[MENSAJES]) {
    short num;
    printf("%s" , texto);
    scanf("%hi" , &num);
    return num;
}

short getShortBetween(short min, short max, char texto[MENSAJES]) {
    short num;
    printf("%s" , texto);
    scanf("%hi" , &num);
    while (num<min || num>max) {
        printf("\n  -Error-\n%s", texto);
        scanf("%hi" , &num);
    }
    return num;
}

/////////////////////////////////////////////////////////////////
