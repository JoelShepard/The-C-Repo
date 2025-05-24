/*
 * File: mcd_euclide.c
 * Descrizione: Calcolo del Massimo Comun Divisore usando l'algoritmo di Euclide
 * Autore: Studente FI
 * Data: Esercitazione 2
 */

#include <stdio.h>
#include <limits.h>

/**
 * Funzione principale che implementa l'algoritmo di Euclide per il calcolo del MCD
 * L'algoritmo si basa sulla proprietà: MCD(a,b) = MCD(b, a mod b)
 * @return 0 se l'esecuzione è avvenuta con successo
 */
int main(){
   // Inizializzazione delle variabili
   int x=UINT_MAX, y=UINT_MAX, mcd=0;
    
   // Input dei due numeri dall'utente
   printf("\nInserisci numeri interi in questo formato: x,y\n");
   scanf("%d,%d", &x, &y);
   
   // Algoritmo di Euclide: sottrazione ripetuta
   // Continua finché x e y non sono uguali
   while (x != y){
       if (x<=y){
          // Se x è minore o uguale a y, sottrae x da y
          y = y - x;
          x = x;
       } else {
          // Se x è maggiore di y, sottrae y da x
          x = x - y; 
          y = y;  
       }
   }
   
   // Quando x == y, abbiamo trovato il MCD
   mcd = x;
   
   // Output del risultato
   printf("mcd è: %d", mcd);
}