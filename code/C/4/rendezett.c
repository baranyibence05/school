#include <stdio.h>
#include <stdbool.h>

bool is_sorted(int t[], int size) {
    if (size <= 1) {
        return true;
    }
    
    for (int i = 0; i < size - 1; i++) {
        if (t[i] > t[i + 1]) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int t[100];
    int n;
    
    printf("Adja meg a tomb meretét: ");
    scanf("%d", &n);
    
    if (n < 0 || n > 100) {
        printf("Érvénytelen méret!\n");
        return 1;
    }
    
    printf("Adja meg a tomb elemeit:\n");
    for (int i = 0; i < n; i++) {
        printf("t[%d] = ", i);
        scanf("%d", &t[i]);
    }
    
    if (is_sorted(t, n)) {
        printf("A tomb rendezett.\n");
    } else {
        printf("A tomb nem rendezett.\n");
    }
    
    return 0;
}