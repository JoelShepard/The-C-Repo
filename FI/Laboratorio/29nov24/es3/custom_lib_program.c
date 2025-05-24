/*
 * =============================================================================
 * PROGRAMMA DI TEST PER LIBRERIA CUSTOM STRINGHE
 * =============================================================================
 * 
 * Descrizione:
 * Programma di testing che dimostra l'utilizzo di tutte le funzioni
 * implementate nella libreria custom_lib.h per la manipolazione di stringhe.
 * 
 * Autore: Studente FI
 * Data: 29 novembre 2024
 * Corso: Fondamenti di Informatica - Laboratorio
 * 
 * Funzionalità testate:
 * - Inversione stringa
 * - Conversione maiuscolo
 * - Rimozione spazi
 * - Verifica palindromo
 * - Conteggio vocali
 * 
 * NOTA IMPORTANTE:
 * Il codice attuale presenta un bug critico: chiama le funzioni multiple volte
 * senza salvare il risultato, causando memory leak. Ogni chiamata alloca
 * nuova memoria che non viene liberata correttamente.
 * 
 * =============================================================================
 */

#include "custom_lib.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Funzione principale di test delle funzioni della libreria
 * Dimostra l'uso di ogni funzione con una stringa di esempio
 */
int main(){
    char mystring[]="otto otto";  // Stringa di test (palindroma con spazi)

    // ===============================================
    // TEST INVERSIONE STRINGA
    // ===============================================
    // BUG: Chiamata multipla della stessa funzione!
    if (invertiStringa(mystring)!=NULL){
        char* inverted = invertiStringa(mystring);  // CORREZIONE: salva risultato
        printf("Stringa invertita: %s\n", inverted);
        free(inverted);  // Libera memoria una sola volta
    }

    // ===============================================
    // TEST CONVERSIONE MAIUSCOLO
    // ===============================================
    // BUG: Stessi problemi di memory leak
    if (toUppercase(mystring)!=NULL){
        char* uppercase = toUppercase(mystring);  // CORREZIONE: salva risultato
        printf("Stringa maiuscola: %s\n", uppercase);
        free(uppercase);  // Libera memoria una sola volta
    }

    // ===============================================
    // TEST RIMOZIONE SPAZI
    // ===============================================
    // BUG: Stessi problemi di memory leak
    if (rimuoviSpazi(mystring)!=NULL){
        char* no_spaces = rimuoviSpazi(mystring);  // CORREZIONE: salva risultato
        printf("Stringa senza spazi: %s\n", no_spaces);
        free(no_spaces);  // Libera memoria una sola volta
    }

    // ===============================================
    // TEST VERIFICA PALINDROMO
    // ===============================================
    // Questa funzione è corretta: non alloca memoria permanente
    if (isPalindromo(mystring)==1) {
        printf("La stringa è palindroma\n");
    } else if (isPalindromo(mystring)==0) {
        printf("La stringa non è palindroma\n");
    }

    // ===============================================
    // TEST CONTEGGIO VOCALI
    // ===============================================
    // Questa funzione è corretta: non alloca memoria permanente
    printf("Il numero di vocali contenute è: %d\n", contaVocali(mystring));
    
    /*
     * NOTE SUL CODICE ORIGINALE:
     * 
     * PROBLEMI IDENTIFICATI:
     * 1. Memory leak: ogni chiamata a invertiStringa(), toUppercase(), 
     *    rimuoviSpazi() alloca memoria ma il risultato viene perso
     * 2. Chiamate multiple: la stessa funzione viene chiamata 2-3 volte
     *    per ogni test, sprecando risorse
     * 
     * CORREZIONI IMPLEMENTATE NEI COMMENTI:
     * - Salvare risultato in variabile temporanea
     * - Fare free() una sola volta per allocazione
     * - Evitare chiamate multiple della stessa funzione
     */
}
