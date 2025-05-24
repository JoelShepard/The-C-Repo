/*
 * File: 5o_q3.c
 * Descrizione: Tema d'esame - Questione 3
 *              Ricerca ricorsiva del carattere minimo in una stringa
 * Autore: Studente FI
 * Data: Tema d'esame
 * Contesto: Fondamenti di Informatica - Algoritmi ricorsivi su stringhe
 * 
 * Funzionalità:
 * - Trova ricorsivamente il carattere con valore ASCII minimo
 * - Implementa algoritmo divide-et-impera su stringhe
 * - Gestisce casi base per stringhe vuote e di un carattere
 */

#include <stdio.h>
#include <strings.h>

/**
 * Funzione ricorsiva per trovare il carattere minimo in una stringa
 * 
 * Algoritmo:
 * 1. Caso base: stringa vuota -> ritorna '\0'
 * 2. Caso base: un carattere -> ritorna quel carattere
 * 3. Caso ricorsivo: confronta primo carattere con minimo del resto
 * 
 * @param s Stringa da analizzare
 * @return  Carattere con valore ASCII minimo, '\0' se stringa vuota
 */
char min_ch(char s[]){
    // === CASO BASE: STRINGA VUOTA ===
    if (s[0] == '\0') {
        return '\0';  // Nessun carattere da confrontare
    }

    // === CASO BASE: STRINGA DI UN CARATTERE ===
    if (s[1] == '\0') {
        return s[0];  // Unico carattere è per definizione il minimo
    }

    // === CASO RICORSIVO ===
    char min_resto = min_ch(s + 1);  // Trova minimo nel resto della stringa

    // === GESTIONE CASO RESTO VUOTO ===
    if (min_resto == '\0') {
        return s[0];  // Se resto vuoto, corrente è il minimo
    }

    // === CONFRONTO E RITORNO MINIMO ===
    if (s[0] < min_resto) {
        return s[0];        // Carattere corrente è minore
    } else {
        return min_resto;   // Minimo del resto è minore o uguale
    }
}

/**
 * Funzione principale - test dell'algoritmo di ricerca carattere minimo
 */
int main(){
    // === DATI DI TEST ===
    char mystr[]="boh";  // Stringa di test
    
    // === ESECUZIONE E OUTPUT ===
    char risultato = min_ch(mystr);
    printf("Carattere minimo in \"%s\": %c\n", mystr, risultato);
    
    // Note: Per "boh" il risultato atteso è 'b' (ASCII 98)
    // 'o' = ASCII 111, 'h' = ASCII 104, quindi 'b' è il minimo
    
    return 0;
}
