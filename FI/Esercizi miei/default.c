/*
 * File: default.c
 * Descrizione: Programma di template base creato su iPad
 *              Include configurazione per output immediato
 * Autore: Studente FI
 * Data: Esercizi personali
 * Note: Creato su iPad
 */

#include <stdio.h>

/**
 * Funzione principale con configurazione per output immediato
 */
int main() {
   // Disabilita il buffering dell'output per visualizzazione immediata
   // Utile quando si lavora su piattaforme mobile o ambienti specifici
   setbuf(stdout, NULL);
   
   // Stampa messaggio di prova
   printf("Hello, World!");
   
   return 0;
}