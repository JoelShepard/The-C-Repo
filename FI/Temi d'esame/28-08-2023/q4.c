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

Node* create() {
    Node* tmp = malloc(sizeof(Node));
    if (tmp == NULL) {
        return NULL;  // Gestione errore di allocazione
    }
    
    tmp->next = NULL;
    return tmp;
}

Node* ArrayPartToList(int my[], int n, int sum) {
    // === CONTROLLO VALIDITÀ ===
    if (n <= 0) {
        return NULL;
    }

    Node* list = NULL;
    Node* prev = NULL;    // Nodo precedente per concatenazione
    Node* current = NULL;

    for (int i = 0; i < n; i++) {
        
        if (i < n-1) {  // === GESTIONE COPPIE ===
            int j = i + 1;
            int tmpsum = my[i] + my[j];
            

            current = create();
            if (current == NULL) {
                // TODO: Gestione errore - liberare lista precedente
                return NULL;
            }

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

            if (list == NULL) {
                list = current;        // Primo nodo della lista
            } else {
                prev->next = current;  // Concatena alla lista esistente
            }
            prev = current;
            
        } else {  // === GESTIONE ULTIMO ELEMENTO ===
            current = create();
            if (current == NULL) {
                // TODO: Gestione errore - liberare lista precedente
                return NULL;
            }
            
            // Ultimo elemento: memorizza sempre solo il proprio indice
            current->firstindex = i;
            current->lastindex = i;
            
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
    int my[]={1, 5, 8, 10, 2};
    int sum = 10;                // Valore target per confronto somme

    Node* result = ArrayPartToList(my, 5, sum);
    
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
