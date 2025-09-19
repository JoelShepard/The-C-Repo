/* 2_labirinto.c - C source file. */

#include <stdio.h>   // Per file I/O, printf
#include <math.h>    // Per sqrt() - calcolo radice quadrata
#include <stdlib.h>  // Per malloc, free

/* *
================================================================
FUNZIONE DI VALIDAZIONE E CONTEGGIO ELEMENTI
================================================================

Parametri:
file - Puntatore al file CSV da analizzare

Ritorna:
int - Numero totale di elementi validi (0 e 1), -1 se formato invalido

Features:
- Conta tutti gli elementi 0 e 1 nel file
- Valida che il file contenga solo characters permessi
- Ignora separatori (virgole) e newline
- Riporta errore per characters non validi
 */
int count_check(FILE* file){
    rewind(file);  // Torna all'inizio del file per analisi completa
    int count = 0; // Contatore elementi validi
    char c;        // Character corrente in lettura
    
    // Scansione character per character del file
    while ((c = getc(file)) != EOF) {
        if (c == '1'){
            count++;  // Conta muri/ostacoli
        } if (c =='0') {
            count++;  // Conta passaggi liberi
        } if (c == ',') {
            continue; // Ignora separatori CSV
        } if (c == '\n') {
            continue; // Ignora fine row
        } if (c != '1' && c != '0' && c != '\n' && c != ',') {
            return -1; // Character non valido trovato
        }
    }
    return count; // Restituisce numero totale elementi validi
}

/* *
================================================================
FUNZIONE DI COSTRUZIONE MATRICE DINAMICA
================================================================

Parametri:
lab - Puntatore al file CSV contenente il labirinto

Ritorna:
int** - Puntatore alla matrix bidimensionale allocata dinamicamente
NULL in caso di errore di allocazione

Features:
- Calcola dimensioni della matrix quadrata (sqrt del numero elementi)
- Alloca dinamicamente array di puntatori (righe)
- Alloca dinamicamente ogni row della matrix
- Legge valori dal CSV e popola la matrix
- Gestisce errori con cleanup completo della memoria
 */
int** matrix(FILE* lab){
    int elems = count_check(lab);     // Numero totale di elementi
    int rows = sqrt(count_check(lab)); // Size matrix quadrata
    rewind(lab);                      // Torna all'inizio per lettura dati
    
    // ================================================================
    // ALLOCAZIONE DINAMICA DELL'ARRAY DI PUNTATORI (RIGHE)
    // ================================================================
    int** matrix = (int**)malloc(sizeof(int*) * rows);
    if (matrix == NULL) {
        printf("Errore di allocazione dell'array dinamico.\n");
        return NULL;
    }
    
    // ================================================================
    // ALLOCAZIONE DINAMICA DI OGNI RIGA DELLA MATRICE
    // ================================================================
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * rows);
        if (matrix[i] == NULL) {
            printf("Errore di allocazione dell'array dinamico.\n");
            // Cleanup: libera tutte le righe già allocate
            for(int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }
    }
    
    // ================================================================
    // LETTURA E INSERIMENTO DATI DAL FILE CSV
    // ================================================================
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            fscanf(lab, "%d,", &matrix[i][j]); // Legge numero e ignora virgola
        }
    }

    return matrix; // Restituisce matrix completamente popolata
}


/* *
================================================================
FUNZIONE PRINCIPALE - GESTIONE LABIRINTO
================================================================
 */
int main(){
    FILE* lab; // Puntatore al file del labirinto

    // ================================================================
    // FASE 1: APERTURA E VALIDAZIONE FILE
    // ================================================================
    lab = fopen("labirinto.csv", "r");
    if (lab == NULL) {
        printf("Apertura di labirinto.csv non riuscita.\n");
        return -1;
    }

    // Validazione formato file (solo characters 0, 1, virgole, newline)
    if (count_check(lab) == -1) {
        printf("Errore. Il file inserito contiene caratteri non validi.\n");
        return -1;
    }

    // ================================================================
    // FASE 2: VERIFICA MATRICE QUADRATA
    // ================================================================
    int n = count_check(lab);              // Numero totale elementi
    int row = sqrt(n);                     // Size lato matrix
    
    // Verifica che sqrt(n) sia un numero intero (matrix quadrata)
    if (sqrt(count_check(lab)) != (int)sqrt(count_check(lab))) {
        printf("Errore. La matrice non è quadrata.\n");
        return -1;
    }
    
    // ================================================================
    // FASE 3: COSTRUZIONE MATRICE IN MEMORIA
    // ================================================================
    int** res = matrix(lab); // Costruisce la matrix dinamica del labirinto
    
    // TODO: Aggiungere funzionalità di elaborazione del labirinto
    // (es: ricerca percorsi, risoluzione, prints)
    
    // Note: Manca la deallocazione della memoria (memory leak)
    // Dovrebbe essere aggiunto cleanup con free() prima del return

    return 0;
}
