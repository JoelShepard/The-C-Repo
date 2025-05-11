#include <stdio.h>
#include <limits.h>

int main(){
   int x=UINT_MAX,y=UINT_MAX,mcd=0;
    
   printf("\nInserisci numeri interi in questo formato: x,y\n");
   scanf("%d,%d", &x, &y);
   while (x != y){
   if (x<=y){
      y = y - x;
      x = x;
   } else {
      x = x - y; 
      y = y;  
   }
   }
   mcd = x;
   printf("mcd è: %d", mcd);
}