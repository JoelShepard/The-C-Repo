/* custom_lib_program.c - C source file. */

#include "custom_lib.h"
#include <stdio.h>
#include <stdlib.h>

/* 
Function principale di test delle funzioni della libreria
Dimostra l'uso di ogni funzione con una string di esempio
 */
int main(){
    char mystring[]="otto otto";  // String di test (palindroma con spazi)


    // BUG: Chiamata multipla della stessa funzione!
    if (invertiStringa(mystring)!=NULL){
        char* inverted = invertiStringa(mystring);
        printf("Stringa invertita: %s\n", inverted);
        free(inverted);  // Libera memoria una sola volta
    }


    // BUG: Stessi problemi di memory leak
    if (toUppercase(mystring)!=NULL){
        char* uppercase = toUppercase(mystring);
        printf("Stringa maiuscola: %s\n", uppercase);
        free(uppercase);  // Libera memoria una sola volta
    }


    // BUG: Stessi problemi di memory leak
    if (rimuoviSpazi(mystring)!=NULL){
        char* no_spaces = rimuoviSpazi(mystring);
        printf("Stringa senza spazi: %s\n", no_spaces);
        free(no_spaces);  // Libera memoria una sola volta
    }


    // Questa funzione è corretta: non alloca memoria permanente
    if (isPalindromo(mystring)==1) {
        printf("La stringa è palindroma\n");
    } else if (isPalindromo(mystring)==0) {
        printf("La stringa non è palindroma\n");
    }


    // Questa funzione è corretta: non alloca memoria permanente
    printf("Il numero di vocali contenute è: %d\n", contaVocali(mystring));
    
/* 
NOTE SUL CODICE ORIGINALE:

PROBLEMI IDENTIFICATI:
1. Memory leak: ogni chiamata a invertiString(), toUppercase(),
rimuoviSpazi() alloca memoria ma il risultato viene perso
2. Chiamate multiple: la stessa funzione viene chiamata 2-3 volte
per ogni test, sprecando risorse

CORREZIONI IMPLEMENTATE NEI COMMENTI:
- Salvare risultato in variabile temporanea
- Fare free() una sola volta per allocazione
- Evitare chiamate multiple della stessa funzione
 */
}
