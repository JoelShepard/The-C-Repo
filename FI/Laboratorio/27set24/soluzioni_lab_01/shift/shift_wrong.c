// shift_wrong.c - Versione errata (bug intenzionali)
#include <stdio.h>

int main()
{
	int a, b, c;

	printf("Inserire il valore di a: ");
	scanf("%d", &a);

	printf("\nInserire il valore di b: ");
	scanf("%d", &b);

	printf("\nInserire il valore di c: ");
	scanf("%d", &c);

	/* BUG: assegnazioni in ordine sbagliato, perdono il valore originale */
	b = a;
	c = b;
	a = c;

	printf("\nIl valore di a è: %d", a);
	printf("\nIl valore di b è: %d", b);
	printf("\nIl valore di c è: %d\n", c);

	return 0;
}
