#include <stdio.h>
#include <stdlib.h>

char freq(FILE* file, int* let){
    char buffer;
    int max=0;
    while ((buffer = fgetc(file)) != EOF) {
        let[buffer-'a']+=1;
    }
    for (int i=0; i<25; i++) {
        if (let[max]<let[i]) {
            max=i;
        }
    }
    char top = max + 'a';
    return top;
}

int main(int argc, char* argv[]){
    if (argc != 2) {
        return -1;
    }
    int letters[26]={0};
    FILE* my = fopen(argv[1], "r");
    if (my==NULL) {
        perror("Errore");
    }
    printf("La lettera più frequente è: %c\nFrequenza: %d\n", freq(my, letters), letters[freq(my, letters)-'a']);
}
