/*
 * File: strings.c
 * Descrizione: Esempi di manipolazione di stringhe e array bidimensionali in C
 *              Dimostra l'uso di fgets, strncpy e concetti di base sulle stringhe
 * Autore: Studente FI
 * Data: 17 ottobre 2024 - Lezione
 */

#include <stdio.h>
#include <string.h> // Libreria per la manipolazione delle stringhe

#define DIM 15  // Dimensione massima per le stringhe

/**
 * Funzione principale che dimostra operazioni su stringhe e array 2D
 * Le stringhe rappresentano caratteri che si leggono in sequenza
 */
int main(){

    /*
     * === ESEMPI COMMENTATI ===
     * char str1[20]; // Spazio per 20 caratteri
     * int x=0;
     * scanf("%s", str1); // scanf si interrompe con spazi, a capo e tabulazioni
     * printf("%s", str1);
     * strcpy(str1, "\nalfa e beta");
     * printf("%s", str1);
     * char strg[] = "Hello World"; 
     * 
     * x = strlen(str1);
     * printf("\nla lunghezza della stringa è: %d", x); // numero caratteri + spazi, senza terminatore
     */
    
    // === DICHIARAZIONE E INIZIALIZZAZIONE STRINGHE ===
    char str1[]="Hello World";  // Stringa inizializzata
    char str2[DIM];             // Buffer per input utente
    
    // === INPUT STRINGA CON FGETS ===
    // fgets acquisisce (n-1) caratteri da stdin, inclusi gli spazi
    // È più sicura di scanf per l'input di stringhe
    fgets(str2, DIM, stdin); // Può dare problemi se usata dopo scanf
    printf("%s", str2);
    
    // === OPERAZIONI SU STRINGHE ===
    // strncpy: copia i primi n caratteri da str1 a str2
    printf(strncpy(str2, str1, 6)); // Sovrascrive l'inizio di str2 con i primi 6 char di str1

    // === ARRAY BIDIMENSIONALI ===
    // Matrice bidimensionale 20x30
    // La rappresentazione in memoria resta comunque monodimensionale
    int a[20][30];
    
    // Assegnazione di valori a posizioni specifiche
    a[14][23] = 1231231;  // Elemento alla riga 14, colonna 23
    a[0][0] = 12082005;   // Elemento nell'angolo superiore sinistro
    
    // Stampa dei valori assegnati
    printf("%d %d", a[0][0], a[14][23]);
}

/*
 * === NOTE TEORICHE SULLE STRINGHE ===
 * La differenza tra stringhe e char sta nel terminatore usato nella stringa: '\0'
 * Le stringhe non sono tipi veri e propri ma sono array di char con terminatore nullo
 * Ogni stringa termina automaticamente con il carattere '\0' (null terminator)
 */