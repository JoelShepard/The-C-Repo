#include <stdio.h>
#include <math.h>

#define MAX 100

typedef struct{
    float x;
    float y;
} punto;

int main(){
    punto punti[MAX];
    int n=0, i=0, a=0;
    float perimetro=0.0;

    printf("Quanti vertici ha il poligono: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++){
        printf("Inserisci la coordinata x del punto %d:", i+1);
        scanf("%f", &punti[i].x);
        printf("Inserisci la coordinata y del punto %d:", i+1);
        scanf("%f", &punti[i].y);
    }

    for (i = 0; i < n; i++)
    {
        if(i == n-1){
            a=0;
        }else{
            a=i+1;
        }

        perimetro+=sqrt(pow(punti[a].x-punti[i].x,2)+pow(punti[a].y-punti[i].y,2));
    }
    printf("Il perimetro è: %.3f", perimetro);

    return 0;
}