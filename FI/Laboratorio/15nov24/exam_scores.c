#include <stdio.h>
#include <string.h>

#define NLEN 14
#define N 5

typedef struct {
    char name[NLEN];
    int code;
    int score;
} exam;

int main(){
    FILE * mydb;
    int i=0, lastchar=0;
    exam allexams[N];

    printf("Benvenuto!\n");

    mydb = fopen("esiti.bin", "w");
    if(mydb == NULL){
        printf("Il file non è stato aperto correttamente."); return 0;
    }

    while (i<N){
        //name input
        printf("Inserisci il cognome del candidato %d: ", i+1);
        scanf("%s", allexams[i].name);
        fprintf(mydb, "%s,", allexams[i].name);

        //code input
        printf("Inserisci il numero di matricola del candidato %d: ", i+1);
        scanf("%d", &allexams[i].code);
        fprintf(mydb, "%d,", allexams[i].code);

        //score input
        printf("Inserisci il voto del candidato %d: ", i+1);
        scanf("%d", &allexams[i].score);
        fprintf(mydb, "%d,", allexams[i].score);

        //newline + increase
        fprintf(mydb, "\n");
        i++;
    }
    fclose(mydb);
    return 0;
}
