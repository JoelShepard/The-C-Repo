// pointers_algebra.c - Dimostrazione algebra dei puntatori

#include <stdio.h>
#define MAX 5
typedef int* Pointer;

int main(){
    int myarray[MAX] = {128, 32, 43, 23, 54}, count=0;
    Pointer mypoint;
    
    myarray[0]=128;
    mypoint = myarray;
    
    printf("mypoint: %d == myarray[0]: %d\n", *mypoint, myarray[0]);
    printf("mypoint: %d == myarray[0]: %d\n", *mypoint, myarray[0]);

    printf("Il tuo array stampato come sempre è: ");
    for(int i=0; i<MAX; i++){
        printf("%d ", myarray[i]);
    }
    
    printf("\nIl tuo array stampato con i puntatori è: ");
    while(count<MAX){
        printf("%d ", *mypoint);
        mypoint++;
        count++;
    }
    printf("\n");
    
    // myarray[i] equivale a *(myarray + i)
    // L'aritmetica dei puntatori considera sizeof(tipo) automaticamente
}
