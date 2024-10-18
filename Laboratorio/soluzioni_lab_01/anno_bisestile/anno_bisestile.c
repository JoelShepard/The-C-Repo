#include <stdio.h>

int main() {
    int anno;

    // Chiedere all'utente di inserire un anno
    printf("Inserisci un anno: ");
    
    // Leggere l'input dell'utente
    if (scanf("%d", &anno) != 1) {
        printf("Input non valido. Inserisci un numero intero.\n");
        return 1;
    }
    
    // Verifica se l'anno è positivo
    if (anno < 0) {
        printf("Per favore inserisci un anno positivo.\n");
        return 1;
    }

    // Verifica se l'anno è bisestile
    if ((anno % 4 == 0 && anno % 100 != 0) || (anno % 400 == 0)) {
        printf("%d è un anno bisestile.\n", anno);
    } else {
        printf("%d non è un anno bisestile.\n", anno);
    }

    return 0;
}