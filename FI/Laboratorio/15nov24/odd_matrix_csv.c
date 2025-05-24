/*
 * =============================================================================
 * ELABORAZIONE MATRICE DA FILE CSV - ESTRAZIONE NUMERI DISPARI
 * =============================================================================
 * 
 * Descrizione:
 * Questo programma legge una matrice 3x3 da un file CSV, estrae tutti i numeri
 * dispari e li riorganizza in una nuova matrice che viene poi salvata in un
 * nuovo file CSV.
 * 
 * Autore: Studente FI
 * Data: 15 novembre 2024
 * Corso: Fondamenti di Informatica
 * 
 * Funzionalità:
 * - Lettura matrice da file CSV con formato "numero,numero,numero"
 * - Identificazione e estrazione numeri dispari
 * - Riorganizzazione in nuova matrice
 * - Salvataggio risultato in nuovo file CSV
 * 
 * Note tecniche:
 * - Il programma ha un bug nella logica di riempimento della matrice dispari
 * - La stampa dice "numeri pari" ma mostra tutta la matrice originale
 * - L'algoritmo di riempimento può causare overflow di indici
 * 
 * =============================================================================
 */

#include <stdio.h>
#define N 3  // Dimensione della matrice quadrata

/*
 * Funzione principale del programma
 * Gestisce la lettura, elaborazione e salvataggio delle matrici
 */
int main(){
    FILE *mycsv, *oddcsv;  // Puntatori ai file di input e output
    int mat1[N][N], mat2[N][N] = {0}, i=0,j=0,k=0,l=0;  // Matrici e variabili di controllo

    // ===========================================
    // SEZIONE 1: LETTURA MATRICE DA FILE CSV
    // ===========================================
    
    mycsv = fopen("matrice.txt", "r");  // Apertura file in modalità lettura

    // Controllo errori apertura file
    if(mycsv == NULL){
        printf("Il file non è stato aperto correttamente."); return 0;
    }

    // Lettura matrice dal file CSV
    // Formato atteso: numero,numero,numero per ogni riga
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            if(fscanf(mycsv, "%d,", &mat1[i][j]) != 1) {
                printf("Errore nel formato del file CSV\n");
                return 0;
            }
        }
    }

    fclose(mycsv);  // Chiusura file di input

    // =====================================================
    // SEZIONE 2: ESTRAZIONE E RIORGANIZZAZIONE DISPARI
    // =====================================================
    
    // ATTENZIONE: Questo algoritmo ha diversi bug!
    // - La logica di incremento di k e l non è corretta
    // - Può causare accesso fuori dai limiti dell'array
    // - L'assegnazione viene fatta due volte
    
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            // Controllo se il numero è dispari
            if (mat1[i][j] % 2 != 0){
                // BUG: logica di riempimento errata
                if(l==N){
                    k++;
                    l=0;
                    mat2[k][l] = mat1[i][j];  // Prima assegnazione
                }
                mat2[k][l] = mat1[i][j];  // Seconda assegnazione (ridondante)
                l++;
            }
        }
    }

    // =======================================
    // SEZIONE 3: VISUALIZZAZIONE RISULTATI
    // =======================================
    
    // ERRORE: dice "numeri pari" ma mostra tutta la matrice
    printf("Matrice numeri pari:\n");
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
        printf("%d  ", mat1[i][j]);
        }
        printf("\n");
    }

    printf("Matrice numeri dispari:\n");
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
        printf("%d  ", mat2[i][j]);
        }
        printf("\n");
    }

    // =======================================
    // SEZIONE 4: SALVATAGGIO SU FILE CSV
    // =======================================
    
    oddcsv = fopen("matrice_dispari.txt", "w");  // Apertura file output
    
    // Controllo errori apertura file
    if(oddcsv == NULL){
        printf("Il file  non è stato aperto correttamente."); return 0;
    }

    // Salvataggio matrice dispari in formato CSV
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            fprintf(oddcsv, "%d,", mat2[i][j]);  // Scrittura con separatore virgola
        }
        fprintf(oddcsv, "\n");  // Nuova riga per ogni riga della matrice
    }
    fclose(oddcsv);  // Chiusura file output

    return 0;  // Terminazione normale del programma
}
