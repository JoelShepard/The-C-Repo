/**
 * File: q3.c
 * Descrizione: Simulatore di percorso in un labirinto 3x3 con sequenza di mosse predefinite
 *              Verifica se un percorso è valido evitando gli ostacoli
 * Autore: [Studente]
 * Data: 28-08-2023
 * Tema d'esame: Navigazione in labirinto con controllo collisioni
 * 
 * Commento originale: "Complicatuccio"
 * 
 * Struttura labirinto:
 * - 0 = casella libera (percorribile)
 * - 1 = ostacolo (muro)
 * - Partenza sempre da posizione (0,0)
 */

#include <stdio.h>

#define MOSSE 20                          // Numero massimo di mosse possibili
#define N 3                               // Altezza del labirinto
#define M 3                               // Larghezza del labirinto

/**
 * Struttura per rappresentare coordinate 2D nel labirinto
 */
typedef struct {
    int x;                                // Coordinata verticale (riga)
    int y;                                // Coordinata orizzontale (colonna)
} Coo;

// VARIABILI GLOBALI
Coo mosse[MOSSE];                         // Array delle mosse da eseguire
int mylab[N][M];                          // Matrice del labirinto

/**
 * Verifica se una sequenza di mosse è valida nel labirinto
 * 
 * @param mylab    Matrice del labirinto (0=libero, 1=ostacolo)
 * @param mosse    Array delle mosse da eseguire
 * @return         1 se il percorso è valido, -1 se incontra ostacoli
 * 
 * Algoritmo:
 * - Parte dalla posizione (0,0)
 * - Per ogni mossa, controlla se la destinazione è libera
 * - Se trova un ostacolo (valore 1), ritorna -1
 * - Se completa tutte le mosse senza ostacoli, ritorna 1
 * 
 * ATTENZIONE: Il codice presenta diversi problemi:
 * - Non controlla i limiti del labirinto (bounds checking)
 * - La sintassi del parametro mylab[][] è incorretta
 * - Mancano controlli per uscire dai confini della matrice
 */
int solve(int mylab[][], Coo mosse[]){
    // POSIZIONE INIZIALE: partenza sempre da (0,0)
    Coo tmp;
    tmp.x = 0;                            // Riga di partenza
    tmp.y = 0;                            // Colonna di partenza

    // ESECUZIONE MOSSE: elabora ogni mossa nell'array
    for (int k = 0; k < MOSSE; k++) {
        
        // MOVIMENTO ORIZZONTALE: solo lungo l'asse Y (destra/sinistra)
        if (mosse[k].x == 0) {
            // CONTROLLO OSTACOLO: verifica se la destinazione è libera
            if (mylab[tmp.x][tmp.y + mosse[k].y] != 0) {
                return -1;                // Ostacolo trovato - percorso non valido
            }
            // AGGIORNAMENTO POSIZIONE: sposta lungo Y
            tmp.y = tmp.y + mosse[k].y;
        }
        
        // MOVIMENTO VERTICALE: solo lungo l'asse X (su/giù)
        if (mosse[k].y == 0) {
            // CONTROLLO OSTACOLO: verifica se la destinazione è libera
            if (mylab[tmp.x + mosse[k].x][tmp.y] != 0) {
                return -1;                // Ostacolo trovato - percorso non valido
            }
            // AGGIORNAMENTO POSIZIONE: sposta lungo X
            tmp.x = tmp.x + mosse[k].x;
        }
    }
    
    // SUCCESSO: tutte le mosse eseguite senza ostacoli
    return 1;
}

/**
 * Funzione principale per testare la navigazione nel labirinto
 * 
 * Crea un labirinto 3x3 con un percorso specifico e testa una sequenza di mosse
 */
int main(){
    int i, j, ris;
    int mylab[N][M];                      // Labirinto locale (ridefinito)

    // CREAZIONE LABIRINTO: definisce la mappa con ostacoli
    // Layout del labirinto (0=libero, 1=ostacolo):
    // [0][1][1]
    // [0][1][1] 
    // [0][0][0]
    mylab[0][0] = 0;                      // Partenza - libera
    mylab[0][1] = 1;                      // Ostacolo
    mylab[0][2] = 1;                      // Ostacolo
    mylab[1][0] = 0;                      // Libera
    mylab[1][1] = 1;                      // Ostacolo
    mylab[1][2] = 1;                      // Ostacolo
    mylab[2][0] = 0;                      // Libera
    mylab[2][1] = 0;                      // Libera
    mylab[2][2] = 0;                      // Libera

    // VISUALIZZAZIONE LABIRINTO
    printf("=== LABIRINTO 3x3 ===\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            printf("[%d]", mylab[i][j]);
        }
        printf("\n");
    }
    printf("0 = libero, 1 = ostacolo\n\n");

    // DEFINIZIONE MOSSE: sequenza di movimenti da testare
    // Inizializza tutte le mosse a (0,0)
    for (int k = 0; k < MOSSE; k++) {
        mosse[k].x = 0;
        mosse[k].y = 0;
    }
    
    // MOSSE SPECIFICHE: percorso di test
    mosse[0].y = 1;                       // Destra: (0,0) → (0,1) - OSTACOLO!
    mosse[1].y = 1;                       // Destra: (0,1) → (0,2)
    mosse[2].x = 1;                       // Giù: (0,2) → (1,2)
    mosse[3].x = 1;                       // Giù: (1,2) → (2,2)
    mosse[4].y = 1;                       // Destra: (2,2) → (2,3) - FUORI LIMITI!

    // VISUALIZZAZIONE MOSSE
    printf("=== SEQUENZA MOSSE ===\n");
    for (int k = 0; k < 5; k++) {
        if (mosse[k].x != 0 || mosse[k].y != 0) {
            printf("Mossa %d: x=%d, y=%d\n", k, mosse[k].x, mosse[k].y);
        }
    }
    printf("\n");

    // ESECUZIONE: verifica se il percorso è valido
    ris = solve(mylab, mosse);
    
    // OUTPUT: risultato della verifica
    printf("=== RISULTATO ===\n");
    if (ris == 1) {
        printf("✓ Percorso valido: %d\n", ris);
    } else {
        printf("✗ Percorso non valido (ostacolo incontrato): %d\n", ris);
    }
    
    return 0;
}

    // DEFINIZIONE MOSSE: sequenza di movimenti da testare
    // Inizializza tutte le mosse a (0,0)
    for (int k = 0; k < MOSSE; k++) {
        mosse[k].x = 0;
        mosse[k].y = 0;
    }
    
    // MOSSE SPECIFICHE: percorso di test
    mosse[0].y = 1;                       // Destra: (0,0) → (0,1) - OSTACOLO!
    mosse[1].y = 1;                       // Destra: (0,1) → (0,2)
    mosse[2].x = 1;                       // Giù: (0,2) → (1,2)
    mosse[3].x = 1;                       // Giù: (1,2) → (2,2)
    mosse[4].y = 1;                       // Destra: (2,2) → (2,3) - FUORI LIMITI!

    // VISUALIZZAZIONE MOSSE
    printf("=== SEQUENZA MOSSE ===\n");
    for (int k = 0; k < 5; k++) {
        if (mosse[k].x != 0 || mosse[k].y != 0) {
            printf("Mossa %d: x=%d, y=%d\n", k, mosse[k].x, mosse[k].y);
        }
    }
    printf("\n");

    // ESECUZIONE: verifica se il percorso è valido
    ris = solve(mylab, mosse);
    
    // OUTPUT: risultato della verifica
    printf("=== RISULTATO ===\n");
    if (ris == 1) {
        printf("✓ Percorso valido: %d\n", ris);
    } else {
        printf("✗ Percorso non valido (ostacolo incontrato): %d\n", ris);
    }
    
    return 0;
}

/*
 * Note tecniche e problemi del codice:
 * 
 * 1. SINTASSI ERRATA: int mylab[][] non è valido in C
 *    Dovrebbe essere int mylab[N][M] o int (*mylab)[M]
 * 
 * 2. MANCANZA BOUNDS CHECKING: non verifica se le coordinate rimangono nei limiti
 *    Può causare segmentation fault se si esce dalla matrice
 * 
 * 3. LOGICA MOVIMENTO: permette solo movimenti orizzontali O verticali, non diagonali
 *    Se una mossa ha sia x che y diversi da 0, viene ignorata
 * 
 * 4. INIZIALIZZAZIONE: l'array mosse non viene inizializzato, può contenere valori casuali
 * 
 * 5. PERCORSO TEST: la prima mossa va subito su un ostacolo, quindi fallisce immediatamente
 * 
 * Miglioramenti suggeriti:
 * - Aggiungere controlli sui limiti della matrice
 * - Correggere la sintassi del parametro della funzione
 * - Inizializzare correttamente l'array delle mosse
 * - Aggiungere visualizzazione del labirinto e del percorso
 */
