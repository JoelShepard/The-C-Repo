/*
 * File: crivello_eratostene.c
 * Descrizione: Laboratorio del 18 ottobre 2024 - Algoritmo del Crivello di Eratostene
 *              Implementazione del famoso algoritmo per trovare numeri primi
 * Autore: Studente FI
 * Data: 18 ottobre 2024
 * Contesto: Fondamenti di Informatica - Algoritmi matematici
 * 
 * Algoritmo del Crivello di Eratostene:
 * 1. Inizializza array con tutti i numeri da 2 a N
 * 2. Per ogni numero primo p, elimina tutti i suoi multipli
 * 3. I numeri rimasti sono tutti primi
 * 
 * Complessità: O(n log log n)
 */

#include <stdio.h>
#include <math.h>

#define NUMERI 500  // Limite superiore per la ricerca dei primi

/**
 * Funzione principale che implementa il Crivello di Eratostene
 */
int main(){
    // === DICHIARAZIONE VARIABILI ===
    int setaccio[NUMERI-1] = {0};  // Array per memorizzare i numeri (0 = eliminato)
    int i=0, j=0, incremento=0;    // Indici e variabile di supporto

    // === FASE 1: INIZIALIZZAZIONE ARRAY ===
    // Riempe l'array con numeri consecutivi da 2 a NUMERI
    for (i = 0; i < NUMERI-1; i++){
        if (i == 0){
            setaccio[i]=2;           // Primo numero primo
            incremento=setaccio[i];
        }else{
            setaccio[i] = incremento + 1;  // Numeri consecutivi: 2,3,4,5,...
            incremento = setaccio[i];
        }
    }

    // === FASE 2: APPLICAZIONE CRIVELLO ===
    // Per ogni numero fino alla radice di NUMERI
    for(i=0; i<sqrt(NUMERI-1); i++){
        if(setaccio[i]!=0){  // Se il numero non è stato eliminato
            // Elimina tutti i multipli di setaccio[i]
            for(j=i+1; j<NUMERI-1; j++){
                if(setaccio[j] % setaccio[i] == 0){
                    setaccio[j]=0;  // Marca come eliminato (non primo)
                }
            }
        }
    }

    // === FASE 3: OUTPUT DEI NUMERI PRIMI ===
    printf("Numeri primi fino a %d:\n", NUMERI);
    for (i = 0; i < NUMERI-1; i++){
        if (setaccio[i]!=0) {           // Solo numeri non eliminati
            printf("%d ", setaccio[i]);
        }
    }
    printf("\n");
    
    return 0;
}
