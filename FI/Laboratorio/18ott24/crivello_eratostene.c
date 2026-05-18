// crivello_eratostene.c - Crivello di Eratostene

#include <stdio.h>
#include <math.h>

#define NUMERI 500

int main(){
    int setaccio[NUMERI-1] = {0};
    int i=0, j=0, incremento=0;

    for (i = 0; i < NUMERI-1; i++){
        if (i == 0){
            setaccio[i]=2;
            incremento=setaccio[i];
        }else{
            setaccio[i] = incremento + 1;
            incremento = setaccio[i];
        }
    }

    // Elimina multipli di ogni numero primo fino a sqrt(NUMERI)
    for(i=0; i<sqrt(NUMERI-1); i++){
        if(setaccio[i]!=0){
            for(j=i+1; j<NUMERI-1; j++){
                if(setaccio[j] % setaccio[i] == 0){
                    setaccio[j]=0;
                }
            }
        }
    }

    printf("Numeri primi fino a %d:\n", NUMERI);
    for (i = 0; i < NUMERI-1; i++){
        if (setaccio[i]!=0) {
            printf("%d ", setaccio[i]);
        }
    }
    printf("\n");
    
    return 0;
}
