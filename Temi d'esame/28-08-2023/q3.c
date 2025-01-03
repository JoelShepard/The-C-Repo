#include <stdio.h>

#define MOSSE 20
#define N 3
#define M 3

typedef struct {
    int x;
    int y;
}Coo;

Coo mosse[MOSSE];
int mylab[N][M];


int solve(int mylab[][], Coo mosse[]){
    Coo tmp;
    tmp.x=0;
    tmp.y=0;

    for (int k=0; k<MOSSE; k++) {
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

    // Create a path
    mylab[0][0] = 0;
    mylab[0][1] = 1;
    mylab[0][2] = 1;
    mylab[1][0] = 0;
    mylab[1][1] = 1;
    mylab[1][2] = 1;
    mylab[2][0] = 0;
    mylab[2][1] = 0;
    mylab[2][2] = 0;


    // Set specific moves to follow the path
    mosse[0].y = 1;  // Right
    mosse[1].y = 1;  // Right
    mosse[2].x = 1; // Down
    mosse[3].x = 1;  // Down
    mosse[4].y = 1;  // Right

    ris = solve(mylab, mosse);
    printf("Result: %d\n", ris);
}

//Complicatuccio
