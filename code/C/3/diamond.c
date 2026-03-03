#include <stdio.h>
#include <stdlib.h>

int main() {
    int height;
    
    printf("Adja meg a gyémánt magasságát: ");
    scanf("%d", &height);
    if (height <= 0 || height % 2 == 0) 
    {
        fprintf(stderr, "Hiba: Csak pozitív páratlan számot fogadunk el!\n");
        return 1;
    }
       
    
   
    
    int mid = height / 2;

    for (int i = 0; i <= mid; i++) {
        for (int j = 0; j < mid - i; j++) {
            printf(" ");
        }
        for (int j = 0; j < 2 * i + 1; j++) {
            printf("*");
        }
        printf("\n");
    }

    for (int i = mid - 1; i >= 0; i--) {
        for (int j = 0; j < mid - i; j++) {
            printf(" ");
        }
        for (int j = 0; j < 2 * i + 1; j++) {
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}