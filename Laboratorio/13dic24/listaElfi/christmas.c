#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct el{
    char name[50];
    int weight;
    int qty;
    struct el* next;
}Gift;
typedef Gift* List;


int main(int argc, char* argv[]){
    if (argc != 2) {
        printf("Errore, parametri non validi\n");
    }
    FILE* elfList = fopen(argv[1], "r");
    if (elfList == NULL) {
        printf("Apertura del file non riuscita\n");
    }
}
