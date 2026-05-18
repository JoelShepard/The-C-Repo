// default.c - Configurazione output immediato

#include <stdio.h>

int main() {
   // Disabilita buffering stdout per ambienti mobile
   setbuf(stdout, NULL);
   
   printf("Hello, World!");
   
   return 0;
}
