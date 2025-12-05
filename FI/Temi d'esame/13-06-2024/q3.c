/* q3.c - C source file. */

#include <stdio.h>

int distingui(char s[], char up[], char low[]){
    int count = 0;
    
    if (*s == '\0'){
        return 0;
    }

    // CASO 1: character lowercase (a-z)
    if (*s >= 'a' && *s <= 'z'){
        *low = *s;                                    // Inserisce in array minuscoli
        count += distingui(s+1, up, low+1);
        return count;
    }
    
    // CASO 2: character uppercase (A-Z)
    if (*s >= 'A' && *s <= 'Z') {
        *up = *s;                                     // Inserisce in array maiuscoli
        count += distingui(s+1, up+1, low);
        return count;
    }
    
    // CASO 3: character non-alphabetic (numeri, simboli)
    else {
        count = distingui(s+1, up, low) + 1;         // Conta +1 e continues recursion
        return count;
    }
}

int main(){
    char s[] = "C4i1a5o?";
    char up[6];                                       // Array per characters maiuscoli
    char low[6];                                      // Array per characters minuscoli

    printf("Caratteri non alfabetici: %d\n", distingui(s, up, low));
    
    return 0;
}
