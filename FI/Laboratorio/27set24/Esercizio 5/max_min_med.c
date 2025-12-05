/* max_min_med.c - C source file. */

#include <stdio.h>  // Per printf, scanf

/* *
================================================================
FUNZIONE PRINCIPALE - CALCOLO STATISTICHE
================================================================
 */
int main() {

    int a, b, c, d, e, f;
    
    // Variabili per i calcoli
    int max, tmp, tmp2 = 0, min;  // max/min e contatori temporanei
    float media;                   // Media aritmetica (precisione float)

    // FASE 1: ACQUISIZIONE DEI 6 NUMERI
    printf("Scegli valori interi positivi: ");
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);
    scanf("%d", &e);
    scanf("%d", &f);

    if(a <= 0 || b <= 0 || c <= 0 || d <= 0 || e <= 0 || f <= 0) {
        printf("\nI valori inseriti devono essere degli interi positivi\n");
        return 0;
    }

    
    // FASE 3: CALCOLO DELLA MEDIA ARITMETICA
    media = (a + b + c + d + e + f) / 6.0f;  // Divisione float per precisione
    printf("\nla media è:%f\n", media);

    // FASE 4: RICERCA DEL VALORE MASSIMO
    // Algoritmo: parte dalla somma totale e decrementa fino a trovare un match
    // Note: algoritmo inefficiente O(somma) invece di semplice confronto O(1)
    tmp = a + b + c + d + e + f;  // Inizia dalla somma totale
    
    while (tmp >= a && tmp >= b && tmp >= c && tmp >= d && tmp >= e && tmp >= f) {
        // Controlla se il valore corrente corrisponde a uno dei numeri inseriti
        if (tmp == a || tmp == b || tmp == c || tmp == d || tmp == e || tmp == f) {
            max = tmp;
            break;
        }
        tmp--;
    }
    printf("il massimo è:%d\n", max);

    // FASE 5: RICERCA DEL VALORE MINIMO
    // Algoritmo: parte da zero e increments fino a trovare un match
    // Note: simile approccio inefficiente per il minimo
    while (tmp2 <= a && tmp2 <= b && tmp2 <= c && tmp2 <= d && tmp2 <= e && tmp2 <= f) {
        // Controlla se il valore corrente corrisponde a uno dei numeri inseriti
        if (tmp2 == a || tmp2 == b || tmp2 == c || tmp2 == d || tmp2 == e || tmp2 == f) {
            min = tmp2;
            break;
        }
        tmp2++;
    }
    printf("il minimo è:%d\n", min);
    
    return 0;
}
