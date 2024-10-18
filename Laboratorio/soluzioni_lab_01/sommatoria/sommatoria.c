#include <stdio.h>

int main()
{
	int r, q;
	float y;
	int i;

	printf("Inserisci i valori di q e r: ");
	scanf("%d%d", &q, &r);

	// valido l'input dell'utente
	if ((r > 0) && (q > 0) && (r > q))
	{
		y = 0;
		i = q;

		// eseguo la sommatoria
		while (i <= r)
		{
			y += 1.0 / i;
			i++;
		}

		printf("Il risultato è %f\n", y);
	}
	else
		printf("Errore nell'immissione dei dati\n");

	return 0;
}