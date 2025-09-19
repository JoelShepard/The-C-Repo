/* somme_successive.c - C source file. */

#include <stdio.h>  // Per printf, scanf

/* *
================================================================
FUNZIONE PRINCIPALE - MOLTIPLICAZIONE PER SOMME
================================================================
 */
int main(){
    // Variabili per i fattori e il risultato
    int a, b, c;
    
    // Inizializzazione esplicita delle variabili
    a = 0;  // Primo fattore (moltiplicando)
    b = 0;  // Secondo fattore (moltiplicatore)
    c = 0;  // Risultato del prodotto (inizialmente zero)
    
    // ================================================================
    // FASE 1: ACQUISIZIONE DEI FATTORI
    // ================================================================
    printf("inserisci il primo fattore:");
    scanf("%d", &a);
    printf("inserisci il secondo fattore:");
    scanf("%d", &b);

    // ================================================================
    // FASE 2: CALCOLO DEL PRODOTTO - CASO MOLTIPLICATORE POSITIVO
    // ================================================================
    if (b > 0) {
        // Somma 'a' per 'b' volte: a + a + ... + a (b volte)
        while(b > 0){
            c = c + a;    // Accumula 'a' nel risultato
            b = b - 1;    // Decrementa il counter
        }   
    }
    
    // ================================================================
    // FASE 3: CALCOLO DEL PRODOTTO - CASO MOLTIPLICATORE NEGATIVO
    // ================================================================
    if (b < 0) {
        // Somma 'a' per |b| volte, poi nega il risultato
        while(b < 0){
            c = c + a;    // Accumula 'a' nel risultato
            b = b + 1;    // Incrementa il counter (verso zero)
        }
        c = -c;  // Nega il risultato finale (a × (-b) = -(a × b))
    }      

    // ================================================================
    // FASE 4: VISUALIZZAZIONE RISULTATO
    // ================================================================
    // Note: se b = 0, c rimane 0 (qualsiasi numero × 0 = 0)
    printf("il risultato è: %d", c);
    return 0;
}
