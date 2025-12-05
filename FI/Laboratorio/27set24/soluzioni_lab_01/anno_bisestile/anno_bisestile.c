/* anno_bisestile.c - C source file. */

#include <stdio.h>  // Per printf, scanf

/* *
================================================================
FUNZIONE PRINCIPALE - VERIFICA ANNO BISESTILE
================================================================
 */
int main() {
    int anno;

    // FASE 1: ACQUISIZIONE ANNO CON VALIDAZIONE
    printf("Inserisci un anno: ");
    
    if (scanf("%d", &anno) != 1) {
        printf("Input non valido. Inserisci un numero intero.\n");
        return 1;
    }
    
    // FASE 2: VALIDAZIONE VALORE ANNO
    if (anno < 0) {
        printf("Per favore inserisci un anno positivo.\n");
        return 1;
    }

    // FASE 3: APPLICAZIONE ALGORITMO GREGORIANO
    // Regole del calendario gregoriano per anni bisestili:
    // 1. Divisibile per 4 → potenzialmente bisestile
    // 2. Se divisibile per 100 → NON bisestile (eccezione regola 1)
    // 3. Se divisibile per 400 → bisestile (eccezione regola 2)
    //
    // Logica combinata: (divisibile per 4 E NON per 100) OPPURE (divisibile per 400)
    
    if ((anno % 4 == 0 && anno % 100 != 0) || (anno % 400 == 0)) {
        printf("%d è un anno bisestile.\n", anno);
    } else {
        printf("%d non è un anno bisestile.\n", anno);
    }

    return 0;
}
