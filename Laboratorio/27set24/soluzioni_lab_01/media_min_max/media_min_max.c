#include <stdio.h>

int main()
{
	int x;
	int max = 0, min = 0;
	int n = 0;
	float media = 0.0;

	printf("Inserisci un valore: ");
	scanf("%d", &x);

	// se il primo valore è negativo, la sequenza inserita è nulla
	if (x > 0)
	{
		// alla prima iterazione max e min sono uguali a x
		max = x;
		min = x;

		// richiedo valori fino a quando x non è negativo
		while (x > 0)
		{
			// aggiorno i valori di max e min
			if (x > max)
				max = x;

			if (x < min)
				min = x;

			media += x;
			n++;

			printf("Inserisci un valore: ");
			scanf("%d", &x);
		}

		media = media / n;
		printf("Massimo = %d, Minimo = %d, Media = %f", max, min, media);
	}
	else
		printf("La sequenza inserita e' nulla");
		
	return 0;
}