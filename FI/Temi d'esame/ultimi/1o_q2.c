/* 1o_q2.c - C source file. */

#include <stdio.h>

int itsfollowed(int a[], int x, int y, int dim, int flag){

    // === CONTROLLO ESISTENZA DI X NELL'ARRAY ===
    for (int i=0; i<dim; i++) {
        if(a[i]==x){
            flag=1;  // x trovato nell'array
        }
    }

    // === CONTROLLO VALIDITÀ ===
    if (!flag){
        return -1;  // x non esiste nell'array, sequenza impossibile
    }

    if (dim == 0) {
        return 0;
    }

    // === CASO RICORSIVO: VERIFICA SEQUENZA ===
    if (*a == x && *(a+1)==y) {
        // Sequenza x,y trovata: increments counter e continues
        return 1+itsfollowed(a+1, x, y, dim-1, flag);
    } else {
        // Sequenza non trovata: continues senza incrementsre
        return 0+itsfollowed(a+1, x, y, dim-1, flag);
    }
}

/* *
Function principale - test dell'algoritmo di conteggio sequenze
 */
int main(){
    int a[]={2,3,4,5,2,3,4,6,2,3};  // Array: contiene sequenze 2,3 (posizioni 0-1, 4-5, 8-9)
    int dim = 10;

    // Cerca sequenza 7,5: 7 non esiste nell'array -> dovrebbe ritornare -1
    int risultato = itsfollowed(a, 7, 5, dim, 0);
    printf("Occorrenze sequenza 7,5: %d\n", risultato);
    
    // itsfollowed(a, 2, 3, dim, 0) dovrebbe ritornare 3
    
    return 0;
}
