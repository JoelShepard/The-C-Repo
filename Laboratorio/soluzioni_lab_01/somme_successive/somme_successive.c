#include <stdio.h>

int main()
{
	int fattore1, fattore2, prodotto = 0, numeroSomme = 0;

	// Legge il primo fattore
	printf("\nInserisci il primo fattore: ");
	scanf("%d", &fattore1);

	// Legge il secondo fattore
	printf("\nInserisci il secondo fattore: ");
	scanf("%d", &fattore2);

	// Inizializzazione numeroSomme
	if (fattore2 >= 0) {
		numeroSomme = fattore2;
	} else {
		// fattore2 < 0
		numeroSomme = -fattore2;
	}

	// Esegue il prodotto con il metodo delle somme successive
	int i = 0;
	while (i < numeroSomme) {
		prodotto += fattore1;
		i++;
	}

	if (fattore2 < 0) {
		prodotto = -prodotto;
	}

	// Scrive il risultato
	printf("\nIl valore del prodotto e': %d\n", prodotto);

	// Termina correttamente
	return 0;
}