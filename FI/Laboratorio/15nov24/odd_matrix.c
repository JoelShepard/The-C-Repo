/*
 * =============================================================================
 * ESTRAZIONE NUMERI DISPARI DA MATRICE - VERSIONE SEMPLIFICATA
 * =============================================================================
 * 
 * Descrizione:
 * Programma che legge una matrice 2x2 dall'utente, estrae tutti i numeri
 * dispari e li riorganizza in una nuova matrice seguendo l'ordine di 
 * lettura lessicografico.
 * 
 * Autore: Studente FI
 * Data: 15 novembre 2024
 * Corso: Fondamenti di Informatica - Laboratorio
 * 
 * Funzionalità:
 * - Input interattivo matrice 2x2
 * - Identificazione numeri dispari
 * - Riorganizzazione in nuova matrice
 * - Visualizzazione risultato
 * 
 * Note tecniche:
 * - Versione semplificata del programma odd_matrix_csv.c
 * - Presenta gli stessi bug nell'algoritmo di riempimento
 * - L'ordine lessicografico significa: riga per riga, da sinistra a destra
 * 
 * Problemi identificati:
 * - Doppia assegnazione nella logica di riempimento
 * - Possibile overflow degli indici k e l
 * - Logica di reset della posizione l non corretta
 * 
 * =============================================================================
 */

#include <stdio.h>
#define N 2  // Dimensione matrice (2x2 per semplicità)

/*
 * Funzione principale per la gestione delle matrici
 * e l'estrazione dei numeri dispari
 */
int main(){
    int mat1[N][N], mat2[N][N] = {0}, i=0,j=0,k=0,l=0;  // Matrici e indici
    
    // ===============================================
    // SEZIONE 1: INPUT MATRICE DALL'UTENTE
    // ===============================================
    
    printf("Inserisci i valori della tua matrice battendo invio ad ogni posizione, il programma li inserirà in ordine lessico-grafico:\n");
    
    // Lettura matrice in ordine lessicografico (riga per riga)
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
        scanf("%d", &mat1[i][j]);  // Input elemento [i][j]
        }
    }

    // Lettura matrice in ordine lessicografico (riga per riga)
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
        scanf("%d", &mat1[i][j]);  // Input elemento [i][j]
        }
    }

    // =====================================================
    // SEZIONE 2: ESTRAZIONE E RIORGANIZZAZIONE DISPARI
    // =====================================================
    
    // ATTENZIONE: Questo algoritmo contiene bug!
    // Stessi problemi del file odd_matrix_csv.c
    
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            // Controllo se il numero è dispari
            if (mat1[i][j] % 2 != 0){
                // BUG: logica di gestione indici errata
                if(l==N){
                    k++;     // Passa alla riga successiva
                    l=0;     // Reset colonna
                    mat2[k][l] = mat1[i][j];  // Prima assegnazione
                }
                mat2[k][l] = mat1[i][j];  // Seconda assegnazione (sovrascrive la prima)
                l++;     // Incrementa posizione colonna
            }
        }
    }

    // ===============================================
    // SEZIONE 3: VISUALIZZAZIONE RISULTATO
    // ===============================================
    
    printf("Matrice numeri dispari:\n");
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
        printf("%d  ", mat2[i][j]);  // Stampa elemento [i][j]
        }
        printf("\n");  // Nuova riga per ogni riga della matrice
    }
    
    /*
     * CORREZIONE SUGGERITA:
     * 
     * int pos = 0;  // Posizione lineare
     * for(i=0; i<N; i++){
     *     for(j=0; j<N; j++){
     *         if (mat1[i][j] % 2 != 0){
     *             mat2[pos/N][pos%N] = mat1[i][j];
     *             pos++;
     *         }
     *     }
     * }
     * 
     * Questo approccio evita i bug nell'indicizzazione.
     */
}
