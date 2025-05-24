/**
 * ================================================================
 * SISTEMA DI GESTIONE LISTA REGALI DI NATALE - ELFI DI BABBO NATALE
 * ================================================================
 * 
 * Descrizione:
 *   Programma per la gestione di una lista collegata di regali natalizi.
 *   Ogni regalo è caratterizzato da nome, peso e quantità. Il sistema
 *   legge da file la lista dei regali e fornisce funzionalità per
 *   visualizzare e manipolare i dati.
 * 
 * Funzionalità:
 *   - Lettura lista regali da file di testo
 *   - Creazione lista collegata dinamica
 *   - Visualizzazione formattata della lista
 *   - Rimozione duplicati (funzione da implementare)
 *   - Gestione memoria dinamica con malloc
 *
 * Formato file: <nome_regalo> <peso> <quantità>
 * Esempio: "Bicicletta 15 2"
 *
 * Autore: Joel (Laboratorio del 13 dicembre 2024)
 * Corso: Fondamenti di Informatica
 * 
 * Note tecniche:
 *   - Struttura dati: Lista collegata semplice
 *   - Gestione parametri da linea di comando
 *   - Allocazione dinamica con controllo errori limitato
 * ================================================================
 */

#include <stdio.h>   // Per file I/O, printf
#include <stdlib.h>  // Per malloc, free
#include <string.h>  // Per strcpy, manipolazione stringhe

/**
 * ================================================================
 * DEFINIZIONE STRUTTURE DATI
 * ================================================================
 */

// Struttura per rappresentare un singolo regalo di Natale
typedef struct el{
    char name[50];      // Nome del regalo (max 49 caratteri + \0)
    int weight;         // Peso del regalo in unità arbitrarie
    int qty;            // Quantità di regali di questo tipo
    struct el* next;    // Puntatore al prossimo regalo nella lista
} Gift;

// Alias per semplificare la gestione della lista
typedef Gift* List;

/**
 * ================================================================
 * FUNZIONE DI STAMPA LISTA REGALI
 * ================================================================
 * 
 * Parametri:
 *   my - Puntatore alla testa della lista collegata
 * 
 * Funzionalità:
 *   - Stampa intestazione tabellare formattata
 *   - Itera attraverso tutti i nodi della lista
 *   - Visualizza nome, peso e quantità di ogni regalo
 *   - Utilizza tabulazioni per allineamento colonne
 */
void stamp(List my){
    printf("Nome\t Peso\t Quantità\n");
    
    // Scorre tutti i nodi della lista collegata
    while (my != NULL) {
        printf("%s\t %d\t %d\n", my->name, my->weight, my->qty);
        my = my->next; // Avanza al nodo successivo
    }
}

/**
 * ================================================================
 * FUNZIONE DI RIMOZIONE DUPLICATI
 * ================================================================
 * 
 * Parametri:
 *   my - Puntatore alla testa della lista collegata
 * 
 * Funzionalità:
 *   TODO: Implementare la logica per rimuovere regali duplicati
 *   - Dovrebbe confrontare i nomi dei regali
 *   - Unire quantità per regali con stesso nome
 *   - Deallocare nodi duplicati dalla memoria
 * 
 * Stato: FUNZIONE NON IMPLEMENTATA
 */
void deletedoubles(List my){
    // Implementazione da completare
    // Algoritmo suggerito:
    // 1. Scorrere la lista con puntatore corrente
    // 2. Per ogni nodo, cercare duplicati nei nodi successivi
    // 3. Sommare le quantità dei duplicati
    // 4. Rimuovere i nodi duplicati e liberare memoria
}



/**
 * ================================================================
 * FUNZIONE DI CREAZIONE NUOVO NODO
 * ================================================================
 * 
 * Parametri:
 *   prev - Puntatore al nodo precedente nella lista
 * 
 * Ritorna:
 *   Gift* - Puntatore al nuovo nodo creato e collegato
 * 
 * Funzionalità:
 *   - Alloca memoria per un nuovo nodo Gift
 *   - Collega il nuovo nodo dopo il nodo precedente
 *   - Inizializza il campo next del nuovo nodo a NULL
 *   - Restituisce puntatore al nuovo nodo per ulteriori operazioni
 */
Gift* create(Gift* prev){
    prev->next = (Gift*)malloc(sizeof(Gift)); // Alloca nuovo nodo
    prev->next->next = NULL;                   // Inizializza next a NULL
    return prev->next;                         // Restituisce nuovo nodo
}

/**
 * ================================================================
 * FUNZIONE DI LETTURA DA FILE E COSTRUZIONE LISTA
 * ================================================================
 * 
 * Parametri:
 *   elf - Puntatore al file contenente la lista dei regali
 *   my  - Puntatore al puntatore della testa della lista (modifica la lista)
 * 
 * Funzionalità:
 *   - Conta il numero di righe nel file per dimensionare il ciclo
 *   - Legge dati in formato: <nome> <peso> <quantità>
 *   - Costruisce dinamicamente la lista collegata
 *   - Gestisce il caso del primo nodo (lista vuota)
 *   - Utilizza fscanf per parsing strutturato dei dati
 */
void read(FILE* elf, List* my){
    char tmpn[50], buffer[1024]; // Buffer temporanei per lettura
    int tmpw, tmpq, count = 0;   // Variabili temporanee e contatore righe
    
    // ================================================================
    // FASE 1: CONTEGGIO RIGHE NEL FILE
    // ================================================================
    while (fgets(buffer, sizeof(buffer), elf) != NULL) {
        count++; // Conta ogni riga letta
    }
    rewind(elf); // Torna all'inizio del file per lettura dati
    
    Gift* tmp = *my; // Puntatore per navigazione/costruzione lista

    // ================================================================
    // FASE 2: LETTURA DATI E COSTRUZIONE LISTA
    // ================================================================
    for (int i = 0; i < count; i++) {
        // Legge una riga: nome peso quantità
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
        tmp->weight = tmpw;      // Assegna il peso
        tmp->qty = tmpq;         // Assegna la quantità
    }
}


/**
 * ================================================================
 * FUNZIONE PRINCIPALE - GESTIONE LISTA REGALI DI NATALE
 * ================================================================
 */
int main(int argc, char* argv[]){
    // ================================================================
    // FASE 1: VALIDAZIONE PARAMETRI LINEA DI COMANDO
    // ================================================================
    if (argc != 2) {
        printf("Errore, parametri non validi\n");
        printf("Uso: %s <nome_file_lista_regali>\n", argv[0]);
        return -1; // Aggiunto return per uscita corretta
    }
    
    // ================================================================
    // FASE 2: APERTURA E VALIDAZIONE FILE
    // ================================================================
    FILE* elfList = fopen(argv[1], "r");
    if (elfList == NULL) {
        printf("Apertura del file non riuscita\n");
        return -1; // Aggiunto return per uscita corretta
    }
    
    List mylist = NULL; // Inizializza lista vuota
    
    // ================================================================
    // FASE 3: COSTRUZIONE E ELABORAZIONE LISTA
    // ================================================================
    read(elfList, &mylist);    // Legge dal file e costruisce la lista
    deletedoubles(mylist);     // Rimuove duplicati (funzione da implementare)
    
    // ================================================================
    // FASE 4: TEST DI FUNZIONAMENTO (DEBUG)
    // ================================================================
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
