/**
 * File: q2.c
 * Descrizione: Implementazione ricorsiva di una funzione di confronto tra stringhe
 *              che conta le differenze cumulative tra caratteri
 * Autore: [Studente]
 * Data: 28-08-2023
 * Tema d'esame: Confronto ricorsivo di stringhe con somma delle differenze
 * 
 * Commento originale: "First Try !!!"
 * 
 * Nota: La funzione ha una logica particolare - non è un semplice strcmp,
 * ma accumula le differenze tra i caratteri delle stringhe
 */

#include <stdio.h>

/**
 * Confronta ricorsivamente due stringhe sommando le differenze tra caratteri
 * 
 * @param s1  Prima stringa da confrontare
 * @param s2  Seconda stringa da confrontare
 * @return    Somma cumulativa delle differenze tra caratteri
 * 
 * Algoritmo:
 * - Caso base: se uno dei due caratteri è '\0', ritorna 0
 * - Se s1[i] > s2[i]: ritorna 1 + risultato ricorsivo del resto
 * - Se s1[i] < s2[i]: ritorna -1 + risultato ricorsivo del resto
 * - Se s1[i] = s2[i]: ritorna 0 + risultato ricorsivo del resto
 * 
 * ATTENZIONE: La condizione di base ha un bug - controlla due volte *s1
 */
int strcmpRec(char s1[], char s2[]){
    // CASO BASE: fine di una delle due stringhe
    // BUG: dovrebbe essere (*s1 == '\0' || *s2 == '\0')
    if (*s1 == '\0' || *s1 == '\0') {
        return 0;
    }
    
    // CASO 1: carattere di s1 maggiore di s2
    if (*s1 > *s2) {
        return 1 + strcmpRec(s1+1, s2+1);        // +1 e continua
    }
    
    // CASO 2: carattere di s1 minore di s2
    if (*s1 < *s2) {
        return -1 + strcmpRec(s1+1, s2+1);       // -1 e continua
    }
    
    // CASO 3: caratteri uguali
    else {
        return 0 + strcmpRec(s1+1, s2+1);        // +0 e continua
    }
}

/**
 * Funzione principale per testare il confronto ricorsivo
 * 
 * Test case: 
 * - "gioele" vs "casa"
 * - Confronto carattere per carattere: g>c, i>a, o>s, e>a, l>'\0', e>'\0'
 */
int main(){
    char a[] = "gioele";                         // Prima stringa di test
    char b[] = "casa";                           // Seconda stringa di test

    // ELABORAZIONE: confronto ricorsivo delle stringhe
    int ris = strcmpRec(a, b);
    
    // OUTPUT: risultato del confronto
    printf("Confronto tra '%s' e '%s': %d\n", a, b, ris);
    
    return 0;
}

/*
 * Note tecniche:
 * - La funzione accumula +1 per ogni carattere in s1 maggiore del corrispondente in s2
 * - La funzione accumula -1 per ogni carattere in s1 minore del corrispondente in s2
 * - Il bug nella condizione di base può causare comportamenti imprevisti
 * - La logica è diversa dallo strcmp standard che ritorna solo -1, 0, o 1
 * - Per "gioele" vs "casa": g>c(+1), i>a(+1), o>s(+1), e>a(+1) = risultato positivo
 */
