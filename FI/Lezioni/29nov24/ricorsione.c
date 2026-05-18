// ricorsione.c - Dimostrazione ricorsione

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
    char mystring[] = "Prova";
    
    printf("Fattoriale iterativo di %d: %d\n", mynum, fattoriale(mynum));
    printf("Fattoriale ricorsivo di %d: %d\n", mynum, fattoriale_ricorsivo(mynum));
    printf("La potenza %d-esima di %d è: %d\n", mynum, mybase, power(mybase, mynum));
    printf("Lunghezza di '%s': %d caratteri\n", mystring, mystrlen(mystring));
    
    return 0;
}

int fattoriale(int n){
    int f = 1;
    while(n > 0){
        f = f * n;
        n--;
    }
    return f;
}

int fattoriale_ricorsivo(int n){
    if(n == 0){
        return 1;
    } else {
        return n * fattoriale_ricorsivo(n-1);
    }
}

/* 
fattoriale_ricorsivo(3):
→ 3 * fattoriale_ricorsivo(2)
→ 3 * (2 * fattoriale_ricorsivo(1))
→ 3 * (2 * (1 * fattoriale_ricorsivo(0)))
→ 3 * (2 * (1 * 1)) = 6
*/

int power(int x, int n){
    if(n == 0){
        return 1;
    } else {
        return x * power(x, n-1);
    }
}

int mystrlen(char str[]){
    if (str[0] == '\0'){
        return 0;
    } else {
        return 1 + mystrlen(str+1);
    }
}

/* 
mystrlen("Prova"):
→ 1 + mystrlen("rova") → ... → 1 + 1 + 1 + 1 + 1 + 0 = 5
*/
