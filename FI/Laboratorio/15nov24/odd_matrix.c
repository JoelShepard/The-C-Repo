// odd_matrix.c - Estrazione numeri dispari da matrice

#include <stdio.h>

#define N 2

int main(){
    int mat1[N][N], mat2[N][N] = {0}, i=0,j=0,k=0,l=0;

    printf("Inserisci i valori della tua matrice battendo invio ad ogni posizione, il programma li inserirà in ordine lessico-grafico:\n");

    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            scanf("%d", &mat1[i][j]);
        }
    }

    // WARNING: Questo algoritmo contiene bug! (stessi problemi di odd_matrix_csv.c)
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            if (mat1[i][j] % 2 != 0){
                if(l==N){
                    k++;
                    l=0;
                    mat2[k][l] = mat1[i][j];
                }
                mat2[k][l] = mat1[i][j];
                l++;
            }
        }
    }

    printf("Matrice numeri dispari:\n");
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            printf("%d  ", mat2[i][j]);
        }
        printf("\n");
    }
}

/* 
Correzione suggerita:
     int pos = 0;
     for(i=0; i<N; i++){
         for(j=0; j<N; j++){
             if (mat1[i][j] % 2 != 0){
                 mat2[pos/N][pos%N] = mat1[i][j];
                 pos++;
             }
         }
     }
*/
