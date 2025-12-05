/* 3_strPalindromaRec.c - C source file. */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 30  // Lunghezza massima della string

char* betterstr(char mystr[]){
    int len = strlen(mystr), count=0;

    for (int i=0; i<len; i++) {
        if (mystr[i]==' ') {
            count++;
        }
    }

    int newlen=len-count+1, j=0;
    char* United =(char*)malloc(sizeof(char)*newlen);

    for (int i=0; i<len; i++) {
        if (mystr[i]!=' ') {
            United[j]=mystr[i];
            j++;
        }
    }
    United[newlen-1]='\0';  // Correzione: era newlen, dovrebbe essere newlen-1

    char* UpperStr = (char*)malloc(sizeof(char)*newlen);

    for (int i=0; i<newlen-1; i++) {
        if (United[i]>='A' && United[i]<='Z') {

            UpperStr[i]=United[i];
        } else if (United[i]>='a' && United[i]<='z'){
            // Converte da lowercase a uppercase
            UpperStr[i] = United[i] - 'a' + 'A';
        } else {
            // Altri characters (numeri, punteggiatura)
            UpperStr[i] = United[i];
        }
    }
    UpperStr[newlen-1]='\0';
    
    // Libera la memoria temporanea
    free(United);
    return UpperStr;
}

int isPalindromaRec(char str[], int start, int end){
    // Se gli indici si sono incontrati o superati, la string è palindroma
    if (start >= end) {
        return 1;
    }
    
    // Se i characters alle posizioni start ed end sono diversi, non è palindroma
    if (str[start] != str[end]) {
        return 0;
    }
    
    // Continua il controllo sui characters interni
    return isPalindromaRec(str, start+1, end-1);
}

/* *
Function principale che gestisce input, normalizzazione e verifica
 */
int main(){
    char str[MAXLEN];
    
    printf("Inserisci la tua stringa: ");
    fgets(str, MAXLEN, stdin);
    str[strlen(str)-1] = '\0';  // Rimuove il character newline

    char* newstr = betterstr(str);
    int poslen = strlen(newstr)-1;

    if (isPalindromaRec(newstr, 0, poslen)) {
        printf("La stringa è palindroma\n");
    } else {
        printf("La stringa non è palindroma\n");
    }
    
    free(newstr);
    return 0;
}
