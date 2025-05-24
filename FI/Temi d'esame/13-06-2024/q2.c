/*
 * File: q2.c
 * Descrizione: Tema d'esame del 13 giugno 2024 - Questione 2
 *              Programma per contare invitati per nazione da file
 * Autore: Studente FI
 * Data: 13 giugno 2024
 * Note: Implementazione con margini di miglioramento
 */

#include <stdio.h>
#include <string.h>

#define MAX_NATIONS 4  // Numero massimo di nazioni gestibili

/**
 * Struttura per rappresentare una nazione con il conteggio degli invitati
 */
typedef struct{
    char name[50];  // Nome della nazione
    int num;        // Numero di invitati da quella nazione
} Nation;

/**
 * Funzione per elaborare il file degli invitati e contare per nazione
 * @param my Puntatore al file aperto in lettura
 * @param array Array di strutture Nation per memorizzare i risultati
 */
void provenienze(FILE* my, Nation array[MAX_NATIONS]){
    char name[25], country[25];  // Buffer per nome e paese
    int flag=0;                  // Flag per verificare se il paese esiste già

    // Legge il file fino alla fine
    while (!feof(my)){
        // Legge nome e paese dal file
        fscanf(my, "%s %s", name, country);
        flag=0;  // Reset del flag

        // === CERCA SE IL PAESE ESISTE GIÀ ===
        for (int i = 0; i < MAX_NATIONS; i++){
            if(strcmp(array[i].name, country)==0){
                flag=1;              // Paese trovato
                array[i].num+=1;     // Incrementa il contatore
            }
        }
        
        // === AGGIUNGE NUOVO PAESE SE NON TROVATO ===
        if (flag==0){
            // NOTA: Questa implementazione ha un bug - sovrascrive tutti gli elementi
            for (int i = 0; i < MAX_NATIONS; i++){
                strcpy(array[i].name, country);  // Copia il nome del paese
                array[i].num+=1;                 // Incrementa il contatore
            }
        }
    }
}

/**
 * Funzione principale che gestisce l'apertura del file e la stampa dei risultati
 */
int main(){
    // === APERTURA FILE ===
    FILE* my = fopen("invitati.txt", "r");
    Nation nazioni[MAX_NATIONS];  // Array per memorizzare le nazioni

    // === ELABORAZIONE E OUTPUT ===
    provenienze(my, nazioni);
    
    // Stampa i risultati per ogni nazione
    for (int i = 0; i < MAX_NATIONS; i++){
        printf("Paese:%s\t Invitati:%d\n", nazioni[i].name, nazioni[i].num);
    }

    return 0;
}

// NOTA: Implementazione con margini di miglioramento (commento originale: "Brutto")