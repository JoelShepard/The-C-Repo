#include "custom_lib.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    char mystring[]="otto otto";

    if (invertiStringa(mystring)!=NULL){
        printf("Stringa invertita: %s\n", invertiStringa(mystring));
        free(invertiStringa(mystring));
    }

    if (toUppercase(mystring)!=NULL){
        printf("Stringa maiuscola: %s\n", toUppercase(mystring));
        free(toUppercase(mystring));
    }

    if (rimuoviSpazi(mystring)!=NULL){
        printf("Stringa senza spazi: %s\n", rimuoviSpazi(mystring));
        free(rimuoviSpazi(mystring));
    }

    if (isPalindromo(mystring)==1) {
        printf("La stringa è palindroma\n");
    } else if (isPalindromo(mystring)==0) {
        printf("La stringa non è palindroma\n");
    }

    printf("Il numero di vocali contenute è: %d\n", contaVocali(mystring));
}
