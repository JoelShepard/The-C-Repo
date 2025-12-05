/* disponi_studenti.c - C source file. */

#include <stdio.h>  // Per printf, scanf

/* *
================================================================
FUNZIONE PRINCIPALE - GESTIONE DISPOSIZIONE AULA
================================================================
 */
int main()
{
    // Variabili per le dimensioni dell'aula e numero studenti
    int x, y, n;  // x = file, y = postazioni per fila, n = studenti

    // FASE 1: ACQUISIZIONE PARAMETRI AULA
    printf("\nDa quante file di postazioni è composta l'aula (max. 15)? ");
    scanf("%d", &x);

    printf("\nCiascuna fila da quante postazioni è composta (max. 20)? ");
    scanf("%d", &y);

    printf("\nQuanti studenti partecipano al corso? ");
    scanf("%d", &n);

    // FASE 2: VALIDAZIONE DEI PARAMETRI
    if (x <= 0 || y <= 0 || n <= 0 || x > 15 || y > 20)
    {
        printf("\nErrore: hai inserito dei parametri non validi. Controlla ed esegui di nuovo il programma.");
        return 0;
    }

    
    // FASE 3: CALCOLO CAPIENZA CON REGOLA DISTANZIAMENTO
    
    // Analisi del pattern di distanziamento:
    // File utilizzabili seguono il pattern: occupata, occupata, VUOTA, ripeti...
    // Formula matematica derivata dall'analisi:
    // - x = 1,2: 1,2 file occupabili
    // - x = 3,4,5: 2,3,4 file occupabili  
    // - x = 6,7,8: 4,5,6 file occupabili
    // Regola generale: file_occupabili = x - x/3
    
    int file_occupabili = 0;
    file_occupabili = x - x / 3;  // Ogni gruppo di 3 file, 1 rimane vuota

    // Calcolo posti totali disponibili
    int posti_disponibili = 0;
    posti_disponibili = file_occupabili * y;

    // FASE 4: VERIFICA CAPIENZA SUFFICIENTE
    if (n > posti_disponibili)
    {
        printf("\nErrore: non ci sono abbastanza posti per tutti gli studenti (%d posti per %d studenti).", posti_disponibili, n);
        return 0;
    }

    
    // FASE 5: GENERAZIONE MAPPA VISIVA DELL'AULA
    
    int i = 1, posti_occupati = 0;  // Contatori per file e studenti posizionati
    
    while (i <= x)  // Ciclo attraverso tutte le file
    {
        int j = 0;      // Contatore per postazioni nella fila corrente
        printf("\n");   // Nuova row per ogni fila
        
        while (j < y)   // Ciclo attraverso tutte le postazioni della fila
        {

            // Una postazione è VUOTA (0) se:
            // 1. La fila è di distanziamento: i % 3 == 0 (ogni terza fila)
            // 2. Tutti gli studenti sono già stati posizionati
            //
            // Una postazione è OCCUPATA (X) se:
            // 1. La fila non è di distanziamento: i % 3 != 0
            // 2. Ci sono ancora studenti da posizionare
            
            if (i % 3 == 0 || posti_occupati == n)
            {
                printf("0");
            }
            else
            {
                printf("X");
                posti_occupati++;
            }

            j++;  // Passa alla postazione successiva
        }

        i++;  // Passa alla fila successiva
    }

    printf("\n");  // Riga finale per formattazione

    return 0;
}
