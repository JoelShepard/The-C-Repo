/* somme_successive.c - C source file. */
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


	printf("\nIl valore del prodotto e': %d\n", prodotto);


	return 0;
}
