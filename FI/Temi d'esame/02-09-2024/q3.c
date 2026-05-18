// q3.c - Filtra lista concatenata

#include <stdlib.h>
#include <stdio.h>

typedef struct nd {
    int valore;
    struct nd *next;
} Nodo;

typedef Nodo* Lista;

Lista filtra(Lista lis){
    Lista prev = lis;
    Lista curr = prev->next;
    Lista succ = curr->next;
    
    if (curr == NULL) {
        return prev;
    } 
    
    if (succ == NULL) {
        if (prev->valore > curr->valore) {
            free(prev->next);
            prev->next = NULL;
            return prev;
        } 
        if (prev->valore == curr->valore) {
            return prev;
        } else {
            return curr; // BUG: memory leak, prev non viene liberato
            free(prev);
        }
    }

    while (succ != NULL) {
        if (prev == lis) {
            if (prev->valore > curr->valore) {
                prev->next = curr->next;
                free(curr);
            } 
            if (prev->valore < curr->valore) {
                lis = curr;
                free(prev);
            }
            curr = succ;
            prev = curr;
            succ = succ->next;
        }
        
        if (curr->valore > succ->valore) {
            curr->next = succ->next;
            free(succ);
        } 
        if (curr->valore < succ->valore) {
            prev->next = succ;
            free(curr);
        }
        
        prev = succ;
        curr = prev->next;
        succ = curr->next;
        return lis;
    }
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
Note: La funzione filtra() presenta problemi di logica e potenziali memory leak.
Il criterio di filtraggio non è chiaramente definito.
*/
