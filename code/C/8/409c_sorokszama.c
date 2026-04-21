#include <stdio.h>

int get_number_of_lines(FILE *fp)
{
	int c;
	int last = '\n';
	int lines = 0;

	while ((c = fgetc(fp)) != EOF) {
		if (c == '\n') {
			lines++;
		}
		last = c;
	}

	if (last != '\n') {
		lines++;
	}

	return lines;
}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "Hiba! Adja meg a fajlnevet!\n");
		return 1;
	}

	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL) {
		fprintf(stderr, "Hiba! A %s nevu fajlt nem sikerult megnyitni!\n", argv[1]);
		return 2;
	}

	printf("%d\n", get_number_of_lines(fp));

	fclose(fp);
	return 0;
}