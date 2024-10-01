#include <stdio.h>

int main(){
    int r, q, y;

    printf("\n inserisci il primo estremo della somma:");
    scanf("%d", &q);
    printf("\n inserisci il secondo estremo della somma:");
    scanf("%d\n", &r);

    if(q < 0 || r < 0){
        printf("\nEstremi inseriti non validi. Inserisci interi positivi diversi da 0");
        return 0;
    }
}