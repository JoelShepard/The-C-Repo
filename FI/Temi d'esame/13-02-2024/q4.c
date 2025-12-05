/* q4.c - C source file. */
#include <stdio.h>
#include <stdlib.h>

// Definizione della struttura per la lista
typedef struct Nodo {
    int valore;
    struct Nodo* prossimo;
} Nodo;

typedef Nodo* Lista;

// Function per creare un nuovo nodo
Nodo* creaNodo(int valore) {
    Nodo* nuovoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (nuovoNodo == NULL) {
        printf("Errore di allocazione memoria\n");
        exit(EXIT_FAILURE);
    }
    nuovoNodo->valore = valore;
    nuovoNodo->prossimo = NULL;
    return nuovoNodo;
}

// Function per addsre un elemento alla lista
Lista aggiungiElemento(Lista testa, int valore) {
    Nodo* nuovoNodo = creaNodo(valore);
    if (testa == NULL) {
        return nuovoNodo;
    }
    Nodo* temp = testa;
    while (temp->prossimo != NULL) {
        temp = temp->prossimo;
    }
    temp->prossimo = nuovoNodo;
    return testa;
}

// Function per printsre la lista
void stampaLista(Lista testa) {
    Nodo* temp = testa;
    while (temp != NULL) {
        printf("%d -> ", temp->valore);
        temp = temp->prossimo;
    }
    printf("NULL\n");
}


Lista ListaMaggioriDiTuttiISuccessori(Lista testa) {
    if (testa == NULL || testa->prossimo == NULL) {
        return testa; // Lista vuota o con un solo elemento
    }

    Nodo* corrente = testa;
    while (corrente != NULL && corrente->prossimo != NULL) {
        Nodo* successore = corrente->prossimo;
        int rimuoviCorrente = 0;

        while (successore != NULL) {
            if (corrente->valore < successore->valore) {
                rimuoviCorrente = 1;
                break;
            }
            successore = successore->prossimo;
        }

        if (rimuoviCorrente) {
            if (corrente == testa) {
                Nodo* temp = testa;
                testa = testa->prossimo;
                free(temp);
                corrente = testa;
            } else {
                Nodo* prec = testa;
                while (prec->prossimo != corrente) {
                    prec = prec->prossimo;
                }
                prec->prossimo = corrente->prossimo;
                free(corrente);
                corrente = prec->prossimo;
            }
        } else {
            corrente = corrente->prossimo;
        }
    }

    return testa;
}

int main() {
    Lista lista = NULL;

    // Creazione della lista di esempio: 3 -> 32 -> 4 -> 6 -> 3 -> 20 -> 17 -> 2 -> 17 -> 9 -> 7 -> 1
    int valori[] = {3, 32, 4, 6, 3, 20, 17, 2, 17, 9, 7, 1};
    int n = sizeof(valori) / sizeof(valori[0]);

    for (int i = 0; i < n; i++) {
        lista = aggiungiElemento(lista, valori[i]);
    }

    printf("Lista originale:\n");
    stampaLista(lista);

    lista = ListaMaggioriDiTuttiISuccessori(lista);

    printf("Lista modificata:\n");
    stampaLista(lista);

    return 0;
}
