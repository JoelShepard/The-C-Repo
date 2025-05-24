/**
 * ================================================================
 * VERIFICA ANNO BISESTILE - ALGORITMO GREGORIANO
 * ================================================================
 * 
 * Descrizione:
 *   Programma per determinare se un anno inserito dall'utente è bisestile
 *   secondo le regole del calendario gregoriano. Implementa l'algoritmo
 *   completo che considera le eccezioni per i multipli di 100 e 400.
 * 
 * Funzionalità:
 *   - Acquisizione sicura dell'anno con validazione input
 *   - Controllo che l'anno sia un numero positivo
 *   - Applicazione delle regole gregoriane per anni bisestili
 *   - Gestione errori per input non numerici
 *   - Messaggi informativi chiari per l'utente
 *
 * Regole calendario gregoriano:
 *   1. Anno divisibile per 4 → bisestile
 *   2. ECCETTO se divisibile per 100 → non bisestile  
 *   3. ECCETTO se divisibile per 400 → bisestile
 *   Formula: (anno % 4 == 0 && anno % 100 != 0) || (anno % 400 == 0)
 *
 * Autore: Soluzione ufficiale (Laboratorio del 27 settembre 2024)
 * Corso: Fondamenti di Informatica
 * 
 * Note tecniche:
 *   - Validazione robusta con controllo valore di ritorno scanf
 *   - Logica booleana compatta per regole complesse
 *   - Gestione casi edge (anni secolari) corretta
 * ================================================================
 */

#include <stdio.h>  // Per printf, scanf

/**
 * ================================================================
 * FUNZIONE PRINCIPALE - VERIFICA ANNO BISESTILE
 * ================================================================
 */
int main() {
    int anno;  // Anno da verificare

    // ================================================================
    // FASE 1: ACQUISIZIONE ANNO CON VALIDAZIONE
    // ================================================================
    printf("Inserisci un anno: ");
    
    // Controllo di validità dell'input (deve essere un numero intero)
    if (scanf("%d", &anno) != 1) {
        printf("Input non valido. Inserisci un numero intero.\n");
        return 1;
    }
    
    // ================================================================
    // FASE 2: VALIDAZIONE VALORE ANNO
    // ================================================================
    if (anno < 0) {
        printf("Per favore inserisci un anno positivo.\n");
        return 1;
    }

    // ================================================================
    // FASE 3: APPLICAZIONE ALGORITMO GREGORIANO
    // ================================================================
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