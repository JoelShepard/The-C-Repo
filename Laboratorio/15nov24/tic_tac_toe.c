#include <stdio.h>

typedef struct{
    int x;
    int y;
} Coord;

int main(){
    int game[3][3] = {0}, i, j, cmd;
    Coord user1, user2;

    while(1){
        printf("inserisci il comando\n 1 - mossa primo utente\n 2 - mossa secondo utente\n 3 - esci dal gioco\n:");
        scanf("%d", &cmd);

        if(cmd == 3){
            printf("Bye bye\n");
            return 0;
        }
        if(cmd == 1){
            printf("Fai la tua mossa (inserisci le coordinate in questo formato: x y): ");
            scanf("%d %d", &user1.x, &user1.y);
            if(game[user1.x-1][user1.y-1] == 0){
                game[user1.x-1][user1.y-1] = 1;
            }else{
                printf("MOSSA NON VALIDA\n");
                continue;
            }
            for(i=0; i<3; i++){
                for(j=0; j<3; j++){
                    if(game[i][j] == 1){
                        printf("%c  ", 'X');
                    }
                    if(game[i][j] == 2){
                        printf("%c  ", 'O');
                    }
                    if(game[i][j] == 0){
                        printf("%c  ", '0');
                    }
                }
                printf("\n");
            }
        }
        if(cmd == 2){
            printf("Fai la tua mossa (inserisci le coordinate in questo formato: x y): ");
            scanf("%d %d", &user2.x, &user2.y);
            if(game[user2.x-1][user2.y-1] == 0){
                game[user2.x-1][user2.y-1] = 2;
            }else{
                printf("MOSSA NON VALIDA\n");
                continue;
            }
            for(i=0; i<3; i++){
                for(j=0; j<3; j++){
                    if(game[i][j] == 1){
                        printf("%c  ", 'X');
                    }
                    if(game[i][j] == 2){
                        printf("%c  ", 'O');
                    }
                    if(game[i][j] == 0){
                        printf("%c  ", '0');
                    }
                }
                printf("\n");
            }
        }
        // Check rows
        for(i = 0; i < 3; i++) {
            if(game[i][0] == game[i][1] && game[i][1] == game[i][2]) {
                if(game[i][0] == 1) {
                    printf("Il giocatore 1 ha vinto!\n");
                    return 0;
                } else if(game[i][0] == 2) {
                    printf("Il giocatore 2 ha vinto!\n");
                    return 0;
                }
            }
        }
        // Check columns
        for(j = 0; j < 3; j++) {
            if(game[0][j] == game[1][j] && game[1][j] == game[2][j]) {
                if(game[0][j] == 1) {
                    printf("Il giocatore 1 ha vinto!\n");
                    return 0;
                } else if(game[0][j] == 2) {
                    printf("Il giocatore 2 ha vinto!\n");
                    return 0;
                }
            }
        }
        // Check diagonals
        if(game[0][0] == game[1][1] && game[1][1] == game[2][2]) {
            if(game[0][0] == 1) {
                printf("Il giocatore 1 ha vinto!\n");
                return 0;
            } else if(game[0][0] == 2) {
                printf("Il giocatore 2 ha vinto!\n");
                return 0;
            }
        }
        if(game[0][2] == game[1][1] && game[1][1] == game[2][0]) {
            if(game[0][2] == 1) {
                printf("Il giocatore 1 ha vinto!\n");
                return 0;
            } else if(game[0][2] == 2) {
                printf("Il giocatore 2 ha vinto!\n");
                return 0;
            }
        }
    }
}
