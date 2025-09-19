/* anagrammi.c - C source file. */

#include <stdio.h>
#include <string.h>

#define MAXLEN 20  // Lunghezza massima delle stringhe

/* *
Function principale per il controllo degli anagrammi
 */
int main(){
    // === DICHIARAZIONE VARIABILI ===
    char word1[MAXLEN], word2[MAXLEN];  // Buffer per le due stringhe
    int same_letter=0;                   // Contatore characters comuni

    // === INPUT DELLE STRINGHE ===
    printf("Inserisci la prima stringa: ");
    fgets(word1, MAXLEN, stdin);
    printf("Inserisci la seconda stringa: ");
    fgets(word2, MAXLEN, stdin);

    // === CORREZIONE CARATTERE NEWLINE ===
    // fgets include il character '\n', lo rimuoviamo
    int lastchar1 = strlen(word1);
    word1[lastchar1 - 1] = '\0';
    int lastchar2 = strlen(word2);
    word2[lastchar2 - 1] = '\0';

    // === CONTEGGIO CARATTERI COMUNI ===
    // Algoritmo semplice: per ogni character della prima string,
    // verifica se esiste nella seconda string
    for (int i = 0; i < strlen(word1); i++){
        for (int j = 0; j < strlen(word2); j++){
            if (word1[i] == word2[j]){
                same_letter++;  // Incrementa se character comune trovato
            }
        }
    }

    // === OUTPUT RISULTATI ===
    printf("Caratteri comuni: %d\n", same_letter);

    // === VERIFICA ANAGRAMMI ===
    // NOTA: Logica semplificata - verifica solo se il numero di characters
    // comuni è uguale alla lunghezza di una delle stringhe
    if(same_letter == strlen(word2) || same_letter == strlen(word1)){ 
        printf("These words are anagrams\n");
    } else{
        printf("These words are not anagrams\n");
    }
    
/* MIGLIORAMENTI POSSIBILI:
- Ordinare entrambe le stringhe e confrontarle
- Usare array di frequenze per ogni character
- Gestire lettere maiuscole/minuscole
- Rimuovere spazi e characters speciali
 */
    
    return 0;
}
