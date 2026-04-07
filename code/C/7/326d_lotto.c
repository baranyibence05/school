#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rendez_novekvo(int n, int tomb[])
{
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (tomb[j] > tomb[j + 1]) {
				int temp = tomb[j];
				tomb[j] = tomb[j + 1];
				tomb[j + 1] = temp;
			}
		}
	}
}

void kiir_tomb(int n, const int tomb[])
{
	for (int i = 0; i < n; i++) {
		printf("%d", tomb[i]);
		if (i < n - 1) {
			printf(" ");
		}
	}
	printf("\n");
}

int tartalmazza(int n, const int tomb[], int ertek)
{
	for (int i = 0; i < n; i++) {
		if (tomb[i] == ertek) {
			return 1;
		}
	}
	return 0;
}

void general_randomok(int n, int also, int felso, int tomb[])
{
	for (int i = 0; i < n; i++) {
		tomb[i] = rand() % (felso - also + 1) + also;
	}
}

void general_egyedi_randomok(int n, int also, int felso, int tomb[])
{
	int i = 0;

	while (i < n) {
		int uj = rand() % (felso - also + 1) + also;
		if (!tartalmazza(i, tomb, uj)) {
			tomb[i] = uj;
			i++;
		}
	}
}

int main(void)
{
	int n;
	int also;
	int felso;

	srand((unsigned)time(NULL));

	printf("Hany db random szamot kersz? ");
	scanf("%d", &n);

	printf("Also hatar: ");
	scanf("%d", &also);

	printf("Felso hatar (zart intervallum): ");
	scanf("%d", &felso);

	if (n <= 0) {
		printf("A darabszamnak pozitivnak kell lennie.\n");
		return 1;
	}

	if (also > felso) {
		int temp = also;
		also = felso;
		felso = temp;
	}

	int a[n];
	int b[n];
	int c[n];

	general_randomok(n, also, felso, a);
	for (int i = 0; i < n; i++) {
		b[i] = a[i];
	}

	rendez_novekvo(n, b);

	printf("\nA) A generalt szamok: ");
	kiir_tomb(n, a);

	printf("B) Rendezve: ");
	kiir_tomb(n, b);

	if (n > felso - also + 1) {
		printf("C) Nem lehet %d kulonbozo szamot generalni a [%d, %d] intervallumbol.\n", n, also, felso);
		return 0;
	}

	general_egyedi_randomok(n, also, felso, c);
	rendez_novekvo(n, c);

	printf("C) Kulonbozo (es rendezett) szamok: ");
	kiir_tomb(n, c);

	return 0;
}