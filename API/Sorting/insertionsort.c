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

int main(int argc, char* argv[]){
    int toOrder[ELEMENTS] = {0};

    RandomNumbers(toOrder);
    for (int i=0; i<ELEMENTS; i++){
        printf("%d\n", toOrder[i]);
    }
}
