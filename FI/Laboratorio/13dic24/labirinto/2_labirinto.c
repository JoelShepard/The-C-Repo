/**
 * ================================================================
 * LETTORE E PROCESSORE DI LABIRINTI DA FILE CSV
 * ================================================================
 * 
 * Descrizione:
 *   Programma per la lettura e gestione di labirinti rappresentati in formato
 *   CSV come matrici quadrate di 0 (passaggio libero) e 1 (muro/ostacolo).
 *   Il programma valida il formato del file e costruisce una rappresentazione
 *   in memoria del labirinto.
 * 
 * Funzionalità:
 *   - Lettura da file CSV "labirinto.csv"
 *   - Validazione caratteri (solo 0, 1, virgole, newline)
 *   - Verifica che la matrice sia quadrata
 *   - Allocazione dinamica della matrice bidimensionale
 *   - Gestione errori di formato e memoria
 *
 * Autore: Joel (Laboratorio del 13 dicembre 2024)
 * Corso: Fondamenti di Informatica
 * 
 * Note tecniche:
 *   - Utilizza sqrt() per determinare dimensioni matrice quadrata
 *   - Allocazione dinamica con controllo errori e cleanup
 *   - Formato CSV: valori separati da virgole, righe da newline
 * ================================================================
 */

#include <stdio.h>   // Per file I/O, printf
#include <math.h>    // Per sqrt() - calcolo radice quadrata
#include <stdlib.h>  // Per malloc, free

/**
 * ================================================================
 * FUNZIONE DI VALIDAZIONE E CONTEGGIO ELEMENTI
 * ================================================================
 * 
 * Parametri:
 *   file - Puntatore al file CSV da analizzare
 * 
 * Ritorna:
 *   int - Numero totale di elementi validi (0 e 1), -1 se formato invalido
 * 
 * Funzionalità:
 *   - Conta tutti gli elementi 0 e 1 nel file
 *   - Valida che il file contenga solo caratteri permessi
 *   - Ignora separatori (virgole) e newline
 *   - Riporta errore per caratteri non validi
 */
int count_check(FILE* file){
    rewind(file);  // Torna all'inizio del file per analisi completa
    int count = 0; // Contatore elementi validi
    char c;        // Carattere corrente in lettura
    
    // Scansione carattere per carattere del file
    while ((c = getc(file)) != EOF) {
        if (c == '1'){
            count++;  // Conta muri/ostacoli
        } if (c =='0') {
            count++;  // Conta passaggi liberi
        } if (c == ',') {
            continue; // Ignora separatori CSV
        } if (c == '\n') {
            continue; // Ignora fine riga
        } if (c != '1' && c != '0' && c != '\n' && c != ',') {
            return -1; // Carattere non valido trovato
        }
    }
    return count; // Restituisce numero totale elementi validi
}

/**
 * ================================================================
 * FUNZIONE DI COSTRUZIONE MATRICE DINAMICA
 * ================================================================
 * 
 * Parametri:
 *   lab - Puntatore al file CSV contenente il labirinto
 * 
 * Ritorna:
 *   int** - Puntatore alla matrice bidimensionale allocata dinamicamente
 *           NULL in caso di errore di allocazione
 * 
 * Funzionalità:
 *   - Calcola dimensioni della matrice quadrata (sqrt del numero elementi)
 *   - Alloca dinamicamente array di puntatori (righe)
 *   - Alloca dinamicamente ogni riga della matrice
 *   - Legge valori dal CSV e popola la matrice
 *   - Gestisce errori con cleanup completo della memoria
 */
int** matrix(FILE* lab){
    int elems = count_check(lab);     // Numero totale di elementi
    int rows = sqrt(count_check(lab)); // Dimensione matrice quadrata
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

    return matrix; // Restituisce matrice completamente popolata
}


/**
 * ================================================================
 * FUNZIONE PRINCIPALE - GESTIONE LABIRINTO
 * ================================================================
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

    // Validazione formato file (solo caratteri 0, 1, virgole, newline)
    if (count_check(lab) == -1) {
        printf("Errore. Il file inserito contiene caratteri non validi.\n");
        return -1;
    }

    // ================================================================
    // FASE 2: VERIFICA MATRICE QUADRATA
    // ================================================================
    int n = count_check(lab);              // Numero totale elementi
    int row = sqrt(n);                     // Dimensione lato matrice
    
    // Verifica che sqrt(n) sia un numero intero (matrice quadrata)
    if (sqrt(count_check(lab)) != (int)sqrt(count_check(lab))) {
        printf("Errore. La matrice non è quadrata.\n");
        return -1;
    }
    
    // ================================================================
    // FASE 3: COSTRUZIONE MATRICE IN MEMORIA
    // ================================================================
    int** res = matrix(lab); // Costruisce la matrice dinamica del labirinto
    
    // TODO: Aggiungere funzionalità di elaborazione del labirinto
    // (es: ricerca percorsi, risoluzione, stampa)
    
    // Nota: Manca la deallocazione della memoria (memory leak)
    // Dovrebbe essere aggiunto cleanup con free() prima del return

    return 0;
}
