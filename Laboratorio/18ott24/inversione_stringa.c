#include <stdio.h>
#include <string.h>
#define MAXLEN 5

int main(){
    // dichiarazione
    int lastchar=0, newlen=0;
    char mystring[MAXLEN], tmpfirst, tmplast, newstring[MAXLEN];

    //Input da stdin
    fgets(mystring, MAXLEN, stdin);

    //aggiustamento per fgets e calcolo della lunghezza
    lastchar = strlen(mystring);
    mystring[lastchar - 1] = '\0';
    newlen = strlen(mystring);

    //controllo stringa
    if (newlen == 0) {
        printf("\nErrore, la stringa inserita è vuota");
        return 0;
    }

    // inversione carattere per carattere
    for (int j = 0; j < newlen/2; j++) {
        tmpfirst = mystring[j];
        tmplast = mystring[newlen-1-j]; // ricorda che l'array stringa parte da 0. Ci ho messo 20 min per capire come mai il tool abbia inserto questo numero
        mystring[j] = tmplast;
        mystring[newlen-1-j] = tmpfirst;
    }

    //Stampa finale
    printf("La tua stringa invertita è: %s", mystring);
    return 0;
}
