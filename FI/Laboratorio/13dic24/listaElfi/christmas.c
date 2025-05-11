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

void stamp(List my){
    printf("Nome\t Peso\t Quantità\n");
    while (my != NULL) {
        printf("%s\t %d\t %d\n", my->name, my->weight, my->qty);
        my = my->next;
    }
}

void deletedoubles(List my){

}



Gift* create(Gift* prev){
    prev->next = (Gift*)malloc(sizeof(Gift));
    prev->next->next = NULL;
    return prev->next;
}

void read(FILE* elf, List* my){
    char tmpn[50], buffer[1024];
    int tmpw, tmpq, count=0;
    while (fgets(buffer, sizeof(buffer), elf) != NULL) {
        count++;
    }
    rewind(elf);
    Gift* tmp = *my;

    for (int i=0; i<count; i++) {
        fscanf(elf, "%s %d %d\n", tmpn, &tmpw, &tmpq);
        if (tmp == NULL) {
            tmp = (Gift*)malloc(sizeof(Gift));
            *my = tmp;
        } else {
            tmp = create(tmp);
        }
        strcpy(tmp->name, tmpn);
        tmp->weight = tmpw;
        tmp->qty = tmpq;
        }

}


int main(int argc, char* argv[]){
    if (argc != 2) {
        printf("Errore, parametri non validi\n");
    }
    FILE* elfList = fopen(argv[1], "r");
    if (elfList == NULL) {
        printf("Apertura del file non riuscita\n");
    }
    List mylist;

    read(elfList, &mylist);
    deletedoubles(mylist);

    printf("%s", mylist->next->name);
}
