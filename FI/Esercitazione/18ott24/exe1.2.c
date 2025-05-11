// una array che data una sequenza, se ci sono due numeri uguali, uno di fianco all'altro, li conta una sola volta, e restituisce la media
#include <stdio.h>

#define DEF_DIM 128

int main(){
    int myarray[DEF_DIM];
    int size=0, sum=0, count=0, i=0;
    float average=0.0;

    printf("Inserisci la quantità di numeri da lavorare:");
    scanf("%d", &size);

    if (size > DEF_DIM){
        printf("Il valore inserito supera il massimo consentito");
        return 0;
    }

    printf("Inserisci i valori:");
    for (i = 0; i < size; i++){
        scanf("%d", &myarray[i]);    
    }

    for (i = 0; i < size; i++)
    {
        if (i == 0 || myarray[i] != myarray[i-1]) {
            sum += myarray[i];
            count++;
        }
    }
    if (count > 0) {
        average = (float) sum / count;
        printf("La tua media è: %f\n", average);
    } else {
        printf("Nessun elemento valido per calcolare la media.\n");
    }

    return 0;
}
