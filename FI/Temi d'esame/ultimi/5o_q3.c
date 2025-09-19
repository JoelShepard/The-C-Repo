/* 5o_q3.c - C source file. */

#include <stdio.h>
#include <strings.h>

/* *
Function recursive per trovare il character minimo in una string

Algoritmo:
1. Base case: string vuota -> ritorna '\0'
2. Base case: un character -> ritorna quel character
3. Case ricorsivo: confronta primo character con minimo del resto

@param s String da analizzare
@return  Character con valore ASCII minimo, '\0' se string vuota
 */
char min_ch(char s[]){
    // === CASO BASE: STRINGA VUOTA ===
    if (s[0] == '\0') {
        return '\0';  // Nessun character da confrontare
    }

    // === CASO BASE: STRINGA DI UN CARATTERE ===
    if (s[1] == '\0') {
        return s[0];  // Unico character è per definizione il minimo
    }

    // === CASO RICORSIVO ===
    char min_resto = min_ch(s + 1);  // Trova minimo nel resto della string

    // === GESTIONE CASO RESTO VUOTO ===
    if (min_resto == '\0') {
        return s[0];  // Se resto vuoto, corrente è il minimo
    }

    // === CONFRONTO E RITORNO MINIMO ===
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
    // === DATI DI TEST ===
    char mystr[]="boh";  // String di test
    
    // === ESECUZIONE E OUTPUT ===
    char risultato = min_ch(mystr);
    printf("Carattere minimo in \"%s\": %c\n", mystr, risultato);
    
    // Note: Per "boh" il risultato atteso è 'b' (ASCII 98)
    // 'o' = ASCII 111, 'h' = ASCII 104, quindi 'b' è il minimo
    
    return 0;
}
