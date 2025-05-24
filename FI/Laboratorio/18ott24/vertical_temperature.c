/*
 * =============================================================================
 * ANALIZZATORE TEMPERATURE CON GRAFICO VERTICALE A ASTERISCHI
 * =============================================================================
 * 
 * Descrizione:
 * Programma avanzato per l'analisi delle temperature giornaliere che genera
 * un grafico verticale a colonne usando asterischi. Ogni asterisco rappresenta
 * un grado sopra la soglia di 34°C, creando una visualizzazione intuitiva
 * dei dati termici.
 * 
 * Autore: Studente FI
 * Data: 18 ottobre 2024
 * Corso: Fondamenti di Informatica - Laboratorio
 * 
 * Funzionalità:
 * - Input temperature per giorni configurabili
 * - Calcolo statistiche: media, minimo, massimo
 * - Generazione grafico verticale con asterischi
 * - Soglia personalizzabile per visualizzazione (34°C)
 * 
 * Algoritmo visualizzazione:
 * - Temperature > 34°C generano asterischi proporzionali
 * - Stampa dall'alto verso il basso (grafico verticale)
 * - Allineamento colonne con tabulazioni
 * 
 * =============================================================================
 */

#include <stdio.h>
#include <limits.h>

#define NUMGIORNI 3  // Numero giorni da analizzare (configurabile)

/*
 * Funzione principale per analisi temperature e generazione grafico
 */
int main() {
    float temperature[NUMGIORNI], sum=0.0, avg, max=0.0, min=__FLT_MAX__;
    int i=0, k=0, col=0, j=0, asterischi[NUMGIORNI], aster=0, maxast=0;

    // ===============================================
    // SEZIONE 1: INPUT TEMPERATURE
    // ===============================================
    
    for (i = 0; i < NUMGIORNI; i++){
        printf("Valore giorno %d:", i+1);
        scanf("%f", &temperature[i]);
    }
    
    // ===============================================
    // SEZIONE 2: CALCOLO STATISTICHE
    // ===============================================
    
    // Calcolo somma per media
    for (i = 0; i < NUMGIORNI; i++){
        sum += temperature[i];
    }
    avg = sum / (float) NUMGIORNI;  // Media temperature

    // Ricerca temperatura massima
    for (i = 0; i < NUMGIORNI; i++){
        if (max < temperature[i])
        {
            max = temperature[i];
        }
    }
    
    // Ricerca temperatura minima
    for (i = 0; i < NUMGIORNI; i++){
        if (min > temperature[i])
        {
            min = temperature[i];
        }
    }

    // ===============================================
    // SEZIONE 3: CALCOLO ASTERISCHI PER GRAFICO
    // ===============================================
    
    // Conta asterischi per ogni giorno (temp > 34°C)
    for (i = 0; i < NUMGIORNI; i++){
        aster=0;
        // Solo temperature sopra 34°C generano asterischi
        if (temperature[i]>34){
            // Numero asterischi = gradi sopra soglia (troncati)
            for (j = 0; j < (int)temperature[i]-34; j++){
                aster+=1;
            }
                    }
        }
        asterischi[i]=aster;  // Memorizza numero asterischi per giorno i
    }
    
    // Trova massimo numero asterischi (per altezza grafico)
    for (i = 0; i < NUMGIORNI; i++){
        if (maxast < asterischi[i]){
            maxast = asterischi[i];
        }
    }

    // ===============================================
    // SEZIONE 4: GENERAZIONE GRAFICO VERTICALE
    // ===============================================
    
    // Stampa grafico dall'alto verso il basso
    for (j = maxast; j >= 0; j--){        // Da massima altezza a 0
        for (i = 0; i < NUMGIORNI; i++){  // Per ogni giorno
            if (asterischi[i] >= j){
                printf("*\t");  // Asterisco se altezza sufficiente
            } else {
                printf("\t");   // Spazio vuoto altrimenti
            }
        }
        printf("\n");  // Nuova riga per livello successivo
    }

    // ===============================================
    // SEZIONE 5: OUTPUT RISULTATI
    // ===============================================
    
    // Stampa temperature sotto il grafico
    for (i = 0; i < NUMGIORNI; i++){
        printf("%.1f\t", temperature[i]);
    }
    printf("\n");

    // Stampa statistiche finali
    printf("\nLa temperatura media è: %.1f\n", avg);
    printf("Il minimo è: %.1f\n", min);
    printf("Il massimo è: %.1f\n", max);

    /*
     * ESEMPIO OUTPUT:
     * Se temp = [36.5, 34.0, 38.2]:
     * 
     *     *
     * *   *
     * *   *
     * *   *
     * 36.5  34.0  38.2
     * 
     * NOTE TECNICHE:
     * - Usa casting (int) per troncare decimali
     * - Tabulazioni per allineamento colonne
     * - Algoritmo "raster scan" per grafico verticale
     * - Soglia 34°C hardcoded (potrebbe essere parametrizzata)
     */

    return 0;
}

