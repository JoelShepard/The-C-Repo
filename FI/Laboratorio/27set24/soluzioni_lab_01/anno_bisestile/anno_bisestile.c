// anno_bisestile.c - Verifica anno bisestile (Gregoriano)

#include <stdio.h>

int main() {
    int anno;

    printf("Inserisci un anno: ");
    
    if (scanf("%d", &anno) != 1) {
        printf("Input non valido. Inserisci un numero intero.\n");
        return 1;
    }
    
    if (anno < 0) {
        printf("Per favore inserisci un anno positivo.\n");
        return 1;
    }

    // Regola gregoriana: divisibile per 4 e non per 100, oppure divisibile per 400
    if ((anno % 4 == 0 && anno % 100 != 0) || (anno % 400 == 0)) {
        printf("%d è un anno bisestile.\n", anno);
    } else {
        printf("%d non è un anno bisestile.\n", anno);
    }

    return 0;
}
