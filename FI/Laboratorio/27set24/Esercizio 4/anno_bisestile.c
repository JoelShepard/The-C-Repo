/* anno_bisestile.c - C source file. */

#include <stdio.h>

/* *
Function principale che verifica se un anno è bisestile
Implementa l'algoritmo del calendario gregoriano per gli anni bisestili
 */
int main(){
    int anno;
    int modulo_anno4, modulo_anno100, modulo_anno400;

    printf("Inserisci un anno qualsiasi:");
    scanf("%d", &anno);

    // Calcoliamo i resti delle divisioni per applicare le regole bisestili
    modulo_anno4 = anno % 4;     // Resto divisione per 4
    modulo_anno100 = anno % 100; // Resto divisione per 100
    modulo_anno400 = anno % 400; // Resto divisione per 400

    // === VERIFICA VALIDITÀ E CALCOLO BISESTILE ===
    if(anno < 0){
        // Anno negativo non valido
        printf("anno inserito non valido\n");
    } else if (anno == 0){
        // L'anno 0 non esiste nel calendario gregoriano
        printf("l'anno inserito non può essere 0\n");
    } else if ((modulo_anno4 == 0 && modulo_anno100 != 0) || modulo_anno400 == 0){
/* 
Regole per anno bisestile:
1. Divisibile per 4 E NON divisibile per 100, OPPURE
2. Divisibile per 400
Esempi: 2000 (divisibile per 400), 2004 (div. per 4 ma non per 100)
1900 NON è bisestile (div. per 100 ma non per 400)
 */
        printf("il tuo anno è bisestile !!!\n");
    } else {
        printf("il tuo anno non è bisestile\n");
    }
}
