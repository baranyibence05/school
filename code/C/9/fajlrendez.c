#include <stdio.h>
#include <stdlib.h>

int hasonlit(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Hasznalat: %s <fajlnev>\n", argv[0]);
        return 1;
    }

    FILE *fajl = fopen(argv[1], "r");
    if (fajl == NULL) {
        perror("Hiba a fajl megnyitasakor");
        return 1;
    }

    int szamok[2000]; 
    int db = 0;

    while (fscanf(fajl, "%d", &szamok[db]) == 1) {
        db++;
        if (db >= 2000) break;
    }
    fclose(fajl);

    qsort(szamok, db, sizeof(int), hasonlit);

    for (int i = 0; i < db; i++) {
        printf("%d\n", szamok[i]);
    }

    return 0;
}