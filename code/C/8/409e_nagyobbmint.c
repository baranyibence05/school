#include <stdio.h>

int main(void)
{
	FILE *in = fopen("in.txt", "r");
	if (in == NULL) {
		fprintf(stderr, "Hiba! nem megnyithato!\n");
		return 1;
	}

	FILE *out = fopen("out.txt", "w");
	if (out == NULL) {
		fclose(in);
		fprintf(stderr, "Hiba! nem megnyithato!\n");
		return 2;
	}

	printf("# in.txt sikeresen megnyitva\n");
	printf("# 0,5-nel nagyobb szamok szurese...\n");

	int count = 0;
	double x;
	while (fscanf(in, "%lf", &x) == 1) {
		if (x > 0.5) {
			fprintf(out, "%.16f\n", x);
			count++;
		}
	}

	printf("# szures vege\n");

	fclose(in);
	fclose(out);

	printf("# out.txt bezarva\n");
	printf("# out.txt-be kiirt szamok mennyisege: %d db\n", count);

	return 0;
}