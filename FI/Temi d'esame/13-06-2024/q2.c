/* q2.c - C source file. */

#include <stdio.h>
#include <string.h>

#define MAX_NATIONS 4  // Numero massimo di nazioni gestibili

/* *
Struttura per rappresentare una nazione con il conteggio degli invitati
 */
typedef struct{
    char name[50];
    int num;        // Numero di invitati da quella nazione
} Nation;

void provenienze(FILE* my, Nation array[MAX_NATIONS]){
    char name[25], country[25];  // Buffer per nome e paese
    int flag=0;                  // Flag per verificare se il paese esiste già

    // Legge il file fino alla fine
    while (!feof(my)){
        // Legge nome e paese dal file
        fscanf(my, "%s %s", name, country);
        flag=0;

        // === CERCA SE IL PAESE ESISTE GIÀ ===
        for (int i = 0; i < MAX_NATIONS; i++){
            if(strcmp(array[i].name, country)==0){
                flag=1;
                array[i].num+=1;
            }
        }
        
        if (flag==0){
            // NOTA: Questa implementazione ha un bug - sovrascrive tutti gli elementi
            for (int i = 0; i < MAX_NATIONS; i++){
                strcpy(array[i].name, country);  // Copia il nome del paese
                array[i].num+=1;
            }
        }
    }
}

/* *
Function principale che gestisce l'apertura del file e la prints dei risultati
 */
int main(){
    FILE* my = fopen("invitati.txt", "r");
    Nation nazioni[MAX_NATIONS];  // Array per memorizzare le nazioni

    provenienze(my, nazioni);
    
    // Prints i risultati per ogni nazione
    for (int i = 0; i < MAX_NATIONS; i++){
        printf("Paese:%s\t Invitati:%d\n", nazioni[i].name, nazioni[i].num);
    }

    return 0;
}

// NOTA: Implementazione con margini di miglioramento (commento originale: "Brutto")
