#include <stdio.h>
#include <string.h> // libreria che manipola le stringhe

#define DIM 15

//rappresentano caratteri che si leggono in fila

int main(){

/*    char str1[20]; //spazio per 32 char
    int x=0;
    scanf("%s", str1); //la scanf si interrompe con spazi, a capo e tabulazioni
    printf("%s", str1);
    strcpy(str1, "\nalfa e beta");
    printf("%s", str1);
    char strg[] = "Hello World"; 

    x = strlen(str1);
    printf("\nla lunghezza della stringa è: %d", x); // numero caratteri, spazi + terminatore */
    char str1[]="Hello World";
    char str2[DIM];
    fgets(str2, DIM, stdin); // acquisisce n-1 caratteri da stdin, compresi gli spazi. Da problemi con le scanf
    printf("%s", str2);
    printf(strncpy(str2, str1, 6)); // sovrascrive str1 all'inizio di str2 per il numero di char indicato
}

/*
la differenza tra stringhe e char sta nel terminature usato nella striga \0
le stringhe non sono tipi veri e propri ma sono semplicemente array di char
*/