/* ascii.c - C source file. */

#include <stdio.h>

char letter = 'z';  // Variabile globale inizializzata con character lowercase

/* *
Function principale che dimostra la conversione uppercase/lowercase
utilizzando l'aritmetica sui codici ASCII
 */
int main(){
    // Prints il character originale
    printf("%c\n", letter);
    
    // Prints il valore ASCII equivalente del character
    printf("%u\n", letter); // equivalent number

    // Conversione da lowercase a uppercase:
    // Sottrae la differenza tra 'a' e 'A' (che è 32 in ASCII)
    letter = letter - ('a'-'A');
    
    // Prints il character convertito in uppercase
    printf("capital letter: %c\n", letter);
}
