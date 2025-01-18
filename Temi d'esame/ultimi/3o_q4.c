#include <stdio.h>
#define ROW 3
#define COL 4

int advanced(int mat[][COL], int row_elem, int col_elem){
    int k=0, l=0, state=0;

    for (int j=0; j<col_elem-1; j++) {
        for (int i=0; i<row_elem; i++) {
            if (mat[j][i]>mat[j][l]) {
                l=i;
            }
        }
        for (int i=0; i<row_elem; i++) {
            if (mat[j+1][i]>mat[j+1][k]) {
                k=i;
            }
        }
        if(l<k){
            state=1;
        } else {
            state=0;
        }
    }
    return state;
}

int main(){
    int mat[ROW][COL]= {
        {100, 40, 1, 2},
        {2, 1760, 70, 5},
        {5, 5, 2560, 40},
    };

    if (advanced(mat, COL, ROW)) {
        printf("La matrice rispetta i parametri indicati\n");
    }else {
        printf("La matrice non rispetta i parametri indicati\n");
    }
}
