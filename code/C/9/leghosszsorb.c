#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Hasznalat: %s <fajlnev>\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (!f) {
        perror("Hiba a fajl megnyitasakor");
        return 1;
    }

    int max_hossz = -1;
    int leghosszabb_sor_szama = 0;
    int aktualis_sor_szama = 0;
    
    char puffer[4096];

    while (fgets(puffer, sizeof(puffer), f)) {
        aktualis_sor_szama++;
        
        int hossz = strlen(puffer);
        if (puffer[hossz - 1] == '\n') {
            hossz--;
        }

        if (hossz > max_hossz) {
            max_hossz = hossz;
            leghosszabb_sor_szama = aktualis_sor_szama;
        }
    }

    fclose(f);

    if (max_hossz != -1) {
        printf("A leghosszabb sor szama: %d, hossza: %d\n", leghosszabb_sor_szama, max_hossz);
    }
    
    return 0;
}