/* q2.c - C source file. */

#include <stdio.h>

int strcmpRec(char s1[], char s2[]){
    // BUG: dovrebbe essere (*s1 == '\0' || *s2 == '\0')
    if (*s1 == '\0' || *s1 == '\0') {
        return 0;
    }
    
    // CASO 1: character di s1 maggiore di s2
    if (*s1 > *s2) {
        return 1 + strcmpRec(s1+1, s2+1);        // +1 e continues
    }
    
    // CASO 2: character di s1 minore di s2
    if (*s1 < *s2) {
        return -1 + strcmpRec(s1+1, s2+1);       // -1 e continues
    }
    
    // CASO 3: characters uguali
    else {
        return 0 + strcmpRec(s1+1, s2+1);        // +0 e continues
    }
}

int main(){
    char a[] = "gioele";                         // Prima string di test
    char b[] = "casa";                           // Seconda string di test

    int ris = strcmpRec(a, b);
    
    printf("Confronto tra '%s' e '%s': %d\n", a, b, ris);
    
    return 0;
}

/* 
Note tecniche:
- La funzione accumula +1 per ogni character in s1 maggiore del corrispondente in s2
- La funzione accumula -1 per ogni character in s1 minore del corrispondente in s2
- Il bug nella condizione di base può causare comportamenti imprevisti
- La logica è diversa dallo strcmp standard che ritorna solo -1, 0, o 1
- Per "gioele" vs "casa": g>c(+1), i>a(+1), o>s(+1), e>a(+1) = risultato positivo
 */
