/*
 * File: ipotenusa.c
 * Descrizione: Calcolo dell'ipotenusa di un triangolo rettangolo 
 *              utilizzando il teorema di Pitagora: i² = c1² + c2²
 * Autore: Studente FI
 * Data: Esercitazione 1
 */

#include <stdio.h>
#include <math.h>

/**
 * Funzione principale che calcola l'ipotenusa di un triangolo rettangolo
 * Formula utilizzata: ipotenusa = sqrt(cateto1² + cateto2²)
 */
int main(){
    // === DICHIARAZIONE VARIABILI ===
    double c1=0.0, c2=0.0, i=0.0;  // c1, c2: cateti; i: ipotenusa
    
    // === INPUT DEI DATI ===
    printf("primo cateto: ");
    scanf("%lf\n", &c1);           // %lf per double

    printf("secondo cateto: ");
    scanf("%lf", &c2);

    // === CALCOLO IPOTENUSA ===
    // Applica il teorema di Pitagora: i = √(c1² + c2²)
    i = sqrt(c1*c1+c2*c2);

    // === OUTPUT RISULTATO ===
    printf("%lf", i);
    
    return 0;
}