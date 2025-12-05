/* default.c - C source file. */

#include <stdio.h>

/* *
Function principale con configurazione per output immediato
 */
int main() {
   // Utile quando si lavora su piattaforme mobile o ambienti specifici
   setbuf(stdout, NULL);
   
   // Prints messaggio di prova
   printf("Hello, World!");
   
   return 0;
}
