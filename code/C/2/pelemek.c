#include <stdio.h>

int main(void) {
    int x;
    int count = 0;

    while (scanf("%d", &x) == 1 && x != 0) {
        if (x > 0) {
            count++;
        }
    }

    printf("Pozitív számok: %d\n", count);
    return 0;
}
