/**
 * File: q3.c
 * Descrizione: Implementazione di una funzione per filtrare liste concatenate
 *              rimuovendo elementi secondo un criterio specifico
 * Autore: [Studente]
 * Data: 02-09-2024
 * Tema d'esame: Manipolazione di liste concatenate con filtri
 * 
 * Commento originale: "le liste sono brutte e cattive"
 * Nota: Il codice presenta alcune problematiche nella logica di filtraggio
 */

#include <stdlib.h>
#include <stdio.h>

/**
 * Struttura per rappresentare un nodo della lista concatenata
 */
typedef struct nd {
    int valore;                    // Valore memorizzato nel nodo
    struct nd *next;               // Puntatore al nodo successivo
} Nodo;

typedef Nodo* Lista;

/**
 * Funzione per filtrare una lista concatenata secondo un criterio specifico
 * 
 * @param lis  Puntatore alla lista da filtrare
 * @return     Puntatore alla lista filtrata
 * 
 * ATTENZIONE: La logica di filtraggio in questa implementazione presenta
 * alcuni problemi e comportamenti non chiari. Il codice sembra tentare
 * di confrontare nodi adiacenti e rimuovere quelli che non soddisfano
 * certe condizioni, ma la logica è incompleta e potenzialmente buggata.
 */
Lista filtra(Lista lis){
    // INIZIALIZZAZIONE: tre puntatori per navigare la lista
    Lista prev = lis;              // Nodo precedente
    Lista curr = prev->next;       // Nodo corrente
    Lista succ = curr->next;       // Nodo successivo
    
    // CASO BASE: lista con un solo elemento
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
            return curr;           // ATTENZIONE: memory leak! prev non viene liberato
            free(prev);            // Codice irraggiungibile
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

/**
 * Funzione di utilità per creare un nuovo nodo
 * 
 * @param val  Valore da memorizzare nel nodo
 * @return     Puntatore al nuovo nodo creato
 */
Nodo* creaNodo(int val) {
    Nodo* nuovo = (Nodo*)malloc(sizeof(Nodo));
    nuovo->valore = val;
    nuovo->next = NULL;
    return nuovo;
}

/**
 * Funzione di utilità per stampare tutti gli elementi di una lista
 * 
 * @param l  Puntatore alla lista da stampare
 */
void stampaLista(Lista l) {
    while(l != NULL) {
        printf("%d ", l->valore);
        l = l->next;
    }
    printf("\n");
}

/**
 * Funzione principale per testare il filtraggio di liste
 * 
 * Crea una lista di test e applica la funzione filtra
 * Test case: 5 → 3 → 7 → 2
 */
int main() {
    // CREAZIONE: lista di test con valori misti
    Lista lista = creaNodo(5);
    lista->next = creaNodo(3);
    lista->next->next = creaNodo(7);
    lista->next->next->next = creaNodo(2);

    // OUTPUT: stato iniziale
    printf("Lista originale: ");
    stampaLista(lista);

    // ELABORAZIONE: applica il filtro
    lista = filtra(lista);

    // OUTPUT: risultato del filtraggio
    printf("Lista dopo il filtraggio: ");
    stampaLista(lista);

    return 0;
}

/*
 * Note tecniche:
 * - La funzione filtra() presenta problemi di logica e potenziali memory leak
 * - Il criterio di filtraggio non è chiaramente definito
 * - Alcuni percorsi del codice potrebbero causare accessi a memoria non valida
 * - È necessaria una revisione completa dell'algoritmo di filtraggio
 */
