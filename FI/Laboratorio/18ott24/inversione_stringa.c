/* inversione_stringa.c - C source file. */

#include <stdio.h>
#include <string.h>
#define MAXLEN 5  // Lunghezza massima string (limitata per test)

/* 
Function principale per l'inversione di string
 */
int main(){
    // SECTION 1: DICHIARAZIONE VARIABILI
    
    int lastchar=0, newlen=0;  // Variabili per gestione lunghezza
    char mystring[MAXLEN], tmpfirst, tmplast, newstring[MAXLEN];

    
    fgets(mystring, MAXLEN, stdin);

    // SECTION 3: GESTIONE TERMINATORI E LUNGHEZZA
    
    // Aggiustamento per fgets: rimuove '\n' inserito da fgets
    lastchar = strlen(mystring);
    mystring[lastchar - 1] = '\0';  // Sostituisce '\n' con terminatestore
    newlen = strlen(mystring);

    
    if (newlen == 0) {
        printf("\nErrore, la stringa inserita è vuota");
        return 0;
    }

    // SECTION 5: ALGORITMO INVERSIONE IN-PLACE
    
    // Inversione character per character con scambio simmetrico
    for (int j = 0; j < newlen/2; j++) {
        tmpfirst = mystring[j];                // Salva character da left
        tmplast = mystring[newlen-1-j];        // Salva character da right
        
        // Scambio simmetrico: posizione j ↔ posizione (newlen-1-j)
        mystring[j] = tmplast;                 // Posizione left ← right
        mystring[newlen-1-j] = tmpfirst;       // Posizione right ← left
        
/* 
NOTA SUL CALCOLO INDICI:
newlen-1-j calcola la posizione simmetrica rispetto al centro
- Per string di lunghezza 5: posizioni 0,1,2,3,4
- j=0: scambia pos 0 ↔ pos 4 (newlen-1-0 = 5-1-0 = 4)
- j=1: scambia pos 1 ↔ pos 3 (newlen-1-1 = 5-1-1 = 3)
- j=2: centro, non serve scambiare (loop si ferma a newlen/2)
 */
    }

    
    printf("La tua stringa invertita è: %s", mystring);
    
/* 
COMPLESSITÀ E OTTIMIZZAZIONE:

TEMPO: O(n/2) → O(n) lineare
SPAZIO: O(1) costante (in-place)

VANTAGGI:
- Non richiede array aggiuntivo
- Efficiente in memoria
- Algoritmo classico e intuitivo

MIGLIORAMENTI POSSIBILI:
- Aumentare MAXLEN per stringhe più lunghe
- Aggiungere validazione characters
- Implementare versione recursive per confronto
 */
    
    return 0;
}
