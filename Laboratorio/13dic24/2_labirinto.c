#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int count_check(FILE* file){
    rewind(file);
    int count=0;
    char c;
    while ((c = getc(file)) != EOF) {
        if (c == '1'){
            count++;
        } if (c =='0') {
            count++;
        } if (c == ',') {
            continue;
        } if (c == '\n') {
            continue;
        } if (c != '1' && c != '0' && c != '\n' && c != ',') {
            return -1;
        }
    }
    return count;
}

int** matrix(FILE* lab){
    int elems = count_check(lab);
    int rows = sqrt(count_check(lab));
    rewind(lab);
    //creazione dell'array dinamico
    int** matrix = (int**)malloc(sizeof(int*)*rows);
    if (matrix == NULL) {
        printf("Errore di allocazione dell'array dinamico.\n");
        return NULL;
    }
    for (int i=0; i<rows; i++) {
        matrix[i] = (int*)malloc(sizeof(int)*rows);
        if (matrix[i] == NULL) {
            printf("Errore di allocazione dell'array dinamico.\n");
            for(int j=0; j<i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }
    }
    //inserimento degli elementi
    for (int i=0; i<rows; i++) {
        for (int j=0; j<rows; j++) {
            fscanf(lab, "%d,", &matrix[i][j]);
        }
    }

    return matrix;
}



int main(){
    FILE* lab;

    lab = fopen("labirinto.csv", "r");
    if (lab == NULL) {
        printf("Apertura di labirinto.csv non riuscita.\n");
        return -1;
    }

    if (count_check(lab) == -1) {
        printf("Errore. Il file inserito contiene caratteri non validi.\n");
        return -1;
    }

    //square check
    int n = count_check(lab);
    int row = sqrt(n);
    if (sqrt(count_check(lab)) != (int)sqrt(count_check(lab))) {
        printf("Errore. La matrice non è quadrata.\n");
        return -1;
    }
    int** res = matrix(lab);

    printf("%d", solve(res, 0, 0, n));
}
