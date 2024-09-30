#include <stdio.h>

int main(){
    int a, b, c;
    a = 0;
    b = 0;
    c = 1;
    printf("inserisci il primo fattore:");
    scanf("%d", &a);
    printf("inserisci il secondo fattore:");
    scanf("%d", &b);

    while(b >= 0){
        c = a + c;
        b = b - 1;
    }
    
    printf("il risultato è: %d", c);
}

// da finire