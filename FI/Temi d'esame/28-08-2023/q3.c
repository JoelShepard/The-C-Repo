// q3.c - Navigazione labirinto

#include <stdio.h>

#define MOSSE 20
#define N 3
#define M 3

typedef struct {
    int x;
    int y;
} Coo;

Coo mosse[MOSSE];
int mylab[N][M];

int solve(int mylab[N][M], Coo mosse[]){
    Coo tmp;
    tmp.x = 0;
    tmp.y = 0;

    for (int k = 0; k < MOSSE; k++) {
        
        if (mosse[k].x == 0) {
            if (mylab[tmp.x][tmp.y + mosse[k].y] != 0) {
                return -1;
            }
            tmp.y = tmp.y + mosse[k].y;
        }
        
        if (mosse[k].y == 0) {
            if (mylab[tmp.x + mosse[k].x][tmp.y] != 0) {
                return -1;
            }
            tmp.x = tmp.x + mosse[k].x;
        }
    }
    
    return 1;
}

int main(){
    int i, j, ris;
    int mylab[N][M];

    mylab[0][0] = 0;
    mylab[0][1] = 1;
    mylab[0][2] = 1;
    mylab[1][0] = 0;
    mylab[1][1] = 1;
    mylab[1][2] = 1;
    mylab[2][0] = 0;
    mylab[2][1] = 0;
    mylab[2][2] = 0;

    printf("=== LABIRINTO 3x3 ===\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            printf("[%d]", mylab[i][j]);
        }
        printf("\n");
    }
    printf("0 = libero, 1 = ostacolo\n\n");

    for (int k = 0; k < MOSSE; k++) {
        mosse[k].x = 0;
        mosse[k].y = 0;
    }
    
    mosse[0].y = 1;
    mosse[1].y = 1;
    mosse[2].x = 1;
    mosse[3].x = 1;
    mosse[4].y = 1;

    printf("=== SEQUENZA MOSSE ===\n");
    for (int k = 0; k < 5; k++) {
        if (mosse[k].x != 0 || mosse[k].y != 0) {
            printf("Mossa %d: x=%d, y=%d\n", k, mosse[k].x, mosse[k].y);
        }
    }
    printf("\n");

    ris = solve(mylab, mosse);
    
    printf("=== RISULTATO ===\n");
    if (ris == 1) {
        printf("OK Percorso valido: %d\n", ris);
    } else {
        printf("X Percorso non valido (ostacolo incontrato): %d\n", ris);
    }
    
    return 0;
}

/* 
Note tecniche e problemi del codice:

1. int mylab[][] non è valido in C in una dichiarazione di parametro di funzione;
   dovrebbe essere int mylab[N][M] o int (*mylab)[M] (corretto nel parametro della solve sopra).

2. Mancano controlli sui limiti della matrice: se le coordinate escono dai bordi,
   si può causare segmentation fault.

3. Se una mossa ha sia x che y diversi da 0, viene ignorata (non sono ammessi
   movimenti diagonali).

4. La prima mossa del test va subito su un ostacolo, quindi il percorso fallisce
   immediatamente.
*/
