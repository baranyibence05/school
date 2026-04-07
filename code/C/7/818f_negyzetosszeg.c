#include <stdio.h>

int main(void)
{
	long long osszeg = 0;
	long long negyzetosszeg = 0;

	for (int i = 1; i <= 100; i++) {
		osszeg += i;
		negyzetosszeg += (long long)i * i;
	}

	long long osszeg_negyzete = osszeg * osszeg;
	long long kulonbseg = osszeg_negyzete - negyzetosszeg;

	printf("Az elso 100 termeszetes szam osszegenek negyzete: %lld\n", osszeg_negyzete);
	printf("Az elso 100 termeszetes szam negyzetosszege: %lld\n", negyzetosszeg);
	printf("A kulonbseg: %lld\n", kulonbseg);

	return 0;
}
