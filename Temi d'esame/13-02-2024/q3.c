#include <stdio.h>
#include <string.h>

int minutiLavorati(FILE * db, char code[5]){
    char tmpcode[5];
    char buffer[1024];
    int ora=0, min=0, count=0, tot=0, init = 0, flag = 0;

    while (fgets(buffer, sizeof(buffer), db) != NULL) {
        count++;
    }
    rewind(db);

    for (int i=0; i<count; i++) {
        fscanf(db, "%d %d %s", &ora, &min, tmpcode);
        if (strcmp(code, tmpcode) == 0) {
            tot = ora*60 + min - tot;
        }
    }
    if (tot == 0) {
        return 0;
    }
    return tot;
}

int main(int argc, char* argv[]){
    if (argc == 2) {
        char buffer[1024];
        FILE * db = fopen(argv[1], "r");
        if (db == NULL) {
            printf("Errore apertura file\n");
        }
        while (fgets(buffer, sizeof(buffer), db) != NULL) {
            printf("%s", buffer);
        }
    }
    if (argc == 3) {
        FILE * db = fopen(argv[1], "r");
        if (db == NULL) {
            printf("Errore apertura file\n");
        }
        int min = minutiLavorati(db, argv[2]);
        printf("Il dipendente %s ha lavorato per %d minuti\n", argv[2], min);
    }
}
