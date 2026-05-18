// media_min_max.c - Media, massimo e minimo da sequenza

#include <stdio.h>

int main()
{
	int x;
	int max = 0, min = 0;
	int n = 0;
	float media = 0.0;

	printf("Inserisci un valore: ");
	scanf("%d", &x);

	if (x > 0)
	{
		max = x;
		min = x;

		while (x > 0)
		{
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
