/*
 * =============================================================================
 * ALGEBRA DEI PUNTATORI - INTRODUZIONE E NAVIGAZIONE ARRAY
 * =============================================================================
 * 
 * Descrizione:
 * Programma dimostrativo per introdurre i concetti fondamentali dell'algebra
 * dei puntatori in C, mostrando l'equivalenza tra notazione array e puntatori
 * per l'accesso agli elementi.
 * 
 * Autore: Studente FI
 * Data: 15 novembre 2024
 * Corso: Fondamenti di Informatica - Laboratorio
 * 
 * Concetti dimostrati:
 * - Dichiarazione e inizializzazione puntatori
 * - Equivalenza tra array[0] e *pointer
 * - Aritmetica dei puntatori (incremento)
 * - Navigazione array con puntatori vs indici
 * 
 * Note didattiche:
 * - Mostra la doppia assegnazione myarray[0]=128 (ridondante)
 * - Confronta due metodi di iterazione: indici tradizionali vs puntatori
 * - Utilizza typedef per migliorare la leggibilità del codice
 * 
 * =============================================================================
 */

#include <stdio.h>
#define MAX 5            // Dimensione massima dell'array
typedef int* Pointer;    // Definizione di tipo per puntatore ad intero

/*
 * Funzione principale che dimostra l'uso dei puntatori
 * con array e l'equivalenza delle diverse notazioni di accesso
 */
int main(){
    // ===============================================
    // SEZIONE 1-2: INIZIALIZZAZIONE E COLLEGAMENTO
    // ===============================================
    
    int myarray[MAX] = {128, 32, 43, 23, 54}, count=0;  // Array con valori iniziali
    Pointer mypoint;                                     // Dichiarazione puntatore
    
    myarray[0]=128;      // Ridondante: già inizializzato sopra
    mypoint = myarray;   // Il puntatore ora punta al primo elemento dell'array
    
    // Dimostrazione equivalenza: *mypoint == myarray[0]
    printf("mypoint: %d == myarray[0]: %d\n", *mypoint, myarray[0]);

    // Dimostrazione equivalenza: *mypoint == myarray[0]
    printf("mypoint: %d == myarray[0]: %d\n", *mypoint, myarray[0]);

    // ===============================================
    // SEZIONE 3: CONFRONTO METODI DI ITERAZIONE
    // ===============================================

    // METODO 1: Iterazione tradizionale con indici
    printf("Il tuo array stampato come sempre è: ");
    for(int i=0; i<MAX; i++){
        printf("%d ", myarray[i]);  // Accesso tramite indice myarray[i]
    }
    
    // METODO 2: Iterazione con algebra dei puntatori
    printf("\nIl tuo array stampato con i puntatori è: ");
    while(count<MAX){
        printf("%d ", *mypoint);    // Dereferenziazione del puntatore
        mypoint++;                  // Incremento puntatore (aritmetica puntatori)
        count++;                    // Incremento contatore
    }
    printf("\n");
    
    /*
     * NOTE DIDATTICHE:
     * - mypoint++ sposta il puntatore all'elemento successivo
     * - *mypoint accede al valore puntato
     * - myarray[i] è equivalente a *(myarray + i)
     * - L'aritmetica dei puntatori tiene conto automaticamente
     *   della dimensione del tipo di dato (sizeof(int))
     */
}
