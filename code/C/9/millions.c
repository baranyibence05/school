#include <stdio.h>
#include <stdlib.h>

int hasonlit(const void *a, const void *b) {
    int felso = *(const int*)a;
    int also = *(const int*)b;
    return (felso > also) - (felso < also);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Használat: %s <fajlnev>\n", argv[0]);
        return 1;
    }

    FILE *fajl = fopen(argv[1], "r");
    if (!fajl) {
        perror("Hiba a fájl megnyitásakor");
        return 1;
    }

    size_t kapacitas = 1000; 
    size_t db = 0;
    int *szamok = malloc(kapacitas * sizeof(int));
    
    if (!szamok) {
        perror("Nem sikerült memóriát foglalni");
        fclose(fajl);
        return 1;
    }

    int aktualis_szam;
    while (fscanf(fajl, "%d", &aktualis_szam) == 1) {
        if (db >= kapacitas) {
            kapacitas *= 2;
            int *uj_tomb = realloc(szamok, kapacitas * sizeof(int));
            if (!uj_tomb) {
                perror("Elfogyott a memória a bővítés során");
                free(szamok);
                fclose(fajl);
                return 1;
            }
            szamok = uj_tomb;
        }
        szamok[db++] = aktualis_szam;
    }
    fclose(fajl);

    if (db > 0) {
        qsort(szamok, db, sizeof(int), hasonlit);
    }

    for (size_t i = 0; i < db; i++) {
        printf("%d\n", szamok[i]);
    }

    free(szamok);

    return 0;
}