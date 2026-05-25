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

    for (int i=1; i<ELEMENTS; i++){
        if (array[i] > max)
            max = array[i];
    }

    int* count = calloc(max+1, sizeof(int));
    /*In questo caso, dato che sappiamo che i numeri generati saranno da 0 a 999
    potremmo allocare questo array staticamente */
    if (count == NULL) return;

    for (int i=0; i<ELEMENTS; i++){
        count[array[i]]++;
    }

    for (int i=1; i<=max; i++){
        count[i] += count[i-1];
    }

    for (int i=ELEMENTS-1; i>=0; i--){
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

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
