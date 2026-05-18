// disponi_studenti.c - Disposizione aula con distanziamento

#include <stdio.h>

int main()
{
    int x, y, n;

    printf("\nDa quante file di postazioni è composta l'aula (max. 15)? ");
    scanf("%d", &x);

    printf("\nCiascuna fila da quante postazioni è composta (max. 20)? ");
    scanf("%d", &y);

    printf("\nQuanti studenti partecipano al corso? ");
    scanf("%d", &n);

    if (x <= 0 || y <= 0 || n <= 0 || x > 15 || y > 20)
    {
        printf("\nErrore: hai inserito dei parametri non validi. Controlla ed esegui di nuovo il programma.");
        return 0;
    }

    // Ogni 3 file, 1 rimane vuota per distanziamento
    int file_occupabili = x - x / 3;
    int posti_disponibili = file_occupabili * y;

    if (n > posti_disponibili)
    {
        printf("\nErrore: non ci sono abbastanza posti per tutti gli studenti (%d posti per %d studenti).", posti_disponibili, n);
        return 0;
    }
    
    int i = 1, posti_occupati = 0;
    
    while (i <= x)
    {
        int j = 0;
        printf("\n");
        
        while (j < y)
        {
            // Fila vuota ogni 3 file per distanziamento, oppure studenti finiti
            if (i % 3 == 0 || posti_occupati == n)
            {
                printf("0");
            }
            else
            {
                printf("X");
                posti_occupati++;
            }

            j++;
        }

        i++;
    }

    printf("\n");

    return 0;
}
