/* exe1.2.c - C source file. */

#include <stdio.h>

#define DEF_DIM 128  // Size massima dell'array

/* *
Function principale che elimina duplicati consecutivi e calcola la media
 */
int main(){
    // === DICHIARAZIONE VARIABILI ===
    int myarray[DEF_DIM];       // Array per memorizzare i numeri
    int size=0, sum=0, count=0, i=0;  // Size, somma, counter e indice
    float average=0.0;          // Media calcolata

    // === INPUT DIMENSIONE ===
    printf("Inserisci la quantità di numeri da lavorare:");
    scanf("%d", &size);

    // === VALIDAZIONE INPUT ===
    if (size > DEF_DIM){
        printf("Il valore inserito supera il massimo consentito");
        return 0;
    }

    // === INPUT DEI VALORI ===
    printf("Inserisci i valori:");
    for (i = 0; i < size; i++){
        scanf("%d", &myarray[i]);    
    }

    // === ELIMINAZIONE DUPLICATI CONSECUTIVI E CALCOLO SOMMA ===
    for (i = 0; i < size; i++)
    {
        // Conta l'elemento solo se:
        // - È il primo elemento (i == 0) OPPURE
        // - È diverso dall'elemento precedente
        if (i == 0 || myarray[i] != myarray[i-1]) {
            sum += myarray[i];  // Aggiunge alla somma
            count++;           // Incrementa il counter degli elementi unici
        }
    }
    
    // === CALCOLO E OUTPUT DELLA MEDIA ===
    if (count > 0) {
        average = (float) sum / count;  // Cast per divisione in virgola mobile
        printf("La tua media è: %f\n", average);
    } else {
        printf("Nessun elemento valido per calcolare la media.\n");
    }

    return 0;
}
