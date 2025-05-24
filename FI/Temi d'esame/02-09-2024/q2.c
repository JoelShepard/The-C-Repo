/**
 * File: q2.c
 * Descrizione: Funzione ricorsiva che incrementa ogni cifra di un numero di 1,
 *              con gestione del wrap-around (9 diventa 0)
 * Autore: [Studente]
 * Data: 02-09-2024
 * Tema d'esame: Manipolazione ricorsiva delle cifre di un numero
 * 
 * Algoritmo: Per ogni cifra, se è 9 diventa 0, altrimenti si incrementa di 1
 * Esempio: 12302 → 23413, 999 → 000
 */

#include <stdio.h>

/**
 * Funzione ricorsiva che incrementa ogni cifra di un numero di 1
 * 
 * @param n  Numero intero da elaborare
 * @return   Nuovo numero con ogni cifra incrementata di 1 (9 → 0)
 * 
 * Strategia ricorsiva:
 * 1. Caso base: se n=0, ritorna 0
 * 2. Estrae l'ultima cifra (n%10)
 * 3. Incrementa la cifra (con wrap 9→0)
 * 4. Elabora ricorsivamente il resto del numero (n/10)
 * 5. Ricompone il risultato: resto_elaborato*10 + cifra_incrementata
 */
int plusone(int n){
    // CASO BASE: numero vuoto
    if (n == 0) {
        return 0;
    } else {
        // ESTRAZIONE: ultima cifra del numero
        int ultimacifra = n % 10;
        int newultima = 0;
        
        // INCREMENTO CON WRAP-AROUND: 9 diventa 0, altri +1
        if (ultimacifra == 9) {
            newultima = 0;                    // Wrap-around: 9 → 0
        } else {
            newultima = ultimacifra + 1;      // Incremento normale: n → n+1
        }
        
        // RICORSIONE: elabora il resto del numero
        int resto = n / 10;                   // Rimuove l'ultima cifra
        int nuovo = plusone(resto);           // Elabora ricorsivamente il resto
        
        // RICOMPOSIZIONE: nuovo_resto * 10 + cifra_incrementata
        return nuovo * 10 + newultima;
    }
}

/**
 * Funzione principale per testare l'incremento ricorsivo delle cifre
 * 
 * Test case: 12302 dovrebbe diventare 23413
 * - 1 → 2
 * - 2 → 3  
 * - 3 → 4
 * - 0 → 1
 * - 2 → 3
 */
int main(){
    // INPUT: numero di test
    int numero = 12302;
    
    // ELABORAZIONE E OUTPUT: incrementa ogni cifra e stampa il risultato
    printf("Numero originale: %d\n", numero);
    printf("Numero incrementato: %d\n", plusone(numero));
    
    return 0;
}
