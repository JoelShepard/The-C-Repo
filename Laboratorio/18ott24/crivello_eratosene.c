#include <stdio.h>
#include <math.h>

#define NUMERI 76

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

    
    
    for (i = 0; i < NUMERI-1; i++)
    {
        printf("%d ", setaccio[i]);
    }
    
    
}