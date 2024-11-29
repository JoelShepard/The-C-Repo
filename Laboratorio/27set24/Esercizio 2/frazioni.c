#include <stdio.h>

int main(){
    int a, b, c, a1, a2, b1, b2;

    printf("inserisci il numeratore della prima frazione:");
    scanf("%d", &a1);

    printf("inserisci il denominatore della prima frazione:");
    scanf("%d", &b1);

    printf("inserisci il numeratore della seconda frazione:");
    scanf("%d", &a2);

    printf("inserisci il denominatore della seconda frazione:");
    scanf("%d", &b2);

    if(b1 == 0){
        printf("\n il primo denominatore è 0");
        return 0;
    } 
    else if(a1 < 0 && b1 > 0){
        printf("\n la prima frazione è negativa");
        return 0;    
    } 
    else if(b1 < 0 && a1 > 0){
        printf("\n la prima frazione è negativa");
        return 0; 
    } 
    else if(b2 == 0){
       printf("\n il secondo denominatore è 0");
        return 0;
    } 
    else if(a2 < 0 && b2 > 0){
        printf("\n la seconda frazione è negativa");
        return 0; 
    }
    else if(b2 < 0 && a2 > 0){
        printf("\n la seconda frazione è negativa");
        return 0;
    } 
    else {
        b = b2 * b1;
        a = (a1 * b2) + (a2 * b1);
    }


    printf("la somma tra le tue frazioni è: %d / %d", a, b); 
}