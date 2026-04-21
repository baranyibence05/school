#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp = fopen("valos_szamok.txt", "r");
	if (fp == NULL) {
		fprintf(stderr, "Hiba! nem megnyithato!\n");
		return 1;
	}

	long double sum = 0.0L;
	char line[256];

	while (fgets(line, sizeof(line), fp) != NULL) {
		for (int i = 0; line[i] != '\0'; i++) {
			if (line[i] == ',') {
				line[i] = '.';
			}
		}

		char *endptr;
		long double value = strtold(line, &endptr);
		if (endptr != line) {
			sum += value;
		}
	}

	fclose(fp);

	printf("%.20Lf\n", sum);
	return 0;
}