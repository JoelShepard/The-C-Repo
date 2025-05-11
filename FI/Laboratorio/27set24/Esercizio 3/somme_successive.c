#include <stdio.h>

int main(){
    int a, b, c;
    a = 0;
    b = 0;
    c = 0;
    printf("inserisci il primo fattore:");
    scanf("%d", &a);
    printf("inserisci il secondo fattore:");
    scanf("%d", &b);

    if (b > 0) {
        while(b > 0){
        c = c + a;
        b = b - 1;
        }   
    }
    if (b < 0) {
        while(b < 0){
        c = c + a;
        b = b + 1;
        }
        c = - c;   
    }      

    printf("il risultato è: %d", c);
    return 0;
}