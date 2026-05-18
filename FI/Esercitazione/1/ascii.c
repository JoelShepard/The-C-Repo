// ascii.c - Conversione uppercase/lowercase con aritmetica ASCII

#include <stdio.h>

char letter = 'z';

int main(){
    printf("%c\n", letter);
    printf("%u\n", letter);

    // Sottrae la differenza tra 'a' e 'A' (32 in ASCII)
    letter = letter - ('a'-'A');
    
    printf("capital letter: %c\n", letter);
}
