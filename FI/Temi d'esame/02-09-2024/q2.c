#include <stdio.h>

int plusone(int n){
    if (n==0) {
        return 0;
    }else {
        int ultimacifra = n%10;
        int newultima=0;
        if (ultimacifra==9) {
            newultima=0;
        } else {
            newultima=ultimacifra+1;
        }
        int resto = n/10;
        int nuovo = plusone(resto);
        return nuovo*10+newultima;
    }
}

int main(){
    printf("%d", plusone(12302));
}
