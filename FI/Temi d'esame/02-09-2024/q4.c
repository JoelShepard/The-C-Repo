/* q4.c - C source file. */

#include <stdio.h>
#include <wchar.h>

/* *
Array con i giorni di ogni mese (considerando anno bisestile per febbraio)
Indici: 0=Gen, 1=Feb, 2=Mar, ..., 11=Dic
 */
const int anno[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/* *
Struttura per rappresentare una data (giorno e mese)
 */
typedef struct {
    int giorno;                    // Giorno del mese (1-31)
    int mese;
} Data;

int differenza(Data a, Data b){
    // VALIDAZIONE: controllo giorni validi per ogni mese
    if (a.giorno > anno[a.mese - 1]) {
        printf("prima data non valida");
        return -1;
    }
    if (b.giorno > anno[b.mese - 1]) {
        printf("seconda data non valida");
        return -1;
    }
    
    // CONTROLLO ORDINE: la prima data deve essere <= della seconda
    if (a.mese > b.mese) {
        printf("inverti l'ordine delle date");
        return -1;
    }
    if (a.mese == b.mese && a.giorno > b.giorno) {
        printf("inverti l'ordine delle date");
        return -1;
    }

    int diff = 0, mdiff = 0;

    // CALCOLO DIFFERENZA MESI: mesi tra le due date (esclusi)
    mdiff = b.mese - a.mese - 1;
    
    // GIORNI RIMANENTI: dal giorno di partenza alla fine del mese
    diff = anno[a.mese-1] - a.giorno;

    // MESI INTERMEDI: somma tutti i giorni dei mesi tra le date
    for (int i = 0; i < mdiff; i++) {
        // CORREZIONE BUG: era a.mese+i, ora corretto come a.mese+i
        diff = diff + anno[a.mese + i]; 
    }
    
    // GIORNI FINALI: aggiungi i giorni del mese di arrivo
    diff = diff + b.giorno;
    
    return diff;
}

int main(int argc, char* argv[]){
    FILE* file;
    char buffer[1024];
    
    // VALIDAZIONE ARGOMENTI: deve essere fornito il nome del file
    if (argc != 2) {
        printf("Uso: %s <nome_file>\n", argv[0]);
        printf("Parametri inseriti non validi\n");
        return 1;
    }
    
    // APERTURA FILE: modalità lettura
    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Apertura del file non andata a buon fine\n");
        return 1;
        
    // CONTEGGIO RIGHE: prima passata per contare quante righe ci sono
    int count = 0;
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        count++;
    }
    
    // RESET FILE: riporta il puntatore all'inizio
    rewind(file);
    
    Data tmpa, tmpb;                       // Date temporanee per ogni soggiorno
    
    for (int i = 0; i < count; i++) {
        // LETTURA: 4 valori per row (giorno1 mese1 giorno2 mese2)
        fscanf(file, "%d %d %d %d", &tmpa.giorno, &tmpa.mese, &tmpb.giorno, &tmpb.mese);
        
        // CALCOLO: differenza in giorni tra le date
        int diff = differenza(tmpa, tmpb);
        
        if (diff >= 0) {
            printf("L'ospite %d ha soggiornato per %d giorni\n", i+1, diff);
        }
    }
    

    fclose(file);
    return 0;
}
