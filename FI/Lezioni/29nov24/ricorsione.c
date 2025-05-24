/**
 * File: ricorsione.c
 * Descrizione: Esempi di funzioni ricorsive fondamentali - fattoriale, 
 *              potenza e lunghezza stringa
 * Autore: [Docente]
 * Data: 29-11-2024
 * Lezione: Programmazione ricorsiva - principi e applicazioni
 * 
 * Commento originale: "nella ricorsione una funzione invoca se stessa"
 * 
 * Concetti chiave:
 * - Caso base: condizione di terminazione della ricorsione
 * - Chiamata ricorsiva: la funzione invoca se stessa con parametri modificati
 * - Stack delle chiamate: ogni chiamata viene memorizzata nello stack
 */

#include <stdio.h>
#define N 2                               // Valore di test per fattoriale e potenza
#define X 3                               // Base per il calcolo della potenza

// PROTOTIPI DELLE FUNZIONI
int fattoriale(int n);
int fattoriale_ricorsivo(int n);
int power(int x, int n);
int mystrlen(char str[]);

/**
 * Funzione principale per dimostrare le varie implementazioni ricorsive
 */
int main(){
    int mynum = N;
    int mybase = X;
    char mystring[] = "Prova";
    
    // CONFRONTO: fattoriale iterativo vs ricorsivo
    printf("Fattoriale iterativo di %d: %d\n", mynum, fattoriale(mynum));
    printf("Fattoriale ricorsivo di %d: %d\n", mynum, fattoriale_ricorsivo(mynum));
    
    // TEST: calcolo potenza ricorsiva
    printf("La potenza %d-esima di %d è: %d\n", mynum, mybase, power(mybase, mynum));
    
    // TEST: lunghezza stringa ricorsiva
    printf("Lunghezza di '%s': %d caratteri\n", mystring, mystrlen(mystring));
    
    return 0;
}

/**
 * Calcolo del fattoriale con approccio iterativo (ciclo while)
 * 
 * @param n  Numero di cui calcolare il fattoriale
 * @return   n! (fattoriale di n)
 * 
 * Algoritmo: f = 1 * 2 * 3 * ... * n
 */
int fattoriale(int n){
    int f = 1;                            // Inizializza il risultato
    
    // ITERAZIONE: moltiplica tutti i numeri da n a 1
    while(n > 0){
        f = f * n;                        // Accumula il prodotto
        n--;                              // Decrementa il contatore
    }
    return f;
}

/**
 * Calcolo del fattoriale con approccio ricorsivo
 * 
 * @param n  Numero di cui calcolare il fattoriale
 * @return   n! (fattoriale di n)
 * 
 * Definizione ricorsiva: n! = n * (n-1)!
 * Caso base: 0! = 1
 */
int fattoriale_ricorsivo(int n){
    // CASO BASE: fattoriale di 0 è 1
    if(n == 0){
        return 1;
    } else {
        // RICORSIONE: n! = n * (n-1)!
        return n * fattoriale_ricorsivo(n-1);
    }
}

/*
 * Esempio di esecuzione per fattoriale_ricorsivo(3):
 * 
 * fattoriale_ricorsivo(3)
 * → 3 * fattoriale_ricorsivo(2)
 * → 3 * (2 * fattoriale_ricorsivo(1))
 * → 3 * (2 * (1 * fattoriale_ricorsivo(0)))
 * → 3 * (2 * (1 * 1))
 * → 3 * 2 * 1 * 1 = 6
 */

/**
 * Calcolo della potenza con approccio ricorsivo
 * 
 * @param x  Base della potenza
 * @param n  Esponente della potenza
 * @return   x^n (x elevato alla n)
 * 
 * Definizione ricorsiva: x^n = x * x^(n-1)
 * Caso base: x^0 = 1
 */
int power(int x, int n){
    // CASO BASE: qualsiasi numero elevato a 0 è 1
    if(n == 0){
        return 1;
    } else {
        // RICORSIONE: x^n = x * x^(n-1)
        return x * power(x, n-1);
    }
/*
 * Principi della ricorsione:
 * - Caso base: il caso più semplice che non richiede ulteriori chiamate ricorsive
 * - Definizione ricorsiva: utilizza la struttura del problema per costruire la soluzione
 * - Pensare come "matriosche": ogni chiamata contiene una versione più piccola del problema
 */

/**
 * Calcolo della lunghezza di una stringa con approccio ricorsivo
 * 
 * @param str  Array di caratteri (stringa) di cui calcolare la lunghezza
 * @return     Numero di caratteri nella stringa (escluso '\0')
 * 
 * Definizione ricorsiva: 
 * - Se il primo carattere è '\0', la lunghezza è 0
 * - Altrimenti, la lunghezza è 1 + lunghezza del resto della stringa
 */
int mystrlen(char str[]){
    // CASO BASE: stringa vuota (terminatore '\0')
    if (str[0] == '\0'){
        return 0;
    }
    else {
        // RICORSIONE: 1 + lunghezza del resto della stringa
        return 1 + mystrlen(str+1);       // str+1 o &str[1]: puntatore al carattere successivo
    }
}

/*
 * Note tecniche su mystrlen:
 * - str+1: aritmetica dei puntatori, equivale a &str[1]
 * - La stringa viene trattata come puntatore al primo elemento
 * - Ogni chiamata ricorsiva sposta il puntatore di una posizione
 * - Lo stack delle chiamate memorizza ogni incremento fino al caso base
 * 
 * Esempio per "Prova":
 * mystrlen("Prova") → 1 + mystrlen("rova")
 * → 1 + (1 + mystrlen("ova"))
 * → 1 + (1 + (1 + mystrlen("va")))
 * → 1 + (1 + (1 + (1 + mystrlen("a"))))
 * → 1 + (1 + (1 + (1 + (1 + mystrlen("")))))
 * → 1 + (1 + (1 + (1 + (1 + 0)))) = 5
 */

/*
 * Esercizio suggerito:
 * Definire una funzione che calcola ricorsivamente la somma dei termini di un array.
 * Ragiona come se stessi costruendo matriosche: funzione che richiama se stessa 
 * fino a ridursi al caso base, per poi trovare il resto a ritroso.
 */
