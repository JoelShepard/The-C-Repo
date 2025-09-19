/* shift_right.c - C source file. */

#include <stdio.h>

/* *
Function principale che implementa lo shift circolare a right
Input: tre valori a, b, c
Output: a2=b, b2=c, c2=a (shift circolare)
/ */
int main() {
	// === DICHIARAZIONE VARIABILI ===
	int a, b, c;        // Variabili originali
	int a2, b2, c2;     // Variabili dopo lo shift

	// Inizializzazione delle variabili
	a = 0;
	b = 0;
	c = 0;
	a2 = 0;
	b2 = 0;
	c2 = 0;

	// === INPUT DEI VALORI ===
	printf("\n Inserire il valore di a: ");
	scanf("%d", &a);

	printf("\n Inserire il valore di b: ");
	scanf("%d", &b);

	printf("\n Inserire il valore di c: ");
	scanf("%d", &c);

	// === OPERAZIONE DI SHIFT CIRCOLARE A DESTRA ===
/* 
Schema dello shift: a → c, b → a, c → b
Quindi: a2 = b, b2 = c, c2 = a
/ */
	 a2 = b;  // Il nuovo valore di 'a' diventa l'ex valore di 'b'
	 b2 = c;  // Il nuovo valore di 'b' diventa l'ex valore di 'c'
	 c2 = a;  // Il nuovo valore di 'c' diventa l'ex valore di 'a'

	 // === OUTPUT DEI RISULTATI ===
	 printf("\nIl valore di a è: %d", a2);
	 printf("\nIl valore di b è: %d", b2);
	 printf("\nIl valore di c è: %d\n", c2);

	 return 0;
}
