#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#define MOSSE 10

void game();
void ui_refresh_input(int user[], char* display);
int compare_same(int* usernum, int* gamenum);
int compare_not_there(int* usernum, int game[]);
void compare(int user[], int game[], char* display);
void generator(int* genseq);
int validation (int number);


int main(){
    int cmd;
    printf("Benvenuto in Mastermind. Seleziona uno dei comandi:\n 1 - Inizia la partita\n 2 - Esci dal gioco\n:");
    scanf("%d", &cmd);

    if (cmd == 2) {
        return 0;
    } if (cmd == 1) {
        game();
    } else {
        printf("Comando non valido");
    }
    return 0;
}

void ui_refresh_input(int user[], char* display){
    if (display[4] == '\0') {
        for (int i=0; i<4; i++) {
            printf("%c ", display[i]);
        }
    }
    printf("\nFai la tua mossa\n:");
    scanf("%d %d %d %d", &user[0], &user[1], &user[2], &user[3]);
}

int compare_same(int* usernum, int* gamenum){
    if (*usernum == *gamenum) {
        return 1;
    } else {
        return 0;
    }
}

int compare_not_there(int* usernum, int game[]){
    for (int i=0; i<4; i++) {
        if (*usernum == game[i]) {
            return 1;
        }
    }
    return 0;
}


void compare(int user[], int game[], char* display){
    for (int i=0; i<4; i++) {
        if (compare_same(&user[i], &game[i]) == 1){
            display[i] = '0';
        } else if (compare_not_there(&user[i], game) == 1 && compare_same(&user[i], &game[i]) == 0) {
            display[i] = '+';
        } else if (compare_not_there(&user[i], game) == 0) {
            display[i] = '-';
        }
    }
    display[4] = '\0';
}

void generator(int* genseq){
    srand(time(NULL));
    for (int i=0; i<4; i++) {
        *(genseq+i) = rand() % 10;
    }
}

int validation (int number){
    if (number<0 || number>9) {
        return 1;
    }
    return 0;
}

void game(){
    int myseq[4]={0};
    int gamerseq[4], win=0, invalid=0, mosse=MOSSE;
    char display[5]={0};

    generator(myseq);

    while(1 && win!=1 && mosse !=0 && invalid !=1){
        ui_refresh_input(gamerseq, display);
        for (int i=0; i<4; i++) {
            if (validation(gamerseq[i]) == 1) {
                invalid = 1;
            }
        }
        if (invalid ==1){
            printf("Sequenza inserita non valida\n");
        }
        compare(gamerseq, myseq, display);
        if (strcmp(display, "0000") == 0) {
            printf("You win !!!\n");
            win = 1;
        }
        mosse--;
        if (mosse == 0) {
            printf("Hai esaurito le mosse a disposizione\n");
            printf("La sequenza corretta era: %d %d %d %d\n", myseq[0], myseq[1], myseq[2], myseq[3]);
        }
    }
}
