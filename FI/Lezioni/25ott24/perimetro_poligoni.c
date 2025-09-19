/* perimetro_poligoni.c - C source file. */

#include <stdio.h>
#include <math.h>

#define MAX 100                           // Numero massimo di vertici supportati

/* *
Struttura per rappresentare un punto nel piano cartesiano
 */
typedef struct{
    float x;                              // Coordinata x del punto
    float y;                              // Coordinata y del punto
} punto;

/* *
Function principale per calcolare il perimetro di un poligono

Il perimetro è la somma delle distanze tra tutti i vertici consecutivi,
includendo la distanza dall'ultimo vertice al primo per chiudere la figura
 */
int main(){
    // VARIABILI
    punto punti[MAX];                     // Array per memorizzare i vertici
    int n = 0, i = 0, a = 0;             // Contatori e indici
    float perimetro = 0.0;               // Perimetro totale del poligono

    // INPUT: acquisizione numero di vertici
    printf("Quanti vertici ha il poligono: ");
    scanf("%d", &n);
    
    // Validazione input
    if (n < 3 || n > MAX) {
        printf("Errore: un poligono deve avere almeno 3 vertici e massimo %d\n", MAX);
        return 1;
    }

    // INPUT: acquisizione coordinate di tutti i vertici
    for (i = 0; i < n; i++){
        printf("Inserisci la coordinata x del punto %d: ", i+1);
        scanf("%f", &punti[i].x);
        printf("Inserisci la coordinata y del punto %d: ", i+1);
        scanf("%f", &punti[i].y);
    }

    // CALCOLO PERIMETRO: somma delle distanze tra vertici consecutivi
    for (i = 0; i < n; i++)
    {
        // GESTIONE CHIUSURA: l'ultimo vertice si collega al primo
        if(i == n-1){
            a = 0;                        // Dall'ultimo vertice al primo
        }else{
            a = i+1;                      // Al vertice successivo
        }

        // FORMULA DISTANZA EUCLIDEA: sqrt((x2-x1)² + (y2-y1)²)
        float distanza = sqrt(pow(punti[a].x - punti[i].x, 2) + 
                             pow(punti[a].y - punti[i].y, 2));
        perimetro += distanza;
    }
    
    // OUTPUT: risultato finale
    printf("Il perimetro del poligono è: %.3f\n", perimetro);

    return 0;
}
