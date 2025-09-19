/* sommatoria.c - C source file. */

#include <stdio.h>  // Per printf, scanf

/* *
================================================================
FUNZIONE PRINCIPALE - CALCOLO SOMMATORIA OTTIMIZZATO
================================================================
/ */
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
		i = q;    // Inizializza counter dall'estremo inferiore
		
		// Ciclo ottimizzato: increments direttamente da q a r
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
