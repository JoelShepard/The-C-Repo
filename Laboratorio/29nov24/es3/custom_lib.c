#include "custom_lib.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* invertiStringa(char *str){
    int len=strlen(str);
    char* newstr = (char*)malloc(sizeof(char)*len);

    for(int i=0; i<len; i++){
        for (int j=len; j>0; j--) {
            newstr[i] = str[j];
        }
    }
    printf("\0", &newstr[len+1]);
    return newstr;
}
