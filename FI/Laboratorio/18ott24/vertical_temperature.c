// vertical_temperature.c - Grafico temperature verticale

#include <stdio.h>
#include <limits.h>

#define NUMGIORNI 3

int main() {
    float temperature[NUMGIORNI], sum=0.0, avg, max=0.0, min=__FLT_MAX__;
    int i=0, k=0, col=0, j=0, asterischi[NUMGIORNI], aster=0, maxast=0;

    for (i = 0; i < NUMGIORNI; i++){
        printf("Valore giorno %d:", i+1);
        scanf("%f", &temperature[i]);
    }
    
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

    // Conta asterischi per ogni giorno (solo temp > 34 C)
    for (i = 0; i < NUMGIORNI; i++){
        aster=0;
        if (temperature[i]>34){
            for (j = 0; j < (int)temperature[i]-34; j++){
                aster+=1;
            }
        }
        asterischi[i]=aster;
    }
    
    // Trova massimo numero asterischi per altezza grafico
    for (i = 0; i < NUMGIORNI; i++){
        if (maxast < asterischi[i]){
            maxast = asterischi[i];
        }
    }

    // Raster scan: stampa dall'alto verso il basso
    for (j = maxast; j >= 0; j--){
        for (i = 0; i < NUMGIORNI; i++){
            if (asterischi[i] >= j){
                printf("*\t");
            } else {
                printf("\t");
            }
        }
        printf("\n");
    }

    for (i = 0; i < NUMGIORNI; i++){
        printf("%.1f\t", temperature[i]);
    }
    printf("\n");

    printf("\nLa temperatura media è: %.1f\n", avg);
    printf("Il minimo è: %.1f\n", min);
    printf("Il massimo è: %.1f\n", max);

    return 0;
}
