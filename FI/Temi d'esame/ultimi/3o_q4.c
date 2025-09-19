/* 3o_q4.c - C source file. */

#include <stdio.h>
#define ROW 3  // Numero di righe della matrix
#define COL 4  // Numero di colonne della matrix

/* *
Function per verificare proprietà di ordinamento posizionale

Algoritmo:
1. Per ogni coppia di righe consecutive
2. Trova l'indice dell'elemento massimo in ciascuna row
3. Verifica che l'indice della row successiva sia maggiore
4. Restituisce 1 solo se la proprietà vale per tutte le coppie

@param mat       Matrice bidimensionale da analizzare
@param row_elem  Numero di colonne (parametro confuso nel nome)
@param col_elem  Numero di righe (parametro confuso nel nome)
@return          1 se proprietà rispettata, 0 altrimenti
 */
int advanced(int mat[][COL], int row_elem, int col_elem){
    int k=0, l=0;        // Indici dei massimi: k per row corrente+1, l per row corrente
    int state=0;         // Stato finale: 1 se proprietà rispettata

    // === CICLO SU COPPIE DI RIGHE CONSECUTIVE ===
    for (int j=0; j<col_elem-1; j++) {
        
        // === TROVA MASSIMO NELLA RIGA CORRENTE ===
        l = 0;  // Reset indice massimo row corrente
        for (int i=0; i<row_elem; i++) {
            if (mat[j][i]>mat[j][l]) {
                l=i;  // Aggiorna indice del massimo
            }
        }
        
        // === TROVA MASSIMO NELLA RIGA SUCCESSIVA ===
        k = 0;  // Reset indice massimo row successiva
        for (int i=0; i<row_elem; i++) {
            if (mat[j+1][i]>mat[j+1][k]) {
                k=i;  // Aggiorna indice del massimo
            }
        }
        
        // === VERIFICA PROPRIETÀ DI ORDINAMENTO ===
        if(l<k){
            state=1;  // Indice crescente: proprietà rispettata per questa coppia
        } else {
            state=0;  // Proprietà violata: terminates con fallimento
            break;    // NOTA: manca break esplicito, l'ultimo controllo prevale
        }
    }
    return state;
}

/* *
Function principale - test dell'algoritmo di verifica proprietà matrix
 */
int main(){
    // === MATRICE DI TEST ===
    int mat[ROW][COL]= {
        {100, 40, 1, 2},     // Riga 0: massimo in posizione 0 (100)
        {2, 1760, 70, 5},    // Riga 1: massimo in posizione 1 (1760)  
        {5, 5, 2560, 40},    // Riga 2: massimo in posizione 2 (2560)
    };
    
    // === VERIFICA E OUTPUT ===
    // Chiamata: COL=4 (colonne), ROW=3 (righe)
    // Proprietà: 0 < 1 < 2 (indici massimi crescenti) ✓
    if (advanced(mat, COL, ROW)) {
        printf("La matrice rispetta i parametri indicati\n");
    }else {
        printf("La matrice non rispetta i parametri indicati\n");
    }
    
    return 0;
}
