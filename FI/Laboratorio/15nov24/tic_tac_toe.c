/* tic_tac_toe.c - C source file. */

#include <stdio.h>

/* 
Struttura per rappresentare coordinate bidimensionali
Utilizzata per memorizzare le mosse dei giocatori
 */
typedef struct{
    int x;  // Coordinata x (row)
    int y;  // Coordinata y (column)
} Coord;

/* 
Function principale che gestisce il ciclo di gioco
e l'interfaccia utente del tris
 */
int main(){
    int game[3][3] = {0}, i, j, cmd;  // Griglia gioco + variabili controllo
    Coord user1, user2;               // Coordinate per i due giocatori

    int game[3][3] = {0}, i, j, cmd;  // Griglia gioco + variabili controllo
    Coord user1, user2;               // Coordinate per i due giocatori

    // ===============================================
    // CICLO PRINCIPALE DI GIOCO
    // ===============================================
    
    while(1){
        // Menu principale con opzioni disponibili
        printf("inserisci il comando\n 1 - mossa primo utente\n 2 - mossa secondo utente\n 3 - esci dal gioco\n:");
        scanf("%d", &cmd);

        // Gestione uscita dal gioco
        if(cmd == 3){
            printf("Bye bye\n");
            return 0;
        }
        
        // ===============================================
        // GESTIONE MOSSA GIOCATORE 1 (X)
        // ===============================================
        
        if(cmd == 1){
            printf("Fai la tua mossa (inserisci le coordinate in questo formato: x y): ");
            scanf("%d %d", &user1.x, &user1.y);
            
            // Validazione mossa: controllo se casella è libera
            if(game[user1.x-1][user1.y-1] == 0){
                game[user1.x-1][user1.y-1] = 1;  // Marca casella per giocatore 1
            }else{
                printf("MOSSA NON VALIDA\n");
                continue;  // Richiedi nuova mossa
            }
            
            // Visualizzazione griglia aggiornata
            for(i=0; i<3; i++){
                for(j=0; j<3; j++){
                    if(game[i][j] == 1){
                        printf("%c  ", 'X');  // Giocatore 1
                    }
                    if(game[i][j] == 2){
                        printf("%c  ", 'O');  // Giocatore 2
                    }
                    if(game[i][j] == 0){
                        printf("%c  ", '0');  // Casella vuota
                    }
                }
                printf("\n");
            }
        }
        
        // ===============================================
        // GESTIONE MOSSA GIOCATORE 2 (O)
        // ===============================================
        
        if(cmd == 2){
            printf("Fai la tua mossa (inserisci le coordinate in questo formato: x y): ");
            scanf("%d %d", &user2.x, &user2.y);
            
            // Validazione mossa: controllo se casella è libera
            if(game[user2.x-1][user2.y-1] == 0){
                game[user2.x-1][user2.y-1] = 2;  // Marca casella per giocatore 2
            }else{
                printf("MOSSA NON VALIDA\n");
                                printf("MOSSA NON VALIDA\n");
                continue;  // Richiedi nuova mossa
            }
            
            // Visualizzazione griglia aggiornata (codice duplicato - da ottimizzare)
            for(i=0; i<3; i++){
                for(j=0; j<3; j++){
                    if(game[i][j] == 1){
                        printf("%c  ", 'X');  // Giocatore 1
                    }
                    if(game[i][j] == 2){
                        printf("%c  ", 'O');  // Giocatore 2
                    }
                    if(game[i][j] == 0){
                        printf("%c  ", '0');  // Casella vuota
                    }
                }
                printf("\n");
            }
        }
        
        // ===============================================
        // CONTROLLO CONDIZIONI DI VITTORIA
        // ===============================================
        
        // CONTROLLO RIGHE: verifica se una row è completamente occupata da un giocatore
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
        
        // CONTROLLO COLONNE: verifica se una column è completamente occupata da un giocatore
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
        
        // CONTROLLO DIAGONALE PRINCIPALE: da top-left a bottom-right
        if(game[0][0] == game[1][1] && game[1][1] == game[2][2]) {
            if(game[0][0] == 1) {
                printf("Il giocatore 1 ha vinto!\n");
                return 0;
            } else if(game[0][0] == 2) {
                printf("Il giocatore 2 ha vinto!\n");
                return 0;
            }
        }
        
        // CONTROLLO DIAGONALE SECONDARIA: da top-right a bottom-left
        if(game[0][2] == game[1][1] && game[1][1] == game[2][0]) {
            if(game[0][2] == 1) {
                printf("Il giocatore 1 ha vinto!\n");
                return 0;
            } else if(game[0][2] == 2) {
                printf("Il giocatore 2 ha vinto!\n");
                return 0;
            }
        }
        
/* 
NOTE DI MIGLIORAMENTO:
1. Aggiungere controllo pareggio (tutte caselle occupate, nessun vincitore)
2. Creare funzione separata per visualizzazione griglia (evitare duplicazione)
3. Aggiungere validazione input (coordinate fuori range)
4. Creare funzioni separate per controllo vittoria
 */
    }  // Fine ciclo while(1)
}
