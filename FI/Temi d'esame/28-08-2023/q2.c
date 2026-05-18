// q2.c - strcmp ricorsivo

#include <stdio.h>

int strcmpRec(char s1[], char s2[]){
    // BUG: dovrebbe essere (*s1 == '\0' || *s2 == '\0')
    if (*s1 == '\0' || *s1 == '\0') {
        return 0;
    }
    
    if (*s1 > *s2) {
        return 1 + strcmpRec(s1+1, s2+1);
    }
    
    if (*s1 < *s2) {
        return -1 + strcmpRec(s1+1, s2+1);
    }
    
    else {
        return 0 + strcmpRec(s1+1, s2+1);
    }
}

int main(){
    char a[] = "gioele";
    char b[] = "casa";

    int ris = strcmpRec(a, b);
    
    printf("Confronto tra '%s' e '%s': %d\n", a, b, ris);
    
    return 0;
}

/* 
Note: La funzione accumula +1/-1 per ogni carattere, logica diversa dallo strcmp standard.
Il bug nella condizione di base può causare comportamenti imprevisti.
Per "gioele" vs "casa": g>c(+1), i>a(+1), o>s(+1), e>a(+1) = risultato positivo.
*/
