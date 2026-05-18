// mcd_euclide.c - MCD con algoritmo di Euclide

#include <stdio.h>
#include <limits.h>

int main(){
   int x=UINT_MAX, y=UINT_MAX, mcd=0;
    
   printf("\nInserisci numeri interi in questo formato: x,y\n");
   scanf("%d,%d", &x, &y);
   
   // Algoritmo di Euclide: sottrazione ripetuta finché x e y non sono uguali
   while (x != y){
       if (x<=y){
          y = y - x;
       } else {
          x = x - y; 
       }
   }
   
   mcd = x;

   printf("mcd è: %d", mcd);
}
