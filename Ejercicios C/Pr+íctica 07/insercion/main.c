#include <stdio.h>
#include <stdlib.h>

void insertion(int[], int);
void burbujeo(int[], int);

int main() {

    int vector[5] = {3,5,1,2,6};
    int i;
    burbujeo(vector, 5);
    for (i=0 ; i<5 ; i++) {
        printf("%d\t" , vector[i]);
    }

    printf("\n");
    return 0;
}

void insertion(int data[], int len) {
    int f;
    int j;
    int temp;
    for (f=1 ; f<len ; f++) {
        temp = data[f];
        j = f-1;
        while (j>=0 && temp<data[j]) {
            data[j+1] = data[j];
            j--;
        }
        data[j+1] = temp; //insertion
    }
}

void burbujeo(int data[], int len) {
    int p;
    int r;
    int aux;
    for (p=0 ; p<len-1 ; p++){
        for (r=p+1 ; r<len ; r++) {
            if (data[p]>data[r]) {
                aux = data[r];
                data[r] = data[p];
                data[p] = aux;
            }
        }
    }
}
