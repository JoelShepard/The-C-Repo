/*
 * File: exe1.1.c
 * Descrizione: Programma per ordinare una sequenza di numeri in ordine crescente
 *              Utilizza un algoritmo di ordinamento simile al selection sort
 * Autore: Studente FI
 * Data: 18 ottobre 2024 - Esercitazione
 * Note: Implementazione da migliorare (vedi commento finale)
 */

#include <stdio.h>

#define DEFAULT_DIM 100  // Dimensione massima dell'array

/**
 * Funzione principale che implementa l'ordinamento di un array di interi
 */
int main(){
    // === DICHIARAZIONE VARIABILI ===
    int myarray[DEFAULT_DIM];           // Array per memorizzare i numeri
    int i=0, j=0, tmp1=0, tmp2=0;      // Indici e variabili temporanee per scambio
    int size=0;                        // Dimensione effettiva dell'array

    // === INPUT DIMENSIONE ===
    printf("Inserisci la quantità di numeri da ordinare:");
    scanf("%d", &size);

    // === VALIDAZIONE INPUT ===
    if (size > DEFAULT_DIM){
        printf("Il valore inserito supera il massimo consentito");
        return 0;
    }

    // === INPUT DEI NUMERI ===
    for (i = 0; i < size; i++){
        scanf("%d", &myarray[i]);    
    }

    // === ALGORITMO DI ORDINAMENTO ===
    // Implementazione ibrida tra selection sort e bubble sort
    // NOTA: Algoritmo inefficiente - dovrebbe essere ottimizzato
    for (i = 0; i < size; i++){
        for (j = 1; j < size; j++){
            if (myarray[i] > myarray[j]){
                // Scambio degli elementi
                tmp1=myarray[i];
                tmp2=myarray[j];
                myarray[i]=tmp2;
                myarray[j]=tmp1;
            }
        }
    }
    
    // === OUTPUT RISULTATI ===
    printf("I tuoi numeri in ordine sono:"); 
    for (i = 0; i < size; i++){
        printf("\n%d", myarray[i]);
    }
    
    return 0;
}

// Nota originale: "prova a sistemare" - L'algoritmo può essere ottimizzato