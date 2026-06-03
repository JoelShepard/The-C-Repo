#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ELEMENTS 5

void RandomNumbers(int* array){
    srand(time(NULL));
    for (int i=0; i<ELEMENTS; i++){
        array[i] = rand() % 1000;
    }
}

void CountingSort(int* array){
    int output[ELEMENTS];
    int max = array[0];

    /*Cerca il massimo */
    for (int i=1; i<ELEMENTS; i++){
        if (array[i] > max)
            max = array[i];
    }

    int* count = calloc(max+1, sizeof(int));
    /* Dato che sappiamo che i numeri generati saranno da 0 a 999
    potremmo allocare array count staticamente */
    if (count == NULL) return;

    /* Conta le occorrenze di ciascun valore nell'array */
    for (int i=0; i<ELEMENTS; i++){
        count[array[i]]++;
    }

    /* Calcola le posizioni cumulative per determinare
    l'indice finale di ciascun elemento nell'array ordinato */
    for (int i=1; i<=max; i++){
        count[i] += count[i-1];
    }

    /* Posiziona ogni elemento nell'array di output
    scorrendo da destra verso sinistra per mantenere la stabilita' */
    for (int i=ELEMENTS-1; i>=0; i--){
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    /* Copia l'array ordinato nell'array originale */
    for (int i=0; i<ELEMENTS; i++){
        array[i] = output[i];
    }

    free(count);
}

int main(){
    int toOrder[ELEMENTS] = {0};

    RandomNumbers(toOrder);

    printf("Original array:\n");
    for (int i=0; i<ELEMENTS; i++){
        printf("%d\n", toOrder[i]);
    }

    CountingSort(toOrder);

    printf("\nSorted array:\n");
    for (int i=0; i<ELEMENTS; i++){
        printf("%d\n", toOrder[i]);
    }
}
