/* christmas.c - C source file. */

#include <stdio.h>   // Per file I/O, printf
#include <stdlib.h>  // Per malloc, free
#include <string.h>  // Per strcpy, manipolazione stringhe

/* *
================================================================
DEFINIZIONE STRUTTURE DATI
================================================================
 */

// Struttura per rappresentare un singolo regalo di Natale
typedef struct el{
    char name[50];      // Nome del regalo (max 49 characters + \0)
    int weight;         // Peso del regalo in unità arbitrarie
    int qty;            // Quantità di regali di questo tipo
    struct el* next;    // Puntatore al prossimo regalo nella lista
} Gift;

// Alias per semplificare la gestione della lista
typedef Gift* List;

void stamp(List my){
    printf("Nome\t Peso\t Quantità\n");
    
    // Scorre tutti i nodi della lista collegata
    while (my != NULL) {
        printf("%s\t %d\t %d\n", my->name, my->weight, my->qty);
        my = my->next; // Avanza al nodo successivo
    }
}

void deletedoubles(List my){


    // 1. Scorrere la lista con puntatore corrente
    // 2. Per ogni nodo, cercare duplicati nei nodi successivi
    // 3. Sommare le quantità dei duplicati
    // 4. Rimuovere i nodi duplicati e liberare memoria
}


Gift* create(Gift* prev){
    prev->next = (Gift*)malloc(sizeof(Gift));
    prev->next->next = NULL;                   // Inizializza next a NULL
    return prev->next;
}

void read(FILE* elf, List* my){
    char tmpn[50], buffer[1024]; // Buffer temporanei per lettura
    int tmpw, tmpq, count = 0;   // Variabili temporanee e counter righe
    
    // FASE 1: CONTEGGIO RIGHE NEL FILE
    while (fgets(buffer, sizeof(buffer), elf) != NULL) {
        count++; // Conta ogni row letta
    }
    rewind(elf); // Torna all'inizio del file per lettura dati
    
    Gift* tmp = *my; // Puntatore per navigazione/costruzione lista

    // FASE 2: LETTURA DATI E COSTRUZIONE LISTA
    for (int i = 0; i < count; i++) {
        // Legge una row: nome peso quantità
        fscanf(elf, "%s %d %d\n", tmpn, &tmpw, &tmpq);
        
        if (tmp == NULL) {
            // Primo nodo: crea la testa della lista
            tmp = (Gift*)malloc(sizeof(Gift));
            *my = tmp; // Aggiorna la testa della lista
        } else {
            // Nodi successivi: crea e collega nuovo nodo
            tmp = create(tmp);
        }
        
        // Popola i dati del nodo corrente
        strcpy(tmp->name, tmpn); // Copia il nome del regalo
        tmp->weight = tmpw;
        tmp->qty = tmpq;
    }
}


/* *
================================================================
FUNZIONE PRINCIPALE - GESTIONE LISTA REGALI DI NATALE
================================================================
 */
int main(int argc, char* argv[]){
    // FASE 1: VALIDAZIONE PARAMETRI LINEA DI COMANDO
    if (argc != 2) {
        printf("Errore, parametri non validi\n");
        printf("Uso: %s <nome_file_lista_regali>\n", argv[0]);
        return -1; // Aggiunto return per uscita corretta
    }
    
    // FASE 2: APERTURA E VALIDAZIONE FILE
    FILE* elfList = fopen(argv[1], "r");
    if (elfList == NULL) {
        printf("Apertura del file non riuscita\n");
        return -1; // Aggiunto return per uscita corretta
    }
    
    List mylist = NULL;
    
    read(elfList, &mylist);    // Legge dal file e costruisce la lista
    deletedoubles(mylist);     // Rimuove duplicati (funzione da implementare)
    
    // FASE 4: TEST DI FUNZIONAMENTO (DEBUG)
    // Test di accesso al secondo nodo (potenzialmente pericoloso)
    if (mylist != NULL && mylist->next != NULL) {
        printf("Secondo regalo nella lista: %s\n", mylist->next->name);
    } else {
        printf("Lista vuota o con un solo elemento\n");
    }
    
    // TODO: Aggiungere chiusura file e deallocazione memoria
    // fclose(elfList);
    // Deallocazione completa della lista collegata
    
    return 0;
}
