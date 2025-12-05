/* pointers_algebra.c - C source file. */

#include <stdio.h>
#define MAX 5            // Size massima dell'array
typedef int* Pointer;    // Definizione di tipo per puntatore ad intero

/* 
Function principale che dimostra l'uso dei puntatori
con array e l'equivalenza delle diverse notezioni di accesso
 */
int main(){
    // SECTION 1-2: INIZIALIZZAZIONE E COLLEGAMENTO
    
    int myarray[MAX] = {128, 32, 43, 23, 54}, count=0;  // Array con valori iniziali
    Pointer mypoint;
    
    myarray[0]=128;      // Ridondante: già inizializzato sopra
    mypoint = myarray;   // Il puntatore ora punta al primo elemento dell'array
    
    // Dimostrazione equivalenza: *mypoint == myarray[0]
    printf("mypoint: %d == myarray[0]: %d\n", *mypoint, myarray[0]);

    // Dimostrazione equivalenza: *mypoint == myarray[0]
    printf("mypoint: %d == myarray[0]: %d\n", *mypoint, myarray[0]);

    // SECTION 3: CONFRONTO METODI DI ITERAZIONE

    // METODO 1: Iterazione tradizionale con indici
    printf("Il tuo array stampato come sempre è: ");
    for(int i=0; i<MAX; i++){
        printf("%d ", myarray[i]);  // Accesso tramite indice myarray[i]
    }
    
    // METODO 2: Iterazione con algebra dei puntatori
    printf("\nIl tuo array stampato con i puntatori è: ");
    while(count<MAX){
        printf("%d ", *mypoint);
        mypoint++;
        count++;
    }
    printf("\n");
    
/* 
NOTE DIDATTICHE:
- mypoint++ sposta il puntatore all'elemento successivo
- *mypoint accede al valore puntato
- myarray[i] è equivalente a *(myarray + i)
- L'aritmetica dei puntatori tiene conto automaticamente
della dimensione del tipo di dato (sizeof(int))
 */
}
