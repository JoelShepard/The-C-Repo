/*
 * File: bubble_sort.c
 * Descrizione: Implementazione dell'algoritmo Bubble Sort per ordinare due array
 *              e successiva fusione degli array ordinati
 * Autore: Studente FI
 * Data: 15 novembre 2024
 */

#include <stdio.h>
#define N 3  // Dimensione degli array

/**
 * Funzione principale che implementa:
 * 1. Input di due array
 * 2. Ordinamento con bubble sort
 * 3. Fusione degli array ordinati
 * 4. Conteggio di swap e confronti
 */
int main(){
    // Dichiarazione delle variabili
    int myarray1[N]={0}, myarray2[N]={0}, myarrayx2[2*N]={0}; // Array di lavoro
    int i=0, k=0, tmp=0, j=0;                                 // Indici e variabile temporanea
    int swap1=0, swap2=0, iter1=0, iter2=0;                  // Contatori per statistiche
    
    // === SEZIONE INPUT ===
    printf("Inserisci i valori nel primo array:\n");
    for (i=0; i<N; i++) {
        scanf("%d", &myarray1[i]);
    }
    printf("Inserisci i valori nel secondo array:\n");
    for (i=0; i<N; i++) {
        scanf("%d", &myarray2[i]);
    }

    // === BUBBLE SORT PRIMO ARRAY ===
    // Algoritmo bubble sort: confronta elementi adiacenti e li scambia se necessario
    for (j=0; j<N-1; j++) {                    // N-1 passate
        for (i=0; i<N; i++) {                  // Scorre l'array
            iter1+=2;                          // Incrementa contatore iterazioni
            if(i+1 == N){continue;}            // Evita di uscire dai bounds
            if (myarray1[i] > myarray1[i+1]) { // Se l'elemento corrente > successivo
                // Scambia gli elementi
                tmp=myarray1[i];
                myarray1[i]=myarray1[i+1];
                myarray1[i+1]=tmp;
                swap1+=1;                      // Incrementa contatore scambi
            }
        }
    }
    
    // === BUBBLE SORT SECONDO ARRAY ===
    for (j=0; j<N-1; j++) {                    // N-1 passate
        for (i=0; i<N; i++) {                  // Scorre l'array
            iter2+=1;                          // Incrementa contatore iterazioni
            if(i+1 == N){continue;}            // Evita di uscire dai bounds
            if (myarray2[i] > myarray2[i+1]) { // Se l'elemento corrente > successivo
                // Scambia gli elementi
                tmp=myarray2[i];
                myarray2[i]=myarray2[i+1];
                myarray2[i+1]=tmp;
                swap2+=1;                      // Incrementa contatore scambi
            }
        }
    }

    // === FUSIONE DEGLI ARRAY ORDINATI (MERGE) ===
    // Algoritmo merge: unisce due array ordinati mantenendo l'ordine
    i = 0;  // Indice per myarray1
    j = 0;  // Indice per myarray2
    k = 0;  // Indice per myarrayx2
    
    // Confronta elementi dei due array e inserisce il minore
    while (i < N && j < N) {
        if (myarray1[i] <= myarray2[j]) {
            myarrayx2[k] = myarray1[i];
                        i++;
        } else {
            myarrayx2[k] = myarray2[j];
            j++;
        }
        k++;
    }
    
    // Copia gli elementi rimanenti del primo array (se presenti)
    while (i < N) {
        myarrayx2[k] = myarray1[i];
        i++;
        k++;
    }
    
    // Copia gli elementi rimanenti del secondo array (se presenti)
    while (j < N) {
        myarrayx2[k] = myarray2[j];
        j++;
        k++;
    }

    // === SEZIONE OUTPUT ===
    // Stampa il primo array ordinato
    printf("Array 1 ordinato è:\n ");
    for (i=0; i<N; i++) {
        printf("%d ", myarray1[i]);
    }
    printf("\n");
    
    // Stampa il secondo array ordinato
    printf("Array 2 ordinato è:\n ");
    for (i=0; i<N; i++) {
        printf("%d ", myarray2[i]);
    }
    printf("\n");
    
    // Stampa l'array risultante dalla fusione
    printf("La loro unione ordinata è:\n ");
    for (i=0; i<2*N; i++) {
        printf("%d ", myarrayx2[i]);
    }
    printf("\n");

    // Stampa le statistiche degli algoritmi
    printf("Numero di swap effettuati\n - per ordinare Array 1: %d\n - per ordinare Array 2: %d\n", swap1, swap2);
    printf("Numero di controlli effettuati\n - per Array 1: %d\n - per Array 2: %d\n", iter1, iter2);
}
