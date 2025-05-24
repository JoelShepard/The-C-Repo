/*
 * File: 1o_q2.c
 * Descrizione: Tema d'esame - Questione 2  
 *              Conta ricorsivamente le occorrenze di una sequenza x,y in un array
 * Autore: Studente FI
 * Data: Tema d'esame
 * Contesto: Fondamenti di Informatica - Algoritmi ricorsivi su array
 * 
 * Funzionalità:
 * - Conta quante volte il valore y segue immediatamente il valore x
 * - Verifica prima che x esista nell'array
 * - Implementa ricorsione con controllo di validità
 * 
 * Note: Logica con possibili ottimizzazioni nel controllo di esistenza
 */

#include <stdio.h>

/**
 * Funzione ricorsiva per contare sequenze consecutive x,y in un array
 * 
 * Algoritmo:
 * 1. Verifica che x esista nell'array (controllo preliminare)
 * 2. Caso base: array vuoto -> ritorna 0
 * 3. Caso ricorsivo: se trova x seguito da y, incrementa contatore
 * 4. Continua ricorsione sul resto dell'array
 * 
 * @param a     Array di interi da analizzare
 * @param x     Primo valore della sequenza da cercare
 * @param y     Secondo valore della sequenza da cercare  
 * @param dim   Dimensione rimanente dell'array
 * @param flag  Flag di esistenza di x nell'array (0=non trovato, 1=trovato)
 * @return      Numero di occorrenze della sequenza x,y oppure -1 se x non esiste
 */
int itsfollowed(int a[], int x, int y, int dim, int flag){

    // === CONTROLLO ESISTENZA DI X NELL'ARRAY ===
    for (int i=0; i<dim; i++) {
        if(a[i]==x){
            flag=1;  // x trovato nell'array
        }
    }

    // === CONTROLLO VALIDITÀ ===
    if (!flag){
        return -1;  // x non esiste nell'array, sequenza impossibile
    }

    // === CASO BASE: ARRAY VUOTO ===
    if (dim == 0) {
        return 0;  // Nessuna sequenza possibile
    }

    // === CASO RICORSIVO: VERIFICA SEQUENZA ===
    if (*a == x && *(a+1)==y) {
        // Sequenza x,y trovata: incrementa contatore e continua
        return 1+itsfollowed(a+1, x, y, dim-1, flag);
    } else {
        // Sequenza non trovata: continua senza incrementare
        return 0+itsfollowed(a+1, x, y, dim-1, flag);
    }
}

/**
 * Funzione principale - test dell'algoritmo di conteggio sequenze
 */
int main(){
    // === DATI DI TEST ===
    int a[]={2,3,4,5,2,3,4,6,2,3};  // Array: contiene sequenze 2,3 (posizioni 0-1, 4-5, 8-9)
    int dim = 10;                    // Dimensione array

    // === ESECUZIONE E OUTPUT ===
    // Cerca sequenza 7,5: 7 non esiste nell'array -> dovrebbe ritornare -1
    int risultato = itsfollowed(a, 7, 5, dim, 0);
    printf("Occorrenze sequenza 7,5: %d\n", risultato);
    
    // Test aggiuntivo per sequenza esistente (non mostrato in output)
    // itsfollowed(a, 2, 3, dim, 0) dovrebbe ritornare 3
    
    return 0;
}
