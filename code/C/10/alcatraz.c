#include <stdio.h>
#include <stdbool.h>

#define CELLAK_SZAMA 600


void szimulal_szokes(int cellak_szama) {
    bool cellak[cellak_szama + 1]; 

    for (int i = 1; i <= cellak_szama; i++) {
        cellak[i] = false;
    }

    for (int lepes = 1; lepes <= cellak_szama; lepes++) {
        for (int j = lepes; j <= cellak_szama; j += lepes) {
            cellak[j] = !cellak[j];
        }
    }

    printf("A nyitva maradt cellak sorszamai:\n");
    int szamlalo = 0;
    for (int i = 1; i <= cellak_szama; i++) {
        if (cellak[i]) {
            printf("%d ", i);
            szamlalo++;
        }
    }
    printf("\n");
    for (int i = 1; i <= cellak_szama; i++) {
        if (cellak[i]) {
            printf("%d", i);
            szamlalo++;
        }
    }
    printf("\n\nOsszesen %d elitelit engedtek szabadon.\n", szamlalo);
}

int main() {
    szimulal_szokes(CELLAK_SZAMA);
    return 0;
}