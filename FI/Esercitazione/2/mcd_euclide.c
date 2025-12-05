/* mcd_euclide.c - C source file. */

#include <stdio.h>
#include <limits.h>

int main(){

   int x=UINT_MAX, y=UINT_MAX, mcd=0;
    
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
   

   printf("mcd è: %d", mcd);
}
