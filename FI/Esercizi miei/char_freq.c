/*
 * File: char_freq.c
 * Descrizione: Programma che analizza la frequenza dei caratteri in un file di testo
 *              e determina quale lettera compare più frequentemente
 * Autore: Studente FI
 * Data: Esercizi personali
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Funzione che calcola le frequenze dei caratteri e trova quello più frequente
 * @param file Puntatore al file da analizzare
 * @param let Array di 26 elementi per contare le occorrenze di ogni lettera
 * @return Carattere più frequente nel file
 */
char freq(FILE* file, int* let){
    char buffer;        // Buffer per leggere caratteri dal file
    int max=0;         // Indice del carattere più frequente
    
    // === CONTEGGIO DELLE FREQUENZE ===
    // Legge carattere per carattere dal file
    while ((buffer = fgetc(file)) != EOF) {
        // Incrementa il contatore per la lettera corrente
        // Nota: Assumo solo lettere minuscole 'a'-'z'
        if (buffer >= 'a' && buffer <= 'z') {
            let[buffer-'a']+=1;
        }
    }
    
    // === RICERCA DEL MASSIMO ===
    // Trova l'indice della lettera con frequenza massima
    for (int i=0; i<26; i++) {  // Correzione: era 25, dovrebbe essere 26
        if (let[max]<let[i]) {
            max=i;
        }
    }
    
    // Converte l'indice nel carattere corrispondente
    char top = max + 'a';
    return top;
}

/**
 * Funzione principale che gestisce l'apertura del file e l'output
 * @param argc Numero di argomenti da linea di comando
 * @param argv Array degli argomenti (argv[1] deve essere il nome del file)
 */
int main(int argc, char* argv[]){
    // === VALIDAZIONE ARGOMENTI ===
    if (argc != 2) {
        printf("Uso: %s <nome_file>\n", argv[0]);
        return -1;
    }
    
    // === INIZIALIZZAZIONE ===
    int letters[26]={0};  // Array per contare le 26 lettere dell'alfabeto
    
    // === APERTURA FILE ===
    FILE* my = fopen(argv[1], "r");
    if (my==NULL) {
        perror("Errore nell'apertura del file");
        return -1;
    }
    
    // === ANALISI E OUTPUT ===
    char most_frequent = freq(my, letters);
    printf("La lettera più frequente è: %c\nFrequenza: %d\n", 
           most_frequent, letters[most_frequent-'a']);
    
    // === CHIUSURA FILE ===
    fclose(my);
    return 0;
}
