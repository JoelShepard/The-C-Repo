#include "custom_lib.h"
#include <string.h>
#include <stdlib.h>

char* invertiStringa(char *str){
    int len=strlen(str);
    char* newstr = (char*)malloc(sizeof(char)*len);
    int j = len;

    for(int i=0; i<len; i++){
        newstr[i] = str[j-1];
        j--;
    }
    newstr[len]='\0';

    return newstr;
}

char* toUppercase(char* str){
    int len=strlen(str);
    char* newstr = (char*)malloc(sizeof(char)*len);

    for (int i=0; i<len; i++) {
        if (str[i]>='a' && str[i]<='z'){
            newstr[i] = str[i] - 'a' + 'A';
        } else {
            newstr[i] = str[i];
        }
    }
    newstr[len]='\0';
    return newstr;
}

char* rimuoviSpazi(char *str){
    int len=strlen(str), spaces=0, j=0;
    

    for(int i=0; i<len; i++){
        if (str[i]==' ') {
           spaces++;
        }
    }

    char* newstr = (char*)malloc((len - spaces +1)*sizeof(char));

    for (int i=0; i<len; i++) {
        if (str[i]!=' ') {
            newstr[j]=str[i];
            j++;
        }
    }
    newstr[j]='\0';
    return newstr;
}

int isPalindromo(char *str){
    int len=strlen(str);
    int lenpos=len-1;
    char* betterstr = toUppercase(str);

    int pal_true=0;
    for (int i=0; i<len/2; i++) {
        if (betterstr[0+i]==betterstr[lenpos-i] && (0+i)!=(lenpos-i)) {
            pal_true=1;
        }
    }
    free(betterstr);

    return pal_true;
}

int contaVocali(char *str){
    int len=strlen(str);
    int vocali=0;
    char* betterstr = toUppercase(str);

    for (int i=0; i<len; i++) {
        if (betterstr[i]=='A' || betterstr[i]=='E' ||betterstr[i]=='I' ||betterstr[i]=='O' ||betterstr[i]=='U') {
            vocali++;
        }
    }
    free(betterstr);
    return vocali;
}