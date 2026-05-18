// exam_scores.c - Registrazione esiti d'esame su file binario

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
    int i = 0;
    exam allexams[N];

    printf("=== SISTEMA REGISTRAZIONE ESITI D'ESAME ===\n");
    printf("Inserimento dati per %d candidati\n\n", N);

    mydb = fopen("esiti.bin", "w");
    if(mydb == NULL){
        printf("ERRORE: Il file non è stato aperto correttamente.\n");
        printf("Verificare i permessi di scrittura nella directory corrente.\n");
        return 1;
    }

    while (i < N){
        printf("--- CANDIDATO %d di %d ---\n", i+1, N);
        
        printf("Inserisci il cognome del candidato %d: ", i+1);
        scanf("%s", allexams[i].name);
        fprintf(mydb, "%s,", allexams[i].name);

        printf("Inserisci il numero di matricola del candidato %d: ", i+1);
        scanf("%d", &allexams[i].code);
        fprintf(mydb, "%d,", allexams[i].code);

        printf("Inserisci il voto del candidato %d (0-30): ", i+1);
        scanf("%d", &allexams[i].score);
        fprintf(mydb, "%d", allexams[i].score);

        fprintf(mydb, "\n");
        
        printf("✓ Dati salvati: %s (Matr: %d) - Voto: %d\n\n", 
               allexams[i].name, allexams[i].code, allexams[i].score);
        
        i++;
    }
    
    fclose(mydb);
    
    printf("=== REGISTRAZIONE COMPLETATA ===\n");
    printf("Tutti i %d esiti sono stati salvati nel file 'esiti.bin'\n", N);
    printf("Formato: cognome,matricola,voto\n");
    
    return 0;
}
