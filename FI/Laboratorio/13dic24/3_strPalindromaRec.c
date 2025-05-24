/*
 * File: 3_strPalindromaRec.c
 * Descrizione: Programma per verificare se una stringa è palindroma usando ricorsione
 *              Include normalizzazione della stringa (rimuove spazi e converte in maiuscolo)
 * Autore: Studente FI
 * Data: 13 dicembre 2024 - Laboratorio 5
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 30  // Lunghezza massima della stringa

/**
 * Funzione che normalizza una stringa rimuovendo spazi e convertendo in maiuscolo
 * @param mystr Stringa di input
 * @return Puntatore alla nuova stringa normalizzata (da liberare con free)
 */
char* betterstr(char mystr[]){
    int len = strlen(mystr), count=0;

    // === CONTEGGIO DEGLI SPAZI ===
    for (int i=0; i<len; i++) {
        if (mystr[i]==' ') {
            count++;
        }
    }

    // === RIMOZIONE DEGLI SPAZI ===
    int newlen=len-count+1, j=0;
    char* United =(char*)malloc(sizeof(char)*newlen);

    for (int i=0; i<len; i++) {
        if (mystr[i]!=' ') {
            United[j]=mystr[i];
            j++;
        }
    }
    United[newlen-1]='\0';  // Correzione: era newlen, dovrebbe essere newlen-1

    // === CONVERSIONE IN MAIUSCOLO ===
    char* UpperStr = (char*)malloc(sizeof(char)*newlen);

    for (int i=0; i<newlen-1; i++) {  // Correzione: usa newlen-1
        if (United[i]>='A' && United[i]<='Z') {
            // Già maiuscolo
            UpperStr[i]=United[i];
        } else if (United[i]>='a' && United[i]<='z'){
            // Converte da minuscolo a maiuscolo
            UpperStr[i] = United[i] - 'a' + 'A';
        } else {
            // Altri caratteri (numeri, punteggiatura)
            UpperStr[i] = United[i];
        }
    }
    UpperStr[newlen-1]='\0';
    
    // Libera la memoria temporanea
    free(United);
    return UpperStr;
}

/**
 * Funzione ricorsiva per verificare se una stringa è palindroma
 * @param str Stringa da verificare
 * @param start Indice iniziale
 * @param end Indice finale
 * @return 1 se palindroma, 0 altrimenti
 */
int isPalindromaRec(char str[], int start, int end){
    // === CASO BASE ===
    // Se gli indici si sono incontrati o superati, la stringa è palindroma
    if (start >= end) {
        return 1;
    }
    
    // === CONFRONTO CARATTERI ===
    // Se i caratteri alle posizioni start ed end sono diversi, non è palindroma
    if (str[start] != str[end]) {
        return 0;
    }
    
    // === CHIAMATA RICORSIVA ===
    // Continua il controllo sui caratteri interni
    return isPalindromaRec(str, start+1, end-1);
}

/**
 * Funzione principale che gestisce input, normalizzazione e verifica
 */
int main(){
    char str[MAXLEN];
    
    // === INPUT STRINGA ===
    printf("Inserisci la tua stringa: ");
    fgets(str, MAXLEN, stdin);
    str[strlen(str)-1] = '\0';  // Rimuove il carattere newline

    // === NORMALIZZAZIONE ===
    char* newstr = betterstr(str);
    int poslen = strlen(newstr)-1;

    // === VERIFICA PALINDROMA ===
    if (isPalindromaRec(newstr, 0, poslen)) {
        printf("La stringa è palindroma\n");
    } else {
        printf("La stringa non è palindroma\n");
    }
    
    // === PULIZIA MEMORIA ===
    free(newstr);
    return 0;
}
