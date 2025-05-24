/**
 * File: q3.c
 * Descrizione: Funzione ricorsiva per separare caratteri maiuscoli, minuscoli 
 *              e contare i caratteri non alfabetici in una stringa
 * Autore: [Studente]
 * Data: 13-06-2024
 * Tema d'esame: Elaborazione ricorsiva di stringhe con separazione caratteri
 * 
 * Commento originale: "C'ero quasi. Allenati di più sul ragionamento ricorsivo. 
 * La return deve passare il tipo della funzione. le chiamate ricorsive falle 
 * su una variabile fuori dalla return per non confonderti."
 */

#include <stdio.h>

/**
 * Funzione ricorsiva che separa i caratteri di una stringa in maiuscoli, 
 * minuscoli e conta i caratteri non alfabetici
 * 
 * @param s[]    Stringa di input da analizzare
 * @param up[]   Array per memorizzare i caratteri maiuscoli
 * @param low[]  Array per memorizzare i caratteri minuscoli
 * @return       Numero di caratteri non alfabetici trovati
 * 
 * Algoritmo:
 * - Caso base: se il carattere corrente è '\0', ritorna 0
 * - Se minuscolo: lo inserisce in low[] e continua ricorsivamente
 * - Se maiuscolo: lo inserisce in up[] e continua ricorsivamente
 * - Altrimenti: conta come carattere non alfabetico e continua
 */
int distingui(char s[], char up[], char low[]){
    int count = 0;
    
    // CASO BASE: fine stringa
    if (*s == '\0'){
        return 0;
    }

    // CASO 1: carattere minuscolo (a-z)
    if (*s >= 'a' && *s <= 'z'){
        *low = *s;                                    // Inserisce in array minuscoli
        count += distingui(s+1, up, low+1);          // Ricorsione con puntatori aggiornati
        return count;
    }
    
    // CASO 2: carattere maiuscolo (A-Z)
    if (*s >= 'A' && *s <= 'Z') {
        *up = *s;                                     // Inserisce in array maiuscoli
        count += distingui(s+1, up+1, low);          // Ricorsione con puntatori aggiornati
        return count;
    }
    
    // CASO 3: carattere non alfabetico (numeri, simboli)
    else {
        count = distingui(s+1, up, low) + 1;         // Conta +1 e continua ricorsione
        return count;
    }
}

/**
 * Funzione principale per testare la separazione ricorsiva dei caratteri
 * 
 * Test case: "C4i1a5o?" dovrebbe produrre:
 * - Maiuscoli: "C"
 * - Minuscoli: "iao"  
 * - Non alfabetici: 4 (caratteri: 4, 1, 5, ?)
 */
int main(){
    // INPUT: stringa di test con caratteri misti
    char s[] = "C4i1a5o?";
    char up[6];                                       // Array per caratteri maiuscoli
    char low[6];                                      // Array per caratteri minuscoli

    // ELABORAZIONE E OUTPUT: stampa il numero di caratteri non alfabetici
    printf("Caratteri non alfabetici: %d\n", distingui(s, up, low));
    
    return 0;
}
