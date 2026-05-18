// partita_iva.c - Validazione partita IVA

#include <stdio.h>

#define PIVALEN 11

int main(){
    char partita_iva[PIVALEN+1];
    int i=0, j=0, pari[5]={0}, sum_pari=0, dispari[6]={0}, sum_dispari=0;
    int decine=0, unità=0, code_dispari=0, final_code=1;

    printf("Inserisci la partita iva: ");
    fgets(partita_iva, PIVALEN+1, stdin);

    for (i = 1, j=0; j < 5; i+=2, j++){
        pari[j]=partita_iva[i] - '0';
    }
    
    // Somma cifre pari moltiplicate per 2
    for (j = 0; j < 5; j++){
        sum_pari += 2*pari[j];
    }
    
    for (i = 0, j=0; j < 6; i+=2, j++){
        dispari[j]=partita_iva[i] - '0';
    }
    
    // Somma cifre dispari
    for (j = 0; j < 6; j++){
        sum_dispari += dispari[j];
    }
    code_dispari = sum_dispari;
    
    // Se somma dispari >= 10, riduci a cifra singola
    if (sum_dispari >= 10) {
        decine = sum_dispari / 10;
        unità = sum_dispari % 10;
        code_dispari = decine + unità;
    }
    
    final_code = (sum_pari + code_dispari) % 10;
    final_code = (sum_pari + code_dispari) % 10;
    
    if (final_code == 0)
    {
        printf("La partita IVA è valida\n");
        return 0;
    }
    printf("La partita IVA non è valida\n");

    return 0;
}
