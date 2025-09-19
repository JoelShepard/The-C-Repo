/* q2.c - C source file. */

#include <stdio.h>

/* *
Confronta recursivemente due stringhe sommando le differenze tra characters

@param s1  Prima string da confrontare
@param s2  Seconda string da confrontare
@return    Somma cumulativa delle differenze tra characters

Algoritmo:
- Base case: se uno dei due characters è '\0', ritorna 0
- Se s1[i] > s2[i]: ritorna 1 + risultato ricorsivo del resto
- Se s1[i] < s2[i]: ritorna -1 + risultato ricorsivo del resto
- Se s1[i] = s2[i]: ritorna 0 + risultato ricorsivo del resto

WARNING: La condizione di base ha un bug - controlla due volte *s1
 */
int strcmpRec(char s1[], char s2[]){
    // CASO BASE: fine di una delle due stringhe
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

/* *
Function principale per testare il confronto ricorsivo

Test case:
- "gioele" vs "casa"
- Confronto character per character: g>c, i>a, o>s, e>a, l>'\0', e>'\0'
 */
int main(){
    char a[] = "gioele";                         // Prima string di test
    char b[] = "casa";                           // Seconda string di test

    // ELABORAZIONE: confronto ricorsivo delle stringhe
    int ris = strcmpRec(a, b);
    
    // OUTPUT: risultato del confronto
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
