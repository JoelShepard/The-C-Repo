#include <stdio.h>

int main() {
	int a, b, c, a2, b2, c2;

	a = 0;
	b = 0;
	c = 0;
	a2 = 0;
	b2 = 0;
	c2 = 0;

	printf("\n Inserire il valore di a: ");
	scanf("%d", &a);

	printf("\n Inserire il valore di b: ");
	scanf("%d", &b);

	printf("\n Inserire il valore di c: ");
	scanf("%d", &c);

	/* Adesso faccio lo shift */
	 a2 = b;
	 b2 = c;
	 c2 = a;

	 printf("\nIl valore di a è: %d", a2);
	 printf("\nIl valore di b è: %d", b2);
	 printf("\nIl valore di c è: %d\n", c2);

	 return 0;
}
