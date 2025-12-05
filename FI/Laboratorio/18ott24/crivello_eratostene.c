/* crivello_eratostene.c - C source file. */

#include <stdio.h>
#include <math.h>

#define NUMERI 500  // Limite superiore per la ricerca dei primi

/* *
Function principale che implementa il Crivello di Eratostene
 */
int main(){
    int setaccio[NUMERI-1] = {0};  // Array per memorizzare i numeri (0 = eliminato)
    int i=0, j=0, incremento=0;    // Indici e variabile di supporto

    // === FASE 1: INIZIALIZZAZIONE ARRAY ===
    // Riempe l'array con numeri consecutivi da 2 a NUMERI
    for (i = 0; i < NUMERI-1; i++){
        if (i == 0){
            setaccio[i]=2;
            incremento=setaccio[i];
        }else{
            setaccio[i] = incremento + 1;
            incremento = setaccio[i];
        }
    }

    // === FASE 2: APPLICAZIONE CRIVELLO ===
    // Per ogni numero fino alla radice di NUMERI
    for(i=0; i<sqrt(NUMERI-1); i++){
        if(setaccio[i]!=0){  // Se il numero non è stato eliminato
            // Elimina tutti i multipli di setaccio[i]
            for(j=i+1; j<NUMERI-1; j++){
                if(setaccio[j] % setaccio[i] == 0){
                    setaccio[j]=0;  // Marca come eliminato (non primo)
                }
            }
        }
    }

    printf("Numeri primi fino a %d:\n", NUMERI);
    for (i = 0; i < NUMERI-1; i++){
        if (setaccio[i]!=0) {           // Solo numeri non eliminati
            printf("%d ", setaccio[i]);
        }
    }
    printf("\n");
    
    return 0;
}
