// char_freq.c - Frequenza caratteri in file

#include <stdio.h>
#include <stdlib.h>

char freq(FILE* file, int* let){
    char buffer;
    int max=0;
    
    while ((buffer = fgetc(file)) != EOF) {
        // Assume solo lettere minuscole 'a'-'z'
        if (buffer >= 'a' && buffer <= 'z') {
            let[buffer-'a']+=1;
        }
    }
    
    for (int i=0; i<26; i++) {
        if (let[max]<let[i]) {
            max=i;
        }
    }
    
    char top = max + 'a';
    return top;
}

int main(int argc, char* argv[]){
    if (argc != 2) {
        printf("Uso: %s <nome_file>\n", argv[0]);
        return -1;
    }
    
    int letters[26]={0};
    
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
