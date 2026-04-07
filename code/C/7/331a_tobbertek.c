#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void tomb_statisztika(const int tomb[], int n, int *minimum, int *maximum, double *atlag)
{
	int osszeg = 0;

	*minimum = tomb[0];
	*maximum = tomb[0];

	for (int i = 0; i < n; i++) {
		if (tomb[i] < *minimum) {
			*minimum = tomb[i];
		}
		if (tomb[i] > *maximum) {
			*maximum = tomb[i];
		}
		osszeg += tomb[i];
	}

	*atlag = (double)osszeg / n;
}

int main(void)
{
	const int n = 10;
	int tomb[n];

	int minimum;
	int maximum;
	double atlag;

	srand(17832178213783127812378123);

	for (int i = 0; i < n; i++) {
		tomb[i] = rand() % 90 + 10;
	}

	printf("A tomb elemei: ");
	for (int i = 0; i < n; i++) {
		printf("%d", tomb[i]);
		if (i < n - 1) {
			printf(", ");
		}
	}
	printf("\n");

	tomb_statisztika(tomb, n, &minimum, &maximum, &atlag);

	printf("Legkisebb elem: %d\n", minimum);
	printf("Legnagyobb elem: %d\n", maximum);
	printf("Az elemek atlaga: %.1f\n", atlag);

	return 0;
}
