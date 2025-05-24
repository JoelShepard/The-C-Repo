/**
 * ================================================================
 * CALCOLATORE SOMMATORIA DI SERIE ARMONICA
 * ================================================================
 * 
 * Descrizione:
 *   Programma per il calcolo della sommatoria di una serie armonica
 *   tra due estremi specificati dall'utente. La formula calcolata è:
 *   S = 1/q + 1/(q+1) + 1/(q+2) + ... + 1/r
 *   dove q è l'estremo inferiore e r quello superiore.
 * 
 * Funzionalità:
 *   - Acquisizione interattiva degli estremi della sommatoria
 *   - Validazione che gli estremi siano positivi e q ≤ r
 *   - Calcolo iterativo della sommatoria armonica
 *   - Utilizzo di aritmetica floating-point per precisione
 *   - Visualizzazione del risultato finale
 *
 * Formula matematica: Σ(k=q to r) 1/k
 *
 * Autore: Joel (Laboratorio del 27 settembre 2024)
 * Corso: Fondamenti di Informatica
 * 
 * Note tecniche:
 *   - Utilizza float per gestire risultati frazionari
 *   - Algoritmo iterativo con complessità O(r-q+1)
 *   - Validazione input per evitare divisioni per zero
 * ================================================================
 */

#include <stdio.h>  // Per printf, scanf

/**
 * ================================================================
 * FUNZIONE PRINCIPALE - CALCOLO SOMMATORIA ARMONICA
 * ================================================================
 */
int main(){
    // Variabili per gli estremi della sommatoria
    int r, q;               // r = estremo superiore, q = estremo inferiore
    int iter;               // Contatore per le iterazioni del ciclo
    float tot = 0.0;        // Accumulatore per il risultato (float per precisione)

    // ================================================================
    // FASE 1: ACQUISIZIONE ESTREMI DELLA SOMMATORIA
    // ================================================================
    printf("\nInserisci il primo estremo della sommatoria:");
    scanf("%d", &q);
    printf("Inserisci il secondo estremo della sommatoria:");
    scanf("%d", &r);

    // ================================================================
    // FASE 2: VALIDAZIONE INPUT
    // ================================================================
    // Controllo: entrambi gli estremi devono essere positivi (evita divisione per 0)
    if(q < 0 || r < 0){
        printf("\nEstremi inseriti non validi. Inserisci interi positivi diversi da 0\n");
        return 0;
    } 
    // Controllo: l'estremo superiore deve essere maggiore o uguale all'inferiore
    else if(r < q){
        printf("\nIl secondo estremo deve essere più grande del primo\n");
        return 0;
    }

    // ================================================================
    // FASE 3: CALCOLO ITERATIVO DELLA SOMMATORIA
    // ================================================================
    iter = r - q;  // Numero di iterazioni necessarie
    
    // Ciclo per calcolare: Σ(k=q to r) 1/k
    while(iter >= 0){
        tot = tot + (1.0 / q);  // Aggiunge 1/q al totale (cast a float)
        iter--;                 // Decrementa contatore iterazioni
        q++;                    // Passa al prossimo termine della serie
    }
    
    // ================================================================
    // FASE 4: VISUALIZZAZIONE RISULTATO
    // ================================================================
    printf("\nIl risultato della sommatoria è: %f\n", tot);
    
    return 0;
}