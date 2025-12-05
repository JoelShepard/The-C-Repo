/* 2o_q2.c - C source file. */

#include <stdio.h>

void order(int a[], int b[], int size_a, int size_b, int c[]) {
    if (size_a == 0 && size_b == 0) {
        return;
    }

    // === CASO: PRIMO ARRAY ESAURITO ===
    if (size_a == 0) {
        *c = *b;  // Copia elemento dal secondo array
        order(a, b+1, size_a, size_b-1, c+1);
        return;
    }

    // === CASO: SECONDO ARRAY ESAURITO ===
    if (size_b == 0) {
        *c = *a;  // Copia elemento dal primo array
        order(a+1, b, size_a-1, size_b, c+1);
        return;
    }

    if (*a < *b) {
        *c = *a;  // Elemento del primo array è minore
        order(a+1, b, size_a-1, size_b, c+1);
    } else {
        *c = *b;  // Elemento del secondo array è minore o uguale
        order(a, b+1, size_a, size_b-1, c+1);
    }
}

/* *
Function principale - test dell'algoritmo di merge ricorsivo
 */
int main(){
    int a[]={1,2};              // Primo array ordinato (2 elementi)
    int b[]={3,5,9,11,14};      // Secondo array ordinato (5 elementi) 
    int c[7]={0};               // Array risultante (7 elementi totali)

    order(a, b, 2, 5, c);
    
    printf("Array risultante dal merge: ");
    for (int i=0; i<7; i++) {
        printf("%d ", c[i]);
    }
    printf("\n");
    
    return 0;
}
