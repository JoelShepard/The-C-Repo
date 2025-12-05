/* q3.c - C source file. */

#include <stdlib.h>
#include <stdio.h>

/* *
Struttura per rappresentare un nodo della lista concatenata
 */
typedef struct nd {
    int valore;                    // Valore memorizzato nel nodo
    struct nd *next;               // Puntatore al nodo successivo
} Nodo;

typedef Nodo* Lista;

Lista filtra(Lista lis){
    // INIZIALIZZAZIONE: tre puntatori per navigare la lista
    Lista prev = lis;
    Lista curr = prev->next;
    Lista succ = curr->next;
    
    if (curr == NULL) {
        return prev;
    } 
    
    // CASO: lista con due elementi
    if (succ == NULL) {
        if (prev->valore > curr->valore) {
            free(prev->next);      // Rimuove il secondo nodo
            prev->next = NULL;
            return prev;
        } 
        if (prev->valore == curr->valore) {
            return prev;           // Mantiene il primo se uguali
        } else {
            return curr;           // WARNING: memory leak! prev non viene liberato
            free(prev);
        }
    }

    // CICLO PRINCIPALE: elabora lista con 3+ elementi
    while (succ != NULL) {
        // Gestione del primo nodo
        if (prev == lis) {
            if (prev->valore > curr->valore) {
                prev->next = curr->next;
                free(curr);
            } 
            if (prev->valore < curr->valore) {
                lis = curr;        // Cambia la testa della lista
                free(prev);
            }
            curr = succ;
            prev = curr;
            succ = succ->next;
        }
        
        // Confronto nodi corrente e successivo
        if (curr->valore > succ->valore) {
            curr->next = succ->next;
            free(succ);            // Rimuove il nodo successivo
        } 
        if (curr->valore < succ->valore) {
            prev->next = succ;
            free(curr);            // Rimuove il nodo corrente
        }
        
        // AVANZAMENTO: aggiorna i puntatori
        prev = succ;
        curr = prev->next;
        succ = curr->next;
        return lis;
}

Nodo* creaNodo(int val) {
    Nodo* nuovo = (Nodo*)malloc(sizeof(Nodo));
    nuovo->valore = val;
    nuovo->next = NULL;
    return nuovo;
}

void stampaLista(Lista l) {
    while(l != NULL) {
        printf("%d ", l->valore);
        l = l->next;
    }
    printf("\n");
}

int main() {
    // CREAZIONE: lista di test con valori misti
    Lista lista = creaNodo(5);
    lista->next = creaNodo(3);
    lista->next->next = creaNodo(7);
    lista->next->next->next = creaNodo(2);


    printf("Lista originale: ");
    stampaLista(lista);

    lista = filtra(lista);

    printf("Lista dopo il filtraggio: ");
    stampaLista(lista);

    return 0;
}

/* 
Note tecniche:
- La funzione filtra() presenta problemi di logica e potenziali memory leak
- Il criterio di filtraggio non è chiaramente definito
- Alcuni percorsi del codice potrebbero causare accessi a memoria non valida
- È necessaria una revisione completa dell'algoritmo di filtraggio
 */
