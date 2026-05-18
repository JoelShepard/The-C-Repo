// custom_lib_program.c - Test libreria custom

#include "custom_lib.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    char mystring[]="otto otto";

    if (invertiStringa(mystring)!=NULL){
        char* inverted = invertiStringa(mystring);
        printf("Stringa invertita: %s\n", inverted);
        free(inverted);
    }

    if (toUppercase(mystring)!=NULL){
        char* uppercase = toUppercase(mystring);
        printf("Stringa maiuscola: %s\n", uppercase);
        free(uppercase);
    }

    if (rimuoviSpazi(mystring)!=NULL){
        char* no_spaces = rimuoviSpazi(mystring);
        printf("Stringa senza spazi: %s\n", no_spaces);
        free(no_spaces);
    }

    if (isPalindromo(mystring)==1) {
        printf("La stringa è palindroma\n");
    } else if (isPalindromo(mystring)==0) {
        printf("La stringa non è palindroma\n");
    }

    printf("Il numero di vocali contenute è: %d\n", contaVocali(mystring));
    
    return 0;
}
/* 
BUG: Le funzioni invertiStringa, toUppercase, rimuoviSpazi vengono chiamate
due volte (una nel check NULL e una per il risultato), sprecando risorse.
Soluzione: salvare il risultato in una variabile.
*/
