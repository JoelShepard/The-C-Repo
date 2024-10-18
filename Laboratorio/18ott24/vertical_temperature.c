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
    
/*    //somma
    for (i = 0; i < NUMGIORNI; i++){
        sum = (float) sum + temperature[i];
    }
    //media
    avg = (float) sum / NUMGIORNI;
    printf("\nLa temperatura media è: %.3f\n", avg);

    //massimo
    for (i = 0; i < NUMGIORNI; i++){
        if (max < temperature[i])
        {
            max = temperature[i];
        }

    }
    printf("Il massimo è: %.1f\n", max);
    
    //minimo
    for (i = 0; i < NUMGIORNI; i++){
        if (min > temperature[i])
        {
            min = temperature[i];
        }

    }
    printf("Il minimo è: %.1f\n", min); */
    
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
    printf("Il massimo è: %d\n", maxast);   
}


//da completare, buon punto ma va rivisto il ciclo di stampa degli asterischi in colonna