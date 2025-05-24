/*
 * =============================================================================
 * INVERSIONE STRINGA IN-PLACE - ALGORITMO DI SCAMBIO CARATTERI
 * =============================================================================
 * 
 * Descrizione:
 * Programma che implementa l'algoritmo di inversione di una stringa utilizzando
 * la tecnica dello scambio in-place. L'algoritmo scambia i caratteri dalle
 * estremità verso il centro, modificando direttamente l'array originale
 * senza allocare memoria aggiuntiva.
 * 
 * Autore: Studente FI
 * Data: 18 ottobre 2024
 * Corso: Fondamenti di Informatica - Laboratorio
 * 
 * Algoritmo implementato:
 * - Scambio simultaneo caratteri da posizioni simmetriche
 * - Iterazione dalla posizione 0 fino a metà stringa
 * - Uso di variabile temporanea per lo scambio
 * 
 * Caratteristiche:
 * - Complessità temporale: O(n/2)
 * - Complessità spaziale: O(1) - in-place
 * - Gestione automatica terminatore stringa
 * 
 * Limitazioni:
 * - Lunghezza massima limitata a MAXLEN caratteri
 * - Input da stdin con fgets per sicurezza
 * 
 * =============================================================================
 */

#include <stdio.h>
#include <string.h>
#define MAXLEN 5  // Lunghezza massima stringa (limitata per test)

/*
 * Funzione principale per l'inversione di stringa
 */
int main(){
    // ===============================================
    // SEZIONE 1: DICHIARAZIONE VARIABILI
    // ===============================================
    
    int lastchar=0, newlen=0;  // Variabili per gestione lunghezza
    char mystring[MAXLEN], tmpfirst, tmplast, newstring[MAXLEN];  // Array e temp

    // ===============================================
    // SEZIONE 2: INPUT SICURO DA STDIN
    // ===============================================
    
    // Input da stdin con protezione overflow
    fgets(mystring, MAXLEN, stdin);

    // ===============================================
    // SEZIONE 3: GESTIONE TERMINATORI E LUNGHEZZA
    // ===============================================
    
    // Aggiustamento per fgets: rimuove '\n' inserito da fgets
    lastchar = strlen(mystring);
    mystring[lastchar - 1] = '\0';  // Sostituisce '\n' con terminatore
    newlen = strlen(mystring);      // Ricalcola lunghezza effettiva

    // ===============================================
    // SEZIONE 4: VALIDAZIONE INPUT
    // ===============================================
    
    // Controllo stringa vuota
    if (newlen == 0) {
        printf("\nErrore, la stringa inserita è vuota");
        return 0;
    }

    // ===============================================
    // SEZIONE 5: ALGORITMO INVERSIONE IN-PLACE
    // ===============================================
    
    // Inversione carattere per carattere con scambio simmetrico
    for (int j = 0; j < newlen/2; j++) {
        tmpfirst = mystring[j];                // Salva carattere da sinistra
        tmplast = mystring[newlen-1-j];        // Salva carattere da destra
        
        // Scambio simmetrico: posizione j ↔ posizione (newlen-1-j)
        mystring[j] = tmplast;                 // Posizione sinistra ← destra
        mystring[newlen-1-j] = tmpfirst;       // Posizione destra ← sinistra
        
        /*
         * NOTA SUL CALCOLO INDICI:
         * newlen-1-j calcola la posizione simmetrica rispetto al centro
         * - Per stringa di lunghezza 5: posizioni 0,1,2,3,4
         * - j=0: scambia pos 0 ↔ pos 4 (newlen-1-0 = 5-1-0 = 4)
         * - j=1: scambia pos 1 ↔ pos 3 (newlen-1-1 = 5-1-1 = 3)
         * - j=2: centro, non serve scambiare (loop si ferma a newlen/2)
         */
    }

    // ===============================================
    // SEZIONE 6: OUTPUT RISULTATO
    // ===============================================
    
    printf("La tua stringa invertita è: %s", mystring);
    
    /*
     * COMPLESSITÀ E OTTIMIZZAZIONE:
     * 
     * TEMPO: O(n/2) → O(n) lineare
     * SPAZIO: O(1) costante (in-place)
     * 
     * VANTAGGI:
     * - Non richiede array aggiuntivo
     * - Efficiente in memoria
     * - Algoritmo classico e intuitivo
     * 
     * MIGLIORAMENTI POSSIBILI:
     * - Aumentare MAXLEN per stringhe più lunghe
     * - Aggiungere validazione caratteri
     * - Implementare versione ricorsiva per confronto
     */
    
    return 0;
}
