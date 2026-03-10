#include <stdio.h>
#include <stdlib.h>

void makePositive(int t[], int size) {
    for (int i = 0; i < size; i++) {
        if (t[i] < 0) {
            t[i] = -t[i];
        }
    }
}

void printArray(int t[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", t[i]);
    }
    printf("\n");
}

int main() {
    int size;
    printf("Tomegméret: ");
    scanf("%d", &size);
    
    int t[size];
    
    printf("Szamok (szóközzel elválasztva):\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &t[i]);
    }
    
    printf("Tomeg a módosítás előtt: ");
    printArray(t, size);
    
    makePositive(t, size);
    
    printf("Tomeg a módosítás után: ");
    printArray(t, size);
    
    return 0;
}