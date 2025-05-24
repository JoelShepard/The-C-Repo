/*
 * File: ascii.c
 * Descrizione: Dimostrazione della conversione tra caratteri minuscoli e maiuscoli
 *              utilizzando i valori ASCII
 * Autore: Studente FI
 * Data: Esercitazione 1
 */

#include <stdio.h>

char letter = 'z';  // Variabile globale inizializzata con carattere minuscolo

/**
 * Funzione principale che dimostra la conversione maiuscolo/minuscolo
 * utilizzando l'aritmetica sui codici ASCII
 */
int main(){
    // Stampa il carattere originale
    printf("%c\n", letter);
    
    // Stampa il valore ASCII equivalente del carattere
    printf("%u\n", letter); // equivalent number

    // Conversione da minuscolo a maiuscolo:
    // Sottrae la differenza tra 'a' e 'A' (che è 32 in ASCII)
    letter = letter - ('a'-'A');
    
    // Stampa il carattere convertito in maiuscolo
    printf("capital letter: %c\n", letter);
}