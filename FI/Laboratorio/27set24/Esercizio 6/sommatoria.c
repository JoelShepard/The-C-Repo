/* sommatoria.c - C source file. */

#include <stdio.h>  // Per printf, scanf

/* *
================================================================
FUNZIONE PRINCIPALE - CALCOLO SOMMATORIA ARMONICA
================================================================
 */
int main(){
    // Variabili per gli estremi della sommatoria
    int r, q;               // r = estremo superiore, q = estremo inferiore
    int iter;               // Contatore per le iterazioni del ciclo
    float tot = 0.0;        // Accumulatore per il risultato (float per precisione)

    // FASE 1: ACQUISIZIONE ESTREMI DELLA SOMMATORIA
    printf("\nInserisci il primo estremo della sommatoria:");
    scanf("%d", &q);
    printf("Inserisci il secondo estremo della sommatoria:");
    scanf("%d", &r);

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

    // FASE 3: CALCOLO ITERATIVO DELLA SOMMATORIA
    iter = r - q;  // Numero di iterazioni necessarie
    
    // Ciclo per calcolare: Σ(k=q to r) 1/k
    while(iter >= 0){
        tot = tot + (1.0 / q);  // Aggiunge 1/q al totale (cast a float)
        iter--;
        q++;                    // Passa al prossimo termine della serie
    }
    
    // FASE 4: VISUALIZZAZIONE RISULTATO
    printf("\nIl risultato della sommatoria è: %f\n", tot);
    
    return 0;
}
