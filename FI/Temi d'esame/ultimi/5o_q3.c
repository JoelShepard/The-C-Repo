/* 5o_q3.c - C source file. */

#include <stdio.h>
#include <strings.h>

char min_ch(char s[]){
    if (s[0] == '\0') {
        return '\0';  // Nessun character da confrontare
    }

    if (s[1] == '\0') {
        return s[0];  // Unico character è per definizione il minimo
    }

    char min_resto = min_ch(s + 1);  // Trova minimo nel resto della string

    if (min_resto == '\0') {
        return s[0];  // Se resto vuoto, corrente è il minimo
    }

    if (s[0] < min_resto) {
        return s[0];        // Character corrente è minore
    } else {
        return min_resto;   // Minimo del resto è minore o uguale
    }
}

/* *
Function principale - test dell'algoritmo di ricerca character minimo
 */
int main(){
    char mystr[]="boh";
    
    char risultato = min_ch(mystr);
    printf("Carattere minimo in \"%s\": %c\n", mystr, risultato);
    
    // Note: Per "boh" il risultato atteso è 'b' (ASCII 98)
    // 'o' = ASCII 111, 'h' = ASCII 104, quindi 'b' è il minimo
    
    return 0;
}
