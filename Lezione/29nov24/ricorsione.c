/* nella riscorsione una funzione invoca se stessa */
#include <stdio.h>
#define N 2
#define X 3

int fattoriale(int n);
int fattoriale_ricorsivo(int n);
int power(int x, int n);
int mystrlen(char str[]);

int main(){
    int mynum = N;
    int mybase = X;
    char mystring[]="Prova";
    printf("%d\n", fattoriale(mynum));
    printf("con la funzione ricorsiva: %d\n", fattoriale_ricorsivo(mynum));
    printf("La potenza %d-esima di %d è: %d\n", mynum, mybase, power(mybase, mynum));
    printf("My string length is: %d\n", mystrlen(mystring));
}

int fattoriale(int n){ //iterazione
    int f=1;
    while(n>0){
        f=f*n;
        n--;
    }
    return f;
}

int fattoriale_ricorsivo(int n){
    if(n==0){
        return 1;
    }else{
        return n*fattoriale_ricorsivo(n-1);
    }
}
/*
Es: (3*fattoriale_ricorsivo(2))
    (3*(2*fattoriale_ricorsivo(1)))
    (3*(2*(1*fattoriale_ricorsivo(0))))
    (3*2*1*1)
*/

int power(int x, int n){
    if(n==0){
        return 1;
    } else {
        int ris = 0;
        return x*power(x, n-1);
    }
}

/* Ricorsione:
- Caso base: il caso più semplice in assoluto
- Uso della definizione della struttura creata per sommare tutte le itarazioni diverse da base: ricorda la definizione matematica del problema
*/

int mystrlen(char str[]){
    if (str[0] == '\0'){
        return 0;
    }
    else {
        return 1+mystrlen(str+1 /*o &str[1]*/);
//sfrutta le stringhe non come array ma come puntatore al primo elemento. Con & sto dicendo alla funzione qual'è l'indirizzo del primo elemento della stringa che voglio considerare
    }
}

/*Definire una funzione che calcola ricorsivamente la somma dei termini di un array*/
