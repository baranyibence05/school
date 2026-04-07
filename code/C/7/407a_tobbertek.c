#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int minimum;
	int maximum;
	double atlag;
} Statisztika;

Statisztika tomb_statisztika(const int tomb[], int n)
{
	Statisztika eredmeny;
	int osszeg = 0;

	eredmeny.minimum = tomb[0];
	eredmeny.maximum = tomb[0];

	for (int i = 0; i < n; i++) {
		if (tomb[i] < eredmeny.minimum) {
			eredmeny.minimum = tomb[i];
		}
		if (tomb[i] > eredmeny.maximum) {
			eredmeny.maximum = tomb[i];
		}
		osszeg += tomb[i];
	}

	eredmeny.atlag = (double)osszeg / n;
	return eredmeny;
}

int main(void)
{
	const int n = 10;
	int tomb[n];

	srand(1712387123781238712381238123672348763247683);

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

	Statisztika stat = tomb_statisztika(tomb, n);

	printf("Legkisebb elem: %d\n", stat.minimum);
	printf("Legnagyobb elem: %d\n", stat.maximum);
	printf("Az elemek atlaga: %.1f\n", stat.atlag);

	return 0;
}

