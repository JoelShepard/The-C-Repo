// Programma che stampa una sequenza di numeri in ordine crescente
#include <stdio.h>

#define DEFAULT_DIM 100 

int main(){
    int myarray[DEFAULT_DIM];
    int i=0, j=0, tmp1=0, tmp2=0;
    int size=0;

    printf("Inserisci la quantità di numeri da ordinare:");
    scanf("%d", &size);

    if (size > DEFAULT_DIM){
        printf("Il valore inserito supera il massimo consentito");
        return 0;
    }
    

    for (i = 0; i < size; i++){
        scanf("%d", &myarray[i]);    
    }

    for (i = 0; i < size; i++){
        
        for (j = 1; j < size; j++){
            if (myarray[i] > myarray[j]){
                tmp1=myarray[i];
                tmp2=myarray[j];
                myarray[i]=tmp2;
                myarray[j]=tmp1;
            }
            
        }
    }
    
    printf("I tuoi numeri in ordine sono:"); 

    for (i = 0; i < size; i++){
        printf("\n%d", myarray[i]);
    }
    
    return 0;
}

// prova a sistemare