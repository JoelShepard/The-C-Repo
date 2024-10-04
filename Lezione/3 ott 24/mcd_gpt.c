#include <stdio.h>

int main() {
    int num1, num2, mcd = 1, i = 1;

        // Chiedere all'utente di inserire due numeri
            printf("Inserire il primo numero: ");
                scanf("%d", &num1);
                    printf("Inserire il secondo numero: ");
                        scanf("%d", &num2);

                            // Ricerca del massimo comune divisore 
                                // senza usare cicli for
                                    while (i <= num1 && i <= num2) {
                                            if (num1 % i == 0 && num2 % i == 0) {
                                                        mcd = i; // Aggiorna il MCD se i è un divisore comune
                                                                }
                                                                        i++; // Incrementa i
                                                                            }

                                                                                // Visualizzare il risultato
                                                                                    printf("Il massimo comune divisore è: %d\n", mcd);

                                                                                        return 0;
                                                                                        }