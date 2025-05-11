#include <stdio.h>
#include <wchar.h>

const int anno[12]={31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

typedef struct {
    int giorno;
    int mese;
} Data;

int differenza(Data a, Data b){
    //validity check
    if (a.giorno > anno[a.mese - 1]) {
        printf("prima data non valida");
        return -1;
    }
    if (b.giorno > anno[b.mese - 1]) {
        printf("seconda data non valida");
        return -1;
    }
    if (a.mese > b.mese) {
        printf("inverti l'ordine delle date");
        return -1;
    }
    if (a.mese == b.mese && a.giorno > b.giorno) {
        printf("inverti l'ordine delle date");
        return -1;
    }

    int diff = 0, mdiff=0;

    mdiff = b.mese - a.mese - 1;
    diff = anno[a.mese-1] - a.giorno;

    for (int i = 0; i<mdiff; i++) {
        diff = diff + anno[a.mese+i]; // errore per colpa di un -1 che non serviva. Stai attento nei for
    }
    diff = diff + b.giorno;
    return diff;
}

int main(int argc, char* argv[]){
    FILE* file;
    char buffer[1024];
    if (argc != 2) {
        printf("Parametri inseriti non validi");
    }
    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Apertura del file non andata a buon fine");
    }
    int count=0;
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        count++;
    }
    rewind(file);
    Data tmpa, tmpb;
    for (int i=0; i<count; i++) {
        fscanf(file, "%d %d %d %d", &tmpa.giorno, &tmpa.mese, &tmpb.giorno, &tmpb.mese);
        int diff = differenza(tmpa, tmpb);
        printf("L'ospite %d ha soggiornato per %d giorni\n", i+1, diff);
    }
}
