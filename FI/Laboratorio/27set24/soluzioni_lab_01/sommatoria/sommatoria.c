/**
 * ================================================================
 * CALCOLATORE SOMMATORIA SERIE ARMONICA - VERSIONE OTTIMIZZATA
 * ================================================================
 * 
 * Descrizione:
 *   Implementazione pulita e ottimizzata per il calcolo della sommatoria
 *   di serie armonica tra due estremi. Calcola la somma Σ(k=q to r) 1/k
 *   utilizzando un approccio iterativo efficiente con validazione
 *   consolidata degli input.
 * 
 * Funzionalità:
 *   - Acquisizione simultanea di entrambi gli estremi (q, r)
 *   - Validazione consolidata: q > 0, r > 0, r > q
 *   - Calcolo iterativo ottimizzato della serie armonica
 *   - Utilizzo di aritmetica floating-point per precisione
 *   - Gestione errori con messaggio unificato
 *
 * Formula matematica: Σ(k=q to r) 1/k = 1/q + 1/(q+1) + ... + 1/r
 *
 * Autore: Soluzione ufficiale (Laboratorio del 27 settembre 2024)
 * Corso: Fondamenti di Informatica
 * 
 * Note tecniche:
 *   - Algoritmo più efficiente rispetto alla versione studente
 *   - Validazione logica combinata in singola condizione
 *   - Ciclo while con condizione diretta (i <= r)
 *   - Incremento diretto senza contatore ausiliario
 * ================================================================
 */

#include <stdio.h>  // Per printf, scanf

/**
 * ================================================================
 * FUNZIONE PRINCIPALE - CALCOLO SOMMATORIA OTTIMIZZATO
 * ================================================================
 */
int main()
{
	// Variabili per calcolo sommatoria
	int r, q;    // Estremi della sommatoria (q = inf, r = sup)
	float y;     // Risultato della sommatoria (precisione float)
	int i;       // Variabile di iterazione

	// ================================================================
	// FASE 1: ACQUISIZIONE ESTREMI SIMULTANEA
	// ================================================================
	printf("Inserisci i valori di q e r: ");
	scanf("%d%d", &q, &r);  // Lettura consolidata di entrambi i valori

	// ================================================================
	// FASE 2: VALIDAZIONE CONSOLIDATA E CALCOLO
	// ================================================================
	// Validazione completa in una sola condizione logica:
	// - r > 0: estremo superiore positivo
	// - q > 0: estremo inferiore positivo  
	// - r > q: ordine corretto degli estremi
	if ((r > 0) && (q > 0) && (r > q))
	{
		// ================================================================
		// FASE 3: CALCOLO ITERATIVO DELLA SOMMATORIA
		// ================================================================
		y = 0;    // Inizializza accumulatore risultato
		i = q;    // Inizializza contatore dall'estremo inferiore
		
		// Ciclo ottimizzato: incrementa direttamente da q a r
		while (i <= r)
		{
			y += 1.0 / i;  // Accumula termine 1/i nella sommatoria
			i++;           // Passa al termine successivo
		}

		// ================================================================
		// FASE 4: VISUALIZZAZIONE RISULTATO
		// ================================================================
		printf("Il risultato è %f\n", y);
	}
	else
	{
		// Gestione errore con messaggio unificato
		printf("Errore nell'immissione dei dati\n");
	}

	return 0;
}