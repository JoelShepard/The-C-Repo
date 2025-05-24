/*
 * =============================================================================
 * LIBRERIA CUSTOM PER MANIPOLAZIONE STRINGHE
 * =============================================================================
 * 
 * Descrizione:
 * Implementazione di una libreria personalizzata contenente funzioni utili
 * per la manipolazione e l'analisi di stringhe in C. Include operazioni
 * di inversione, conversione case, rimozione spazi e analisi contenuto.
 * 
 * Autore: Studente FI
 * Data: 29 novembre 2024
 * Corso: Fondamenti di Informatica - Laboratorio
 * 
 * Funzioni implementate:
 * - invertiStringa(): inverte l'ordine dei caratteri
 * - toUppercase(): converte in maiuscolo
 * - rimuoviSpazi(): rimuove tutti gli spazi
 * - isPalindromo(): verifica se la stringa è palindroma
 * - contaVocali(): conta le vocali nella stringa
 * 
 * Note tecniche:
 * - Tutte le funzioni allocano dinamicamente memoria per il risultato
 * - È responsabilità del chiamante liberare la memoria con free()
 * - Gestione case-insensitive per palindromi e conteggio vocali
 * 
 * =============================================================================
 */

#include "custom_lib.h"
#include <string.h>
#include <stdlib.h>

/*
 * Inverte l'ordine dei caratteri in una stringa
 * 
 * Parametri:
 *   str - stringa da invertire
 * 
 * Ritorna:
 *   char* - nuova stringa invertita (memoria allocata dinamicamente)
 */
char* invertiStringa(char *str){
    int len=strlen(str);
    char* newstr = (char*)malloc(sizeof(char)*len);  // Allocazione memoria
    int j = len;

    // Copia caratteri in ordine inverso
    for(int i=0; i<len; i++){
        newstr[i] = str[j-1];  // Ultimo carattere -> primo posto
        j--;
    }
    newstr[len]='\0';  // Terminatore stringa

    return newstr;
}

/*
 * Converte una stringa in maiuscolo
 * 
 * Parametri:
 *   str - stringa da convertire
 * 
 * Ritorna:
 *   char* - nuova stringa in maiuscolo (memoria allocata dinamicamente)
 */
char* toUppercase(char* str){
    int len=strlen(str);
    char* newstr = (char*)malloc(sizeof(char)*len);

    // Conversione carattere per carattere
    for (int i=0; i<len; i++) {
        if (str[i]>='A' && str[i]<='Z') {
            newstr[i]=str[i];  // Già maiuscolo
        } else if (str[i]>='a' && str[i]<='z'){
            newstr[i] = str[i] - 'a' + 'A';  // Conversione a->A, b->B, etc.
        } else {
            newstr[i] = str[i];  // Altri caratteri inalterati
        }
            }
    }
    newstr[len]='\0';  // Terminatore stringa
    return newstr;
}

/*
 * Rimuove tutti gli spazi da una stringa
 * 
 * Parametri:
 *   str - stringa da cui rimuovere gli spazi
 * 
 * Ritorna:
 *   char* - nuova stringa senza spazi (memoria allocata dinamicamente)
 */
char* rimuoviSpazi(char *str){
    int len=strlen(str), spaces=0, j=0;
    
    // Prima passata: conta gli spazi
    for(int i=0; i<len; i++){
        if (str[i]==' ') {
           spaces++;
        }
    }

    // Allocazione memoria per stringa risultato (meno spazi)
    char* newstr = (char*)malloc((len - spaces +1)*sizeof(char));

    // Seconda passata: copia solo caratteri non-spazio
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
 * Verifica se una stringa è palindroma (case-insensitive)
 * 
 * Parametri:
 *   str - stringa da verificare
 * 
 * Ritorna:
 *   int - 1 se palindroma, 0 altrimenti
 */
int isPalindromo(char *str){
    int len=strlen(str);
    int lenpos=len-1;
    char* betterstr = toUppercase(str);  // Conversione per confronto case-insensitive

    int pal_true=0;
    // Confronta caratteri da estremi verso centro
    for (int i=0; i<len/2; i++) {
        if (betterstr[0+i]==betterstr[lenpos-i] && (0+i)!=(lenpos-i)) {
            pal_true=1;  // Trovata corrispondenza
        }
    }
    free(betterstr);  // Liberazione memoria temporanea

    return pal_true;
}

/*
 * Conta il numero di vocali in una stringa (case-insensitive)
 * 
 * Parametri:
 *   str - stringa in cui contare le vocali
 * 
 * Ritorna:
 *   int - numero di vocali trovate
 */
int contaVocali(char *str){
    int len=strlen(str);
    int vocali=0;
    char* betterstr = toUppercase(str);  // Conversione per confronto uniforme

    // Scansione carattere per carattere
    for (int i=0; i<len; i++) {
        // Controllo se è una vocale (A, E, I, O, U)
        if (betterstr[i]=='A' || betterstr[i]=='E' ||betterstr[i]=='I' ||betterstr[i]=='O' ||betterstr[i]=='U') {
            vocali++;
        }
    }
    free(betterstr);  // Liberazione memoria temporanea
    return vocali;
}
