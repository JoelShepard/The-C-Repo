/* odd_matrix.c - C source file. */
+/* odd_matrix.c - C source file. */



#include <stdio.h>

#define N 2  // Size matrix (2x2 per semplicità)



/* 

Function principale per la gestione delle matrixs

e l'estrazione dei numeri dispari

 */

int main(){

    int mat1[N][N], mat2[N][N] = {0}, i=0,j=0,k=0,l=0;  // Matrices and indices

    

    // ===============================================

    // SECTION 1: INPUT MATRICE DALL'UTENTE

    // ===============================================

    

    printf("Inserisci i valori della tua matrice battendo invio ad ogni posizione, il programma li inserirà in ordine lessico-grafico:\n");

    

    // Lettura matrix in lexicographic order (row per row)

    for(i=0; i<N; i++){

        for(j=0; j<N; j++){

        scanf("%d", &mat1[i][j]);  // Input elemento [i][j]

        }

    }



    // Lettura matrix in lexicographic order (row per row)

    for(i=0; i<N; i++){

        for(j=0; j<N; j++){

        scanf("%d", &mat1[i][j]);  // Input elemento [i][j]

        }

    }



    // =====================================================

    // SECTION 2: ESTRAZIONE E RIORGANIZZAZIONE DISPARI

    // =====================================================

    

    // WARNING: Questo algoritmo contiene bug!

    // Stessi problemi del file odd_matrix_csv.c

    

    for(i=0; i<N; i++){

        for(j=0; j<N; j++){

            // Controllo se il numero è dispari

            if (mat1[i][j] % 2 != 0){

                // BUG: logica di gestione indici errata

                if(l==N){

                    k++;     // Passa alla row successiva

                    l=0;     // Reset column

                    mat2[k][l] = mat1[i][j];  // Prima assegnazione

                }

                mat2[k][l] = mat1[i][j];  // Seconda assegnazione (sovrascrive la prima)

                l++;     // Incrementa posizione column

            }

        }

    }



    // ===============================================

    // SECTION 3: VISUALIZZAZIONE RISULTATO

    // ===============================================

    

    printf("Matrice numeri dispari:\n");

    for(i=0; i<N; i++){

        for(j=0; j<N; j++){

        printf("%d  ", mat2[i][j]);  // Prints elemento [i][j]

        }

        printf("\n");  // Nuova row per ogni row della matrix

    }

    

/* 

CORREZIONE SUGGERITA:



     * int pos = 0;  // Posizione lineare

for(i=0; i<N; i++){

for(j=0; j<N; j++){

if (mat1[i][j] % 2 != 0){

mat2[pos/N][pos%N] = mat1[i][j];

pos++;

}

}

}



Questo approccio evita i bug nell'indicizzazione.

 */

}

