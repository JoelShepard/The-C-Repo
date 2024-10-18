#include <stdio.h>
#include <limits.h>

#define NUMGIORNI 3

int main() {
    float temperature[NUMGIORNI], sum=0.0, avg, max=0.0, min=__FLT_MAX__;
    int i=0, k=0, col=0, j=0, asterischi[NUMGIORNI], aster=0, maxast=0;

    //inserimento
    for (i = 0; i < NUMGIORNI; i++){
        printf("Valore giorno %d:", i+1);
        scanf("%f", &temperature[i]);
    }
    
    //somma
    for (i = 0; i < NUMGIORNI; i++){
        sum += temperature[i];
    }
    //media
    avg = sum / (float) NUMGIORNI;


    //massimo
    for (i = 0; i < NUMGIORNI; i++){
        if (max < temperature[i])
        {
            max = temperature[i];
        }

    }

    
    //minimo
    for (i = 0; i < NUMGIORNI; i++){
        if (min > temperature[i])
        {
            min = temperature[i];
        }

    }

    
    //Star count
    for (i = 0; i < NUMGIORNI; i++){
        aster=0;
        if (temperature[i]>34){
            for (j = 0; j < (int)temperature[i]-34; j++){
                aster+=1;
            }
        }
        asterischi[i]=aster; 
    }
    //massimo asterischi
    for (i = 0; i < NUMGIORNI; i++){
        if (maxast < asterischi[i]){
            maxast = asterischi[i];
        }
    }
// stampa asterischi in colonne verticali
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

// stampa temperatura in fondo
    for (i = 0; i < NUMGIORNI; i++){
        printf("%.1f\t", temperature[i]);
    }
    printf("\n");

    printf("\nLa temperatura media è: %.1f\n", avg);
    printf("Il minimo è: %.1f\n", min);
    printf("Il massimo è: %.1f\n", max);


}

