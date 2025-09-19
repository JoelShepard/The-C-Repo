/* strings.c - C source file. */

#include <stdio.h>
#include <string.h> // Libreria per la manipolazione delle stringhe

#define DIM 15  // Size massima per le stringhe

/* *
Function principale che dimostra operazioni su stringhe e array 2D
Le stringhe rappresentano characters che si leggono in sequenza
 */
int main(){

/* 
=== ESEMPI COMMENTATI ===
     * char str1[20]; // Spazio per 20 characters
int x=0;
     * scanf("%s", str1); // scanf si interrompe con spazi, a capo e tabulazioni
printf("%s", str1);
strcpy(str1, "\nalfa e beta");
printf("%s", str1);
char strg[] = "Hello World";

x = strlen(str1);
     * printf("\nla lunghezza della stringa è: %d", x); // numero characters + spazi, senza terminatestore
 */
    
    // === DICHIARAZIONE E INIZIALIZZAZIONE STRINGHE ===
    char str1[]="Hello World";  // String inizializzata
    char str2[DIM];             // Buffer per input utente
    
    // === INPUT STRINGA CON FGETS ===
    // fgets acquisisce (n-1) characters da stdin, inclusi gli spazi
    // È più sicura di scanf per l'input di stringhe
    fgets(str2, DIM, stdin); // Può dare problemi se usata dopo scanf
    printf("%s", str2);
    
    // === OPERAZIONI SU STRINGHE ===
    // strncpy: copia i primi n characters da str1 a str2
    printf(strncpy(str2, str1, 6)); // Sovrascrive l'inizio di str2 con i primi 6 char di str1

    // === ARRAY BIDIMENSIONALI ===
    // Matrice bidimensionale 20x30
    // La rappresentazione in memoria resta comunque monodimensionale
    int a[20][30];
    
    // Assegnazione di valori a posizioni specifiche
    a[14][23] = 1231231;  // Elemento alla row 14, column 23
    a[0][0] = 12082005;   // Elemento nell'angolo superiore sinistro
    
    // Prints dei valori assegnati
    printf("%d %d", a[0][0], a[14][23]);
}

/* 
=== NOTE TEORICHE SULLE STRINGHE ===
La differenza tra stringhe e char sta nel terminatestore usato nella string: '\0'
Le stringhe non sono tipi veri e propri ma sono array di char con terminatestore nullo
Ogni string terminates automaticamente con il character '\0' (null terminatestor)
 */
