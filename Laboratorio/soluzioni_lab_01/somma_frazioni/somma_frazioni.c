#include <stdio.h>

int main()
{
	int num1, denom1, num2, denom2, result_num, result_denom;

	printf("Inserisci la prima frazione: ");
	scanf("%d/%d", &num1, &denom1);

	printf("Inserisci la seconda frazione: ");
	scanf("%d/%d", &num2, &denom2);

	result_num = num1 * denom2 + num2 * denom1;
	result_denom = denom1 * denom2;

	printf("La somma è %d/%d\n", result_num, result_denom);

	return 0;
}