/*
 * =============================================================================
 * HOTEL DA INCUBO - SISTEMA DI VALUTAZIONE E RANKING
 * =============================================================================
 * 
 * Descrizione:
 * Sistema completo per la valutazione di hotel basato su tre criteri:
 * servizio, pulizia e posizione. Il programma legge le valutazioni da file,
 * calcola i punteggi medi e identifica l'hotel con il punteggio più basso
 * ("hotel da incubo").
 * 
 * Autore: Studente FI
 * Data: 29 novembre 2024
 * Corso: Fondamenti di Informatica - Laboratorio
 * 
 * Funzionalità principali:
 * - Lettura valutazioni da file per ogni hotel
 * - Calcolo media ponderata per tre criteri
 * - Ordinamento hotel per punteggio
 * - Identificazione hotel peggiore
 * - Gestione dinamica memoria
 * 
 * Input formato:
 * - File index: lista nomi file hotel
 * - File hotel: intestazione + righe "servizio pulizia posizione"
 * 
 * Note tecniche:
 * - Uso di malloc/free per allocazione dinamica
 * - Algoritmo bubble sort per ordinamento
 * - Gestione parametri command line
 * 
 * =============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 20  // Lunghezza massima nomi file/hotel

// Variabile globale per memorizzare nome hotel peggiore
char looser_name[LEN];

/*
 * Struttura per memorizzare i voti di una singola recensione
 * Tre criteri di valutazione: servizio, pulizia, posizione
 */
typedef struct{
    int serv;  // Voto servizio (1-10)
    int pul;   // Voto pulizia (1-10)
    int pos;   // Voto posizione (1-10)
} voto;

/*
 * Struttura per memorizzare il punteggio complessivo di un hotel
 * Include nome file dell'hotel e punteggio medio calcolato
 */
typedef struct{
    char name[LEN];  // Nome file dell'hotel
    float score;     // Punteggio medio complessivo
} hscore;

// Dichiarazioni funzioni
float voto_hotel(char myhfilename[]);
char* incubo(char index[]);

/*
 * Funzione per calcolare il voto medio di un hotel
 * Legge le recensioni dal file e calcola la media dei tre criteri
 * 
 * Parametri:
 *   myhfilename[] - nome del file contenente le recensioni
 * 
 * Ritorna:
 *   float - punteggio totale medio dell'hotel
 */
float voto_hotel(char myhfilename[]){
    float avgserv, avgpul, avgpos, tot;  // Medie per categoria e totale
    int sum=0, people=0;                 // Somma parziale e contatore recensioni
    char buffer[1024], let;              // Buffer lettura e carattere temporaneo
    FILE*myhotel = fopen(myhfilename, "r");  // Apertura file hotel

    // Controllo errore apertura file
    if (myhotel == NULL) {
        printf("Errore. Il file non si apre");
    }

    // ===============================================
    // CONTEGGIO NUMERO RECENSIONI
    // ===============================================
    
    // Conta le righe per determinare il numero di recensioni
    while ((let = fgetc(myhotel)) != EOF) {
        if (let == '\n') {
            people++;
        }
    }
    people = people-1;  // Sottrae intestazione
    rewind(myhotel);    // Torna all'inizio del file

    // Allocazione dinamica array per le recensioni
    voto* myvoti = malloc(sizeof(voto)*(people));

    // Allocazione dinamica array per le recensioni
    voto* myvoti = malloc(sizeof(voto)*(people));

    // ===============================================
    // LETTURA DATI DAL FILE
    // ===============================================
    
    // Salta l'intestazione del file
    fgets(buffer, sizeof(buffer), myhotel);
    
    // Legge tutti i voti: servizio, pulizia, posizione
    for (int i = 0; i<people; i++) {
        fscanf(myhotel, "%d %d %d\n", &myvoti[i].serv, &myvoti[i].pul, &myvoti[i].pos);
    }
    fclose(myhotel);

    // ===============================================
    // CALCOLO MEDIE PER CATEGORIA
    // ===============================================
    
    // Media voti SERVIZIO
    for (int i=0; i<people; i++) {
        sum = sum + myvoti[i].serv;
    // Media voti SERVIZIO
    for (int i=0; i<people; i++) {
        sum = sum + myvoti[i].serv;
    }
    avgserv = (float) sum / people;  // Cast per divisione float
    sum = 0;  // Reset somma
    
    // Media voti PULIZIA
    for (int i=0; i<people; i++) {
        sum = sum + myvoti[i].pul;
    }
    avgpul = (float) sum / people;
    sum = 0;  // Reset somma
    
    // Media voti POSIZIONE
    for (int i=0; i<people; i++) {
        sum = sum + myvoti[i].pos;
    }
    avgpos = (float) sum / people;
    sum = 0;  // Reset somma

    // Calcolo punteggio totale (somma delle tre medie)
    tot = avgserv + avgpul + avgpos;

    free(myvoti);  // Liberazione memoria allocata
    return tot;    // Ritorna punteggio totale
}

/*
 * Funzione per identificare l'hotel peggiore (da incubo)
 * Legge lista hotel, calcola punteggi e trova il minimo
 * 
 * Parametri:
 *   index[] - nome del file contenente la lista degli hotel
 * 
 * Ritorna:
 *   char* - puntatore al nome dell'hotel peggiore
 */
char* incubo(char index[]){

    FILE*myindex = fopen(index, "r");    // Apertura file indice
    char let, tmp_name[LEN];             // Variabili temporanee
    int rows=0, l=0, m=0;                // Contatori
    float tmp;                           // Variabile temporanea per swap

    // ===============================================
    // CONTEGGIO NUMERO HOTEL
    // ===============================================
    
    // Conta righe per determinare numero hotel
    while ((let = fgetc(myindex)) != EOF) {
        if (let == '\n') {
            rows++;
        }
    }
    rewind(myindex);  // Torna all'inizio

    // Allocazione dinamica array per hotel e punteggi
    hscore* hotel = malloc(sizeof(hscore)*(rows));

    // ===============================================
    // LETTURA NOMI HOTEL E CALCOLO PUNTEGGI
    // ===============================================
    
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

    // ===============================================
    // ORDINAMENTO CRESCENTE (BUBBLE SORT)
    // ===============================================
    
    // Bubble sort per ordinare hotel dal peggiore al migliore
    for (int i=0; i<rows-1; i++){
        for (int j=0; j<rows-i-1; j++){
            if(hotel[j].score > hotel[j+1].score){
                // Swap punteggi
                tmp = hotel[j].score;
                hotel[j].score = hotel[j+1].score;
                hotel[j+1].score = tmp;
                
                // Swap nomi
                strcpy(tmp_name, hotel[j].name);
                strcpy(hotel[j].name, hotel[j+1].name);
                strcpy(hotel[j+1].name, tmp_name);
            }
        }
    }

    // Il primo elemento è l'hotel con punteggio più basso (peggiore)
    strcpy(looser_name, hotel[0].name);
    free(hotel);  // Liberazione memoria

    return looser_name;  // Ritorna nome hotel peggiore
}

    return looser_name;  // Ritorna nome hotel peggiore
}

/*
 * Funzione principale del programma
 * Gestisce parametri command line e coordina l'esecuzione
 * 
 * Parametri:
 *   argc - numero argomenti command line
 *   argv - array argomenti command line
 * 
 * Uso: ./hotel_da_incubo <file_indice_hotel>
 */
int main(int argc, char* argv[]){
    // Controllo numero parametri
    if (argc == 2){
        // Esecuzione normale con un parametro
        char* worst_hotel = incubo(argv[1]);  // Trova hotel peggiore
        
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
     * NOTE TECNICHE E POSSIBILI MIGLIORAMENTI:
     * 
     * 1. GESTIONE ERRORI:
     *    - Aggiungere controllo esistenza file
     *    - Gestire malloc fallite
     *    - Validare formato dati input
     * 
     * 2. OTTIMIZZAZIONI:
     *    - Evitare doppia chiamata voto_hotel nel main
     *    - Usare algoritmi ordinamento più efficienti (quicksort)
     *    - Implementare media ponderata per i criteri
     * 
     * 3. ROBUSTEZZA:
     *    - Controllo range voti (1-10)
     *    - Gestione file vuoti o malformati
     *    - Limitazione lunghezza nomi file
     * 
     * 4. FUNZIONALITÀ AGGIUNTIVE:
     *    - Classifica completa hotel
     *    - Statistiche dettagliate per categoria
     *    - Export risultati in formato CSV
     */
}
