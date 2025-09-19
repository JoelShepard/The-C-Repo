/* q3.c - C source file. */

#include <stdio.h>

/* *
Function recursive che separa i characters di una string in maiuscoli,
minuscoli e conta i characters non-alphabetic

@param s[]    String di input da analizzare
@param up[]   Array per memorizzare i characters maiuscoli
@param low[]  Array per memorizzare i characters minuscoli
@return       Numero di characters non-alphabetic trovati

Algoritmo:
- Base case: se il character corrente è '\0', ritorna 0
- Se lowercase: lo inserisce in low[] e continues recursivemente
- Se uppercase: lo inserisce in up[] e continues recursivemente
- Altrimenti: conta come character non-alphabetic e continues
 */
int distingui(char s[], char up[], char low[]){
    int count = 0;
    
    // CASO BASE: fine string
    if (*s == '\0'){
        return 0;
    }

    // CASO 1: character lowercase (a-z)
    if (*s >= 'a' && *s <= 'z'){
        *low = *s;                                    // Inserisce in array minuscoli
        count += distingui(s+1, up, low+1);          // Ricorsione con puntatori aggiornati
        return count;
    }
    
    // CASO 2: character uppercase (A-Z)
    if (*s >= 'A' && *s <= 'Z') {
        *up = *s;                                     // Inserisce in array maiuscoli
        count += distingui(s+1, up+1, low);          // Ricorsione con puntatori aggiornati
        return count;
    }
    
    // CASO 3: character non-alphabetic (numeri, simboli)
    else {
        count = distingui(s+1, up, low) + 1;         // Conta +1 e continues recursion
        return count;
    }
}

/* *
Function principale per testare la separazione recursive dei characters

Test case: "C4i1a5o?" dovrebbe produrre:
- Maiuscoli: "C"
- Minuscoli: "iao"
- Non alfabetici: 4 (characters: 4, 1, 5, ?)
 */
int main(){
    // INPUT: string di test con characters misti
    char s[] = "C4i1a5o?";
    char up[6];                                       // Array per characters maiuscoli
    char low[6];                                      // Array per characters minuscoli

    // ELABORAZIONE E OUTPUT: prints il numero di characters non-alphabetic
    printf("Caratteri non alfabetici: %d\n", distingui(s, up, low));
    
    return 0;
}
