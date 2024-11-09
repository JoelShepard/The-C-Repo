#include <stdio.h>
#include <math.h>

#define NUMERI 500

int main(){
    int setaccio[NUMERI-1] = {0}, i=0, j=0, incremento=0;

    for (i = 0; i < NUMERI-1; i++){
        if (i == 0){
            setaccio[i]=2;
            incremento=setaccio[i];
        }else{
        setaccio[i] = incremento + 1;
        incremento = setaccio[i];
        }
    }

    for(i=0;i<sqrt(NUMERI-1);i++){
        if(setaccio[i]!=0){
            for(j=i+1;j<NUMERI-1;j++){
                if(setaccio[j]%setaccio[i]==0){
                    setaccio[j]=0;
                }
            }
        }
    }

    for (i = 0; i < NUMERI-1; i++){
        if (setaccio[i]!=0) {
        printf("%d ", setaccio[i]);
        }
    }
}
