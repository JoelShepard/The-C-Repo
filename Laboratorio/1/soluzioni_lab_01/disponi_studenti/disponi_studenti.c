#include <stdio.h>

int main()
{

    int x, y, n;

    // richiedo i valori

    printf("\nDa quante file di postazioni è composta l'aula (max. 15)? ");
    scanf("%d", &x);

    printf("\nCiascuna fila da quante postazioni è composta (max. 20)? ");
    scanf("%d", &y);

    printf("\nQuanti studenti partecipano al corso? ");
    scanf("%d", &n);

    // verifico la correttezza dei valori

    if (x <= 0 || y <= 0 || n <= 0 || x > 15 || y > 20)
    {
        printf("\nErrore: hai inserito dei parametri non validi. Controlla ed esegui di nuovo il programma.");
        return 0;
    }

    // verifico che tutti gli studenti possano accomodarsi in aula

    // date x file, quante possono essere occupate? Provo a trovare una formula:
    // se x = 1, allora 1 - x/3 = 0, x%3 = 1
    // se x = 2, allora 2 - x/3 = 0, x%3 = 2
    // se x = 3, allora 2 - x/3 = 1, x%3 = 0
    // se x = 4, allora 3 - x/3 = 1, x%3 = 1
    // se x = 5, allora 4 - x/3 = 1, x%3 = 2
    // se x = 6, allora 4 - x/3 = 2, x%3 = 0
    // e così via.
    // Il numero di file occupabili sarà x - x / 3.
    // Le file completamente vuote saranno quelle con x % 3 == 0.

    int file_occupabili = 0;
    file_occupabili = x - x / 3;

    // quanti posti sono disponibili?

    int posti_disponibili = 0;
    posti_disponibili = file_occupabili * y;

    // ci stanno tutti gli studenti?

    if (n > posti_disponibili)
    {
        printf("\nErrore: non ci sono abbastanza posti per tutti gli studenti (%d posti per %d studenti).", posti_disponibili, n);
        return 0;
    }

    // stampo la pianta dell'aula a partire dalla prima fila

    int i = 1, posti_occupati = 0;
    while (i <= x)
    {

        // questo ciclo scorre le file

        int j = 0;
        printf("\n");

        while (j < y)
        {

            // questo ciclo scorre le postazioni della singola fila

            // una postazione è vuota se (basta una delle condizioni):
            // - la fila i di cui fa parte è tale per cui i % 3 == 0
            // - non ci sono più studenti da fare accomodare

            if (i % 3 == 0 || posti_occupati == n)
            {
                printf("0");
            }
            else
            {
                printf("X");
                posti_occupati++; // tengo conto di quanti posti ho occupato
            }

            j++;
        }

        i++;
    }

    printf("\n");

    return 0;
}