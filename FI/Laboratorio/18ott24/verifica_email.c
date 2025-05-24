/**
 * ================================================================
 * VALIDATORE DI INDIRIZZI EMAIL
 * ================================================================
 * 
 * Descrizione:
 *   Programma che verifica la validità formale di base di un indirizzo email
 *   controllando la presenza e la posizione corretta dei caratteri '@' e '.'
 *   secondo regole semplificate di validazione.
 * 
 * Funzionalità:
 *   - Acquisisce un indirizzo email dall'utente (max 30 caratteri)
 *   - Verifica che non inizi con '@' o '.'
 *   - Controlla la presenza obbligatoria di '@' e '.'
 *   - Valida che ci sia almeno un '.' dopo '@'
 *   - Verifica che '.' non sia immediatamente dopo '@'
 *
 * Autore: Joel (Laboratorio del 18 ottobre 2024)
 * Corso: Fondamenti di Informatica
 * 
 * Note tecniche:
 *   - Validazione semplificata (non RFC 5322 compliant)
 *   - Non verifica caratteri speciali o domini esistenti
 *   - Algoritmo lineare O(n) con singola scansione
 * ================================================================
 */

#include <stdio.h>  // Per printf, fgets
#include <string.h> // Per strlen

#define MAXLEN 30   // Lunghezza massima dell'email da validare

/**
 * ================================================================
 * FUNZIONE PRINCIPALE - VALIDAZIONE EMAIL
 * ================================================================
 */
int main(){
    // Variabili per la gestione dell'email e della validazione
    char email[MAXLEN];           // Buffer per contenere l'email inserita
    int real_len = 0;             // Lunghezza reale della stringa (escluso \n)
    int i = 0;                    // Indice per il ciclo di scansione
    int position_at = 0;          // Posizione del carattere '@' (0 = non trovato)
    int position_full_stop = 0;   // Posizione dell'ultimo '.' trovato (0 = non trovato)

    // ================================================================
    // FASE 1: ACQUISIZIONE DELL'EMAIL
    // ================================================================
    printf("Inserisci una email: ");
    fgets(email, MAXLEN, stdin);        // Legge l'email incluso il carattere newline
    real_len = strlen(email);           // Calcola la lunghezza totale incluso \n

    // ================================================================
    // FASE 2: VALIDAZIONI PRELIMINARI - CONTROLLI CARATTERI INIZIALI
    // ================================================================
    
    // Verifica che l'email non inizi con '@'
    if (email[0] == '@'){
        printf("L'email non può iniziare con una @\n");
        return 0;
    }
    
    // Verifica che l'email non inizi con '.'
    if (email[0] == '.'){
        printf("L'email non può iniziare con un .\n");
        return 0;
    }
    
    // ================================================================
    // FASE 3: SCANSIONE E RICERCA CARATTERI SPECIALI
    // ================================================================
    // Algoritmo: scansione lineare per trovare le posizioni di '@' e '.'
    // Nota: real_len-1 per escludere il carattere newline finale
    
    for (i = 0; i < real_len-1; i++){
        
        // Memorizza la posizione di '@' (sovrascrive se ce ne sono più di una)
        if (email[i] == '@'){
            position_at = i;
        }
        
        // Memorizza la posizione dell'ultimo '.' trovato
        if (email[i] == '.'){
            position_full_stop = i;
        }
    }
    
    // ================================================================
    // FASE 4: VALIDAZIONI STRUTTURALI - CONTROLLI DI PRESENZA
    // ================================================================
    
    // Verifica che sia presente almeno una '@'
    if (position_at == 0){
        printf("Formato non corretto. La @ non è presente\n");
        return 0;
    }
    
    // Verifica che sia presente almeno un '.'
    if (position_full_stop == 0){
        printf("Formato non corretto. Non è presente nenache un .\n");
        return 0;
    }

    // ================================================================
    // FASE 5: VALIDAZIONI POSIZIONALI - CONTROLLI DI ORDINAMENTO
    // ================================================================
    
    // Verifica che '.' non sia immediatamente dopo '@' (es: user@.domain.com)
    if (position_full_stop == position_at + 1)
    {
        printf("Formato non corretto. Il . non può essere subito dopo la @\n");
        return 0;
    }
    
    // Verifica che ci sia almeno un '.' dopo '@' (es: user.name@domain è invalido)
    if (position_full_stop < position_at)
    {
        printf("Formato non corretto. Deve esserci almeno un . dopo la @\n");
        return 0;
    }
    
    // ================================================================
    // FASE 6: VALIDAZIONE COMPLETATA CON SUCCESSO
    // ================================================================
    printf("Formato email corretto :)\n");

    return 0;
}