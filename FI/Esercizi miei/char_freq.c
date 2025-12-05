/* char_freq.c - C source file. */

#include <stdio.h>
#include <stdlib.h>

char freq(FILE* file, int* let){
    char buffer;        // Buffer per leggere characters dal file
    int max=0;         // Indice del character più frequente
    
    // Legge character per character dal file
    while ((buffer = fgetc(file)) != EOF) {

        // Note: Assumo solo lettere minuscole 'a'-'z'
        if (buffer >= 'a' && buffer <= 'z') {
            let[buffer-'a']+=1;
        }
    }
    
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

int main(int argc, char* argv[]){
    if (argc != 2) {
        printf("Uso: %s <nome_file>\n", argv[0]);
        return -1;
    }
    
    int letters[26]={0};  // Array per contare le 26 lettere dell'alfabeto
    
    FILE* my = fopen(argv[1], "r");
    if (my==NULL) {
        perror("Errore nell'apertura del file");
        return -1;
    }
    
    char most_frequent = freq(my, letters);
    printf("La lettera più frequente è: %c\nFrequenza: %d\n", 
           most_frequent, letters[most_frequent-'a']);
    
    fclose(my);
    return 0;
}
