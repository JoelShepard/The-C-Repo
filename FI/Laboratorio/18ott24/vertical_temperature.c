/* vertical_temperature.c - C source file. */

#include <stdio.h>
#include <limits.h>

#define NUMGIORNI 3  // Numero giorni da analizzare (configurabile)

/* 
Function principale per analisi temperature e generazione grafico
 */
int main() {
    float temperature[NUMGIORNI], sum=0.0, avg, max=0.0, min=__FLT_MAX__;
    int i=0, k=0, col=0, j=0, asterischi[NUMGIORNI], aster=0, maxast=0;

    
    for (i = 0; i < NUMGIORNI; i++){
        printf("Valore giorno %d:", i+1);
        scanf("%f", &temperature[i]);
    }
    
    // SECTION 2: CALCOLO STATISTICHE
    
    // Calcolo somma per media
    for (i = 0; i < NUMGIORNI; i++){
        sum += temperature[i];
    }
    avg = sum / (float) NUMGIORNI;


    for (i = 0; i < NUMGIORNI; i++){
        if (max < temperature[i])
        {
            max = temperature[i];
        }
    }
    

    for (i = 0; i < NUMGIORNI; i++){
        if (min > temperature[i])
        {
            min = temperature[i];
        }
    }

    // SECTION 3: CALCOLO ASTERISCHI PER GRAFICO
    
    // Conta asterischi per ogni giorno (temp > 34°C)
    for (i = 0; i < NUMGIORNI; i++){
        aster=0;
        // Solo temperature sopra 34°C generano asterischi
        if (temperature[i]>34){
            // Numero asterischi = gradi sopra soglia (troncati)
            for (j = 0; j < (int)temperature[i]-34; j++){
                aster+=1;
            }
                    }
        }
        asterischi[i]=aster;  // Memorizza numero asterischi per giorno i
    }
    
    // Trova massimo numero asterischi (per altezza grafico)
    for (i = 0; i < NUMGIORNI; i++){
        if (maxast < asterischi[i]){
            maxast = asterischi[i];
        }
    }

    // SECTION 4: GENERAZIONE GRAFICO VERTICALE
    
    // Prints grafico dall'alto verso il basso
    for (j = maxast; j >= 0; j--){        // Da massima altezza a 0
        for (i = 0; i < NUMGIORNI; i++){
            if (asterischi[i] >= j){
                printf("*\t");  // Asterisco se altezza sufficiente
            } else {
                printf("\t");
            }
        }
        printf("\n");  // Nuova row per livello successivo
    }

    
    // Prints temperature sotto il grafico
    for (i = 0; i < NUMGIORNI; i++){
        printf("%.1f\t", temperature[i]);
    }
    printf("\n");


    printf("\nLa temperatura media è: %.1f\n", avg);
    printf("Il minimo è: %.1f\n", min);
    printf("Il massimo è: %.1f\n", max);

/* 
ESEMPIO OUTPUT:
Se temp = [36.5, 34.0, 38.2]:

*
*   *
*   *
*   *
36.5  34.0  38.2

NOTE TECNICHE:
- Usa casting (int) per troncare decimali
- Tabulazioni per allineamento colonne
- Algoritmo "raster scan" per grafico verticale
- Soglia 34°C hardcoded (potrebbe essere parametrizzata)
 */

    return 0;
}

