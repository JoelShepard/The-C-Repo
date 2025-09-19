/* mcd_gpt.c - C source file. */

#include <stdio.h>

/* *
Function principale per calcolare il MCD di due numeri interi

Metodo utilizzato: Ricerca esaustiva
- Testa tutti i numeri da 1 al minimo tra num1 e num2
- Per ogni numero i, verifica se divide entrambi i numeri
- L'ultimo divisore comune trovato è il MCD

Complessità temporale: O(min(num1, num2))
 */
int main() {
    // VARIABILI
    int num1, num2;                       // I due numeri di input
    int mcd = 1;                          // MCD inizializzato a 1 (sempre divisore)
    int i = 1;                            // Contatore per testare i divisori

    // INPUT: acquisizione dei due numeri
    printf("Inserire il primo numero: ");
    scanf("%d", &num1);
    printf("Inserire il secondo numero: ");
    scanf("%d", &num2);
    
    // Validazione input (numeri positivi)
    if (num1 <= 0 || num2 <= 0) {
        printf("Errore: inserire solo numeri positivi\n");
        return 1;
    }

    // ALGORITMO MCD: ricerca esaustiva di tutti i divisori comuni
    // Continua finché i non supera il minimo tra i due numeri
    while (i <= num1 && i <= num2) {
        // VERIFICA DIVISIBILITÀ: i deve dividere entrambi i numeri
        if (num1 % i == 0 && num2 % i == 0) {
            mcd = i;                      // Aggiorna il MCD: i è un divisore comune
        }
        i++;                              // Incrementa per testare il divisore successivo
    }

    // OUTPUT: visualizzazione del risultato
    printf("Il massimo comune divisore di %d e %d è: %d\n", num1, num2, mcd);

    return 0;
}

/* 
Note tecniche:
- Questo algoritmo è semplice ma non efficiente per numeri grandi
- L'algoritmo di Euclide sarebbe più efficiente: O(log(min(num1, num2)))
- Il risultato è sempre corretto per numeri positivi
- Il MCD di due numeri è sempre >= 1 (il numero 1 divide sempre tutto)
 */
