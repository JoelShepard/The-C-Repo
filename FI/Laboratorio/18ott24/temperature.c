/*
 * File: temperature.c
 * Descrizione: Programma per gestire temperature settimanali con calcolo di statistiche
 *              e visualizzazione grafica tramite istogramma
 * Autore: Studente FI
 * Data: 18 ottobre 2024
 */

#include <stdio.h>
#include <limits.h>

#define NUMGIORNI 7  // Numero di giorni della settimana

/**
 * Funzione principale per l'analisi delle temperature settimanali
 * Calcola media, massimo, minimo e mostra un istogramma
 */
int main() {
    // === DICHIARAZIONE VARIABILI ===
    float temperature[NUMGIORNI];         // Array delle temperature
    float sum=0.0, avg, max=0.0, min=__FLT_MAX__;  // Variabili per calcoli statistici
    int i=0, col=0, j=0;                 // Indici e contatori

    // === INPUT DELLE TEMPERATURE ===
    for (i = 0; i < NUMGIORNI; i++){
        printf("Valore giorno %d:", i+1);
        scanf("%f", &temperature[i]);
    }
    
    // === CALCOLO DELLA SOMMA ===
    for (i = 0; i < NUMGIORNI; i++){
        sum = (float) sum + temperature[i];  // Cast esplicito per chiarezza
    }
    
    // === CALCOLO DELLA MEDIA ===
    avg = (float) sum / NUMGIORNI;
    printf("\nLa temperatura media è: %.3f\n", avg);

    // === RICERCA DEL MASSIMO ===
    for (i = 0; i < NUMGIORNI; i++){
        if (max < temperature[i])
        {
            max = temperature[i];  // Aggiorna il massimo
        }
    }
    printf("Il massimo è: %.1f\n", max);
    
    // === RICERCA DEL MINIMO ===
    for (i = 0; i < NUMGIORNI; i++){
        if (min > temperature[i])
        {
            min = temperature[i];  // Aggiorna il minimo
        }
    }
    printf("Il minimo è: %.1f\n", min);
    
    // === VISUALIZZAZIONE TABELLA CON ISTOGRAMMA ===
    printf ("Giorno\tTemperatura\tIstogramma\t");
    for (i = 0; i < NUMGIORNI; i++){
        printf("\n%6d\t%11.1f\t", col+=1, temperature[i]);
        
        // Crea istogramma con asterischi per temperature > 34°C
        if (temperature[i]>34){
            // Un asterisco per ogni grado sopra i 34°C
            for (j = 0; j < (int)temperature[i]-34; j++){
                printf("*");
            }
        }
    }

    printf("\n");
    return 0;
}