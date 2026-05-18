// inversione_stringa.c - Inversione stringa in-place

#include <stdio.h>
#include <string.h>
#define MAXLEN 5

int main(){
    int lastchar=0, newlen=0;
    char mystring[MAXLEN], tmpfirst, tmplast, newstring[MAXLEN];

    fgets(mystring, MAXLEN, stdin);

    // Rimuove '\n' inserito da fgets
    lastchar = strlen(mystring);
    mystring[lastchar - 1] = '\0';
    newlen = strlen(mystring);

    if (newlen == 0) {
        printf("\nErrore, la stringa inserita è vuota");
        return 0;
    }

    // Inversione simmetrica in-place
    for (int j = 0; j < newlen/2; j++) {
        tmpfirst = mystring[j];
        tmplast = mystring[newlen-1-j];
        
        mystring[j] = tmplast;
        mystring[newlen-1-j] = tmpfirst;
    }

    printf("La tua stringa invertita è: %s", mystring);
    
    return 0;
}
