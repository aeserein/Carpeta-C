#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Devuelve los n%cmeros 3, 6, 9, 12, ...99\n\n" , 163);
    int f;

    for(f=3 ; f<=99 ; f=f+3) {
        printf("%d " , f);
    }

    printf("\n");
    return 0;

}
