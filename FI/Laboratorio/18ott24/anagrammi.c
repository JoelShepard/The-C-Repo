/*
 * File: anagrammi.c
 * Descrizione: Laboratorio del 18 ottobre 2024 - Verifica di anagrammi
 *              Programma che determina se due stringhe sono anagrammi
 * Autore: Studente FI
 * Data: 18 ottobre 2024
 * Contesto: Fondamenti di Informatica - Elaborazione stringhe
 * 
 * Funzionalità:
 * - Confronta due stringhe per verificare se sono anagrammi
 * - Conta i caratteri comuni tra le due stringhe
 * - Implementa logica semplificata (con possibili miglioramenti)
 * 
 * Note: Algoritmo attuale non perfetto - conta solo caratteri comuni,
 *       non verifica distribuzione esatta delle lettere
 */

#include <stdio.h>
#include <string.h>

#define MAXLEN 20  // Lunghezza massima delle stringhe

/**
 * Funzione principale per il controllo degli anagrammi
 */
int main(){
    // === DICHIARAZIONE VARIABILI ===
    char word1[MAXLEN], word2[MAXLEN];  // Buffer per le due stringhe
    int same_letter=0;                   // Contatore caratteri comuni

    // === INPUT DELLE STRINGHE ===
    printf("Inserisci la prima stringa: ");
    fgets(word1, MAXLEN, stdin);
    printf("Inserisci la seconda stringa: ");
    fgets(word2, MAXLEN, stdin);

    // === CORREZIONE CARATTERE NEWLINE ===
    // fgets include il carattere '\n', lo rimuoviamo
    int lastchar1 = strlen(word1);
    word1[lastchar1 - 1] = '\0';
    int lastchar2 = strlen(word2);
    word2[lastchar2 - 1] = '\0';

    // === CONTEGGIO CARATTERI COMUNI ===
    // Algoritmo semplice: per ogni carattere della prima stringa,
    // verifica se esiste nella seconda stringa
    for (int i = 0; i < strlen(word1); i++){
        for (int j = 0; j < strlen(word2); j++){
            if (word1[i] == word2[j]){
                same_letter++;  // Incrementa se carattere comune trovato
            }
        }
    }

    // === OUTPUT RISULTATI ===
    printf("Caratteri comuni: %d\n", same_letter);

    // === VERIFICA ANAGRAMMI ===
    // NOTA: Logica semplificata - verifica solo se il numero di caratteri
    // comuni è uguale alla lunghezza di una delle stringhe
    if(same_letter == strlen(word2) || same_letter == strlen(word1)){ 
        printf("These words are anagrams\n");
    } else{
        printf("These words are not anagrams\n");
    }
    
    /* MIGLIORAMENTI POSSIBILI:
     * - Ordinare entrambe le stringhe e confrontarle
     * - Usare array di frequenze per ogni carattere
     * - Gestire lettere maiuscole/minuscole
     * - Rimuovere spazi e caratteri speciali
     */
    
    return 0;
}