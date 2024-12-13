#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 30

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
    United[newlen]='\0';

    char* UpperStr = (char*)malloc(sizeof(char)*len);

    for (int i=0; i<len; i++) {
        if (United[i]>='A' && United[i]<='Z') {
            UpperStr[i]=United[i];
        } else if (United[i]>='a' && United[i]<='z'){
            UpperStr[i] = United[i] - 'a' + 'A';
        } else {
            UpperStr[i] = United[i];
        }
    }
    UpperStr[len]='\0';
    free(United);

    return UpperStr;
}

int isPalindromaRec(char str[], int start, int end){
    if (start >= end) {
        return 1;
    }
    if (str[start] != str[end]) {
        return 0;
    }

    return isPalindromaRec(str, start+1, end-1);
}


int main(){
    char str[MAXLEN];
    printf("Inserisci la tua stringa: ");
    fgets(str, MAXLEN, stdin);
    str[strlen(str)-1] = '\0';

    char* newstr = betterstr(str);
    int poslen = strlen(newstr)-1;

    if (isPalindromaRec(newstr, 0, poslen)) {
        printf("La stringa è palindroma\n");
    } else {
        printf("La stringa non è palindroma\n");
    }
    free(newstr);

}
