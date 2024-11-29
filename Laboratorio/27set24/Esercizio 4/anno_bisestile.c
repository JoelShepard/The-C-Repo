#include <stdio.h>

int main(){
    int anno, modulo_anno4, modulo_anno100, modulo_anno400;

    printf("Inserisci un anno qualsiasi:");
    scanf("%d", &anno);

    modulo_anno4 = anno % 4;
    modulo_anno100 = anno % 100;
    modulo_anno400 = anno % 400;

    if(anno < 0){
        printf("anno inserito non valido\n");
    } else if (anno == 0){
        printf("l'anno inserito non può essere 0\n");
    } else if ((modulo_anno4 == 0 && modulo_anno100 != 0) || modulo_anno400 == 0){
        printf("il tuo anno è bisestile !!!\n");
    } else {
        printf("il tuo anno non è bisestile\n");
    }
}