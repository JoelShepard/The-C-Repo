/* char_freq.c - C source file. */

#include <stdio.h>
#include <stdlib.h>

/* *
Function che calcola le frequenze dei characters e trova quello più frequente
@param file Puntatore al file da analizzare
@param let Array di 26 elementi per contare le occorrenze di ogni lettera
@return Character più frequente nel file
 */
char freq(FILE* file, int* let){
    char buffer;        // Buffer per leggere characters dal file
    int max=0;         // Indice del character più frequente
    
    // === CONTEGGIO DELLE FREQUENZE ===
    // Legge character per character dal file
    while ((buffer = fgetc(file)) != EOF) {
        // Incrementa il counter per la lettera corrente
        // Note: Assumo solo lettere minuscole 'a'-'z'
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
    
    // Converte l'indice nel character corrispondente
    char top = max + 'a';
    return top;
}

/* *
Function principale che gestisce l'apertura del file e l'output
@param argc Numero di argomenti da linea di comando
@param argv Array degli argomenti (argv[1] deve essere il nome del file)
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
