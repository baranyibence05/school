#include <stdio.h>

int find_min(int t[], int size) {
    int min = t[0];
    for (int i = 1; i < size; i++) {
        if (t[i] < min) {
            min = t[i];
        }
    }
    return min;
}

int find_max(int t[], int size) {
    int max = t[0];
    for (int i = 1; i < size; i++) {
        if (t[i] > max) {
            max = t[i];
        }
    }
    return max;
}

int main() {
    int n;
    printf("Tömbmeret: ");
    scanf("%d", &n);
    
    int t[n];
    for (int i = 0; i < n; i++) {
        printf("t[%d]: ", i);
        scanf("%d", &t[i]);
    }
    
    printf("Legkisebb: %d\n", find_min(t, n));
    printf("Legnagyobb: %d\n", find_max(t, n));
    
    return 0;
}