/* temperature.c - C source file. */

#include <stdio.h>
#include <limits.h>

#define NUMGIORNI 7  // Numero di giorni della settimana

/* *
Function principale per l'analisi delle temperature settimanali
Calcola media, massimo, minimo e mostra un istogramma
 */
int main() {
    float temperature[NUMGIORNI];
    float sum=0.0, avg, max=0.0, min=__FLT_MAX__;  // Variabili per calcoli statistici
    int i=0, col=0, j=0;

    for (i = 0; i < NUMGIORNI; i++){
        printf("Valore giorno %d:", i+1);
        scanf("%f", &temperature[i]);
    }
    
    for (i = 0; i < NUMGIORNI; i++){
        sum = (float) sum + temperature[i];  // Cast esplicito per chiarezza
    }
    
    avg = (float) sum / NUMGIORNI;
    printf("\nLa temperatura media è: %.3f\n", avg);

    for (i = 0; i < NUMGIORNI; i++){
        if (max < temperature[i])
        {
            max = temperature[i];
        }
    }
    printf("Il massimo è: %.1f\n", max);
    
    for (i = 0; i < NUMGIORNI; i++){
        if (min > temperature[i])
        {
            min = temperature[i];
        }
    }
    printf("Il minimo è: %.1f\n", min);
    
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
