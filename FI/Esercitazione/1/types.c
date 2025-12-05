/* types.c - C source file. */

#include <stdio.h>
#include <inttypes.h>

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

/* *
Function principale che dimostra l'uso dei diversi tipi di dati
e i fenomeni di overflow
 */
int main(){
    int var3; // Variabile locale (valore dipende dal settore di memoria assegnato)
    
    printf("var: %d\n", var);
    printf("var2: %u\n", var2);
    printf("var hex: %04X\n", var);     // Prints in formato esadecimale (4 cifre)

    printf("%d\n", two_comp);
    two_comp = two_comp +1;
    // Equivalenti: two_comp +=1; oppure two_comp++;
    printf("%d/n", two_comp);           // Risultato: -128 (overflow da 127 a -128)

    // bash:"man ascii" -> per consultare la tabella ASCII
    // ASCII usa 7 bit ma il compilatore C adds 1 bit per raddsre 8 bit
    // Unicode è migliore di ASCII perché include ASCII + altri characters
}
