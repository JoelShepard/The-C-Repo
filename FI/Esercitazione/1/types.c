/*
 * File: types.c
 * Descrizione: Dimostrazione dei tipi di dati in C e delle loro caratteristiche
 *              Include esempi di overflow, rappresentazione esadecimale e variabili globali/locali
 * Autore: Studente FI
 * Data: Esercitazione 1
 */

#include <stdio.h>
#include <inttypes.h>

// === VARIABILI GLOBALI ===
// Le variabili globali occupano memoria e sono accessibili da tutte le funzioni
int var=-154;           // Tipo int con complemento a 2 (C2)
unsigned var2=5;        // Variabile intera positiva, formato %u
                        // Limite massimo memoria per variabili = 4 bytes
                        // Inizializzare le variabili è sempre una buona pratica
                        // La dimensione del tipo int dipende dalla piattaforma usata

int8_t two_comp = 127;  // Equivalente a C2 range [-128, 127] - 1 byte
uint8_t pos_int = 42;   // Equivalente a unsigned range [0, 255] - 1 byte
                        // _t significa tipo specifico con dimensione fissa

int32_t thirtytwo_bit= 355; // Tipo a 32 bit (4 bytes)

/**
 * Funzione principale che dimostra l'uso dei diversi tipi di dati
 * e i fenomeni di overflow
 */
int main(){
    // === VARIABILI LOCALI ===
    int var3; // Variabile locale (valore dipende dal settore di memoria assegnato)
    
    // === STAMPA VALORI E FORMATI ===
    printf("var: %d\n", var);           // Stampa valore decimale
    printf("var2: %u\n", var2);         // Stampa unsigned integer
    printf("var hex: %04X\n", var);     // Stampa in formato esadecimale (4 cifre)

    // === DIMOSTRAZIONE OVERFLOW ===
    printf("%d\n", two_comp);           // Valore iniziale: 127
    two_comp = two_comp +1;             // Incremento che causa overflow
    // Equivalenti: two_comp +=1; oppure two_comp++;
    printf("%d/n", two_comp);           // Risultato: -128 (overflow da 127 a -128)

    // === NOTE TECNICHE ===
    // bash:"man ascii" -> per consultare la tabella ASCII
    // ASCII usa 7 bit ma il compilatore C aggiunge 1 bit per raggiungere 8 bit
    // Unicode è migliore di ASCII perché include ASCII + altri caratteri
}