/* shift.c - C source file. */
#include <stdio.h>

int main()
{

	int a, b, c, temp;

	// Richieste e lettura da stdin
	printf("\nInserire il valore di a: ");
	scanf("%d", &a);

	printf("Inserire il valore di b: ");
	scanf("%d", &b);

	printf("Inserire il valore di c: ");
	scanf("%d", &c);

	// Shift circolare
	temp = c;
	c = b;
	b = a;
	a = temp;

	printf("\nIl valore di a e': %d", a);
	printf("\nIl valore di b e': %d", b);
	printf("\nIl valore di c e': %d \n", c);

	// Terminazione corretta del programma
	return 0;
}
