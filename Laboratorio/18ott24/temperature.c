#include <stdio.h>
#include <limits.h>

#define NUMGIORNI 7

int main() {
    float temperature[NUMGIORNI], sum=0.0, avg, max=0.0, min=__FLT_MAX__;
    int i=0, col=0, j=0;

    //inserimento
    for (i = 0; i < NUMGIORNI; i++){
        printf("Valore giorno %d:", i+1);
        scanf("%f", &temperature[i]);
    }
    
    //somma
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
    printf("Il minimo è: %.1f\n", min);
    
    //Table
    printf ("Giorno\tTemperatura\tIstogramma\t");
    for (i = 0; i < NUMGIORNI; i++){
        printf("\n%6d\t%11.1f\t", col+=1, temperature[i]);
        
        if (temperature[i]>34){
            for (j = 0; j < (int)temperature[i]-34; j++){
                printf("*");
            }
        }
        
    }

    printf("\n");
    return 0;
}