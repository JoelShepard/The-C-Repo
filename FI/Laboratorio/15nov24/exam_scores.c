/* exam_scores.c - C source file. */

#include <stdio.h>
#include <string.h>

#define NLEN 14                           // Lunghezza massima per il cognome
#define N 5                               // Numero di candidati da registrare

/* *
Struttura per rappresentare il risultato di un esame
 */
typedef struct {
    char name[NLEN];                      // Cognome del candidato
    int code;                             // Numero di matricola universitaria
    int score;                            // Voto dell'esame (0-30)
} exam;

/* *
Function principale per la registrazione degli esiti d'esame

Il programma acquisisce i dati di N candidati e li salva in un file CSV
con formato: cognome,matricola,voto
 */
int main(){
    FILE * mydb;                          // Puntatore al file di database
    int i = 0;                            // Contatore per il ciclo di input
    exam allexams[N];                     // Array per memorizzare tutti gli esami

    // INTESTAZIONE: benvenuto all'utente
    printf("=== SISTEMA REGISTRAZIONE ESITI D'ESAME ===\n");
    printf("Inserimento dati per %d candidati\n\n", N);

    // APERTURA FILE: creazione del file di output in modalità scrittura
    mydb = fopen("esiti.bin", "w");
    if(mydb == NULL){
        printf("ERRORE: Il file non è stato aperto correttamente.\n");
        printf("Verificare i permessi di scrittura nella directory corrente.\n");
        return 1;
    }

    // CICLO ACQUISIZIONE: raccolta dati per ogni candidato
    while (i < N){
        printf("--- CANDIDATO %d di %d ---\n", i+1, N);
        
        // INPUT COGNOME: acquisizione e scrittura su file
        printf("Inserisci il cognome del candidato %d: ", i+1);
        scanf("%s", allexams[i].name);
        fprintf(mydb, "%s,", allexams[i].name);

        // INPUT MATRICOLA: acquisizione e scrittura su file
        printf("Inserisci il numero di matricola del candidato %d: ", i+1);
        scanf("%d", &allexams[i].code);
        fprintf(mydb, "%d,", allexams[i].code);

        // INPUT VOTO: acquisizione e scrittura su file
        printf("Inserisci il voto del candidato %d (0-30): ", i+1);
        scanf("%d", &allexams[i].score);
        fprintf(mydb, "%d", allexams[i].score);     // Ultimo campo senza virgola

        // FINE RIGA: newline per separare i record
        fprintf(mydb, "\n");
        
        // CONFERMA: feedback per l'utente
        printf("✓ Dati salvati: %s (Matr: %d) - Voto: %d\n\n", 
               allexams[i].name, allexams[i].code, allexams[i].score);
        
        i++;                              // Incrementa il counter
    }
    
    // CHIUSURA FILE: finalizzazione del salvataggio
    fclose(mydb);
    
    // MESSAGGIO FINALE: conferma completamento
    printf("=== REGISTRAZIONE COMPLETATA ===\n");
    printf("Tutti i %d esiti sono stati salvati nel file 'esiti.bin'\n", N);
    printf("Formato: cognome,matricola,voto\n");
    
    return 0;
}
