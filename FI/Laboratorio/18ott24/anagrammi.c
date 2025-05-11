#include <stdio.h>
#include <string.h>

#define MAXLEN 20

int main(){
    char word1[MAXLEN], word2[MAXLEN];
    int same_letter=0;

    printf("Inserisci la prima stringa: ");
    fgets(word1, MAXLEN, stdin);
    printf("Inserisci la seconda stringa: ");
    fgets(word2, MAXLEN, stdin);

    //aggiustamento per fgets
    int lastchar1 = strlen(word1);
    word1[lastchar1 - 1] = '\0';
    int lastchar2 = strlen(word2);
    word2[lastchar2 - 1] = '\0';

    for (int i = 0; i < strlen(word1); i++){
        for (int j = 0; j < strlen(word2); j++){
            if (word1[i] == word2[j]){
                same_letter++;
            }
        }
    }


    printf("%d", same_letter);

    if(same_letter == strlen(word2) || same_letter == strlen(word1)){ 
        printf("These words are anagrams");
    } else{
        printf("These words are not anagrams");
    }
    
}