#include <stdio.h>
#include <string.h>

#define PIVALEN 11

int main(){
    char partita_iva[PIVALEN+1], sum_2digits[2];
    int i=0, j=0, pari[5]={0}, sum_pari=0, dispari[5]={0}, sum_dispari=0, tmp=0;

    printf("Inserisci la partita iva: ");
    fgets(partita_iva, PIVALEN+1, stdin);

    //pari
    for (i = 1, j=0; i < PIVALEN, j < 5; i+=2, j++){
        pari[j]=partita_iva[i] - '0';
    }
    for (j = 0; j < 5; j++){
        sum_pari += 2*pari[j];
    }
    printf("Somma x2 delle cifre pari:%d\n", sum_pari);

    if(sum_pari >= 10){
    sprintf(sum_2digits, "%d", sum_pari);
    }
    printf(sum_2digits);

    //dispari
    for (i = 0, j=0; i < PIVALEN, j < 5; i+=2, j++){
        dispari[j]=partita_iva[i] - '0';
        printf("%d", dispari[j]);
    }
    for (j = 0; j < 5; j++){
        sum_dispari += dispari[j];
    }
    printf("Somma delle cifre dispari: %d\n", sum_dispari);

}
