// mcd_gpt.c - MCD per ricerca esaustiva

#include <stdio.h>

int main() {
    int num1, num2;
    int mcd = 1;
    int i = 1;

    printf("Inserire il primo numero: ");
    scanf("%d", &num1);
    printf("Inserire il secondo numero: ");
    scanf("%d", &num2);
    
    if (num1 <= 0 || num2 <= 0) {
        printf("Errore: inserire solo numeri positivi\n");
        return 1;
    }

    while (i <= num1 && i <= num2) {
        if (num1 % i == 0 && num2 % i == 0) {
            mcd = i;
        }
        i++;
    }

    printf("Il massimo comune divisore di %d e %d è: %d\n", num1, num2, mcd);

    return 0;
}

// Nota: O(n) - l'algoritmo di Euclide sarebbe O(log(min(num1, num2)))
