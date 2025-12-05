/* ricorsione.c - C source file. */

#include <stdio.h>
#define N 2                               // Valore di test per fattoriale e potenza
#define X 3                               // Base per il calcolo della potenza


int fattoriale(int n);
int fattoriale_ricorsivo(int n);
int power(int x, int n);
int mystrlen(char str[]);

/* *
Function principale per dimostrare le varie implementazioni ricorsive
 */
int main(){
    int mynum = N;
    int mybase = X;
    char mystring[] = "Prova";
    
    // CONFRONTO: fattoriale iterativo vs ricorsivo
    printf("Fattoriale iterativo di %d: %d\n", mynum, fattoriale(mynum));
    printf("Fattoriale ricorsivo di %d: %d\n", mynum, fattoriale_ricorsivo(mynum));
    
    // TEST: calcolo potenza recursive
    printf("La potenza %d-esima di %d è: %d\n", mynum, mybase, power(mybase, mynum));
    
    // TEST: lunghezza string recursive
    printf("Lunghezza di '%s': %d caratteri\n", mystring, mystrlen(mystring));
    
    return 0;
}

int fattoriale(int n){
    int f = 1;
    
    // ITERAZIONE: moltiplica tutti i numeri da n a 1
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
Esempio di esecuzione per fattoriale_ricorsivo(3):

fattoriale_ricorsivo(3)
→ 3 * fattoriale_ricorsivo(2)
→ 3 * (2 * fattoriale_ricorsivo(1))
→ 3 * (2 * (1 * fattoriale_ricorsivo(0)))
→ 3 * (2 * (1 * 1))
→ 3 * 2 * 1 * 1 = 6
 */

int power(int x, int n){
    if(n == 0){
        return 1;
    } else {
        return x * power(x, n-1);
    }
/* 
Principi della recursion:
- Base case: il caso più semplice che non richiede ulteriori chiamate ricorsive
- Definizione recursive: utilizza la struttura del problema per costruire la soluzione
- Pensare come "matriosche": ogni chiamata contiene una versione più piccola del problema
 */

int mystrlen(char str[]){
    if (str[0] == '\0'){
        return 0;
    }
    else {
        return 1 + mystrlen(str+1);       // str+1 o &str[1]: puntatore al character successivo
    }
}

/* 
Note tecniche su mystrlen:
- str+1: aritmetica dei puntatori, equivale a &str[1]
- La string viene trattata come puntatore al primo elemento
- Ogni chiamata recursive sposta il puntatore di una posizione
- Lo stack delle chiamate memorizza ogni incremento fino al caso base

Esempio per "Prova":
mystrlen("Prova") → 1 + mystrlen("rova")
→ 1 + (1 + mystrlen("ova"))
→ 1 + (1 + (1 + mystrlen("va")))
→ 1 + (1 + (1 + (1 + mystrlen("a"))))
→ 1 + (1 + (1 + (1 + (1 + mystrlen("")))))
→ 1 + (1 + (1 + (1 + (1 + 0)))) = 5
 */

/* 
Esercizio suggerito:
Definire una funzione che calcola recursivemente la somma dei termini di un array.
Ragiona come se stessi costruendo matriosche: funzione che richiama se stessa
fino a ridursi al caso base, per poi trovare il resto a ritroso.
 */
