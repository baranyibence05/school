#include <stdio.h>
#include <stdlib.h>

int hasonlit(const void *a, const void *b) {
    int felso = *(const int*)a;
    int also = *(const int*)b;
    return (felso > also) - (felso < also);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Használat: %s <forras_fajl> <cel_fajl>\n", argv[0]);
        return 1;
    }

    FILE *f_be = fopen(argv[1], "r");
    if (!f_be) {
        perror("Hiba a bemeneti fájl megnyitásakor");
        return 1;
    }

    size_t kapacitas = 1000; 
    size_t db = 0;
    int *szamok = malloc(kapacitas * sizeof(int));
    
    if (!szamok) {
        perror("Nem sikerült memóriát foglalni");
        fclose(f_be);
        return 1;
    }

    int aktualis_szam;
    while (fscanf(f_be, "%d", &aktualis_szam) == 1) {
        if (db >= kapacitas) {
            kapacitas *= 2;
            int *uj_tomb = realloc(szamok, kapacitas * sizeof(int));
            if (!uj_tomb) {
                perror("Elfogyott a memória");
                free(szamok);
                fclose(f_be);
                return 1;
            }
            szamok = uj_tomb;
        }
        szamok[db++] = aktualis_szam;
    }
    fclose(f_be);

    if (db > 0) {
        qsort(szamok, db, sizeof(int), hasonlit);
    }

    FILE *f_ki = fopen(argv[2], "w");
    if (!f_ki) {
        perror("Hiba a kimeneti fájl létrehozásakor");
        free(szamok);
        return 1;
    }

    for (size_t i = 0; i < db; i++) {
        fprintf(f_ki, "%d\n", szamok[i]);
    }

    fclose(f_ki);
    free(szamok);

    printf("A rendezett szamok sikeresen elmentve ide: %s\n", argv[2]);

    return 0;
}