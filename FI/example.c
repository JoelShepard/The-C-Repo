/*
 * File: example.c
 * Descrizione: Funzione ricorsiva per separare caratteri maiuscoli e minuscoli
 *              da una stringa, contando i caratteri non alfabetici
 * Autore: Studente FI
 * Data: Esempio di programmazione
 */

#include <stdio.h>

/**
 * Funzione ricorsiva che separa i caratteri maiuscoli e minuscoli di una stringa
 * @param s[] stringa di input da analizzare
 * @param up[] array per raccogliere i caratteri maiuscoli
 * @param low[] array per raccogliere i caratteri minuscoli
 * @return numero di caratteri non alfabetici trovati
 */
int distingui(char s[], char up[], char low[]) {
    // Caso base: se la stringa è vuota, termina la ricorsione
    if (*s == '\0') {
        return 0; // Caso base: stringa vuota
    }

    char c = *s; // Carattere corrente
    
    if (c >= 'A' && c <= 'Z') { 
        // Carattere maiuscolo: aggiunge a up[] e continua ricorsivamente
        *up = c;
        return distingui(s + 1, up + 1, low);
    } else if (c >= 'a' && c <= 'z') { 
        // Carattere minuscolo: aggiunge a low[] e continua ricorsivamente
        *low = c;
        return distingui(s + 1, up, low + 1);
    } else { 
        // Carattere non alfabetico: incrementa il contatore e continua
        return 1 + distingui(s + 1, up, low);
    }
}

/**
 * Funzione principale per testare la funzione distingui
 */
int main(){
    // Stringa di test con caratteri misti
    char s[] = "2Ew?jm7y9TR£";
    char low[5], up[5]; // Array per caratteri minuscoli e maiuscoli

    // Chiama la funzione ricorsiva
    distingui(s, up, low);

    // Stampa i caratteri maiuscoli trovati
    for (int i=0; i<5; i++) {
        printf("%c ", up[i]);
    }
    
    // Stampa i caratteri minuscoli trovati
    for (int i=0; i<5; i++) {
        printf("%c ", low[i]);
    }
}
