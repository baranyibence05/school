#include <stdio.h>

int contains(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int t[10];
    int size, search;
    
    printf("Hány elemet szeretnél megadni? ");
    scanf("%d", &size);
    
    printf("Add meg az elemeket:\n");
    for (int i = 0; i < size; i++) {
        printf("[%d]: ", i);
        scanf("%d", &t[i]);
    }
    
    printf("Mit szeretnél keresni? ");
    scanf("%d", &search);
    
    if (contains(t, size, search)) {
        printf("Az elem megtalálható a tömbben.\n");
    } else {
        printf("Az elem nem található a tömbben.\n");
    }
    
    return 0;
}