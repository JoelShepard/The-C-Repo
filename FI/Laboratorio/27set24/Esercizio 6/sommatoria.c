#include <stdio.h>

int main(){
    int r, q, iter; 
    float tot = 0.0;

    printf("\nInserisci il primo estremo della sommatoria:");
    scanf("%d", &q);
    printf("Inserisci il secondo estremo della sommatoria:");
    scanf("%d", &r);

    if(q < 0 || r < 0){
        printf("\nEstremi inseriti non validi. Inserisci interi positivi diversi da 0\n");
        return 0;
    } else if(r < q){
        printf("\nIl secondo estremo deve essere più grande del primo\n");
        return 0;
    }

    iter = r - q;

    while(iter >= 0){
        tot = tot + (1.0 / q);
        iter--;
        q++;
    }
    printf("\nIl risultato della sommatoria è: %f\n", tot);
}