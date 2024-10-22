#include <stdio.h>
#include <string.h>

#define PIVALEN 11

/*P.IVA non valida: 04657384957
P.IVA valida(Agenzia delle entrate): 06363391001
P.IVA valida, secondo le istruzioni fornite: 04657384955*/



int main(){
    char partita_iva[PIVALEN+1];
    int i=0, j=0, pari[5]={0}, sum_pari=0, dispari[6]={0}, sum_dispari=0, decine=0, unità=0, code_dispari=0, final_code=1;

    printf("Inserisci la partita iva: ");
    fgets(partita_iva, PIVALEN+1, stdin);

    //pari
    for (i = 1, j=0; i < PIVALEN, j < 5; i+=2, j++){
        pari[j]=partita_iva[i] - '0';
    }
    for (j = 0; j < 5; j++){
        sum_pari += 2*pari[j];
    }
    //printf("Somma x2 delle cifre pari:%d\n", sum_pari);


    //dispari
    for (i = 0, j=0; i < PIVALEN, j < 6; i+=2, j++){
        dispari[j]=partita_iva[i] - '0';
    }
    for (j = 0; j < 6; j++){
        sum_dispari += dispari[j];
    }
    code_dispari = sum_dispari;
    //printf("Somma delle cifre dispari: %d\n", sum_dispari);

    // somma cifre dispari
    if (sum_dispari >= 10) {
        decine = sum_dispari / 10;
        unità = sum_dispari % 10;
        code_dispari = decine + unità;
        //printf("Il codice delle cifre dispari è: %d\n", code_dispari);
    }
    
    //Controllo finale

    final_code = (sum_pari + code_dispari) % 10;
    //printf("Il codice di controllo finale è: %d\n", final_code);

    if (final_code == 0)
    {
        printf("La partita IVA è valida\n");
        return 0;
    }
    printf("La partita IVA non è valida\n");

    return 0;
    
}

// Algoritmo implementato come da istruzioni ma non riconosce correttamente partite iva valide. Sospetto istruzioni incomplete o non corrette