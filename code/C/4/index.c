#include <stdio.h>

int _index(int t[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (t[i] == element) {
            return i;
        }
    }
    return -1;
}

int main() {
    int t[10];
    int size, element;

    printf("Adja meg a tomb meretet: ");
    scanf("%d", &size);

    printf("Adja meg a tomb elemeit:\n");
    for (int i = 0; i < size; i++) {
        printf("t[%d] = ", i);
        scanf("%d", &t[i]);
    }

    printf("Keresett elem: ");
    scanf("%d", &element);

    int result = _index(t, size, element);

    if (result != -1) {
        printf("Az elem a(z) %d. pozicion talalhato.\n", result);
    } else {
        printf("Az elem nem talalhato a tombben.\n");
    }

    return 0;
}