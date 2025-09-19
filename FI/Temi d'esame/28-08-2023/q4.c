/* q4.c - C source file. */

#include <stdio.h>
#include <stdlib.h>

/* *
Struttura per rappresentare un nodo della lista concatenata
 */
typedef struct ls {
    int firstindex;  // Primo indice della coppia (o singolo)
    int lastindex;   // Secondo indice della coppia (o uguale al primo)
    struct ls* next; // Puntatore al nodo successivo
} Node;

/* *
Function per creare un nuovo nodo inizializzato
@return Puntatore al nuovo nodo o NULL se allocazione fallisce
 */
Node* create() {
    // === ALLOCAZIONE MEMORIA ===
    Node* tmp = malloc(sizeof(Node));
    if (tmp == NULL) {
        return NULL;  // Gestione errore di allocazione
    }
    
    // === INIZIALIZZAZIONE ===
    tmp->next = NULL;
    return tmp;
}

/* *
Function principale per convertire array in lista basata su analisi di coppie

Algoritmo:
1. Per ogni elemento (tranne l'ultimo), analizza la coppia con il successivo
2. Calcola somma della coppia e confronta con target
3. Memorizza indici appropriati nel nodo in base al risultato del confronto
4. Gestisce separatamente l'ultimo elemento dell'array

@param my  Array di interi da analizzare
@param n   Size dell'array
@param sum Valore target per il confronto delle somme
@return    Puntatore alla testa della lista creata
 */
Node* ArrayPartToList(int my[], int n, int sum) {
    // === CONTROLLO VALIDITÀ ===
    if (n <= 0) {
        return NULL;
    }

    // === INIZIALIZZAZIONE VARIABILI ===
    Node* list = NULL;    // Testa della lista
    Node* prev = NULL;    // Nodo precedente per concatenazione
    Node* current = NULL; // Nodo corrente

    // === ELABORAZIONE ELEMENTI ===
    for (int i = 0; i < n; i++) {
        
        if (i < n-1) {  // === GESTIONE COPPIE ===
            int j = i + 1;
            int tmpsum = my[i] + my[j];  // Somma della coppia
            
            // Creazione nuovo nodo
            current = create();
            if (current == NULL) {
                // TODO: Gestione errore - liberare lista precedente
                return NULL;
            }

            // === LOGICA DI ASSEGNAZIONE INDICI ===
            if (tmpsum == sum) {
                // Somma uguale: memorizza entrambi gli indici
                current->firstindex = i;
                current->lastindex = j;
            } else if (tmpsum > sum) {
                // Somma maggiore: memorizza solo primo indice
                current->firstindex = i;
                current->lastindex = i;
            } else {  // tmpsum < sum
                // Somma minore: memorizza solo primo indice
                current->firstindex = i;
                current->lastindex = i;
            }

            // === CONCATENAZIONE LISTA ===
            if (list == NULL) {
                list = current;        // Primo nodo della lista
            } else {
                prev->next = current;  // Concatena alla lista esistente
            }
            prev = current;  // Aggiorna riferimento precedente
            
        } else {  // === GESTIONE ULTIMO ELEMENTO ===
            current = create();
            if (current == NULL) {
                // TODO: Gestione errore - liberare lista precedente
                return NULL;
            }
            
            // Ultimo elemento: memorizza sempre solo il proprio indice
            current->firstindex = i;
            current->lastindex = i;
            
            // === CONCATENAZIONE FINALE ===
            if (list == NULL) {
                list = current;        // Case particolare: array di 1 elemento
            } else {
                prev->next = current;  // Aggiungi alla fine della lista
            }
        }
    }

    return list;
}

/* *
Function principale - test dell'algoritmo di conversione array-lista
 */
int main(){
    // === DATI DI TEST ===
    int my[]={1, 5, 8, 10, 2};  // Array di esempio
    int sum = 10;                // Valore target per confronto somme

    // === ESECUZIONE ===
    Node* result = ArrayPartToList(my, 5, sum);
    
    // === OUTPUT ===
    // Prints lastindex del secondo nodo (posizione 1 nella lista)
    printf("LastIndex del secondo nodo: %d\n", result->next->lastindex);
    
/* Analisi dell'esempio:
Coppia (1,5): somma=6 < 10 → firstindex=0, lastindex=0
Coppia (5,8): somma=13 > 10 → firstindex=1, lastindex=1
Coppia (8,10): somma=18 > 10 → firstindex=2, lastindex=2
Coppia (10,2): somma=12 > 10 → firstindex=3, lastindex=3
Ultimo (2): → firstindex=4, lastindex=4

result->next->lastindex = 1 (secondo nodo)
 */
    
    return 0;
}
