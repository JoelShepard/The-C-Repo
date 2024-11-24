#include <stdio.h>
#define N 3

int main(){
    FILE *mycsv, *oddcsv;
    int mat1[N][N], mat2[N][N] = {0}, i=0,j=0,k=0,l=0;

    mycsv = fopen("matrice.txt", "r");

    if(mycsv == NULL){
        printf("Il file non è stato aperto correttamente."); return 0;
    }

    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            if(fscanf(mycsv, "%d,", &mat1[i][j]) != 1) {
                printf("Errore nel formato del file CSV\n");
                return 0;
            }
        }
    }

    fclose(mycsv);


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

    oddcsv = fopen("matrice_dispari.txt", "w");
    if(oddcsv == NULL){
        printf("Il file  non è stato aperto correttamente."); return 0;
    }

    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            fprintf(oddcsv, "%d,", mat2[i][j]);
        }
        fprintf(oddcsv, "\n");
    }
    fclose(oddcsv);

    return 0;
}
