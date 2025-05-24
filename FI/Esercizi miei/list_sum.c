/*
 * File: list_sum.c
 * Descrizione: Implementazione di liste concatenate con operazione di somma tra nodi adiacenti
 *              Ogni nodo viene modificato sommando il valore del nodo precedente
 * Autore: Studente FI
 * Data: Esercizi personali
 */

#include <stdlib.h>
#include <stdio.h>

/**
 * Struttura per rappresentare un nodo della lista
 */
typedef struct nd{
    int val;           // Valore del nodo
    struct nd* next;   // Puntatore al nodo successivo
}Node;

typedef Node* List;  // Alias per puntatore alla lista

/**
 * Funzione che modifica la lista sommando ogni nodo con il precedente
 * @param my Puntatore alla testa della lista
 * Algoritmo: curr->val += prev->val per ogni nodo (tranne il primo)
 */
void sumbytwo(List my){
    List prev = my;           // Puntatore al nodo precedente
    List curr = my->next;     // Puntatore al nodo corrente
    int tmp=0;               // Variabile temporanea (non utilizzata)
    
    // Scorre la lista fino al penultimo nodo
    while (curr->next!=NULL) {
        if (prev != my) {
            // Somma il valore del nodo precedente al corrente
            curr->val+=prev->val;
        }
        // Avanza entrambi i puntatori
        curr = curr->next;
        prev = prev->next;
    }
}

/**
 * Funzione principale che crea, modifica e gestisce la lista
 */
int main(){
    // === CREAZIONE DELLA LISTA ===
    // Crea il nodo testa con valore 0
    List head = malloc(sizeof(Node));
    head->val = 0;

    // Costruisce una lista con valori 0, 1, 2, 3, 4
    List curr = head;
    for(int i = 1; i <= 4; i++) {
        curr->next = malloc(sizeof(Node));
        curr->next->val = i;
        curr->next->next = NULL;
        curr = curr->next;
    }

    // === STAMPA LISTA ORIGINALE ===
    printf("Original list: ");
    curr = head;
    while(curr != NULL) {
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");

    // === MODIFICA DELLA LISTA ===
    sumbytwo(head);

    // === STAMPA LISTA MODIFICATA ===
    printf("Modified list: ");
    curr = head;
    while(curr != NULL) {
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");

    // === LIBERAZIONE DELLA MEMORIA ===
    curr = head;
    while(curr != NULL) {
        List tmp = curr;
        curr = curr->next;
        free(tmp);  // Dealloca ogni nodo
    }

    return 0;
}

// Nota originale: "Liste Bastarde" - Commento scherzoso sulle liste concatenate
