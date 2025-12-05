/* q2.c - C source file. */

#include <stdio.h>

int plusone(int n){
    if (n == 0) {
        return 0;
    } else {
        int ultimacifra = n % 10;
        int newultima = 0;
        

        if (ultimacifra == 9) {
            newultima = 0;
        } else {
            newultima = ultimacifra + 1;
        }
        
        int resto = n / 10;
        int nuovo = plusone(resto);
        
        return nuovo * 10 + newultima;
    }
}

int main(){
    int numero = 12302;
    
    printf("Numero originale: %d\n", numero);
    printf("Numero incrementato: %d\n", plusone(numero));
    
    return 0;
}
