/*
 * =============================================================================
 * VALIDATORE PARTITA IVA ITALIANA - ALGORITMO DI CONTROLLO
 * =============================================================================
 * 
 * Descrizione:
 * Implementazione dell'algoritmo di validazione per le partite IVA italiane
 * secondo le specifiche ufficiali. L'algoritmo calcola un codice di controllo
 * basato su posizioni pari e dispari per verificare la correttezza formale
 * del codice fiscale.
 * 
 * Autore: Studente FI
 * Data: 18 ottobre 2024
 * Corso: Fondamenti di Informatica - Laboratorio
 * 
 * Algoritmo di validazione:
 * 1. Separa cifre in posizioni pari e dispari
 * 2. Moltiplica per 2 le cifre in posizione pari
 * 3. Somma tutte le cifre in posizione dispari
 * 4. Se somma dispari >= 10, somma le cifre del risultato
 * 5. Somma finale: (pari + dispari_processate) mod 10 deve essere 0
 * 
 * Formato input: 11 cifre numeriche
 * 
 * Note tecniche:
 * - Il commento finale indica possibili problemi nell'implementazione
 * - L'algoritmo potrebbe non essere completo rispetto alle specifiche ufficiali
 * 
 * =============================================================================
 */

#include <stdio.h>
#include <string.h>

#define PIVALEN 11  // Lunghezza standard partita IVA italiana

/*
 * Esempi di test forniti:
 * P.IVA non valida: 04657384957
 * P.IVA valida (Agenzia delle entrate): 06363391001
 * P.IVA valida, secondo le istruzioni fornite: 04657384955
 */

/*
 * Funzione principale per la validazione della partita IVA
 */
int main(){
    char partita_iva[PIVALEN+1];  // +1 per terminatore stringa
    int i=0, j=0, pari[5]={0}, sum_pari=0, dispari[6]={0}, sum_dispari=0;
    int decine=0, unità=0, code_dispari=0, final_code=1;

    // ===============================================
    // SEZIONE 1: INPUT PARTITA IVA
    // ===============================================
    
    printf("Inserisci la partita iva: ");
    fgets(partita_iva, PIVALEN+1, stdin);  // Lettura sicura con limite

    // ===============================================
    // SEZIONE 2: ELABORAZIONE CIFRE PARI
    // ===============================================
    
    // Estrazione cifre in posizione pari (1, 3, 5, 7, 9)
    for (i = 1, j=0; i < PIVALEN, j < 5; i+=2, j++){
        pari[j]=partita_iva[i] - '0';  // Conversione char->int
    }
    
    // Calcolo somma delle cifre pari moltiplicate per 2
    for (j = 0; j < 5; j++){
        sum_pari += 2*pari[j];
    }
    //printf("Somma x2 delle cifre pari:%d\n", sum_pari);  // Debug

    // ===============================================
    // SEZIONE 3: ELABORAZIONE CIFRE DISPARI
    // ===============================================
    
    // Estrazione cifre in posizione dispari (0, 2, 4, 6, 8, 10)
    for (i = 0, j=0; i < PIVALEN, j < 6; i+=2, j++){
        dispari[j]=partita_iva[i] - '0';  // Conversione char->int
    }
    
    // Calcolo somma delle cifre dispari
    for (j = 0; j < 6; j++){
        sum_dispari += dispari[j];
    }
    code_dispari = sum_dispari;
    //printf("Somma delle cifre dispari: %d\n", sum_dispari);  // Debug

    // ===============================================
    // SEZIONE 4: GESTIONE SOMMA DISPARI >= 10
    // ===============================================
    
    // Se somma dispari >= 10, somma le cifre del risultato
    if (sum_dispari >= 10) {
        decine = sum_dispari / 10;     // Cifra delle decine
        unità = sum_dispari % 10;      // Cifra delle unità
        code_dispari = decine + unità; // Riduzione a cifra singola
        //printf("Il codice delle cifre dispari è: %d\n", code_dispari);  // Debug
    }
    
    // ===============================================
    // SEZIONE 5: CONTROLLO FINALE E VALIDAZIONE
    // ===============================================
    
    // Calcolo codice di controllo finale
    final_code = (sum_pari + code_dispari) % 10;
    //printf("Il codice di controllo finale è: %d\n", final_code);  // Debug

        // Calcolo codice di controllo finale
    final_code = (sum_pari + code_dispari) % 10;
    //printf("Il codice di controllo finale è: %d\n", final_code);  // Debug
    
    // Verifica validità: codice deve essere 0
    if (final_code == 0)
    {
        printf("La partita IVA è valida\n");
        return 0;
    }
    printf("La partita IVA non è valida\n");

    return 0;
    
    /*
     * NOTE SULL'IMPLEMENTAZIONE:
     * 
     * PROBLEMA IDENTIFICATO:
     * Il commento originale indica che l'algoritmo implementato
     * non riconosce correttamente partite IVA valide, suggerendo
     * che le istruzioni potrebbero essere incomplete o non corrette.
     * 
     * POSSIBILI CAUSE:
     * 1. L'algoritmo ufficiale della partita IVA italiana è più complesso
     * 2. Potrebbero mancare controlli aggiuntivi (lunghezza, formato)
     * 3. La gestione delle cifre >= 10 potrebbe essere diversa
     * 
     * MIGLIORAMENTI SUGGERITI:
     * - Validazione input (solo cifre, lunghezza corretta)
     * - Implementazione algoritmo ufficiale Agenzia delle Entrate
     * - Gestione errori più robusta
     * - Test con più casi di esempio
     */
}