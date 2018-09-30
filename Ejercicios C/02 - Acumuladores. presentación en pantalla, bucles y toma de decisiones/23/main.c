#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Lee tres n%cmeros, devuelve el mayor.\n\n" , 163);

    int a, b, c;
    int max;

    printf("A:\t");
    scanf("%d" , &a);
    printf("B:\t");
    scanf("%d" , &b);
    printf("C:\t");
    scanf("%d" , &c);

    if (a>=b) {
        if (a>=c) {
            max = a;
        } else {
            max = c;
        }
    } else if (b>=c) {
        max = b;
    } else {
        max = c;
    }

    printf("MAX:\t%d", max);

    return 0;
}
