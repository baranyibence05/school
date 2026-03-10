#include <stdio.h>

void kiir(int t[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", t[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Hany elem? ");
    scanf("%d", &n);
    
    int t[n];
    for (int i = 0; i < n; i++) {
        printf("t[%d] = ", i);
        scanf("%d", &t[i]);
    }
    
    kiir(t, n);
    
    return 0;
}