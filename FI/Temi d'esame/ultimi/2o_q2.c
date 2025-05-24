/*
 * File: 2o_q2.c
 * Descrizione: Tema d'esame - Questione 2
 *              Merge ricorsivo di due array ordinati in un array risultante ordinato
 * Autore: Studente FI
 * Data: Tema d'esame
 * Contesto: Fondamenti di Informatica - Algoritmi ricorsivi su array
 * 
 * Funzionalità:
 * - Unisce ricorsivamente due array ordinati mantenendo l'ordinamento
 * - Implementa l'algoritmo merge classico in modo ricorsivo
 * - Gestisce array di dimensioni diverse
 */

#include <stdio.h>

/**
 * Funzione ricorsiva per il merge di due array ordinati
 * 
 * Algoritmo:
 * 1. Caso base: se entrambi gli array sono vuoti, termina
 * 2. Se un array è vuoto, copia l'elemento dell'altro
 * 3. Confronta gli elementi correnti e copia il minore
 * 4. Ricorsione sull'array da cui è stato prelevato l'elemento
 * 
 * @param a         Primo array ordinato
 * @param b         Secondo array ordinato  
 * @param size_a    Dimensione rimanente del primo array
 * @param size_b    Dimensione rimanente del secondo array
 * @param c         Array risultante dove scrivere il merge
 */
void order(int a[], int b[], int size_a, int size_b, int c[]) {
    // === CASO BASE: ENTRAMBI ARRAY VUOTI ===
    if (size_a == 0 && size_b == 0) {
        return;  // Merge completato
    }

    // === CASO: PRIMO ARRAY ESAURITO ===
    if (size_a == 0) {
        *c = *b;  // Copia elemento dal secondo array
        order(a, b+1, size_a, size_b-1, c+1);  // Ricorsione su secondo array
        return;
    }

    // === CASO: SECONDO ARRAY ESAURITO ===
    if (size_b == 0) {
        *c = *a;  // Copia elemento dal primo array
        order(a+1, b, size_a-1, size_b, c+1);  // Ricorsione su primo array
        return;
    }

    // === CONFRONTO E MERGE ===
    if (*a < *b) {
        *c = *a;  // Elemento del primo array è minore
        order(a+1, b, size_a-1, size_b, c+1);  // Avanza primo array
    } else {
        *c = *b;  // Elemento del secondo array è minore o uguale
        order(a, b+1, size_a, size_b-1, c+1);  // Avanza secondo array
    }
}

/**
 * Funzione principale - test dell'algoritmo di merge ricorsivo
 */
int main(){
    // === DATI DI TEST ===
    int a[]={1,2};              // Primo array ordinato (2 elementi)
    int b[]={3,5,9,11,14};      // Secondo array ordinato (5 elementi) 
    int c[7]={0};               // Array risultante (7 elementi totali)

    // === ESECUZIONE MERGE ===
    order(a, b, 2, 5, c);
    
    // === OUTPUT RISULTATO ===
    printf("Array risultante dal merge: ");
    for (int i=0; i<7; i++) {
        printf("%d ", c[i]);
    }
    printf("\n");
    
    // Note: Output atteso: 1 2 3 5 9 11 14
    return 0;
}
