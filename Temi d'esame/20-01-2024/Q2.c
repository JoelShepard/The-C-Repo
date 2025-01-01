#include <stdio.h>
#include <string.h>
#define MAX_PROD 100

typedef struct {
    char name[30];
    int qta;
} elem;

void Ripulisci(FILE *fin, FILE *fout){
    elem list[MAX_PROD];
    char c;
    int count = 1;

    while((c = fgetc(fin)) != EOF){
        if(c == '\n'){
            count++;
        }
    }

    //insert
    rewind(fin);
    for(int i=0; i<count; i++){
        fscanf(fin, "%s %d\n", list[i].name, &(list[i].qta));
    }

    //clean up
    int i=0, j=0;
    for(i=0; i<count; i++){
        int ptot=0;
        if (list[i].qta == -1) {
            continue;
        }
        for(j=i+1; j<count; j++){
            if(strcmp(list[j].name, list[i].name)==0){
                ptot = ptot + list[j].qta;
                list[j].qta = -1;
            }
        }
        fprintf(fout,"%s %d\n", list[i].name, list[i].qta+ptot);
    }
}

int main(int argc, char* argv[]) {
    FILE *fin, *fout;

    if (argc != 3) {
        printf("Errore nei parametri del programma.\n");
        return -1;
    }

    // Apertura file di input
    fin = fopen(argv[1], "r");
    if (fin == NULL) {
        printf("Errore nell'apertura del file di input\n");
        return 1;
    }

    // Apertura file di output
    fout = fopen(argv[2], "w");
    if (fout == NULL) {
        printf("Errore nell'apertura del file di output\n");
        fclose(fin);
        return 1;
    }

    // Chiamata alla funzione Ripulisci
    Ripulisci(fin, fout);

    // Chiusura dei file
    fclose(fin);
    fclose(fout);

    printf("Elaborazione completata con successo!\n");
    return 0;
}
