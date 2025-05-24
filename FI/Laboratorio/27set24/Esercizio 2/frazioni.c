/**
 * ================================================================
 * CALCOLATORE SOMMA DI FRAZIONI
 * ================================================================
 * 
 * Descrizione:
 *   Programma per eseguire la somma di due frazioni inserite dall'utente.
 *   Il programma acquisisce numeratore e denominatore di entrambe le frazioni,
 *   esegue controlli di validità (denominatore non nullo, frazioni positive)
 *   e calcola la somma utilizzando la regola matematica standard.
 * 
 * Funzionalità:
 *   - Acquisizione interattiva di due frazioni
 *   - Validazione denominatori diversi da zero
 *   - Controllo che le frazioni siano positive
 *   - Calcolo somma: a1/b1 + a2/b2 = (a1*b2 + a2*b1)/(b1*b2)
 *   - Visualizzazione risultato in formato frazione
 *
 * Autore: Joel (Laboratorio del 27 settembre 2024)
 * Corso: Fondamenti di Informatica
 * 
 * Note tecniche:
 *   - Non esegue semplificazione della frazione risultante
 *   - Controlli di validità per frazioni negative
 *   - Algoritmo classico per somma frazioni
 * ================================================================
 */

#include <stdio.h>  // Per printf, scanf

/**
 * ================================================================
 * FUNZIONE PRINCIPALE - SOMMA FRAZIONI
 * ================================================================
 */
int main(){
    // Variabili per il risultato finale
    int a, b;                    // Numeratore e denominatore della somma
    
    // Variabili per le due frazioni di input
    int a1, a2;                  // Numeratori delle frazioni
    int b1, b2;                  // Denominatori delle frazioni

    // ================================================================
    // FASE 1: ACQUISIZIONE PRIMA FRAZIONE
    // ================================================================
    printf("inserisci il numeratore della prima frazione:");
    scanf("%d", &a1);

    printf("inserisci il denominatore della prima frazione:");
    scanf("%d", &b1);

    // ================================================================
    // FASE 2: ACQUISIZIONE SECONDA FRAZIONE  
    // ================================================================
    printf("inserisci il numeratore della seconda frazione:");
    scanf("%d", &a2);

    printf("inserisci il denominatore della seconda frazione:");
    scanf("%d", &b2);

    // ================================================================
    // FASE 3: VALIDAZIONE DELLE FRAZIONI INSERITE
    // ================================================================
    
    // Controllo: denominatore della prima frazione non può essere zero
    if(b1 == 0){
        printf("\n il primo denominatore è 0");
        return 0;
    } 
    // Controllo: prima frazione negativa (numeratore negativo, denominatore positivo)
    else if(a1 < 0 && b1 > 0){
        printf("\n la prima frazione è negativa");
        return 0;    
    } 
    // Controllo: prima frazione negativa (numeratore positivo, denominatore negativo)
    else if(b1 < 0 && a1 > 0){
        printf("\n la prima frazione è negativa");
        return 0; 
    } 
    // Controllo: denominatore della seconda frazione non può essere zero
    else if(b2 == 0){
       printf("\n il secondo denominatore è 0");
        return 0;
    } 
    // Controllo: seconda frazione negativa (numeratore negativo, denominatore positivo)
    else if(a2 < 0 && b2 > 0){
        printf("\n la seconda frazione è negativa");
        return 0; 
    }
    // Controllo: seconda frazione negativa (numeratore positivo, denominatore negativo)
    else if(b2 < 0 && a2 > 0){
        printf("\n la seconda frazione è negativa");
        return 0;
    } 
    // ================================================================
    // FASE 4: CALCOLO DELLA SOMMA
    // ================================================================
    else {
        // Formula: a1/b1 + a2/b2 = (a1*b2 + a2*b1)/(b1*b2)
        b = b2 * b1;                    // Denominatore comune
        a = (a1 * b2) + (a2 * b1);      // Numeratore della somma
    }

    // ================================================================
    // FASE 5: VISUALIZZAZIONE RISULTATO
    // ================================================================
    printf("la somma tra le tue frazioni è: %d / %d", a, b); 
}