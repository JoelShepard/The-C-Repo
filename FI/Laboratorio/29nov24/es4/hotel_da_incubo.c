/* hotel_da_incubo.c - C source file. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 20  // Lunghezza massima nomi file/hotel

// Variabile globale per memorizzare nome hotel peggiore
char looser_name[LEN];

/* 
Struttura per memorizzare i voti di una singola recensione
Tre criteri di valutazione: servizio, pulizia, posizione
 */
typedef struct{
    int serv;
    int pul;
    int pos;
} voto;

/* 
Struttura per memorizzare il punteggio complessivo di un hotel
Include nome file dell'hotel e punteggio medio calcolato
 */
typedef struct{
    char name[LEN];
    float score;
} hscore;


float voto_hotel(char myhfilename[]);
char* incubo(char index[]);

float voto_hotel(char myhfilename[]){
    float avgserv, avgpul, avgpos, tot;  // Medie per categoria e totale
    int sum=0, people=0;                 // Somma parziale e counter recensioni
    char buffer[1024], let;              // Buffer lettura e character temporaneo
    FILE*myhotel = fopen(myhfilename, "r");

    // Controllo errore apertura file
    if (myhotel == NULL) {
        printf("Errore. Il file non si apre");
    }


    // Conta le righe per determinatesre il numero di recensioni
    while ((let = fgetc(myhotel)) != EOF) {
        if (let == '\n') {
            people++;
        }
    }
    people = people-1;
    rewind(myhotel);    // Torna all'inizio del file

    // Allocazione dinamica array per le recensioni
    voto* myvoti = malloc(sizeof(voto)*(people));

    // Allocazione dinamica array per le recensioni
    voto* myvoti = malloc(sizeof(voto)*(people));

    // LETTURA DATI DAL FILE
    
    // Salta l'intestazione del file
    fgets(buffer, sizeof(buffer), myhotel);
    
    // Legge tutti i voti: servizio, pulizia, posizione
    for (int i = 0; i<people; i++) {
        fscanf(myhotel, "%d %d %d\n", &myvoti[i].serv, &myvoti[i].pul, &myvoti[i].pos);
    }
    fclose(myhotel);

    // CALCOLO MEDIE PER CATEGORIA
    

    for (int i=0; i<people; i++) {
        sum = sum + myvoti[i].serv;

    for (int i=0; i<people; i++) {
        sum = sum + myvoti[i].serv;
    }
    avgserv = (float) sum / people;  // Cast per divisione float
    sum = 0;
    

    for (int i=0; i<people; i++) {
        sum = sum + myvoti[i].pul;
    }
    avgpul = (float) sum / people;
    sum = 0;
    

    for (int i=0; i<people; i++) {
        sum = sum + myvoti[i].pos;
    }
    avgpos = (float) sum / people;
    sum = 0;

    // Calcolo punteggio totale (somma delle tre medie)
    tot = avgserv + avgpul + avgpos;

    free(myvoti);
    return tot;
}

char* incubo(char index[]){

    FILE*myindex = fopen(index, "r");
    char let, tmp_name[LEN];
    int rows=0, l=0, m=0;
    float tmp;                           // Variabile temporanea per swap


    // Conta righe per determinatesre numero hotel
    while ((let = fgetc(myindex)) != EOF) {
        if (let == '\n') {
            rows++;
        }
    }
    rewind(myindex);

    // Allocazione dinamica array per hotel e punteggi
    hscore* hotel = malloc(sizeof(hscore)*(rows));

    // LETTURA NOMI HOTEL E CALCOLO PUNTEGGI
    
    // Lettura nomi file hotel
    for (int i=0; i<rows; i++) {
        fscanf(myindex, "%s\n", hotel[i].name);
    }
    
    // Calcolo punteggio per ogni hotel
    for (int i=0; i<rows; i++) {
        hotel[i].score = voto_hotel(hotel[i].name);
    }

    //printf("%.2f", hotel[3].score);  // Debug print (commentato)
    //printf(" %s\n", hotel[3].name);

    // ORDINAMENTO CRESCENTE (BUBBLE SORT)
    
    // Bubble sort per ordinare hotel dal peggiore al migliore
    for (int i=0; i<rows-1; i++){
        for (int j=0; j<rows-i-1; j++){
            if(hotel[j].score > hotel[j+1].score){

                tmp = hotel[j].score;
                hotel[j].score = hotel[j+1].score;
                hotel[j+1].score = tmp;
                

                strcpy(tmp_name, hotel[j].name);
                strcpy(hotel[j].name, hotel[j+1].name);
                strcpy(hotel[j+1].name, tmp_name);
            }
        }
    }

    // Il primo elemento è l'hotel con punteggio più basso (peggiore)
    strcpy(looser_name, hotel[0].name);
    free(hotel);

    return looser_name;  // Ritorna nome hotel peggiore
}

    return looser_name;  // Ritorna nome hotel peggiore
}

int main(int argc, char* argv[]){

    if (argc == 2){
        // Esecuzione normale con un parametro
        char* worst_hotel = incubo(argv[1]);
        
        // Rimuove estensione .txt dal nome per la visualizzazione
        char* hotel_name = strtok(worst_hotel, ".");
        
        // Calcola e mostra risultato finale
        printf("L'Hotel da incubo tra quelli indicati è: %s\nIl suo voto complessivo è stato di %.2f\n", 
               hotel_name, voto_hotel(worst_hotel));
        return 0;
    } else {
        // Errore: numero parametri non valido
        printf("Argomenti inseriri non validi");
        return 0;
    }
    
/* 
NOTE TECNICHE E POSSIBILI MIGLIORAMENTI:

1. GESTIONE ERRORI:
- Aggiungere controllo esistenza file
- Gestire malloc fallite
- Validare formato dati input

2. OTTIMIZZAZIONI:
- Evitare doppia chiamata voto_hotel nel main
- Usare algoritmi ordinamento più efficienti (quicksort)
- Implementare media ponderata per i criteri

3. ROBUSTEZZA:
- Controllo range voti (1-10)
- Gestione file vuoti o malformati
- Limitazione lunghezza nomi file

4. FUNZIONALITÀ AGGIUNTIVE:
- Classifica completa hotel
- Statistiche dettagliate per categoria
- Export risultati in formato CSV
 */
}
