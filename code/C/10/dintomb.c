#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *adatok;
    size_t db;
    size_t kapacitas;
} DynArray;

void da_init(DynArray *self) {
    self->adatok = NULL;
    self->db = 0;
    self->kapacitas = 0;
}

void da_push(DynArray *self, int ertek) 
{
    if (self->db >= self->kapacitas) {
        size_t uj_kapacitas = (self->kapacitas == 0) ? 2 : self->kapacitas * 2;
        int *uj_tomb = (int *)realloc(self->adatok, uj_kapacitas * sizeof(int));
        if (!uj_tomb) {
            perror("realloc");
            return;
        }
        self->adatok = uj_tomb;
        self->kapacitas = uj_kapacitas;
    }
    self->adatok[self->db++] = ertek;
}

void da_clear(DynArray *self) {
    if (self->adatok != NULL) {
        free(self->adatok);
    }
    self->adatok = NULL;
    self->db = 0;
    self->kapacitas = 0;
}

int main() {
    DynArray da;
    da_init(&da);

    printf("Elemek hozzaadasa...\n");
    for (int i = 0; i < 5; i++) 
    {
        da_push(&da, i * 10);
    }
    printf("Elemszam: %zu, Kapacitas: %zu\n", da.db, da.kapacitas);

    printf("Torles (da_clear)...\n");
    da_clear(&da);
    printf("Elemszam torles utan: %zu\n", da.db);

    printf("Uj elemek hozzaadasa...\n");
    da_push(&da, 100);
    da_push(&da, 200);
    
    for (size_t i = 0; i < da.db; i++) 
    {
        printf("Elem[%zu]: %d\n", i, da.adatok[i]);
    }

    da_clear(&da);

    return 0;
}