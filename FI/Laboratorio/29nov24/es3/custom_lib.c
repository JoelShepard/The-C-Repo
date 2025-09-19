/* custom_lib.c - C source file. */

#include "custom_lib.h"
#include <string.h>
#include <stdlib.h>

/* 
Inverte l'ordine dei characters in una string

Parametri:
str - string da invertire

Ritorna:
char* - nuova string invertita (memoria allocata dinamicamente)
 */
char* invertiStringa(char *str){
    int len=strlen(str);
    char* newstr = (char*)malloc(sizeof(char)*len);  // Allocazione memoria
    int j = len;

    // Copia characters in ordine inverso
    for(int i=0; i<len; i++){
        newstr[i] = str[j-1];  // Ultimo character -> primo posto
        j--;
    }
    newstr[len]='\0';  // Terminatore string

    return newstr;
}

/* 
Converte una string in uppercase

Parametri:
str - string da convertire

Ritorna:
char* - nuova string in uppercase (memoria allocata dinamicamente)
 */
char* toUppercase(char* str){
    int len=strlen(str);
    char* newstr = (char*)malloc(sizeof(char)*len);

    // Conversione character per character
    for (int i=0; i<len; i++) {
        if (str[i]>='A' && str[i]<='Z') {
            newstr[i]=str[i];  // Già uppercase
        } else if (str[i]>='a' && str[i]<='z'){
            newstr[i] = str[i] - 'a' + 'A';  // Conversione a->A, b->B, etc.
        } else {
            newstr[i] = str[i];  // Altri characters inalterati
        }
            }
    }
    newstr[len]='\0';  // Terminatore string
    return newstr;
}

/* 
Rimuove tutti gli spazi da una string

Parametri:
str - string da cui rimuovere gli spazi

Ritorna:
char* - nuova string senza spazi (memoria allocata dinamicamente)
 */
char* rimuoviSpazi(char *str){
    int len=strlen(str), spaces=0, j=0;
    
    // Prima passata: conta gli spazi
    for(int i=0; i<len; i++){
        if (str[i]==' ') {
           spaces++;
        }
    }

    // Allocazione memoria per string risultato (meno spazi)
    char* newstr = (char*)malloc((len - spaces +1)*sizeof(char));

    // Seconda passata: copia solo characters non-spazio
    for (int i=0; i<len; i++) {
        if (str[i]!=' ') {
            newstr[j]=str[i];
            j++;
        }
    }
    newstr[j]='\0';  // Terminatore
    return newstr;
}

/* 
Verifica se una string è palindroma (case-insensitive)

Parametri:
str - string da verificare

Ritorna:
int - 1 se palindroma, 0 altrimenti
 */
int isPalindromo(char *str){
    int len=strlen(str);
    int lenpos=len-1;
    char* betterstr = toUppercase(str);  // Conversione per confronto case-insensitive

    int pal_true=0;
    // Confronta characters da estremi verso centro
    for (int i=0; i<len/2; i++) {
        if (betterstr[0+i]==betterstr[lenpos-i] && (0+i)!=(lenpos-i)) {
            pal_true=1;  // Trovata corrispondenza
        }
    }
    free(betterstr);  // Liberazione memoria temporanea

    return pal_true;
}

/* 
Conta il numero di vocali in una string (case-insensitive)

Parametri:
str - string in cui contare le vocali

Ritorna:
int - numero di vocali trovate
 */
int contaVocali(char *str){
    int len=strlen(str);
    int vocali=0;
    char* betterstr = toUppercase(str);  // Conversione per confronto uniforme

    // Scansione character per character
    for (int i=0; i<len; i++) {
        // Controllo se è una vocale (A, E, I, O, U)
        if (betterstr[i]=='A' || betterstr[i]=='E' ||betterstr[i]=='I' ||betterstr[i]=='O' ||betterstr[i]=='U') {
            vocali++;
        }
    }
    free(betterstr);  // Liberazione memoria temporanea
    return vocali;
}
